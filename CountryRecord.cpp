//Author: Jian Xie (251036512)
//Description: Code file for CountryRecord Class
//Date: October 2020
#include "CountryRecord.h"
#include <iostream>

using namespace std;


CountryRecord::CountryRecord(string newCountry, string newCountryCode, int new_cases, int new_deaths, int new_recoveries, int total_cases, int total_deaths, int total_recoveries){
    country = newCountry;
    countryCode = newCountryCode;
    newCases = new_cases;
    newDeaths = new_deaths;
    newRecoveries = new_recoveries;
    totalCases = total_cases;
    totalDeaths = total_deaths;
    totalRecoveries = total_recoveries;
}

//mutators
void CountryRecord::setCountry(string newCount){
    country = newCount;
}

void CountryRecord::setCountryCode(string newCode)
{
    countryCode = newCode;
}

void CountryRecord::setCases(int cases)
{
    newCases = cases;
}

void CountryRecord::setDeaths(int deaths)
{
    newDeaths = deaths;
}

void CountryRecord::setRecoveries(int recovery)
{
    newRecoveries = recovery;
}

void CountryRecord::setTotalCases(int tCase)
{
    totalCases = tCase;
}

void CountryRecord::setTotalRecoveries(int tRecovery)
{
    totalRecoveries = tRecovery;
}

void CountryRecord::setTotalDeaths(int tDeaths)
{
    totalDeaths = tDeaths;
}

//accessors
string CountryRecord::getCountry()
{
    return country;
}

string CountryRecord::getCountryCode()
{
    return countryCode;
}

int CountryRecord::getNewCases()
{
    return newCases;
}

int CountryRecord::getNewDeaths()
{
    return newDeaths;
}

int CountryRecord::getNewRecoveries()
{
    return newRecoveries;
}

int CountryRecord::getTotalCases()
{
    return totalCases;
}

int CountryRecord::getTotalDeaths()
{
    return totalDeaths;
}

int CountryRecord::getTotalRecoveries()
{
    return totalRecoveries;
}
