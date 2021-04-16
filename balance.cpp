#include "balance.h"

using namespace std;

vector <Income_expense> Balance::sort_vector(vector < Income_expense > &incomes_expenses)
{
    int check = 0, id_temp = 0, i = 0, z = 0, counter = 0, maximum = 0, q = 0;
    do{
        check = 0;
        for(i = 0; i <  incomes_expenses.size(); i++)
        {
            if(i < incomes_expenses.size() - 1)
            {
                if(check == 0)
                {
                    if(incomes_expenses[i].getYear() > incomes_expenses[i+1].getYear())
                    {
                        if(incomes_expenses[i].getId() < incomes_expenses[i+1].getId())
                        {
                                id_temp = incomes_expenses[i].getId();
                                incomes_expenses[i].setId(incomes_expenses[i+1].getId());
                                incomes_expenses[i+1].setId(id_temp);
                                check = 1;
                        }
                    }
                    else if(incomes_expenses[i].getYear() < incomes_expenses[i+1].getYear())
                    {
                        if(incomes_expenses[i].getId() > incomes_expenses[i+1].getId())
                        {
                                id_temp = incomes_expenses[i].getId();
                                incomes_expenses[i].setId(incomes_expenses[i+1].getId());
                                incomes_expenses[i+1].setId(id_temp);
                                check = 1;
                        }
                    }
                }
                if(check == 0)
                {
                    if(incomes_expenses[i].getYear() == incomes_expenses[i+1].getYear())
                    {
                        if(incomes_expenses[i].getMonth() > incomes_expenses[i+1].getMonth())
                        {
                                if(incomes_expenses[i].getId() < incomes_expenses[i+1].getId())
                                {
                                        id_temp = incomes_expenses[i].getId();
                                        incomes_expenses[i].setId(incomes_expenses[i+1].getId());
                                        incomes_expenses[i+1].setId(id_temp);
                                        check = 1;
                                }
                        }
                        else if(incomes_expenses[i].getMonth() < incomes_expenses[i+1].getMonth())
                        {
                                if(incomes_expenses[i].getId() > incomes_expenses[i+1].getId())
                                {
                                        id_temp = incomes_expenses[i].getId();
                                        incomes_expenses[i].setId(incomes_expenses[i+1].getId());
                                        incomes_expenses[i+1].setId(id_temp);
                                        check = 1;
                                }
                        }
                    }
                }
                if(check == 0)
                {
                    if(incomes_expenses[i].getYear() == incomes_expenses[i+1].getYear())
                    {
                        if(incomes_expenses[i].getMonth() == incomes_expenses[i+1].getMonth())
                        {
                            if(incomes_expenses[i].getDay() > incomes_expenses[i+1].getDay())
                            {
                                    if(incomes_expenses[i].getId() < incomes_expenses[i+1].getId())
                                    {
                                            id_temp = incomes_expenses[i].getId();
                                            incomes_expenses[i].setId(incomes_expenses[i+1].getId());
                                            incomes_expenses[i+1].setId(id_temp);
                                            check = 1;
                                    }
                            }
                            else if(incomes_expenses[i].getDay() < incomes_expenses[i+1].getDay())
                            {
                                    if(incomes_expenses[i].getId() > incomes_expenses[i+1].getId())
                                    {
                                            id_temp = incomes_expenses[i].getId();
                                            incomes_expenses[i].setId(incomes_expenses[i+1].getId());
                                            incomes_expenses[i+1].setId(id_temp);
                                            check = 1;
                                    }
                            }
                        }
                    }
                }
            }
            else
            {
                if(check == 0)
                {
                    if(incomes_expenses[i].getYear() > incomes_expenses[0].getYear())
                    {
                        if(incomes_expenses[i].getId() < incomes_expenses[0].getId())
                        {
                                id_temp = incomes_expenses[i].getId();
                                incomes_expenses[i].setId(incomes_expenses[0].getId());
                                incomes_expenses[0].setId(id_temp);
                                check = 1;
                        }
                    }
                    else if(incomes_expenses[i].getYear() < incomes_expenses[0].getYear())
                    {
                        if(incomes_expenses[i].getId() > incomes_expenses[0].getId())
                        {
                                id_temp = incomes_expenses[i].getId();
                                incomes_expenses[i].setId(incomes_expenses[0].getId());
                                incomes_expenses[0].setId(id_temp);
                                check = 1;
                        }
                    }
                }
                if(check == 0)
                {
                    if(incomes_expenses[i].getYear() == incomes_expenses[0].getYear())
                    {
                        if(incomes_expenses[i].getMonth() > incomes_expenses[0].getMonth())
                        {
                                if(incomes_expenses[i].getId() < incomes_expenses[0].getId())
                                {
                                        id_temp = incomes_expenses[i].getId();
                                        incomes_expenses[i].setId(incomes_expenses[0].getId());
                                        incomes_expenses[0].setId(id_temp);
                                        check = 1;
                                }
                        }
                        else if(incomes_expenses[i].getMonth() < incomes_expenses[0].getMonth())
                        {
                                if(incomes_expenses[i].getId() > incomes_expenses[0].getId())
                                {
                                        id_temp = incomes_expenses[i].getId();
                                        incomes_expenses[i].setId(incomes_expenses[0].getId());
                                        incomes_expenses[0].setId(id_temp);
                                        check = 1;
                                }
                        }
                    }
                }
                if(check == 0)
                {
                    if(incomes_expenses[i].getYear() == incomes_expenses[0].getYear())
                    {
                        if(incomes_expenses[i].getMonth() == incomes_expenses[0].getMonth())
                        {
                            if(incomes_expenses[i].getDay() > incomes_expenses[0].getDay())
                            {
                                    if(incomes_expenses[i].getId() < incomes_expenses[0].getId())
                                    {
                                            id_temp = incomes_expenses[i].getId();
                                            incomes_expenses[i].setId(incomes_expenses[0].getId());
                                            incomes_expenses[0].setId(id_temp);
                                            check = 1;
                                    }
                            }
                            else if(incomes_expenses[i].getDay() < incomes_expenses[0].getDay())
                            {
                                    if(incomes_expenses[i].getId() > incomes_expenses[0].getId())
                                    {
                                            id_temp = incomes_expenses[i].getId();
                                            incomes_expenses[i].setId(incomes_expenses[i+1].getId());
                                            incomes_expenses[0].setId(id_temp);
                                            check = 1;
                                    }
                            }
                        }
                    }
                }
            }
        }
        q++;
    }while(q < 3);

    return incomes_expenses;
}

