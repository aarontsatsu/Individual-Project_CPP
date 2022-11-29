#include <iostream>
#include <string>
using namespace std;

/**
 * The Airlines class represents all the features of an airline
 * It also defines getters and setters to retrieve and initialize the features.
*/
class Airlines
{
    protected:
    string airlineID;
    string airlineName;
    string IATACode;
    string IACOCode;
    string country;


    public:
    string getAirlineID()
    {
        return airlineID;
    }

    void setAirlineID(string airlineID)
    {
        this->airlineID = airlineID;
    }

    string getAirlineName()
    {
        return airlineName;
    }

    void setAirlineName(string airlineName)
    {
        this->airlineName = airlineName;
    }

    string getIATACode()
    {
        return IATACode;
    }

    void setIATACode(string IATACode)
    {
        this->IATACode = IATACode;
    }

    string getIACOCode()
    {
        return IACOCode;
    }

    void setIACOCode(string IACOCode)
    {
        this->IACOCode = IACOCode;
    }

    string getCountry()
    {
        return country;
    }
    
    void setCountry(string country)
    {
        this->country = country;
    }
};