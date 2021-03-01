#include "auxiliary_methods.h"

using namespace std;

string Auxiliary_methods::convert_int_to_string(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
string Auxiliary_methods::convert_double_to_string(double number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int Auxiliary_methods::convert_string_to_int(string number)
{
    int number_Int;
    istringstream iss(number);
    iss >> number_Int;

    return number_Int;
}
int Auxiliary_methods::exponentiation(int date_char, int exponent_index)
{
    int date_number = 1;
    for(int i = 0; i < exponent_index; i++)
    {
        date_number = date_number*10;
    }
    date_number = date_char*date_number;
    return date_number;
}
Auxiliary_date Auxiliary_methods::create_date(string date_chain)
{
    Auxiliary_date date_of_income_expense;
    int day = 0;
    int month = 0;
    int year = 0;
    for(int i = 0; i < 2; i++)
    {
        day = day + exponentiation(date_chain[i], 1-i);
    }
    date_of_income_expense.setDay(day);
    for(int i = 3; i < 5; i++)
    {
        month = month + exponentiation(date_chain[i], 4-i);
    }
    date_of_income_expense.setMonth(month);
    for(int i = 6; i < 10; i++)
    {
        year = year + exponentiation(date_chain[i], 9-i);
    }
    date_of_income_expense.setYear(year);

    return date_of_income_expense;
}

Auxiliary_date Auxiliary_methods::current_date()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    Auxiliary_date date_of_income_expense;

      time (&rawtime);
      timeinfo = localtime(&rawtime);

      strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
      std::string str(buffer);

      std::cout << str;
    date_of_income_expense = create_date(str);
  return date_of_income_expense;
}

bool Auxiliary_methods::ifLeapYear(int year)
{
   if (((year%4 == 0)&& (year%100 != 0)) || (year%400 == 0))
   {
     	return false;
   }
   else
   {
        return true;
   }
}

int Auxiliary_methods::check_month_length(int month_number, int year)
{
    int month_length = 0;
    if(month_number%2 == 0 && month_number != 2)
    {
        month_length = 30;
    }
    else if(month_number == 2)
    {
            if(ifLeapYear(year) == 0)
            {
                month_length = 28;
            }
            else
            {
                month_length = 29;
            }
    }
    else
    {
        month_length = 31;
    }
    return month_length;
}
bool Auxiliary_methods::check_format(string data_chain)
{
    bool result;
    result = true;
    int i;
    for(i = 0; i < data_chain.length(); i++)
    {
        if(data_chain[i] < 48 || data_chain[i] > 57)
        {
            if(data_chain[i] != 44 || data_chain[i] != 46)
            {
                result = false;
            }
        }
    }
    return result;
}
string Auxiliary_methods::transform_amount(double data_chain)
{
    string data_chain_temp;
    string data_chain_new;
    data_chain_temp = convert_double_to_string(data_chain);
    int i = 0;
    for(i = 0; i < data_chain_temp.length(); i++)
    {
        if (data_chain_temp[i] == 44)
        {
            data_chain_temp[i] = 46;
        }
    }
    return data_chain_new;
}
bool Auxiliary_methods::check_date(string date_chain)
{
    Auxiliary_date date_of_income_expense;
    Auxiliary_date whole_date;
    bool result = false;
    int day = 0;
    int month = 0;
    int month_length = 0;
    int year = 0;
    int i = 0;
    whole_date = current_date();
    for(int i = 6; i < 10; i++)
    {
        year = whole_date.getYear();
    }
    date_of_income_expense = create_date(date_chain);
    if(date_of_income_expense.getYear() > 2000 && date_of_income_expense.getYear() < year + 1)
    {
        if(date_of_income_expense.getMonth() > 0 && date_of_income_expense.getMonth() < 13)
        {
            month_length = check_month_length(date_of_income_expense.getMonth(), date_of_income_expense.getYear());
            if(date_of_income_expense.getDay() > 0 && date_of_income_expense.getDay() < month_length)
            {
                if(date_chain[2] == 45 && date_chain[5] == 45)
                {
                    result = true;
                }
            }
        }
    }
    return result;
}
bool Auxiliary_methods::compare_date(string date_one, string date_two)
{
    bool result = false;
    Auxiliary_date date_of_income_expense_1 = create_date(date_one);
    Auxiliary_date date_of_income_expense_2 = create_date(date_two);
    if (date_of_income_expense_1.getYear() == date_of_income_expense_2.getYear())
    {
        if(date_of_income_expense_1.getMonth() == date_of_income_expense_2.getMonth())
        {
            if(date_of_income_expense_1.getDay() == date_of_income_expense_2.getDay())
            {
                result = false;
            }
            else
            {
                if(date_of_income_expense_1.getDay() > date_of_income_expense_2.getDay())
                {
                    result = true;
                }
                else
                {
                    result = false;
                }
            }
        }
        else
        {
            if(date_of_income_expense_1.getMonth() > date_of_income_expense_2.getMonth())
            {
                result = true;
            }
            else
            {
                result =false;
            }
        }
    }
    else
    {
        if (date_of_income_expense_1.getYear() > date_of_income_expense_2.getYear())
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    return result;
}