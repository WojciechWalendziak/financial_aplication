#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#include "income_expense.h"
#include "Income_expense_file.h"
#include "auxiliary_date.h"

using namespace std;

class Balance
{

public:

    void show_balance(int user_id, Auxiliary_date start_date, Auxiliary_date end_date);
    vector <Income_expense> sort_vector(vector < Income_expense > &incomes_expenses);
    void calculate_difference(double summary_1, double summary_2);
    double calculate_summary(int user_id, int kind_of_record, Auxiliary_date start_date, Auxiliary_date end_date);

};
#endif
