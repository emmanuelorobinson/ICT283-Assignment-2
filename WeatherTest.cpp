#include "WeatherData.h"
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <typeinfo>

using namespace std;

void weatherConstructorTest();
void setWindSpeedTest1();
void setWindSpeedTest2();
void setWindSpeedTest3();
void setSolarRadiationTest1();
void setSolarRadiationTest2();
void setSolarRadiationTest3();
void setAmbientAirTest1();
void setAmbientAirTest2();
void setAmbientAirTest3();
void setTimeTest1();
void setTimeTest2();
void setTimeTest3();
void setDateTest1();
void setDateTest2();
void setDateTest3();



int main4() {
    weatherConstructorTest();
    setWindSpeedTest1();
    setWindSpeedTest2();
    setWindSpeedTest3();
    setSolarRadiationTest1();
    setSolarRadiationTest2();
    setSolarRadiationTest3();
    setAmbientAirTest1();
    setAmbientAirTest2();
    setAmbientAirTest3();
    setTimeTest1();
    setTimeTest2();
    setTimeTest3();
    setDateTest1();
    setDateTest2();
    setDateTest3();
    return 0;
}

void weatherConstructorTest() {
    try {
        WeatherData W;

        if (typeid(W) == typeid(WeatherData) && W.GetWindSpeed() == 0 && W.GetAmbientAir() == 0 && W.GetSolarRadiation() == 0) {
            cout << "1, Default constructor test: -> Successful" << endl;
        }
        else {
            cout << "1, Default constructor test: -> Unsuccessful" << endl;
        }
    }
    catch(...) {
        cout << "1, Default constructor test: -> Unsuccessful" << endl;
    }
}

void setWindSpeedTest1() {
    WeatherData W;

    cout << "2, Test wind speed setter with 20: ";

    W.SetWindSpeed(20);

    if(W.GetWindSpeed() == 20) {
        cout << "Wind speed = " <<W.GetWindSpeed() << " -> Successful" << '\n';
    }
    else {
        cout << "Wind speed = " <<W.GetWindSpeed() << " -> Unsuccessful" << '\n';
    }
}

void setWindSpeedTest2() {
    WeatherData W;

    cout << "3, Test wind speed setter with 0: ";

    W.SetWindSpeed(0);

    if(W.GetWindSpeed() == 0.0) {
        cout << "Wind speed = " <<W.GetWindSpeed() << " -> Successful" << '\n';
    }
    else {
        cout << "Wind speed = " <<W.GetWindSpeed() << " -> Unsuccessful" << '\n';
    }
}

void setWindSpeedTest3() {
    WeatherData W;

    cout << "4, Test wind speed setter with -1: ";

    W.SetWindSpeed(-1);

    if(W.GetWindSpeed() == 0.0) {
        cout << "Wind speed = " <<W.GetWindSpeed() << " -> Successful" << '\n';
    }
    else {
        cout << "Wind speed = " <<W.GetWindSpeed() << " -> Unsuccessful" << '\n';
    }
}

void setSolarRadiationTest1() {
    WeatherData W;

    cout << "5, Test Solar Radiation setter with 30: ";

    W.SetSolarRadiation(30);

    if(W.GetSolarRadiation() == 30) {
        cout << "Solar Radiation = " <<W.GetSolarRadiation() << " -> Successful" << '\n';
    }
    else {
        cout << "Solar Radiation = " <<W.GetSolarRadiation() << " -> Unsuccessful" << '\n';
    }
}

void setSolarRadiationTest2() {
    WeatherData W;

    cout << "6, Test Solar Radiation setter with 0: ";

    W.SetSolarRadiation(0);

    if(W.GetSolarRadiation() == 0.0) {
        cout << "Solar Radiation = " <<W.GetSolarRadiation() << " -> Successful" << '\n';
    }
    else {
        cout << "Solar Radiation = " <<W.GetSolarRadiation() << " -> Unsuccessful" << '\n';
    }
}
void setSolarRadiationTest3() {
    WeatherData W;

    cout << "7, Test Solar Radiation setter with -1: ";

    W.SetSolarRadiation(-1);

    if(W.GetSolarRadiation() == 0.0) {
        cout << "Solar Radiation = " <<W.GetSolarRadiation() << " -> Successful" << '\n';
    }
    else {
        cout << "Solar Radiation = " <<W.GetSolarRadiation() << " -> Unsuccessful" << '\n';
    }
}

