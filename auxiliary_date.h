#ifndef AUXILIARY_DATE_H
#define AUXILIARY_DATE_H

#include <iostream>

using namespace std;

class Auxiliary_date
{
    int year;
    int month;
    int day;

public:

    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);

    int getYear();
    int getMonth();
    int getDay();

};
#endif
