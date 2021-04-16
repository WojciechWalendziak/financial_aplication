#include "income_expense.h"

    void Income_expense::setId(int newId)
    {
        id = newId;
    }
    void Income_expense::setTitle(string newTitle)
    {
        title = newTitle;
    }
    void Income_expense::setDay(int newDay)
    {
        day = newDay;
    }
    void Income_expense::setMonth(int newMonth)
    {
        month = newMonth;
    }
    void Income_expense::setYear(int newYear)
    {
        year = newYear;
    }
    void Income_expense::setAmount(double newAmount)
    {
        amount = newAmount;
    }
    int Income_expense::getId()
    {
        return id;
    }
    string Income_expense::getTitle()
    {
        return title;
    }
    int Income_expense::getDay()
    {
        return day;
    }
    int Income_expense::getMonth()
    {
        return month;
    }
    int Income_expense::getYear()
    {
        return year;
    }
    double Income_expense::getAmount()
    {
        return amount;
    }

