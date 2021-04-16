#include "Income_expense_file.h"

using namespace std;

void Income_expense_file::save_new_Income_expense(int user_id, int kind_of_record)
{
    //Auxiliary_date
    char sign = 'a';
    string title = "", amount_to_save = "", string_date = "";
    int timeline = 0, check = 0, id = 0, counter = 0, i = 0;
    Auxiliary_date Income_expense_date;
    Auxiliary_date Income_expense;
    double amount_double;
    bool bSuccess = false;

    cout << "podaj tytul: " << endl;
    while(title == ""){
       getline(cin, title);
    };
    //title = Auxiliary_methods::get_Line();

    cout << "jezeli data dzisiejsza wybierz 1, a jezeli inna - dowolna inna cyfre: ";
    cin >> timeline;
    if(timeline == 1)
    {
     	Income_expense_date = Auxiliary_methods::current_date();
    }
    else
    {
        check = 0;
        do
        {
                cout << "podaj date: " << endl;
                cin >> string_date;
                if(Auxiliary_methods::check_date(string_date) == true)
                {
                    check = 1;
                }
                else
                {
                    cout << "niepoprawna data - popraw" << endl;
                }
        }while(check == 0);
        Income_expense_date = Auxiliary_methods::create_date(string_date);
    }
    check = 1;
    do{
        cout << "podaj kwote: ";
        cin >> amount_to_save;
        //amount_to_save = Auxiliary_methods::transform_amount(amount_to_save);
        if(Auxiliary_methods::check_format(amount_to_save) == true)
        {
            check = 0;
            amount_to_save = Auxiliary_methods::transform_amount(amount_to_save);
            //amount_to_save = Auxiliary_methods::transform_amount(amount_to_save);
        }
        else
        {
            cout << "kwota niepoprawna, podaj jeszcze raz " << endl;
        }
    }while(check == 1);

    CMarkup xml;
        if(kind_of_record == 1)
        {
            bSuccess = xml.Load("C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\incomes.xml");
        }
        else
        {
            bSuccess = xml.Load("C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\expenses.xml");
        }
        //cout << xml.GetResult() << endl;
        //cout << "bSuccess: " << bSuccess << endl;
        if(bSuccess == true)
        {
                xml.FindElem(); // main is TESTDOC, no child position
                xml.IntoElem();
                xml.FindElem();
                    MCD_STR element_count = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                            counter = atoi(element_count.c_str());
                do
                {
                    xml.FindElem();
                    MCD_STR element_count = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                            id = atoi(element_count.c_str());
                    xml.FindElem();
                    if(id == user_id)
                    {
                        xml.IntoElem();
                            xml.FindElem();
                            element_count = xml.GetData();
                            id = atoi(element_count.c_str());
                            xml.SetData(id + 1);
                            if(kind_of_record == 1)
                            {
                                xml.AddElem( "income" );
                            }
                            else
                            {
                                xml.AddElem( "expense" );
                            }
                            xml.IntoElem();
                                xml.AddElem( "id", id + 1 );
                                xml.AddElem( "title", title );
                                xml.AddElem( "day", Income_expense_date.getDay());
                                xml.AddElem( "month", Income_expense_date.getMonth());
                                xml.AddElem( "year", Income_expense_date.getYear());
                                xml.AddElem( "amount", amount_to_save );
                            xml.OutOfElem();
                        xml.OutOfElem();
                        i = counter + 1;
                    }
                    else
                    {
                        xml.FindElem();
                        i++;
                    }
                }while(i < counter);
                if(i == counter)
                {
                    xml.AddElem( "user_id", i );
                    xml.AddElem( "test", user_id );
                    if(kind_of_record == 1)
                    {
                        xml.AddElem("income_list");
                    }
                    else
                    {
                        xml.AddElem("expense_list");
                    }
                    xml.IntoElem();
                    if(kind_of_record == 1)
                    {
                        xml.AddElem("count_incomes", 1);
                        xml.AddElem("income");
                    }
                    else
                    {
                        xml.AddElem("count_expenses", 1);
                        xml.AddElem("expense");
                    }
                    xml.IntoElem();
                        xml.AddElem( "id", 1 );
                        xml.AddElem( "title", title );
                        xml.AddElem( "day", Income_expense_date.getDay());
                        xml.AddElem( "month", Income_expense_date.getMonth());
                        xml.AddElem( "year", Income_expense_date.getYear());
                        xml.AddElem( "amount", amount_to_save );
                        xml.OutOfElem();
                    xml.OutOfElem();
                    xml.ResetPos();
                    xml.FindElem(); // main is TESTDOC, no child position
                    xml.IntoElem();
                    xml.FindElem();
                    xml.SetData(counter + 1);
                }
                xml.ResetMainPos();
                if(kind_of_record == 1)
                {
                    xml.Save( "C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\incomes.xml" );
                }
                else
                {
                    xml.Save( "C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\expenses.xml" );
                }
                xml.ResetMainPos();
                xml.RemoveElem();
        }
        else
        {
                //cout << "pliku jeszcze nie ma" << endl;
                if(kind_of_record == 1)
                {
                    xml.AddElem("incomes");
                }
                else
                {
                    xml.AddElem("expenses");
                }
                xml.IntoElem();
                    xml.AddElem( "count", 1 );
                    xml.AddElem( "user_id", user_id );
                    if(kind_of_record == 1)
                    {
                        xml.AddElem("income_list");
                    }
                    else
                    {
                        xml.AddElem("expense_list");
                    }
                    xml.IntoElem();
                        if(kind_of_record == 1)
                        {
                            xml.AddElem("count_incomes", 1);
                            xml.AddElem("income");
                        }
                        else
                        {
                            xml.AddElem("count_expenses", 1);
                            xml.AddElem("expense");
                        }
                        xml.IntoElem();
                            xml.AddElem( "id", 1 );
                            xml.AddElem( "title", title );
                            xml.AddElem( "day", Income_expense_date.getDay());
                            xml.AddElem( "month", Income_expense_date.getMonth());
                            xml.AddElem( "year", Income_expense_date.getYear());
                            xml.AddElem( "amount", amount_to_save );
                            xml.OutOfElem();
                        xml.ResetPos();
                        if(kind_of_record == 1)
                        {
                            xml.Save( "C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\incomes.xml" );
                        }
                        else
                        {
                            xml.Save( "C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\expenses.xml" );
                        }
                        xml.ResetMainPos();
                        xml.RemoveElem();
        }
}