double Balance::calculate_summary(int user_id, int kind_of_record, Auxiliary_date start_date, Auxiliary_date end_date)
{
    string data_to_insert;
    int id = 1, count_index = 1, income_id = 0, id_temp = 0, check_size = 0, i = 0, q = 1;
    bool bSuccess = true, result = false;
    Income_expense income_expense;
    Income_expense_file income_expense_file;
    vector <Income_expense> incomes_expenses;
    double summary = 0;

    incomes_expenses = income_expense_file.getIncomes_Expenses(user_id, kind_of_record, start_date, end_date);
    incomes_expenses = sort_vector(incomes_expenses);
    for(i = 0; i <  incomes_expenses.size(); i++)
    {
        if(incomes_expenses[i].getId() > check_size)
        {
            check_size = incomes_expenses[i].getId();
        }
    }
    do{
       for(i = 0; i <  incomes_expenses.size(); i++)
        {
            if(incomes_expenses[i].getId() == q)
            {
                cout << incomes_expenses[i].getTitle() << endl;
                cout << incomes_expenses[i].getYear() << "-" << incomes_expenses[i].getMonth() << "-" << incomes_expenses[i].getDay() << endl;
                cout << incomes_expenses[i].getAmount() << endl;
                summary = summary + incomes_expenses[i].getAmount();
                i = incomes_expenses.size() + 1;
            }
        }
        q++;
    }while(q < check_size + 1);
    return summary;
}

double Balance::calculate_difference(double summary_1, double summary_2)
{
    double difference = summary_1 - summary_2;
    cout << "suma przychodow: " << summary_1 << endl;
    cout << "suma wydatkow: " << summary_2 << endl;
    cout << "Roznica przychodow i wydatkow: " << difference << endl;
    return difference;
}

void Balance::show_balance(int user_id, Auxiliary_date start_date, Auxiliary_date end_date)
{
    double incomes, expenses, difference;
    incomes = calculate_summary(user_id, 1, start_date, end_date);
    expenses = calculate_summary(user_id, 0, start_date, end_date);
    difference = calculate_difference(incomes, expenses);
}



