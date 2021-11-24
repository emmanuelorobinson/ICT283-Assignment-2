#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <string>

using namespace std;

/** \brief Time.h simulates the 24 hour clock. hh:mm
 *
 * @author Emmanuel Oghenetega Ejakpomewhe
 *Student ID: 33961412
 * @version 17.12
 * @date 23/10/2021
 * @bug To my knowledge, my program contains no bugs
 */

class Time
{
    public:

        /** \brief Default constructor for time class
         *
         * \param
         * \param
         * \return
         *
         */

        Time();

        /** \brief Non-default constructor for time class
         *
         * \param
         * \param
         * \return
         *
         */

        Time(unsigned hh, unsigned mm);

        /** \brief Getter for hour variable
         *
         * \param
         * \param
         * \return
         *
         */

        unsigned GetHour() const;

        /** \brief Setter for hour variable
         *
         * \param val - used to pass in a value for hour variable to be set to.
         * \param
         * \return
         *
         */

        void SetHour(unsigned val);

        /** \brief Getter for minute variable
         *
         * \param
         * \param
         * \return
         *
         */

        unsigned GetMinute() const;

        /** \brief Setter for minute variable
         *
         * \param val - used to pass in a value for minute to be set to
         * \param
         * \return
         *
         */

        void SetMinute(unsigned val);

        /** \brief Used to concatenate the hour and minute into a string
         *
         * \param
         * \param
         * \return
         *
         */

        string Timefunc();

        bool operator == (const Time& T) const;

        bool operator != (const Time& T) const;

        bool operator < (const Time& T) const;

        bool operator > (const Time& T) const;

        bool operator <= (const Time& T) const;

        bool operator >= (const Time& T) const;


    private:
        unsigned hour;
        unsigned minute;
};

istream & operator >> (istream & input, Time & D);
ostream & operator << (ostream & os, Time & T);




#endif // TIME_H
