#include <iostream>
#include <fstream>
#include "BST.h"
#include "Date.h"
#include "string"
#include <cmath>
#include "Monthly.h"

typedef map<int, Monthly> MonthlyMap;
typedef BST<Monthly> MonthlyBST;

using namespace std;


void printMonthly(Monthly &m);
bool readFile(MonthlyBST &bst);
int getYearMonthKey(int year, int month);
int getDayHourMinuteKey(int day, int hour, int minute);
bool readMonthAndYear(int &month, int &year);
bool readYearChoice(int &year);
bool menu(MonthlyBST &bst);
bool option1(MonthlyBST &bst);
bool option2(MonthlyBST &bst);
bool option3(MonthlyBST &bst);
bool option4(MonthlyBST &bst);
bool option5(MonthlyBST &bst); //bounus question
string FullMonth(int month);

int main()
{
    MonthlyBST bst;
    readFile(bst);
    menu(bst);

    return 0;
}

int getYearMonthKey(int year, int month)
{
    return (year*100) + month;
}

int getDayHourMinuteKey(int day, int hour, int minute)
{
    return (day*10000) + (hour*100) + minute;
}

bool readFile(MonthlyBST &bst)
{
    WeatherData windlogEntry;
    MonthlyMap entryMap;

    string line, wline;

    string indexFileName = "data/met_index.txt";
    string dataFileName;

    ifstream infile, dinfile;

    int key1, key2;

    infile.open(indexFileName.c_str());

    if( !infile )
        return false;

    while (getline(infile, line))
    {

        dataFileName = "data/" + line;

        dinfile.open(dataFileName.c_str());


        if( !dinfile )
            return false;

        cout << line << endl;

        while (!dinfile.eof())
        {
            dinfile >> windlogEntry;

            key1 = (windlogEntry.GetDate().GetYear()*100) + windlogEntry.GetDate().GetMonth();
            key2 = ((windlogEntry.GetDate().GetDay()*100) + windlogEntry.GetTime().GetHour())*100 + windlogEntry.GetTime().GetMinute();

            //inserting year month key into datamap
            entryMap[key1].SetYMK(key1);

            //inserting day hour minute key into Monthly object map
            entryMap[key1].AddWeatherData(key2, windlogEntry);
        }
        dinfile.close();

    }

    infile.close();


    //insert into MonthlyBST
    for (MonthlyMap::iterator it = entryMap.begin(); it != entryMap.end(); ++it)
    {
        bst.Insert(it->second);
    }

    return true;
}

bool readMonthAndYear(int &month, int &year)
{

    cout << "\nPlease enter specified month(integer only): ";
    cin >> month;
    cout << "\nPlease enter specified year(integer only): ";
    cin >> year;

    if (month > 12 || month < 1 || year < 1 || year > 3000)
    {
        cout << "Invalid month or year";
        return false;
    }
    else
        return true;
}

//Function used to enable user enter the year of their choice. Prevents repetition
bool readYearChoice(int &year)
{

    cout << "\nPlease enter specified year(integer only): ";
    cin >> year;

    if (year < 0 || year > 3000)
    {
        cout << "Invalid year";
        return false;
    }
    else
        return true;
}

void printMonthly(Monthly &m)
{
    cout << m.GetYMK() << endl;
}

bool menu(MonthlyBST &bst)
{
    int userChoice;

    do
    {
        cout << "\nMenu\n";
        cout << "1. The average wind speed and average ambient air temperature for a specified month and year. (print on screen only)\n";
        cout << "2. Average wind speed and average ambient air temperature for each month of a specified year. (print on screen only)\n";
        cout << "3. Total solar radiation in kWh/m2 for each month of a specified year. (print on screen only)\n";
        cout << "4. Average wind speed(km/h), average ambient air temperature and total solar radiation in kWh/m2\n"
             << "   for each month of a specified year. (write to a file called WindTempSolar.csv)\n";
        cout << "5. Given a Date in the form d/m/yyyy, show the times for the highest solar radiation for the Date\n";
        cout << "6. Exit the program.\n";


        cout << "Please select an option from 1 to 6 (integer only): ";
        cin >> userChoice;

        if(userChoice == 1)
        {
            option1(bst);
        }
        else if (userChoice == 2)
        {
            option2(bst);
        }
        else if (userChoice == 3)
        {
            option3(bst);
        }
        else if (userChoice == 4)
        {
            option4(bst);
        }
        else if (userChoice == 5)
        {
            option5(bst);
        }
        else if (userChoice == 6)
        {
            cout << "\nExiting program...";
            return false;
        }
        else
        {
            cout << "\nInvalid option... Please try again\n";
        }
    }
    while (userChoice != 6);

    return true;
}

string FullMonth(int month)
{
    string monthName = "";

    switch(month)
    {
    case 1:
        monthName += "January";
        break;
    case 2:
        monthName += "February ";
        break;
    case 3:
        monthName += "March";
        break;
    case 4:
        monthName += "April";
        break;
    case 5:
        monthName += "May";
        break;
    case 6:
        monthName += "June";
        break;
    case 7:
        monthName += "July";
        break;
    case 8:
        monthName += "August";
        break;
    case 9:
        monthName += "September";
        break;
    case 10:
        monthName += "October";
        break;
    case 11:
        monthName += "November";
        break;
    case 12:
        monthName += "December";
        break;
    default:
        monthName += "NULL";

    }

    return monthName;
}

