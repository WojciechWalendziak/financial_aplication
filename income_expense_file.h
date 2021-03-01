#ifndef INCOME_EXPENSE_FILE_H
#define INCOME_EXPENSE_FILE_H

#include <iostream>
#include <vector>
#include<fstream>
#include<cstdlib>

#include "auxiliary_methods.h"
#include "income_expense.h"
#include "Markup.h"

using namespace std;

class Income_expense_file
{

public:
    //Date_of_income_expense income_expense_date_separated;
    void save_new_Income_expense(int user_id, int kind_of_record);
    vector <Income_expense> getIncomes_Expenses(int user_id, int kind_of_record, Auxiliary_date date_of_start, Auxiliary_date date_of_end);
};
#endif
