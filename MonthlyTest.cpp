#include "Monthly.h"
#include <iostream>
#include <typeinfo>
#include "WeatherData.h"

using namespace std;

void monthlyConstructorTest();
void monthlyNonDefaultConstructorTest();
void SetYMKTest1();
void SetYMKTest2();
void SetYMKTest3();
void AddWeatherDataTest1();
void AddWeatherDataTest2();
void AddWeatherDataTest3();
void testOverloadedOperator1Monthly();
void testOverloadedOperator2Monthly();
void testOverloadedOperator3Monthly();
void testOverloadedOperator4Monthly();

int main6()
{
    monthlyConstructorTest();
    monthlyNonDefaultConstructorTest();
    SetYMKTest1();
    SetYMKTest2();
    SetYMKTest3();
    AddWeatherDataTest1();
    AddWeatherDataTest2();
    AddWeatherDataTest3();
    testOverloadedOperator1Monthly();
    testOverloadedOperator2Monthly();
    testOverloadedOperator3Monthly();
    testOverloadedOperator4Monthly();

    return 0;
}

void monthlyConstructorTest()
{
    Monthly monthly;

    if(typeid(monthly) == typeid(Monthly))
    {
        cout << "1. Default consturctor test: -> Successful" << endl;
    }
    else
    {
        cout << "1. Default consturctor test: -> Unsuccessful" << endl;
    }
}

void monthlyNonDefaultConstructorTest()
{
    Monthly monthly(201323);

    if(typeid(monthly) == typeid(Monthly))
    {
        cout << "2. Non Default consturctor test: -> Successful" << endl;
    }
    else
    {
        cout << "2. Non Default consturctor test: -> Unsuccessful" << endl;
    }
}

void SetYMKTest1()
{
    Monthly monthly;

    cout << "3. Test SetYMK with 20131: ";

    monthly.SetYMK(20131);

    if(monthly.GetYMK() == 20131)
    {
        cout << "Key = " << monthly.GetYMK() << " ->Successful" << endl;
    }
    else
    {
        cout << "Key = " << monthly.GetYMK() << " ->Unsuccessful" << endl;
    }
}

void SetYMKTest2()
{
    Monthly monthly;

    cout << "4. Test SetYMK with 20162: ";

    monthly.SetYMK(20162);

    if(monthly.GetYMK() == 20162)
    {
        cout << "Key = " << monthly.GetYMK() << " ->Successful" << endl;
    }
    else
    {
        cout << "Key = " << monthly.GetYMK() << " ->Unsuccessful" << endl;
    }
}

void SetYMKTest3()
{
    Monthly monthly;

    cout << "5. Test SetYMK with 20102: ";

    monthly.SetYMK(20102);

    if(monthly.GetYMK() == 20102)
    {
        cout << "Key = " << monthly.GetYMK() << " ->Successful" << endl;
    }
    else
    {
        cout << "Key = " << monthly.GetYMK() << " ->Unsuccessful" << endl;
    }
}

void AddWeatherDataTest1(){
    Monthly monthly;
    WeatherData weatherData;

    cout << "6. Test AddWeatherData with 20131: ";

    weatherData.SetAmbientAir(10);
    weatherData.SetWindSpeed(10);
    weatherData.SetSolarRadiation(10);

    monthly.AddWeatherData(20131, weatherData);

    if(monthly.GetWeatherData(20131).GetAmbientAir() == 10)
    {
        cout << "20131 ambient air 10, speed 10 solar radiation 10: -> Successful" << endl;
    }
    else
    {
        cout << "20131: -> Unsuccessful" << endl;
    }
}

void AddWeatherDataTest2(){
    Monthly monthly;
    WeatherData weatherData;

    cout << "7. Test AddWeatherData with 20162: ";

    weatherData.SetAmbientAir(10);
    weatherData.SetWindSpeed(6);
    weatherData.SetSolarRadiation(4);

    monthly.AddWeatherData(20162, weatherData);

    if(monthly.GetWeatherData(20162).GetAmbientAir() == 10)
    {
        cout << "20162 ambient air 10, speed 6 solar radiation 4: -> Successful" << endl;
    }
    else
    {
        cout << "20162: -> Unsuccessful" << endl;
    }
}

void AddWeatherDataTest3(){
    Monthly monthly;
    WeatherData weatherData;

    cout << "8. Test AddWeatherData with 20102: ";

    weatherData.SetAmbientAir(2);
    weatherData.SetWindSpeed(1);
    weatherData.SetSolarRadiation(4);

    monthly.AddWeatherData(20102, weatherData);

    if(monthly.GetWeatherData(20102).GetAmbientAir() == 2)
    {
        cout << "20102 ambient air 2, speed 1 solar radiation 4: -> Successful" << endl;
    }
    else
    {
        cout << "20102: -> Unsuccessful" << endl;
    }
}

void testOverloadedOperator1Monthly(){
    Monthly monthly1;
    Monthly monthly2;

    cout << "9. Test overloaded operator ==: ";

    monthly1.SetYMK(20131);
    monthly2.SetYMK(20131);

    if(monthly1 == monthly2)
    {
        cout << "monthly1 == monthly2: -> Successful" << endl;
    }
    else
    {
        cout << "monthly1 == monthly2: -> Unsuccessful" << endl;
    }
}

void testOverloadedOperator2Monthly(){
    Monthly monthly1;
    Monthly monthly2;

    cout << "10. Test overloaded operator !=: ";

    monthly1.SetYMK(20131);
    monthly2.SetYMK(20162);

    if(monthly1 != monthly2)
    {
        cout << "monthly1 != monthly2: -> Successful" << endl;
    }
    else
    {
        cout << "monthly1 != monthly2: -> Unsuccessful" << endl;
    }
}

void testOverloadedOperator3Monthly(){
    Monthly monthly1;
    Monthly monthly2;

    cout << "11. Test overloaded operator <: ";

    monthly1.SetYMK(20131);
    monthly2.SetYMK(20162);

    if(monthly1 < monthly2)
    {
        cout << "monthly1 < monthly2: -> Successful" << endl;
    }
    else
    {
        cout << "monthly1 < monthly2: -> Unsuccessful" << endl;
    }
}

void testOverloadedOperator4Monthly(){
    Monthly monthly1;
    Monthly monthly2;

    cout << "12. Test overloaded operator >: ";

    monthly1.SetYMK(20162);
    monthly2.SetYMK(20131);

    if(monthly1 > monthly2)
    {
        cout << "monthly1 > monthly2: -> Successful" << endl;
    }
    else
    {
        cout << "monthly1 > monthly2: -> Unsuccessful" << endl;
    }
}



// Test for calculations are done in main
