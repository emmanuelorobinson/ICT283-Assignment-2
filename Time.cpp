#include "Time.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

Time::Time()
{
    hour = 0;
    minute = 0;
}

Time::Time(unsigned hh, unsigned mm)
{
    hour = hh;
    minute = mm;
}

unsigned Time::GetHour() const
{
    return hour;
}

void Time::SetHour(unsigned val)
{
    //restrict data to realistic 24 hour values
    if (val >= 0 && val <= 24)
    {
        hour = val;
    }
    else
    {
        hour = 0;
    }
}

unsigned Time::GetMinute() const
{
    return minute;
}

void Time::SetMinute(unsigned val)
{
    if (val >= 0 && val <= 60)
    {
        minute = val;
    }
    else
    {
        minute = 0;
    }
}

string Time::Timefunc()
{

    stringstream timeToString;

    timeToString << hour << ":" << minute;
    string timeString = timeToString.str();

    return timeString;
}

istream & operator >> (istream & input, Time & T)
{

    string strHour, strMinute;
    unsigned tmpHour, tmpMinute;

    getline(input, strHour, ':');
    tmpHour = atoi(strHour.c_str());
    T.SetHour(tmpHour);

    getline(input, strMinute, ',');
    tmpMinute = atoi(strMinute.c_str());
    T.SetMinute(tmpMinute);

    return input;
}

ostream & operator << (ostream & os, Time & T)
{

    const string timeString = T.Timefunc();

    os << timeString << '\n';

    return os;
}

bool Time::operator == (const Time& T) const
{

    if (hour == T.hour && minute == T.minute)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Time::operator != (const Time& T) const
{

    if (hour != T.hour || minute != T.minute)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Time::operator < (const Time& T) const
{

    if (hour < T.hour)
    {
        return true;
    }
    else if (hour == T.hour && minute < T.minute)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Time::operator > (const Time& T) const
{

    if (hour > T.hour)
    {
        return true;
    }
    else if (hour == T.hour && minute > T.minute)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Time::operator <= (const Time& T) const
{

    if (hour < T.hour)
    {
        return true;
    }
    else if (hour == T.hour && minute <= T.minute)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Time::operator >= (const Time& T) const
{

    if (hour > T.hour)
    {
        return true;
    }
    else if (hour == T.hour && minute >= T.minute)
    {
        return true;
    }
    else
    {
        return false;
    }
}

