#ifndef MONTHLY_H
#define MONTHLY_H
#include <vector>
#include <map>
#include "WeatherData.h"

/** \brief Monthly.h is used to simulate a Months worth of data from the Weather Data
 *
 * @author Emmanuel Oghenetega Ejakpomewhe
 *Student ID: 33961412
 * @version 17.12
 * @date 28/11/2021
 * @bug To my knowledge, my program contains no bugs
 */

class Monthly
{
public:

    /** \brief Default constructor for Monthly Object
     *
     * \param
     * \param
     * \return
     *
     */

    Monthly();

    /** \brief Non Default constructor for Monthly object
     *
     * \param ykey - used to set the desired year month key during initialization
     * \param
     * \return
     *
     */

    Monthly(int ykey);

    /** \brief Getter method for ymkey
     *
     * \param
     * \param
     * \return
     *
     */

    int GetYMK();

    /** \brief Setter method for ymkey
     *
     * \param ymk - used to pass in a integer for ymkey to be set to
     * \param
     * \return
     *
     */

    void SetYMK(int ymk);

    /** \brief Used to add weather data object to map
     *
     * \param dhmkey - Used to set key in dataMap
     * \param wd - used to pass input an object into dataMap
     * \return
     *
     */

    void AddWeatherData(int dhmkey, WeatherData wd);

//    WeatherData GetWeatherData(int key);

    /** \brief Used to calculate the monthly average wind speed in dataMap
     *
     * \param
     * \param
     * \return
     *
     */


    float MonthlyAverageWindSpeed();

    /** \brief Used to calculate the monthly average solar radiation in dataMap
     *
     * \param
     * \param
     * \return
     *
     */

    float MonthlyTotalSolarRadiation();

    /** \brief Used to calculate the monthly average total solar radiation above 100 in dataMap
     *
     * \param
     * \param
     * \return
     *
     */

    float MonthlyTotalSolarRadiationAboveHundred();

    /** \brief Used to calculate the monthly average ambient air temperature in dataMap
     *
     * \param
     * \param
     * \return
     *
     */

    float MonthlyAverageAmbientTemp();

    /** \brief Used to get the highest solar radiation in a give day in dataMap
     *
     * \param dhmkey - used to pass in the desired day to be searched on
     * \param
     * \return
     *
     */

    float GetHighestSolarRadiation(int dhmkey);

    /** \brief Used to get the times that match the highest solar radiation in a give data in dataMap
     *
     * \param dhmkey - used to pass in the desired day to be searched on
     * \param highestSR - used to pass in the highest solar radiation to be searched for
     * \return
     *
     */

    void GetHighestSolarRadiationTimes(int dhmkey, float highestSR);

    /** \brief Overloaded operator for "=="
     *
     * \param M - compares monthly object to check if one is equal to the other
     * \param
     * \return
     *
     */

    bool operator==(Monthly &M);

    /** \brief Overloaded operator for "!="
     *
     * \param M - compares monthly object to check if one is not equal to the other
     * \param
     * \return
     *
     */

    bool operator!=(Monthly &M);

    /** \brief Overloaded operator for "<"
     *
     * \param M - compares monthly object to check if one is less than the other
     * \param
     * \return
     *
     */

    bool operator<(Monthly &M);

    /** \brief Overloaded operator for ">"
     *
     * \param M - compares monthly object to check if one is greater than the other
     * \param
     * \return
     *
     */

    bool operator>(Monthly &M);

private:
    int ymkey;
    std::map<int, WeatherData> dataMap;

};

#endif // MONTHLY_H
