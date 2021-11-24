#ifndef MONTHLY_H
#define MONTHLY_H
#include <vector>
#include <map>
#include "WeatherData.h"

class Monthly
{
public:
    Monthly()
    {
        ymkey = 0;
    };

    Monthly(int ykey)
    {
        ymkey = ykey;
    };

    ~Monthly();

    int GetYMK();

    void SetYMK(int ymk);

    void AddWeatherData(int key, WeatherData wd);

    WeatherData GetWeatherData(int key);

    float MonthlyAverageWindSpeed();

    float MonthlyTotalSolarRadiation();

    float MonthlyTotalSolarRadiationAboveHundred();

    float MonthlyAverageAmbientTemp();

    bool operator==(Monthly &M);
    bool operator!=(Monthly &M);
    bool operator<(Monthly &M);
    bool operator>(Monthly &M);

private:
    int ymkey;
    std::map<int, WeatherData> dataMap;
    //vector<int> dhmkeys;

};

#endif // MONTHLY_H
