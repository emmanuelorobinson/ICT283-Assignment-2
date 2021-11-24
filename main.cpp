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

int main()
{
    MonthlyBST bst;
    readFile(bst);

    return 1;
}

int getYearMonthKey(int year, int month)
{
    cout << "Please enter year: " << endl;
    cin >> year;
    cout << "Please enter month: " << endl;
    cin >> month;

    return (year*100) + month;
}

bool readFile(MonthlyBST &bst) {
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

            //MonthlyWeatherLog mwl(GetYearMonthKey(windlogEntry))
            //cout << windlogEntry.GetAmbientAir() << endl;
        }
        dinfile.close();

    }

    infile.close();

    //iterate through entryMap and call GetYMK() on each Monthly object
    //insert into MonthlyBST

    for (MonthlyMap::iterator it = entryMap.begin(); it != entryMap.end(); ++it)
    {
        bst.Insert(it->second);
    }

    Monthly m = 201603;

    bst.Search(m);
    bst.PostOrder(printMonthly);
    cout << m.MonthlyAverageAmbientTemp() << endl;

    //cout << entryMap[201603].GetWeatherData(10900).GetAmbientAir() << endl;
    return true;
}

void printMonthly(Monthly &m) {
    cout << m.GetYMK() << endl;
}

