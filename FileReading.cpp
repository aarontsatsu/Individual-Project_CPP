#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <set>
#include "Routes.cpp"
#include "Node.cpp"
#include "BFSAlgo.cpp"

using namespace std;

template<typename K, typename V>

void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}




int main() {
    static unordered_map<string, vector<Routes>> routesMap;
    static unordered_map<string, string> airportsToPlaces;
    static unordered_map<string, vector<string>> locationToAirportsMap;


/*
   * Reading and processing the airports.csv file
 **/
    try {
        ifstream airportsFile("airports.csv");
        string row = "";
        int count = 0;
        string ignore;
        string key;
        string values;
        string city;
        string country;
        string code;
        char delim = ',';

        /**
         * How to Split strings in C++ - javatpoint. (n.d.). www.javatpoint.com. https://www.javatpoint.com/how-to-split-strings-in-cpp
        */

        while (getline(airportsFile, row)) {
            if (count == 0) {
                count++;
                continue;
            }

            stringstream input(row);

            getline(input, ignore, delim);
            getline(input, ignore, delim);
            getline(input, city, delim);
            getline(input, country, delim);
            getline(input, key, delim);
            getline(input, code, delim);

            values = city + ", " + country;

            airportsToPlaces.insert({key, values});

            
            //keeps airport codes
            vector<string> airportValues;
            for (const auto& [k, v] : airportsToPlaces) {
                if (v == values) {
                    airportValues.push_back(k);
                }
            }


            /*
            * If airportValues is null, the String(city, country) key does not have any value yet.
            * Create new airport values arraylist for the key and add corresponding airport code to it.
            */
            if (airportValues.empty()) {
                vector<string> newAirportValues;
                string codeforAirport = key;
                string nullValue = "\\N";
                if (codeforAirport == nullValue) {
                    newAirportValues.push_back(code);
                } else {
                    newAirportValues.push_back(key);
                }
                locationToAirportsMap.insert({values, newAirportValues});

                /*
                 * If airportValues is not null, check if current route is in values before
                 * adding, to prevent duplicate airport codes in each value arraylist
                 */
            } else {
                static string codeForAirport;
                if (!std::count(airportValues.begin(), airportValues.end(), key)) {
                    if (key == "\\N") {
                        string codeForAirport = code;
                    } else {
                        string codeForAirport = key;
                    }
                    airportValues.push_back(codeForAirport);
                    locationToAirportsMap.insert({values, airportValues});
                }
            }

        }

        //iterating through the locationToAirportMap unordered_map
        for (auto &itr: locationToAirportsMap) {
            for (string i: itr.second){
                cout << itr.first << ": " << i << endl;
            }
        }
        cout << "" << endl;
        print_map(airportsToPlaces);


        airportsFile.close();

    } catch (const exception &e) {
        cout << "File opening failed!" << e.what() << endl;
    }

/*
    * Reading and processing the routes.csv file
**/
   try{
       ifstream routesFile("routes.csv");
       string row = "";
       int count = 0;
       string ignore;
       string key;
       string airlinecode;
       string airlineid;
       string destairportcode;
       int stops;
       char delim = ',';
        static vector<Routes> values;

       while (getline(routesFile, row)) {
           if (count == 0) {
               count++;
               continue;
           }

           stringstream input(row);

           getline(input, airlinecode, delim);
           getline(input, airlineid, delim);
           getline(input, key, delim);
           getline(input, ignore, delim);
           getline(input, destairportcode, delim);
           getline(input, ignore, delim);

           Routes route(airlinecode, airlineid, destairportcode, stops);

           values.push_back(route);
            cout << route.toString() << endl;


           routesMap.insert({key, values});

       }
       for (Routes i: values){cout << i.toString() << endl;}
       routesFile.close();

   } catch (const exception &e) {
       cout << "File opening failed!" << e.what() << endl;
   }


   //reading from the input file
    ifstream inputFile("accra-winnipeg.txt");

    // initialLoc and destinationLoc will serve as the start and end points for the BFS search
    string initialLoc;
    string destinationLoc;

    getline(inputFile, initialLoc);
    getline(inputFile,destinationLoc);


   BFS newBFSObj(airportsToPlaces, locationToAirportsMap, routesMap);
   queue<Node> frontier;
   set<string> exploredSet;
   vector<string> airports = locationToAirportsMap.at(initialLoc);




   
    /*
     * The following lines of code create an output.txt file where 
     the various routes will be written. 
    */
   ofstream outputFile("output.txt");
   vector<string> path = newBFSObj.algSearch(initialLoc, destinationLoc);

   int numFlights = 0;
   if(!path.empty())
   {
    for(string flight : path)
    {
        outputFile << flight << endl;
        numFlights ++;
    }

    outputFile << "Total Flights: " + numFlights;
   }
   else
   {
    outputFile << "No paths found, sorry";
   }outputFile.close();


    return 0;
}