//Asks users for input and carries out calculation for option 1 of menu
bool option1(MonthlyBST &bst)
{
    int month, year;

    float averageWSpeed = 0;
    float averageAmbAir = 0;

    if(!readMonthAndYear(month, year))
        return false;

    int key = getYearMonthKey(year, month);

    Monthly entryMonth(key);

    bst.Search(entryMonth);

    averageWSpeed = entryMonth.MonthlyAverageWindSpeed();
    averageAmbAir = entryMonth.MonthlyAverageAmbientTemp();

    if (averageAmbAir > 0 && averageWSpeed > 0)
    {
        cout << FullMonth(month) << " " << year << ": " << averageWSpeed << " km/h, ";
        cout << averageAmbAir << " degrees C \n";
        return true;
    }
    else
    {
        cout << FullMonth(month) << " " << year << ": No Data\n";
        return false;
    }

}

bool option2(MonthlyBST &bst)
{
    int year;


    readYearChoice(year);

    for (int m = 1; m < 13; m++)
    {

        float averageWSpeed = 0;
        float averageAmbAir = 0;

        int key = getYearMonthKey(year, m);
        Monthly entryMonth = key;

        bst.Search(entryMonth);

        averageWSpeed = entryMonth.MonthlyAverageWindSpeed();
        averageAmbAir = entryMonth.MonthlyAverageAmbientTemp();

        if (averageAmbAir > 0 && averageWSpeed > 0)
        {
            cout << FullMonth(m) << " " << year << ": " << averageWSpeed << " km/h, ";
            cout << averageAmbAir << " degrees C\n";
        }
        else
        {
            cout << FullMonth(m) << " " << year << ": No Data\n";
        }
    }
    return true;

}


bool option3(MonthlyBST &bst)
{
    int year;

    readYearChoice(year);

    for (int m = 1; m < 13; m++)
    {

        float totalSR = 0;

        int key = getYearMonthKey(year, m);
        Monthly entryMonth(key);

        bst.Search(entryMonth);

        totalSR = entryMonth.MonthlyTotalSolarRadiation();


        if (totalSR != 0)
        {
            cout << FullMonth(m) << " " << year << ": " << totalSR << " kWh/m^2\n";
        }
        else
        {
            cout << FullMonth(m) << " " << year << ": No Data\n";
        }
    }
    return true;

}

bool option4(MonthlyBST &bst)
{
    int year;

    int noDataCount = 0;

    readYearChoice(year);

    WeatherData tmpWindlog;
    ofstream ofile( "WindTempSolar.csv" );

    ofile << year << '\n';

    for (int m = 1; m < 13; m++)
    {
        float averageWSpeed = 0;
        float averageAmbAir = 0;
        float totalSR = 0;

        int key = getYearMonthKey(year, m);
        Monthly entryMonth(key);

        bst.Search(entryMonth);

        averageWSpeed = entryMonth.MonthlyAverageWindSpeed();
        averageAmbAir = entryMonth.MonthlyAverageAmbientTemp();
        totalSR = entryMonth.MonthlyTotalSolarRadiation();

        if (averageAmbAir > 0 && averageWSpeed > 0 && totalSR > 0)
        {
            ofile << FullMonth(m) << ", " << averageWSpeed << ", " << averageAmbAir << ", ";
            ofile << totalSR << "\n";
        }
        else
        {
            noDataCount++;
        }
    }

    if (noDataCount == 12)
    {
        ofile << "No Data\n";
    }

    ofile.close();
    cout << "Data read out successfully\n";
    return true;

}

bool option5(MonthlyBST &bst)
{
    //Given a Date in the form d/m/yyyy, show the times for the highest solar radiation for the Date
    int day, month, year;
    string date;

    cout << "\nPlease enter a date in the form d/m/yyyy (Please include '/' E.g.: 21/5/2021): ";

    int check = 0;
    //split date by / to get day, month and year
    while (check == 0)
    {
        try
        {
            getline(cin, date, '/');
            day = stoi(date);
            getline(cin, date, '/');
            month = stoi(date);
            getline(cin, date, '\n');
            year = stoi(date);
            check = 1;
        }
        catch(...)
        {
            cin.clear();
            cout << "\nInvalid date format. Please try again(d/m/yyyy): ";
        }
    }

    cout << endl;

    cout << "Date: " << day << "/" << month << "/" << year << "\n";

    int key = getYearMonthKey(year, month);

    Monthly entryMonth(key);

    bst.Search(entryMonth);

    //for each hour and minute in the day calculate the highest solar radiation
    float highestSR = 0;

    for(int h = 0; h < 24; h++)
    {
        for(int m = 0; m < 60; m++)
        {

            int dhmkey = getDayHourMinuteKey(day, h, m);

            if (highestSR < entryMonth.GetHighestSolarRadiation(dhmkey))
            {
                highestSR = entryMonth.GetHighestSolarRadiation(dhmkey);
            }


        }
    }

    if (highestSR > 0)
    {
        cout << "High solar radiation for the day: " << highestSR << " W/m^2\n" << endl;// h << ":" << m << "\n";
    }

    //get times with highest solar radiation
    cout << "Time:" << endl;

    for(int h = 0; h < 24; h++)
    {
        for(int m = 0; m < 60; m++)
        {
            int dhmkey = getDayHourMinuteKey(day, h, m);

            entryMonth.GetHighestSolarRadiationTimes(dhmkey, highestSR);
        }
    }

    return true;
}

