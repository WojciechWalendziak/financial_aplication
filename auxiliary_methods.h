#ifndef AUXILIARY_METHODS_H
#define AUXILIARY_METHODS_H

#include <iostream>
#include <vector>
#include<fstream>
#include<cstdlib>
#include <time.h>
#include <sstream>
#include <algorithm>
//#include "Markup.h"
#include "auxiliary_date.h"

using namespace std;

string imie, nazwisko;
int nr_tel;

class Auxiliary_methods
{
    public:
        static string convert_int_to_string(int number);
        static string convert_double_to_string(double number);
        static int convert_string_to_int(string number);
        static int exponentiation(int date_char, int exponent_index);
        static Auxiliary_date create_date(string date_chain);
        static bool check_date(string date_chain);
        static bool compare_date(string date_one, string date_two);
        static Auxiliary_date current_date();
        static bool ifLeapYear(int year);
        static int check_month_length(int month_number, int year);
        static bool check_format(string data_chain);
        static string transform_amount(double data_chain);
};
#endif
