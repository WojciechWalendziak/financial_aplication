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
string Auxiliary_methods::get_Line()
{
    string text_to_send = "";
    getline(cin, text_to_send);
    return text_to_send;
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
    int element = 0;
    int i = 0;
    for(int i = 0; i < 4; i++)
    {
        element = element + exponentiation(date_chain[i] - 48, 3-i);
    }
    date_of_income_expense.setYear(element);
    element = 0;
    for(int i = 5; i < 7; i++)
    {
        element = element + exponentiation(date_chain[i] - 48, 6-i);
    }
    date_of_income_expense.setMonth(element);
    element = 0;
    for(int i = 8; i < 10; i++)
    {
        element = element + exponentiation(date_chain[i] - 48, 9-i);
    }
    date_of_income_expense.setDay(element);
    element = 0;
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

      strftime(buffer,sizeof(buffer),"%Y-%m-%d %H:%M:%S",timeinfo);
      std::string str(buffer);

    date_of_income_expense = create_date(str);
    return date_of_income_expense;
}

bool Auxiliary_methods::ifLeapYear(int year)
{
   if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
   {
     	return true;
   }
   else
   {
        return false;
   }
}

int Auxiliary_methods::check_month_length(int month_number, int year)
{
    int month_length = 0;
    if(month_number == 4 || month_number == 6 || month_number == 9 || month_number == 11)
    {
        month_length = 30;
    }
    else if(month_number == 2)
    {
            if(ifLeapYear(year) == true)
            {
                month_length = 29;
            }
            else
            {
                month_length = 28;
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
    char char_1 = ',', char_2 = '.';
    int i;
    for(i = 0; i < data_chain.length(); i++)
    {
        if(data_chain[i] < 48 || data_chain[i] > 57)
        {
            if(data_chain[i] != '.')
            {
                if(data_chain[i] != ',')
                {
                    result = false;
                }
            }
        }
    }
    return result;
}
string Auxiliary_methods::transform_amount(string data_chain)
{
    int i = 0;
    for(i = 0; i < data_chain.length(); i++)
    {
        if (data_chain[i] == 44)
        {
            data_chain[i] = 46;
        }
    }
    return data_chain;
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
    if(date_of_income_expense.getYear() > 1999 && date_of_income_expense.getYear() < year + 1)
    {
        if(date_of_income_expense.getMonth() > 0 && date_of_income_expense.getMonth() < 13)
        {
            month_length = check_month_length(date_of_income_expense.getMonth(), date_of_income_expense.getYear());
            if(date_of_income_expense.getDay() > 0 && date_of_income_expense.getDay() < month_length + 1)
            {
                if(date_chain[4] == 45 && date_chain[7] == 45)
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
