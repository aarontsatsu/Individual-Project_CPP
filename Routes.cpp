#include <iostream>
#include <string>
#pragma once


using namespace std;

/**
 * The Routes class represents all the features of a route
 * It also defines getters and setters to retrieve and initialize the features.
*/
class Routes{

    // instance variables of the Routes class
    protected:
    string airlineCode;
    string airlineID;
    string destinationAirportCode;
    int stops;
    
    public :
    // constructor for the instance variables
    Routes(string airlineCode, string airlineID, string destinationAirportCode, int stops)
    {
        this->airlineCode = airlineCode;
        this->airlineID = airlineID;
        this->destinationAirportCode = destinationAirportCode;
        this->stops = stops;
    }

    /*
    * Getters and Setters for the routes class
    */
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

    //toString method for the Routes class
    string toString()
    {
        return "Routes{airlineCode= " + airlineCode + ", airlineID= " + airlineID + ", destinationAirportCode= " + destinationAirportCode + ", stops= " + to_string(stops) + "}";
    }
};