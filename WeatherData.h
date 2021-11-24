#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include "Date.h"
#include "Time.h"

/** \brief WeatherData.h simulates Weather data from input file. Enables reading of date values and outputting.
 *
 * @author Emmanuel Oghenetega Ejakpomewhe
 *Student ID: 33961412
 * @version 17.12
 * @date 23/10/2021
 * @bug To my knowledge, my program contains no bugs
 */
class WeatherData
{
    public:

        /** \brief Default constructor for WeatherData class
         *
         * \param
         * \param
         * \return
         *
         */

        WeatherData();

        /** \brief Getter for Date object
         *
         * \param
         * \param
         * \return
         *
         */

        Date GetDate();

        /** \brief Setter for Date object
         *
         * \param val: used to pass in date object for the date object variable
         * \param
         * \return
         *
         */

        void SetDate(Date val);

        /** \brief Getter for time object
         *
         * \param
         * \param
         * \return
         *
         */

        Time GetTime();

        /** \brief Setter for time object
         *
         * \param val: used to pass in time object for the time object variable
         * \param
         * \return
         *
         */
        void SetTime(Time val);

        /** \brief Getter for windSpeed variable
         *
         * \param
         * \param
         * \return
         *
         */

        float GetWindSpeed();

        /** \brief Setter for windSpeed variable
         *
         * \param val: used to pass in a float to the windSpeed variable
         * \param
         * \return
         *
         */

        void SetWindSpeed(float val);

        /** \brief Getter for solarRadiation variable
         *
         * \param
         * \param
         * \return
         *
         */

        float GetSolarRadiation();

        /** \brief Setter for solarRadiation variable
         *
         * \param val: used to pass in a float to the solarRadiation variable
         * \param
         * \return
         *
         */

        void SetSolarRadiation(float val);

        /** \brief Getter for the ambientAir variable
         *
         * \param
         * \param
         * \return
         *
         */

        float GetAmbientAir();

        /** \brief Setter for ambientAir variable
         *
         * \param val: used to pass in a float to the ambient air variable
         * \param
         * \return
         *
         */

        void SetAmbientAir(float val);

        bool operator==(const WeatherData& W) const;
        bool operator!=(const WeatherData& W) const;
        bool operator<(const WeatherData& W) const;
        bool operator>(const WeatherData& W) const;
        bool operator<=(const WeatherData& W) const;
        bool operator>=(const WeatherData& W) const;

    private:
        Date d;
        Time t;
        float windSpeed;
        float solarRadiation;
        float ambientAir;
};

istream & operator >> (istream & infile, WeatherData & W);

#endif // WEATHERDATA_H
