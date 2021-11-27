#include "Time.h"
#include <iostream>
#include <typeinfo>

using namespace std;


void timeConstructorTest();
void timeNonDefaultConstructorTest();
void setHourTest1();
void setHourTest2();
void setHourTest3();
void setMinuteTest1();
void setMinuteTest2();
void setMinuteTest3();
void testTimefunc1();
void testTimefunc2();
void testTimefunc3();
void testOverloadedOperator1Time();
void testOverloadedOperator2Time();
void testOverloadedOperator3Time();
void testOverloadedOperator4Time();
void testOverloadedOperator5Time();
void testOverloadedOperator6Time();



int main3()
{

    cout << "Testing the time class\n";

    timeConstructorTest();
    timeNonDefaultConstructorTest();
    setHourTest1();
    setHourTest2();
    setHourTest3();
    setMinuteTest1();
    setMinuteTest2();
    setMinuteTest3();
    testTimefunc1();
    testTimefunc2();
    testTimefunc3();
    testOverloadedOperator1Time();
    testOverloadedOperator2Time();
    testOverloadedOperator3Time();
    testOverloadedOperator4Time();
    testOverloadedOperator5Time();
    testOverloadedOperator6Time();


    return 0;
}

void timeConstructorTest()
{
    Time T;

    if (typeid(T) == typeid(Time) && T.GetHour() == 0 && T.GetMinute() == 0 )
    {
        cout << "1, Default constructor test: " << T.Timefunc() << " ->Successful\n";
    }
    else
    {
        cout << "1, Default constructor test: -> Unsuccessful" << endl;
    }

}

void timeNonDefaultConstructorTest()
{
    Time T(9, 12);

    if (typeid(T) == typeid(Time) && T.GetHour() == 9 && T.GetMinute() == 12 )
    {
        cout << "2, Non default constructor test: " << T.Timefunc() << " ->Successful\n";
    }
    else
    {
        cout << "2, Non default constructor test: -> Unsuccessful" << endl;
    }

}

void setHourTest1()
{

    Time T;

    cout << "3, Test hour setter with 9: ";

    T.SetHour(9);

    if(T.GetHour() == 9)
    {
        cout << "Time = " << T.GetHour() << " ->Successful" << '\n';
    }
    else
    {
        cout << "Time = " << T.GetHour() << " ->Unsuccessful" << '\n';
    }
}

void setHourTest2()
{

    Time T;

    cout << "4, Test hour setter with out of bounds 30: ";

    T.SetHour(30);

    if(T.GetHour() == 0)
    {
        cout << "Time = " << T.GetHour() << " ->Successful" << '\n';
    }
    else
    {
        cout << "Time = " << T.GetHour() << " ->Unsuccessful" << '\n';
    }
}

void setHourTest3()
{

    Time T;

    cout << "5, Test hour setter with out of bounds -1: ";

    T.SetHour(-1);

    if(T.GetHour() == 0)
    {
        cout << "Time = " << T.GetHour() << " ->Successful" << '\n';
    }
    else
    {
        cout << "Time = " << T.GetHour() << " ->Unsuccessful" << '\n';
    }
}

void setMinuteTest1()
{

    Time T;

    cout << "6, Test minute setter with 30: ";

    T.SetMinute(30);

    if(T.GetMinute() == 30)
    {
        cout << "Time = " << T.GetMinute() << " ->Successful" << '\n';
    }
    else
    {
        cout << "Time = " << T.GetMinute() << " ->Unsuccessful" << '\n';
    }
}

void setMinuteTest2()
{

    Time T;

    cout << "7, Test minute setter with out of bounds 70: ";

    T.SetMinute(70);

    if(T.GetMinute() == 0)
    {
        cout << "Time = " << T.GetMinute() << " ->Successful" << '\n';
    }
    else
    {
        cout << "Time = " << T.GetMinute() << " ->Unsuccessful" << '\n';
    }
}

