#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <unordered_map>
#include "Routes.cpp"
#include "Node.cpp"

/**
 * The BFS class implements methods like contains and equals.
 * The class implmements the method that does a BFS search given a start and end point.
*/
class BFS
{
    protected:
    string initialLoc;
    string destinationLoc;
    queue<Node> frontier;
    set<string> exploredSet;
    vector<string> airports;

    /**
     * GeeksforGeeks. (2022, October 14). unordered_map in C++ STL. https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
    */
    unordered_map<string, string> airportsToPlaces;
    unordered_map<string, vector<string>> locationToAirportsMap;

    public:
    BFS(unordered_map<string, string> airportsMap, unordered_map<string, vector<string>> locationsMap);

    bool contains(queue<Node> aQueue, Node aNode);

    bool contains(set<string> aSet, string aString);

    bool equals(Node node1, Node node2);

    bool equals(string firstString, string secondString);

    bool equals(vector<Routes> firstList, any secondItem);

    vector<string> algSearch(string initialLoc, string destinationLoc);

};


BFS::BFS (unordered_map<string, string> airportsMap, unordered_map<string, vector<string>> locationsMap)
    {
        this-> airportsToPlaces = airportsMap;
        this->locationToAirportsMap = locationsMap;
    }

bool BFS::contains(queue<Node> aQueue, Node aNode)
{
    bool check;
    queue<Node> newQueueCopy = aQueue;
    while(!newQueueCopy.empty())
    {
        Node item = newQueueCopy.front();
        check = equals(item, aNode);
    }
    return check;
}


bool BFS::contains(set<string> aSet, string aString)
{
    bool check;
    for(auto item : aSet)
    {
        check = (item == aString);
        if(check == true)
            break;
    }
    return check;
}


bool BFS::equals(Node firstNode, Node secNode)
{
    return (typeid(firstNode) == typeid(secNode));
}

bool BFS::equals(string firstString, string secondString)
{
    return (firstString == secondString);
}

bool BFS::equals(vector<Routes> firstList, any secondItem)
{
    return (typeid(firstList) == typeid(secondItem));
}


vector<string> BFS::algSearch(string initialLoc, string destinationLoc){
    airports = locationToAirportsMap.at(initialLoc);

    for(string airport:airports)
    {
        Node airportNode(NULL, airport, NULL, 0, NULL);
        frontier.push(airportNode);
    }

    
    /**
     * Techie Delight. (2022, February 6). Iterate through a queue in C++. https://www.techiedelight.com/iterate-through-a-queue-in-cpp/
    */
    while(frontier.size() != 0)
    {
        Node currentNode = frontier.pop();

        exploredSet.insert(currentNode.getAirportCode());
        vector<Routes> successorStates = routesMap.get(currentNode.getAirportCode());

        if (equals(successorStates, NULL) == false)
        {
            for(Routes successorState: successorStates)
            {
                Node child(currentNode, successorState.getDestinationAirportCode(), successorState.getAirlineCode(), successorState.getStops(), NULL);

                if (!(contains(frontier, child)) && !(contains(exploredSet, child.getAirportCode()))){
                    string destinationName = airportsToPlaces.at(child.getAirportCode());
                    if((equals(destinationName, NULL) == false) && (equals(destinationName, destinationLoc) == true))
                    {
                        return child.solutionPath();
                    }
                }
                frontier.push(child);
            }
        }
    }
}