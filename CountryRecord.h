//Author: Jian Xie (251036512)
//Description: Header file for CountryRecord class
//Date: October 2020

#include <string>
#include <iostream>
using namespace std;
class CountryRecord
{
private:
    string country, countryCode;
    int newCases, newDeaths, newRecoveries, totalCases, totalDeaths, totalRecoveries;

public:
    //default construct
    CountryRecord(int num) {}

    CountryRecord(string newCountry, string newCountryCode, int new_cases, int new_deaths, int new_recoveries, int total_cases, int total_deaths, int total_recoveries);
    //country
    void setCountry(string newCount);
    void setCountryCode(string newCode);
    //new
    void setCases(int cases);
    void setDeaths(int death);
    void setRecoveries(int recovery);
    //set total
    void setTotalCases(int tCase);
    void setTotalDeaths(int tDeath);
    void setTotalRecoveries(int tRecovery);

    //country
    string getCountry();
    string getCountryCode();
    //new
    int getNewCases();
    int getNewDeaths();
    int getNewRecoveries();
    //total
    int getTotalCases();
    int getTotalDeaths();
    int getTotalRecoveries();

 
    //destructor
    ~CountryRecord() {}
};

