#include <iostream>
#include <string>
#include <any>
using namespace std;

class Routes{
    
    // instance variables of the Routes class
    protected:
    string airlineCode;
    string airlineID;
    string destinationAirportCode;
    int stops;
    
    public :
    // constructor method for the instance variables
    Routes(string airlineCode, string airlineID, string destinationAirportCode, int stops)
    {
        this->airlineCode = airlineCode;
        this->airlineID = airlineID;
        this->destinationAirportCode = destinationAirportCode;
        this->stops = stops;
    }

    string getAirlineCode()
    {
        return airlineCode;
    }

    void setAirlineCode(string airlineCode)
    {
        this->airlineCode = airlineCode;
    }

    string getAirlineID()
    {
        return airlineID;
    }

    void setAirlineID(string airlineID)
    {
        this->airlineID = airlineID;
    }

    string getDestinationAirportCode()
    {
        return destinationAirportCode;
    }

    void setDestinationAirportCode(string destinationAirportCode)
    {
        this->destinationAirportCode = destinationAirportCode;
    }

    int getStops()
    {
        return stops;
    }

    void setStops(int stops)
    {
        this->stops = stops;
    }

    // override toString method for this class.
    string toString()
    {
        return "Routes{airlineCode= " + airlineCode + ", airlineID= " + airlineID + ", destinationAirportCode= " + destinationAirportCode + ", stops= " + to_string(stops) + "})";
    }
};