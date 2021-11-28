#include "Monthly.h"

Monthly::Monthly()
{
    ymkey = 0;
}

Monthly::Monthly(int ykey)
{
    ymkey = ykey;
}

int Monthly::GetYMK()
{
    return ymkey;
}

void Monthly::SetYMK(int ymk)
{
    ymkey = ymk;
}

void Monthly::AddWeatherData(int dhmkey, WeatherData wd)
{
    //adds a weather data object to the map
    //key is the day, hour and minute
    //wd is the weather data object
    //wd is inserted into dataMap
    //if the key already exists, the weather data object is replaced
    //if the key does not exist, a new key is created and the weather data object is added to it

    if(dataMap.find(dhmkey) == dataMap.end())
    {
        //key does not exist
        //create a new key
        dataMap.insert(std::pair<int, WeatherData>(dhmkey, wd));

    }
    else
    {
        //key exists
        //replace the weather data object
        dataMap.erase(dhmkey);
        dataMap.insert(std::pair<int, WeatherData>(dhmkey, wd));
    }

}

WeatherData Monthly::GetWeatherData(int dmmkey)
{
    //Gets the weather data object from the map
    //key is the day, hour and minute
    //if the key does not exist, an error message is displayed
    //if the key does exist, the weather data object is returned

    if(dataMap.find(dmmkey) == dataMap.end())
    {
        //key does not exist
        std::cout << "Error: Key does not exist" << std::endl;
    }

    //key exists
    //return the weather data object
    return dataMap.find(dmmkey)->second;
}

float Monthly:: MonthlyAverageWindSpeed()
{
    //Calculates the average wind speed for the month
    //returns the average wind speed

    float totalWindSpeed = 0;
    int totalWindSpeedCount = 0;

    //iterate through the map
    for(std::map<int, WeatherData>::iterator it = dataMap.begin(); it != dataMap.end(); ++it)
    {
        //get the wind speed
        float windSpeed = it->second.GetWindSpeed();
        //add the wind speed to the total
        totalWindSpeed += windSpeed;
        //increment the total wind speed count
        totalWindSpeedCount++;
    }

    //return the average wind speed
    return (totalWindSpeed * 3.6) / totalWindSpeedCount;
}

float Monthly::MonthlyTotalSolarRadiation()
{
    //Calculates the total solar radiation for the month
    //returns the total solar radiation

    float totalSolarRadiation = 0;

    //iterate through the map
    for(std::map<int, WeatherData>::iterator it = dataMap.begin(); it != dataMap.end(); ++it)
    {
        //get the solar radiation
        float solarRadiation = it->second.GetSolarRadiation();
        //add the solar radiation to the total
        if(solarRadiation >= 100)
        {
            totalSolarRadiation += solarRadiation;
        }
    }

    //return the total solar radiation
    return totalSolarRadiation/6000;
}

float Monthly::MonthlyAverageAmbientTemp()
{
    //Calculates the average ambient temperature for the month
    //returns the average ambient temperature

    float totalAmbientTemp = 0;
    int totalAmbientTempCount = 0;

    //iterate through the map
    for(std::map<int, WeatherData>::iterator it = dataMap.begin(); it != dataMap.end(); ++it)
    {
        //get the ambient temperature
        float ambientTemp = it->second.GetAmbientAir();
        //add the ambient temperature to the total
        totalAmbientTemp += ambientTemp;
        //increment the total ambient temperature count
        totalAmbientTempCount++;
    }

    //return the average ambient temperature
    return totalAmbientTemp / totalAmbientTempCount;
}

float Monthly::GetHighestSolarRadiation(int dhmkey)
{
    //Calculates the highest solar radiation for all the hours and minutes in the day part of the dhmkey
    //returns the highest solar radiation

    float highestSolarRadiation = 0;

    //iterate through the map
    for(std::map<int, WeatherData>::iterator it = dataMap.begin(); it != dataMap.end(); ++it)
    {
        //get the solar radiation
        float solarRadiation = it->second.GetSolarRadiation();
        //get the key
        int key = it->first;

        if(dhmkey == key)
        {
            //if the solar radiation is higher than the highest solar radiation
            if(solarRadiation > highestSolarRadiation)
            {
                //set the highest solar radiation to the solar radiation
                highestSolarRadiation = solarRadiation;
            }
        }
    }

    return highestSolarRadiation;
}

void Monthly::GetHighestSolarRadiationTimes(int dhmkey, float highestSR)
{
    //returns the times of a day where solar radiation is the same as highestSR

    //iterate through the map
    for(std::map<int, WeatherData>::iterator it = dataMap.begin(); it != dataMap.end(); ++it)
    {
        //get the solar radiation
        float solarRadiation = it->second.GetSolarRadiation();
        //get the key
        int key = it->first;

        if(dhmkey == key)
        {
            //if the solar radiation is the same as the highest solar radiation
            if(solarRadiation == highestSR)
            {
                //cout the hour and minute
                cout << it->second.GetTime().GetHour() << ":" << it->second.GetTime().GetMinute() << endl;
            }
        }
    }
}

bool Monthly::operator!=(Monthly &M)
{
    return ymkey != M.GetYMK();
}

bool Monthly::operator==(Monthly &M)
{
    return ymkey == M.GetYMK();
}

bool Monthly::operator<(Monthly &M)
{
    return ymkey < M.GetYMK();
}

bool Monthly::operator>(Monthly &M)
{
    return ymkey > M.GetYMK();
}