void setAmbientAirTest1() {
    WeatherData W;

    cout << "8, Test ambient air setter with 45: ";

    W.SetAmbientAir(45);

    if(W.GetAmbientAir() == 45) {
        cout << "Ambient Air = " <<W.GetAmbientAir() << " -> Successful" << '\n';
    }
    else {
        cout << "Ambient Air = " <<W.GetAmbientAir() << " -> Unsuccessful" << '\n';
    }
}

void setAmbientAirTest2() {
    WeatherData W;

    cout << "9, Test ambient air setter with 0: ";

    W.SetAmbientAir(0);

    if(W.GetAmbientAir() == 0.0) {
        cout << "Ambient Air = " <<W.GetAmbientAir() << " -> Successful" << '\n';
    }
    else {
        cout << "Ambient Air = " <<W.GetAmbientAir() << " -> Unsuccessful" << '\n';
    }
}

void setAmbientAirTest3() {
    WeatherData W;

    cout << "10, Test ambient air setter with -1: ";

    W.SetAmbientAir(-1);

    if(W.GetAmbientAir() == 0.0) {
        cout << "Ambient Air = " <<W.GetAmbientAir() << " -> Successful" << '\n';
    }
    else {
        cout << "Ambient Air = " <<W.GetAmbientAir() << " -> Unsuccessful" << '\n';
    }
}

void setTimeTest1() {
    Time T;
    WeatherData W;

    T.SetHour(2);
    T.SetMinute(50);

    W.SetTime(T);

    cout << "11, Test Time setter hour 2, minute 50: ";

    if (W.GetTime().GetHour() == 2 && W.GetTime().GetMinute() == 50) {
        cout << "WeatherData time = " << W.GetTime().Timefunc() << " ->Successful" << '\n';
    }
    else {
        cout << "WeatherData time = " << W.GetTime().Timefunc() << " ->Unsuccessful" << '\n';
    }

}

void setTimeTest2() {
    Time T;
    WeatherData W;

    T.SetHour(26);
    T.SetMinute(70);

    W.SetTime(T);

    cout << "12, Test Time setter with out of bound values hour 26, minute 70: ";

    if (W.GetTime().GetHour() == 0 && W.GetTime().GetMinute() == 0) {
        cout << "WeatherData time = " << W.GetTime().Timefunc() << " ->Successful" << '\n';
    }
    else {
        cout << "WeatherData time = " << W.GetTime().Timefunc() << " ->Unsuccessful" << '\n';
    }

}


void setTimeTest3() {
    Time T;
    WeatherData W;

    T.SetHour(-1);
    T.SetMinute(-1);

    W.SetTime(T);

    cout << "13, Test Time setter with out of bound values hour -1, minute -1: ";

    if (W.GetTime().GetHour() == 0 && W.GetTime().GetMinute() == 0) {
        cout << "WeatherData time = " << W.GetTime().Timefunc() << " ->Successful" << '\n';
    }
    else {
        cout << "WeatherData time = " << W.GetTime().Timefunc() << " ->Unsuccessful" << '\n';
    }

}


void setDateTest1() {
    Date D;
    WeatherData W;

    D.SetDay(25);
    D.SetMonth(3);
    D.SetYear(2015);

    W.SetDate(D);

    cout << "14, Test Date setter Day 25, month 3, year 2015: ";

    if (W.GetDate().Datefunc() == "25 March 2015") {
        cout << "WeatherData date = " << W.GetDate().Datefunc() << " ->Successful" << '\n';
    }
    else {
        cout << "WeatherData date = " << W.GetDate().Datefunc() << " ->Unsuccessful" << '\n';
    }

}

void setDateTest2() {
    Date D;
    WeatherData W;

    D.SetDay(36);
    D.SetMonth(16);
    D.SetYear(3500);

    W.SetDate(D);

    cout << "15, Test Date setter with out of bounds value Day 36, month 16, year 3500: ";

    if (W.GetDate().Datefunc() == "1 January 1") {
        cout << "WeatherData date = " << W.GetDate().Datefunc() << " ->Successful" << '\n';
    }
    else {
        cout << "WeatherData date = " << W.GetDate().Datefunc() << " ->Unsuccessful" << '\n';
    }

}

void setDateTest3() {
    Date D;
    WeatherData W;

    D.SetDay(-1);
    D.SetMonth(-1);
    D.SetYear(-1);

    W.SetDate(D);

    cout << "16, Test Date setter with out of bounds value Day -1, month -1, year -1: ";

    if (W.GetDate().Datefunc() == "1 January 1") {
        cout << "WeatherData date = " << W.GetDate().Datefunc() << " ->Successful" << '\n';
    }
    else {
        cout << "WeatherData date = " << W.GetDate().Datefunc() << " ->Unsuccessful" << '\n';
    }

}
