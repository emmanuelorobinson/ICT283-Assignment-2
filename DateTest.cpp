#include "Date.h"
#include <iostream>
#include <typeinfo>

using namespace std;

void constructorTest();
void nonDefaultConstructorTest();
void setDay1();
void setDay2();
void setDay3();
void setMonth1();
void setMonth2();
void setMonth3();
void setYear1();
void setYear2();
void setYear3();
void testDatefunc1();
void testDatefunc2();
void testDatefunc3();
void testMonthName1();
void testMonthName2();
void testMonthName3();

int main3() {
     cout << "Testing the date class\n";

    constructorTest();
    nonDefaultConstructorTest();
    setDay1();
    setDay2();
    setDay3();
    setMonth1();
    setMonth2();
    setMonth3();
    setYear1();
    setYear2();
    setYear3();
    testMonthName1();
    testMonthName2();
    testMonthName3();
    testDatefunc1();
    testDatefunc2();
    testDatefunc3();

    return 0;
}

void constructorTest(){
    Date D;

    if (typeid(D) == typeid(Date) && D.GetDay() == 1 && D.GetMonth() == 1 && D.GetYear() == 1) {

        cout << "1, Default constructor test: " << D.Datefunc() << " ->Successful\n";
    }
    else {
        cout << "1, Default constructor test: -> Unsuccessful" << endl;
    }

}

void nonDefaultConstructorTest(){
    Date D(12, 03, 2021);

    if (typeid(D) == typeid(Date) && D.GetDay() == 12 && D.GetMonth() == 3 && D.GetYear() == 2021) {

        cout << "2, Non default constructor test: " << D.Datefunc() << " ->Successful\n";
    }
    else {
        cout << "2, Non default constructor test: -> Unsuccessful" << endl;
    }

}

void setDay1(){

    Date D;

    cout << "3, Test day setter with 12: ";

    D.SetDay(12);

    if(D.GetDay() == 12){
        cout << "Day = " << D.GetDay() << " ->Successful" << '\n';
    } else {
        cout << "Day = " << D.GetDay() << " ->Unsuccessful" << '\n';
    }
}

void setDay2(){

    Date D;

    cout << "4, Test day setter with out of bounds 40: ";

    D.SetDay(40);

    if(D.GetDay() == 1){
        cout << "Day = " << D.GetDay() << " ->Successful" << '\n';
    } else {
        cout << "Day = " << D.GetDay() << " ->Unsuccessful" << '\n';
    }
}

void setDay3(){

    Date D;

    cout << "5, Test day setter with out of bounds -1: ";

    D.SetDay(-1);

    if(D.GetDay() == 1){
        cout << "Day = " << D.GetDay() << " ->Successful" << '\n';
    } else {
        cout << "Day = " << D.GetDay() << " ->Unsuccessful" << '\n';
    }
}

void setMonth1(){

    Date D;

    cout << "6, Test month setter with 3: ";

    D.SetMonth(3);

    if(D.GetMonth() == 3){
        cout << "Month = " << D.GetMonth() << " ->Successful" << '\n';
    } else {
        cout << "Month = " << D.GetMonth() << " ->Unsuccessful" << '\n';
    }
}

void setMonth2(){

    Date D;

    cout << "7, Test month setter with out of bounds 13: ";

    D.SetMonth(13);

    if(D.GetMonth() == 1){
        cout << "Month = " << D.GetMonth() << " ->Successful" << '\n';
    } else {
        cout << "Month = " << D.GetMonth() << " ->Unsuccessful" << '\n';
    }
}

void setMonth3(){

    Date D;

    cout << "8, Test month setter with out of bounds -1: ";

    D.SetMonth(-1);

    if(D.GetMonth() == 1){
        cout << "Month = " << D.GetMonth() << " ->Successful" << '\n';
    } else {
        cout << "Month = " << D.GetMonth() << " ->Unsuccessful" << '\n';
    }
}

void setYear1(){

    Date D;

    cout << "9, Test year setter with 2021: ";

    D.SetYear(2021);

    if(D.GetYear() == 2021){
        cout << "Year = " << D.GetYear() << " ->Successful" << '\n';
    } else {
        cout << "Year = " << D.GetYear() << " ->Unsuccessful" << '\n';
    }
}

void setYear2(){

    Date D;

    cout << "10, Test year setter with out of bounds 4000: ";

    D.SetYear(4000);

    if(D.GetYear() == 1){
        cout << "Year = " << D.GetYear() << " ->Successful" << '\n';
    } else {
        cout << "Year = " << D.GetYear() << " ->Unsuccessful" << '\n';
    }
}

void setYear3(){

    Date D;

    cout << "11, Test year setter with out of bounds -1: ";

    D.SetYear(-1);

    if(D.GetYear() == 1){
        cout << "Year = " << D.GetYear() << " ->Successful" << '\n';
    } else {
        cout << "Year = " << D.GetYear() << " ->Unsuccessful" << '\n';
    }
}

void testMonthName1() {
    Date D;
    string name;

    cout << "12, Test MonthName() with 5: ";

    D.SetMonth(5);
    name = D.MonthName();

    if(name == "May"){
        cout << "Month Name = " << name << " ->Successful" << '\n';
    } else {
         cout << "Month Name = " << name << " ->unsuccessful" << '\n';
    }
}

void testMonthName2() {
    Date D;
    string name;

    cout << "13, Test MonthName() with out of bounds value 14: ";

    D.SetMonth(14);
    name = D.MonthName();

    if(name == "January"){
        cout << "Month Name = " << name << " ->Successful" << '\n';
    } else {
         cout << "Month Name = " << name << " ->unsuccessful" << '\n';
    }
}

void testMonthName3() {
    Date D;
    string name;

    cout << "14, Test MonthName() with out of bounds value -1: ";

    D.SetMonth(-1);
    name = D.MonthName();

    if(name == "January"){
        cout << "Month Name = " << name << " ->Successful" << '\n';
    } else {
         cout << "Month Name = " << name << " ->unsuccessful" << '\n';
    }
}

void testDatefunc1(){
    Date D;

    cout << "15, Test datefunc with 12/03/2021: ";

    D.SetDay(12);
    D.SetMonth(03);
    D.SetYear(2021);

    if(D.Datefunc() == "12 March 2021"){
        cout << "Year = " << D.Datefunc() << " ->Successful" << '\n';
    } else {
        cout << "Year = " << D.Datefunc() << " ->Unsuccessful" << '\n';
    }
}

void testDatefunc2(){
    Date D;

    cout << "16, Test datefunc with out of bounds 40/13/4000: ";

    D.SetDay(40);
    D.SetMonth(13);
    D.SetYear(4000);

    if(D.Datefunc() == "1 January 1"){
        cout << "Year = " << D.Datefunc() << " ->Successful" << '\n';
    } else {
        cout << "Year = " << D.Datefunc() << " ->Unsuccessful" << '\n';
    }
}

void testDatefunc3(){
    Date D;

    cout << "17, Test datefunc with out of bounds -1/-1/-1: ";

    D.SetDay(-1);
    D.SetMonth(-1);
    D.SetYear(-1);

    if(D.Datefunc() == "1 January 1"){
        cout << "Year = " << D.Datefunc() << " ->Successful" << '\n';
    } else {
        cout << "Year = " << D.Datefunc() << " ->Unsuccessful" << '\n';
    }
}
