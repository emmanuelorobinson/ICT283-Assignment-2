#include "WeatherData.h"

WeatherData::WeatherData()
{
    windSpeed = 0;
    solarRadiation = 0;
    ambientAir = 0;
}


Date WeatherData::GetDate() {
    return d;
}


void WeatherData::SetDate(Date val) {
    d = val;
}

Time WeatherData::GetTime() {
    return t;
}


void WeatherData::SetTime(Time val) {
    t = val;
}

float WeatherData::GetWindSpeed() {
    return windSpeed;
}

void WeatherData::SetWindSpeed(float val) {
    if(val >= 0) {
        windSpeed = val;
    }
    else{
        windSpeed = 0;
    }
}

float WeatherData::GetSolarRadiation() {
    return solarRadiation;
}

void WeatherData::SetSolarRadiation(float val) {
    if(val >= 0) {
        solarRadiation = val;
    }
    else{
        solarRadiation = 0;
    }
}

float WeatherData::GetAmbientAir() {
    return ambientAir;
}

void WeatherData::SetAmbientAir(float val) {
    if(val >= 0) {
        ambientAir = val;
    }
    else{
        ambientAir = 0;
    }
}

//operator overloader used to simplify reading it data
istream & operator >> (istream & infile, WeatherData & W){

    string datetest,strSpeed, strSR, strAmbAir;
    float  tmpSpeed, tmpSR, tmpAmbAir;
    Date tmpDate;
    Time tmpTime;

    infile >> tmpDate;
    W.SetDate(tmpDate);

    infile >> tmpTime;
    W.SetTime(tmpTime);

    for (unsigned i = 0; i < 9; i++) {
        getline(infile, datetest, ',');
    }

    getline(infile, strSpeed, ',');
    tmpSpeed = atof(strSpeed.c_str());
    W.SetWindSpeed(tmpSpeed);

    getline(infile, strSR, ',');
    tmpSR = atof(strSR.c_str());
    W.SetSolarRadiation(tmpSR);

    for (unsigned i = 0; i < 5; i++) {
        getline(infile, datetest, ',');
    }

    getline(infile, strAmbAir, '\n');
    tmpAmbAir = atof(strAmbAir.c_str());
    W.SetAmbientAir(tmpAmbAir);

    return infile;
}

bool WeatherData::operator==(const WeatherData& W) const {
    return (d == W.d && t == W.t);
}

bool WeatherData::operator!=(const WeatherData& W) const {
    return !(*this == W);
}

bool WeatherData::operator<(const WeatherData& W) const {
    return (d < W.d || (d == W.d && t < W.t));
}

bool WeatherData::operator>(const WeatherData& W) const {
    return (d > W.d || (d == W.d && t > W.t));
}

bool WeatherData::operator<=(const WeatherData& W) const {
    return (d < W.d || (d == W.d && t <= W.t));
}

bool WeatherData::operator>=(const WeatherData& W) const {
    return (d > W.d || (d == W.d && t >= W.t));
}


