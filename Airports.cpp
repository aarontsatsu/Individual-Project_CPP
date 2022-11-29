#include <iostream>
#include <string>
using namespace std;

/**
 * The Airports class represents all the features of an airport
 * It also defines getters and setters to retrieve and initialize the features.
*/
class Airports
{
    protected:
    string airportID;
    string airportName;
    string city;
    string country;
    string IACOCode;


    public :
    Airports(string airportID, string airportName, string city, string country, string IACOCode)
    {
        this->airportID = airportID;
        this->airportName = airportName;
        this->city = city;
        this->country = country;
        this->IACOCode = IACOCode;
    }

    string getAirportID()
    {
        return airportID;
    }

    void setAirportID(string airportID)
    {
        this->airportID = airportID;
    }

    string getAirportName()
    {
        return airportName;
    }

    void setAirportName(string airportName)
    {
        this->airportName = airportName;
    }

    string getCity()
    {
        return city;
    }

    void setCity(string city)
    {
        this->city = city;
    }

    string getCountry()
    {
        return country;
    }

    void setCountry(string country)
    {
        this->country = country;
    }

    string getIACOCode()
    {
        return IACOCode;
    }

    void setIACOCode(string IACOCode)
    {
        this->IACOCode = IACOCode;
    }

    string toString()
    {
        return "Airports{airportID= " + airportID + ", airportName= " + airportName + ", city= " + city + ", country= " + country + ", IACOCode= " + IACOCode + "}";
    }
};