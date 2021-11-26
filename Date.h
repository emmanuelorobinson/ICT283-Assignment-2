#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>


using namespace std;

/** \brief Date.h simulates Gregorian date. Enables reading of date values and outputting.
 *
 * @author Emmanuel Oghenetega Ejakpomewhe
 *Student ID: 33961412
 * @version 17.12
 * @date 28/11/2021
 * @bug To my knowledge, my program contains no bugs
 */

class Date
{
    public:
        /** \brief Default constructor for date class
         *
         * \param
         * \param
         * \return
         *
         */

        Date();

        /** \brief Non-default constructor for date class
         *
         * \param dd - initializing variable for date
         * \param mm - initializing variable for month
         * \param yy - initializing variable for year
         * \return
         *
         */

        Date(int dd, int mm, int yy);

        /** \brief Getter for day variable
         *
         * \param
         * \param
         * \return
         *
         */

        int GetDay() const;

        /** \brief Setter for day variable
         *
         * \param val - used to pass in a value for day variable to be set to in the set method
         * \param
         * \return
         *
         */

        void SetDay(int val);

        /** \brief Getter for month variable
         *
         * \param
         * \param
         * \return
         *
         */

        int GetMonth() const;

        /** \brief Setter for month variable
         *
         * \param val- used to pass in value for the month variable to be set to
         * \param
         * \return
         *
         */

        void SetMonth(int val);

        /** \brief Getter for year variable
         *
         * \param
         * \param
         * \return
         *
         */

        int GetYear() const;

        /** \brief Setter for year variable
         *
         * \param val - used to pass a value for the year variable.
         * \param
         * \return
         *
         */

        void SetYear(int val);


        /** \brief Used to get the month in a long format from the integer initially passed in
         *
         * \param
         * \param
         * \return
         *
         */

        string MonthName();

        /** \brief Used to concatenate the day, month, and year into a single string
         *
         * \param
         * \param
         * \return
         *
         */

        string Datefunc();

        /** \brief overloaded operator for "=="
         *
         * \param D - The date object is compared to check if one object is equals to the other
         * \param
         * \return
         *
         */

        bool operator==(const Date& D) const;

        /** \brief overloaded operator for "!="
         *
         * \param D - The date object is compared to check if one object is not equals to the other
         * \param
         * \return
         *
         */

        bool operator!=(const Date& D) const;

        /** \brief overloaded operator for "<"
         *
         * \param D - The date object is compared to check if one object is less than the other
         * \param
         * \return
         *
         */

        bool operator<(const Date& D) const;

        /** \brief overloaded operator for ">"
         *
         * \param D - The date object is compared to check if one object is greater than the other
         * \param
         * \return
         *
         */

        bool operator>(const Date& D) const;

        /** \brief overloaded operator for "<="
         *
         * \param D - The date object is compared to check if one object is less than or equals to the other
         * \param
         * \return
         *
         */

        bool operator<=(const Date& D) const;

        /** \brief overloaded operator for ">="
         *
         * \param D - The date object that is compared to check if one object is greater than or equals to the other
         * \param
         * \return
         *
         */

        bool operator>=(const Date& D) const;

    protected:

    private:
        int day;
        int month;
        int year;
};

istream & operator >>( istream & input, Date & D );
ostream & operator <<( ostream & os, Date & D );

#endif // DATE_H
