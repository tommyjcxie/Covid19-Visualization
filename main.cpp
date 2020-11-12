//Author: Jian Xie (251036512)
//Description: The main function for the program. It contains the code reading from the file
//as well as the menu, sorting, and displaying the data.
//Date: October 2020

#include "CountryRecord.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
//clang++ -std=c++11 -stdlib=libc++ -Weverything main.cpp CountryRecord.cpp -o main
int main(int argc, char **argv)
{

    //read from csv and add contents of file into records vector
    string line;
    vector<string> records;

    ifstream myfile("summary.csv");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            records.push_back(line);
        }
        myfile.close();
    }

    //creating a vector of CountryRecord classes to hold data
    vector<CountryRecord> countryInst;
    for (int i = 1; i < 187; ++i)
    {
        countryInst.emplace_back(i);
    }

    //process and split each country; tokenize strings

    for (int i = 1; i < 187; i++)
    {
        vector<string> splitOne;
        vector<string> splitTwo;
        vector<string> splitThree;
        //split to get country and code
        string split1 = records[i];
        stringstream check1(split1);
        string temp;
        while (getline(check1, temp, '"'))
        {
            splitOne.push_back(temp);
        }

        //split to get new cases,recoveries,deaths
        string split2 = splitOne[6];
        stringstream check2(split2);
        string temp2;

        while (getline(check2, temp2, ','))
        {
            splitTwo.push_back(temp2);
        }

        //split to get total cases,recoveries,deaths
        string split3 = splitOne[10];
        stringstream check3(split3);
        string temp3;

        while (getline(check3, temp3, ','))
        {
            splitThree.push_back(temp3);
        }

        //convert string to int
        int newCases = stoi(splitTwo[1]);
        int newDeaths = stoi(splitTwo[2]);
        int newRecoveries = stoi(splitTwo[3]);
        int totalCases = stoi(splitThree[1]);
        int totalDeaths = stoi(splitThree[2]);
        int totalRecover = stoi(splitThree[3]);

        //populating CountryRecord class with instances
        countryInst[i].setCountry(splitOne[1]);
        countryInst[i].setCountryCode(splitOne[3]);
        countryInst[i].setCases(newCases);
        countryInst[i].setDeaths(newDeaths);
        countryInst[i].setRecoveries(newRecoveries);
        countryInst[i].setTotalCases(totalCases);
        countryInst[i].setTotalDeaths(totalDeaths);
        countryInst[i].setTotalRecoveries(totalRecover);
        splitOne.clear();
        splitTwo.clear();
        splitThree.clear();
    }

    //Menu and simple input validation
    cout << "What case do you want to sort by? Enter the code (case-sensitive) for the one you want as shown below. \n";
    cout << "Total Cases (TC), Total Deaths (TD), Total Recoveries(TR), New Cases (NC), New Deaths (ND), New Recoveries (NR) \n";

    string option1;
    getline(cin, option1);
    if (option1 != "TC" && option1 != "TD" && option1 != "TR" && option1 != "NC" && option1 != "ND" && option1 != "NR")
    {
        cout << "Please try again and select the right option, for example: 'TC' for Total Cases";
        return 0;
    }

    string option2;
    cout << "Ascending (AS) or Descending (DS)? Note: Case sensitive. \n";
    getline(cin, option2);
    if (option2 != "AS" && option2 != "DS")
    {
        cout << "Please try again and enter either 'AS' or 'DS";
        return 0;
    }

    cout << "\n";

    //Sort by Total Cases
    if (option1 == "TC")
    {
        int legend;
        if (option2 == "DS")
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getTotalCases() > rhs.getTotalCases();
                 });
            legend = 90009;
        }
        else
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getTotalCases() < rhs.getTotalCases();
                 });
            legend = 5;
        }

        for (int i = 1; i < 11; i++)
        {
            string bars = "#";
            int totalBars = (countryInst[i].getTotalCases()) / legend;
            cout << countryInst[i].getCountryCode() << "| ";

            for (int i = 0; i < totalBars; i++)
            {
                cout << "#";
            }
            cout << "\n";
        }
        cout << "Total Confirmed Cases; Each number is approx. " << legend << " cases. \n";
    }

    //Sort by Total Recoveries
    if (option1 == "TR")
    {
        int legend;
        if (option2 == "DS")
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getTotalRecoveries() > rhs.getTotalRecoveries();
                 });
            legend = 60000;
        }
        else
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getTotalRecoveries() < rhs.getTotalRecoveries();
                 });
            legend = 3;
        }

        for (int i = 1; i < 11; i++)
        {
            string bars = "#";
            int totalBars = (countryInst[i].getTotalRecoveries()) / legend;
            cout << countryInst[i].getCountryCode() << "| ";

            for (int i = 0; i < totalBars; i++)
            {
                cout << "#";
            }
            cout << "\n";
        }
        cout << "Total Recoveries; Each number is approx. " << legend << " cases. Note: some countries may have 0 total recoveries if sorted by ascending. \n";
    }

    //Sort by Total Deaths
    if (option1 == "TD")
    {
        int legend;
        if (option2 == "DS")
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getTotalDeaths() > rhs.getTotalDeaths();
                 });
            legend = 3000;
        }
        else
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getTotalDeaths() < rhs.getTotalDeaths();
                 });
            legend = 1;
        }

        for (int i = 1; i < 11; i++)
        {
            string bars = "#";
            int totalBars = (countryInst[i].getTotalDeaths()) / legend;
            cout << countryInst[i].getCountryCode() << "| ";

            for (int i = 0; i < totalBars; i++)
            {
                cout << "#";
            }
            cout << "\n";
        }
        cout << "Total Deaths, Each number is approx. " << legend << " cases. Note: some countries may have 0 total deaths if sorted by ascending.\n";
    }

    //Sort by New Cases
    if (option1 == "NC")
    {
        int legend;
        if (option2 == "DS")
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getNewCases() > rhs.getNewCases();
                 });
            legend = 1500;
        }
        else
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getNewCases() < rhs.getNewCases();
                 });
            legend = 3;
        }

        for (int i = 1; i < 11; i++)
        {
            string bars = "#";
            int totalBars = (countryInst[i].getNewCases()) / legend;
            cout << countryInst[i].getCountryCode() << "| ";

            for (int i = 0; i < totalBars; i++)
            {
                cout << "#";
            }
            cout << "\n";
        }
        cout << "Total New Cases; Each number is approx. " << legend << " cases. Note: some countries may have 0 new cases if sorted by ascending. \n";
    }

    //Sort by New Deaths
    if (option1 == "ND")
    {
        int legend;
        if (option2 == "DS")
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getNewDeaths() > rhs.getNewDeaths();
                 });
            legend = 100;
        }
        else
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getNewDeaths() < rhs.getNewDeaths();
                 });
            legend = 1;
        }

        for (int i = 1; i < 11; i++)
        {
            string bars = "#";
            int totalBars = (countryInst[i].getNewDeaths()) / legend;
            cout << countryInst[i].getCountryCode() << "| ";

            for (int i = 0; i < totalBars; i++)
            {
                cout << "#";
            }
            cout << "\n";
        }
        cout << "Total New Deaths; Each number is approx. " << legend << " cases. Note: some countries may have 0 new deaths if sorted by ascending. \n";
    }

    //Sort by New Recoveries
    if (option1 == "NR")
    {
        int legend;
        if (option2 == "DS")
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getNewRecoveries() > rhs.getNewRecoveries();
                 });
            legend = 1500;
        }
        else
        {
            sort(countryInst.begin(),
                 countryInst.end(),
                 [](CountryRecord &lhs, CountryRecord &rhs) {
                     return lhs.getNewRecoveries() < rhs.getNewRecoveries();
                 });
            legend = 1;
        }

        for (int i = 1; i < 11; i++)
        {
            string bars = "#";
            int totalBars = (countryInst[i].getNewRecoveries()) / legend;
            cout << countryInst[i].getCountryCode() << "| ";

            for (int i = 0; i < totalBars; i++)
            {
                cout << "#";
            }
            cout << "\n";
        }
        cout << "Total New Recoveries; Each number is approx. " << legend << " cases. Note: some countries may have 0 new recoveries if sorted by ascending. \n";
    }
}

