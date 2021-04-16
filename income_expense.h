#ifndef INCOME_EXPENSE_H
#define INCOME_EXPENSE_H

#include <iostream>

using namespace std;

class Income_expense
{
    string title;
    int id;
    int day;
    int month;
    int year;
    double amount;

public:
    void setTitle(string newTitle);
    void setId(int newId);
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    void setAmount(double newAmount);

    string getTitle();
    int getId();
    int getDay();
    int getMonth();
    int getYear();
    double getAmount();
};
#endif