void setMinuteTest3()
{

    Time T;

    cout << "8, Test minute setter with out of bounds -1: ";

    T.SetMinute(-1);

    if(T.GetMinute() == 0)
    {
        cout << "Time = " << T.GetMinute() << " ->Successful" << '\n';
    }
    else
    {
        cout << "Time = " << T.GetMinute() << " ->Unsuccessful" << '\n';
    }
}


void testTimefunc1()
{
    Time T;

    cout << "9, Test Timefunc with hour 9, minute 30: ";

    T.SetHour(9);
    T.SetMinute(30);

    if(T.Timefunc() == "9:30")
    {
        cout << "Year = " << T.Timefunc() << " ->Successful" << '\n';
    }
    else
    {
        cout << "Year = " << T.Timefunc() << " ->Unsuccessful" << '\n';
    }
}

void testTimefunc2()
{
    Time T;

    cout << "10, Test Timefunc with out of bounds hour 25, minute 65: ";

    T.SetHour(25);
    T.SetMinute(65);

    if(T.Timefunc() == "0:0")
    {
        cout << "Year = " << T.Timefunc() << " ->Successful" << '\n';
    }
    else
    {
        cout << "Year = " << T.Timefunc() << " ->Unsuccessful" << '\n';
    }
}

void testTimefunc3()
{
    Time T;

    cout << "11, Test Timefunc with out of bounds hour -1, minute -1: ";

    T.SetHour(-1);
    T.SetMinute(-1);

    if(T.Timefunc() == "0:0")
    {
        cout << "Year = " << T.Timefunc() << " ->Successful" << '\n';
    }
    else
    {
        cout << "Year = " << T.Timefunc() << " ->Unsuccessful" << '\n';
    }
}

void testOverloadedOperator1Time()
{
    Time T1 = Time(9, 30);
    Time T2 = Time(9, 30);

    cout << "12, Test overloaded operator == with T1(9, 30) and T2(9, 30): ";

    if(T1 == T2)
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Successful" << '\n';
    }
    else
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Unsuccessful" << '\n';
    }
}

void testOverloadedOperator2Time()
{
    Time T1 = Time(9, 30);
    Time T2 = Time(9, 31);

    cout << "13, Test overloaded operator != with T1(9, 30) and T2(9, 31): ";

    if(T1 != T2)
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Successful" << '\n';
    }
    else
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Unsuccessful" << '\n';
    }
}

void testOverloadedOperator3Time()
{
    Time T1 = Time(9, 10);
    Time T2 = Time(9, 30);

    cout << "14, Test overloaded operator < with T1(9, 10) and T2(9, 30): ";

    if(T1 < T2)
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Successful" << '\n';
    }
    else
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Unsuccessful" << '\n';
    }
}

void testOverloadedOperator4Time()
{
    Time T1 = Time(10, 30);
    Time T2 = Time(9, 20);

    cout << "15, Test overloaded operator > with T1(10, 30) and T2(9, 20): ";

    if(T1 > T2)
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Successful" << '\n';
    }
    else
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Unsuccessful" << '\n';
    }
}

void testOverloadedOperator5Time()
{
    Time T1 = Time(1, 30);
    Time T2 = Time(9, 20);

    cout << "16, Test overloaded operator <= with T1(1, 30) and T2(9, 20): ";

    if(T1 <= T2)
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Successful" << '\n';
    }
    else
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Unsuccessful" << '\n';
    }
}

void testOverloadedOperator6Time()
{
    Time T1 = Time(10, 30);
    Time T2 = Time(9, 20);

    cout << "17, Test overloaded operator >= with T1(10, 30) and T2(9, 20): ";

    if(T1 >= T2)
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Successful" << '\n';
    }
    else
    {
        cout << "T1 = " << T1.Timefunc() << " T2 = " << T2.Timefunc() << " ->Unsuccessful" << '\n';
    }
}