vector <Income_expense> Income_expense_file::getIncomes_Expenses(int user_id, int kind_of_record, Auxiliary_date start_date, Auxiliary_date end_date)
{
    Income_expense Income_expense_object;
    vector <Income_expense> incomes_expenses;
    CMarkup xml;
    MCD_STR element_count;
    string data_to_insert;
    int check = 0, id = 0, i = 0, q = 0, data_int = 0, counter_1 = 0, counter_2 = 0;
    double data_double = 0;
    bool bSuccess = false;
    if(kind_of_record == 1)
    {
        bSuccess = xml.Load("C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\incomes.xml");
    }
    else
    {
        bSuccess = xml.Load("C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\expenses.xml");
    }
    //cout << xml.GetResult() << endl;
    //cout << "bSuccess: " << bSuccess << endl;
    if(bSuccess == true)
    {
        xml.FindElem(); // main is TESTDOC, no child position
        xml.IntoElem();
        xml.FindElem();
                    element_count = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                    counter_1 = atoi(element_count.c_str()) + 1;
	    q = 0;
	    do
	    {
            xml.FindElem();
                    element_count = xml.GetData();// ODCZYTAÆ WARTOŒÆ
                    id = atoi(element_count.c_str());
            xml.FindElem();
            if(id == user_id)
            {
                xml.IntoElem();
                xml.FindElem();
                element_count = xml.GetData();
                counter_2 = atoi(element_count.c_str());
                i = 0;
                do
                {
                    check = 0;
                    xml.FindElem();
                    xml.IntoElem();
                        xml.FindElem();
                        data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                        data_int = Auxiliary_methods::convert_string_to_int(data_to_insert);
                                    Income_expense_object.setId(data_int);
                        xml.FindElem();
                        data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                                    Income_expense_object.setTitle(data_to_insert);
                        xml.FindElem();
                        data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                        data_int = Auxiliary_methods::convert_string_to_int(data_to_insert);
                                    Income_expense_object.setDay(data_int);
                        xml.FindElem();
                        data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                        data_int = Auxiliary_methods::convert_string_to_int(data_to_insert);
                                    Income_expense_object.setMonth(data_int);
                        xml.FindElem();
                        data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                        data_int = Auxiliary_methods::convert_string_to_int(data_to_insert);
                                    Income_expense_object.setYear(data_int);
                        xml.FindElem();
                        data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                        data_double = atof(data_to_insert.c_str());
                        Income_expense_object.setAmount(data_double);
                    if(end_date.getYear() != start_date.getYear())
                    {
                        if(Income_expense_object.getYear() <= end_date.getYear() && Income_expense_object.getYear() >= start_date.getYear() )
                        {
                            if(Income_expense_object.getYear() == end_date.getYear())
                            {
                                if(Income_expense_object.getMonth() <= end_date.getMonth())
                                {
                                    if(Income_expense_object.getMonth() == end_date.getMonth())
                                    {
                                        if(Income_expense_object.getDay() > end_date.getDay())
                                        {
                                            check = 1;
                                        }
                                    }
                                }
                                else
                                {
                                    check = 1;
                                }
                            }
                            else
                            {
                                if(Income_expense_object.getYear() == start_date.getYear())
                                {
                                    if(Income_expense_object.getMonth() >= start_date.getMonth())
                                    {
                                        if(Income_expense_object.getMonth() == start_date.getMonth())
                                        {
                                            if(Income_expense_object.getDay() < start_date.getDay())
                                            {
                                                check = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            check = 1;
                        }
                    }
                    else
                    {
                        if(Income_expense_object.getYear() == start_date.getYear())
                        {
                            if(end_date.getMonth() != start_date.getMonth())
                            {
                                if(Income_expense_object.getMonth() <= end_date.getMonth() && Income_expense_object.getMonth() >= start_date.getMonth())
                                {
                                    if(Income_expense_object.getMonth() == end_date.getMonth())
                                    {
                                        if(Income_expense_object.getDay() > end_date.getDay())
                                        {
                                            check = 1;
                                        }
                                    }
                                    else
                                    {
                                        if(Income_expense_object.getMonth() == start_date.getMonth())
                                        {
                                            if(Income_expense_object.getDay() < start_date.getDay())
                                            {
                                                check = 1;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    check = 1;
                                }
                            }
                            else
                            {
                                if(Income_expense_object.getMonth() == start_date.getMonth())
                                {
                                    if(Income_expense_object.getDay() < start_date.getDay())
                                    {
                                        check = 1;
                                    }
                                    else
                                    {
                                        if(Income_expense_object.getDay() > end_date.getDay())
                                        {
                                            check = 1;
                                        }
                                    }
                                }
                                else
                                {
                                    check = 1;
                                }
                            }
                        }
                        else
                        {
                            check = 1;
                        }
                    }
                    if(check == 0)
                    {
                        incomes_expenses.push_back(Income_expense_object);
                    }
                    i++;
                    xml.OutOfElem();
                    q = counter_2;
                }while(i < counter_2);
            xml.OutOfElem();
            }
            q++;
        }while(q < counter_2);
        xml.ResetPos();
	}
    return incomes_expenses;
}
