#include "Date.h"
#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

Date::Date()
{
    day = 1;
    month = 1;
    year = 1;
}

Date::Date(int dd, int mm, int yy)
{
    day = dd;
    month = mm;
    year = yy;
}

int Date::GetDay() const
{
    return day;
}

void Date::SetDay(int val)
{
    if(val > 0 && val < 32)
    {
        day = val;
    }
    else
    {
        day = 1;
    }
}

int Date::GetMonth() const
{
    return month;
}

void Date::SetMonth(int val)
{
    if(val > 0 && val < 13)
    {
        month = val;
    }
    else
    {
        month = 1;
    }
}

int Date::GetYear() const
{
    return year;
}

void Date::SetYear(int val)
{
    if(val > 0 && val < 3000)
    {
        year = val;
    }
    else
    {
        year = 1;
    }
}


istream & operator >>( istream & input, Date & D )
{
    string strDay, strMonth, strYear;
    int tmpDay, tmpMonth, tmpYear;


    getline(input, strDay, '/');
    tmpDay = atoi(strDay.c_str());
    D.SetDay(tmpDay);

    getline(input, strMonth, '/');
    tmpMonth = atoi(strMonth.c_str());
    D.SetMonth(tmpMonth);

    getline(input, strYear, ' ');
    tmpYear = atoi(strYear.c_str());
    D.SetYear(tmpYear);

    return input;
}

//Allows for month to be returned in full form
string Date::MonthName()
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
        monthName += "Null";

    }

    return monthName;
}

bool Date::operator ==(const Date &D) const
{
    if(day == D.day && month == D.month && year == D.year)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::operator !=(const Date &D) const
{
    if(day != D.day || month != D.month || year != D.year)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::operator <(const Date &D) const
{
    if(year < D.year)
    {
        return true;
    }
    else if(year == D.year)
    {
        if(month < D.month)
        {
            return true;
        }
        else if(month == D.month)
        {
            if(day < D.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Date::operator >(const Date &D) const
{
    if(year > D.year)
    {
        return true;
    }
    else if(year == D.year)
    {
        if(month > D.month)
        {
            return true;
        }
        else if(month == D.month)
        {
            if(day > D.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Date::operator <=(const Date &D) const
{
    if(year < D.year)
    {
        return true;
    }
    else if(year == D.year)
    {
        if(month < D.month)
        {
            return true;
        }
        else if(month == D.month)
        {
            if(day < D.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Date::operator >=(const Date &D) const
{
    if(year > D.year)
    {
        return true;
    }
    else if(year == D.year)
    {
        if(month > D.month)
        {
            return true;
        }
        else if(month == D.month)
        {
            if(day > D.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


string Date::Datefunc()
{


    stringstream dateToString;
    dateToString << day << " " << MonthName() << " " << year;
    string dateString = dateToString.str();

    return dateString;
}


ostream & operator <<( ostream & os, Date & D )
{
    const string dateString = D.Datefunc();

    os << dateString << ' ';
    return os;
}
