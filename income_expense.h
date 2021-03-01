#ifndef INCOME_EXPENSE_H
#define INCOME_EXPENSE_H

#include <iostream>

using namespace std;

class Income_expense
{
    string title;
    string date_of_income_expense;
    int id;
    int day;
    int month;
    int year;
    double amount;

public:
    void setTitle(string newTitle);
    void setId(int newId);
    void setDate_of_income_expense(string newDate);
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    void setAmount(double newAmount);

    string getTitle();
    string getDate_of_income_expense();
    int getId();
    int getDay();
    int getMonth();
    int getYear();
    double getAmount();
};
#endif
