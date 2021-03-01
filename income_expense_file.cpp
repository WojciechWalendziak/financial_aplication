#include "Income_expense_file.h"

using namespace std;

void Income_expense_file::save_new_Income_expense(int user_id, int kind_of_record)
{
    //Auxiliary_date
    string title, amount_to_save, string_date;
    int timeline = 0, check = 0, id = 0;
    Auxiliary_date Income_expense_date;
    Auxiliary_date Income_expense_date_separated;
    double amount_double;
    bool bSuccess = false;

    cout << "podaj tytul: ";
    cin >> title;

    cout << "jezeli data dzisiejsza wybierz 1, a jezeli inna - dowolna inna cyfre: ";
    cin >> timeline;
    if(timeline = 1)
    {
     	Income_expense_date = Auxiliary_methods::current_date();
    }
    else
    {
        do
        {
                cout <<" podaj date: " << endl;
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
    }
    Income_expense_date_separated = Auxiliary_methods::create_date(string_date);

    do{
        cout << "podaj kwote: ";
        cin >> amount_to_save;
        //amount_to_save = Auxiliary_methods::transform_amount(amount_to_save);
        if(Auxiliary_methods::check_format(amount_to_save) == true)
        {
            check = 0;
            //amount_to_save = Auxiliary_methods::transform_amount(amount_to_save);
        }
        else
        {
            cout << "kwota niepoprawna, podaj jeszcze raz " << endl;
        }
    }while(check == 1);

    CMarkup xml;
    //MCD_STR strXML = xml.GetDoc();

    //cout << "wynik: " << strXML << endl;

    if(kind_of_record == 1)
    {
	    bSuccess = xml.Load("C:\\incomes\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_data_base\\incomes.xml");
        cout << xml.GetResult() << endl;
        cout << "bSuccess: " << bSuccess << endl;
        if(bSuccess == true)
        {
                cout << "plik JEST" << endl;
                xml.FindElem(); // main is TESTDOC, no child position
                xml.IntoElem();
                do
                {
                    xml.FindElem();
                    MCD_STR element_count = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                            cout << "trzy " << element_count << " cztery" << endl;
                            id = atoi(element_count.c_str());
                    xml.FindElem();
                    if(id == user_id)
                    {
                        xml.FindElem();
                        xml.IntoElem();
                        xml.FindElem();
                        element_count = xml.GetData();
                        xml.SetData(id + 1);
                        xml.AddElem( "id", id + 1 );
                        xml.AddElem( "title", title );
                        xml.AddElem( "day", Income_expense_date_separated.getDay());
                        xml.AddElem( "month", Income_expense_date_separated.getMonth());
                        xml.AddElem( "year", Income_expense_date_separated.getYear());
                        xml.AddElem( "amount", amount_to_save );
                        xml.OutOfElem();
                    }
                }while(id != user_id);
                xml.ResetMainPos();
                if(check == 0)
                {
                    xml.AddElem( "id", user_id);
                        //xml.ResetPos(); // no current position
                    //xml.FindElem(); // main is TESTDOC, no child position
                    //xml.IntoElem();
                    xml.AddChildElem( "count", 1 );
                    xml.AddElem( "id", 1 );
                    xml.AddChildElem( "title", title );
                    xml.AddChildElem( "day", Income_expense_date_separated.getDay());
                    xml.AddChildElem( "month", Income_expense_date_separated.getMonth());
                    xml.AddChildElem( "year", Income_expense_date_separated.getYear());
                    xml.AddChildElem( "amount", amount_to_save );
                    xml.OutOfElem();
                }
                xml.ResetPos();
                xml.Save( "C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_data_base\\incomes.xml" );
                xml.ResetMainPos();
                xml.RemoveElem();
        }
        else
        {
                cout << "pliku jeszcze nie ma" << endl;
                xml.AddElem("incomes");
                xml.AddChildElem( "id", user_id);
                xml.IntoElem();
                xml.AddChildElem( "count", 1 );
                xml.AddElem( "id", 1 );
                xml.AddChildElem( "title", title );
                xml.AddChildElem( "day", Income_expense_date_separated.getDay());
                xml.AddChildElem( "month", Income_expense_date_separated.getMonth());
                xml.AddChildElem( "year", Income_expense_date_separated.getYear());
                xml.AddChildElem( "amount", amount_to_save );
                xml.OutOfElem();
                xml.ResetPos();
                xml.Save( "C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_data_base\\incomes.xml" );
                xml.ResetMainPos();
                xml.RemoveElem();
        }

    }
    else
    {
        bSuccess = xml.Load("C:\\incomes\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_data_base\\expenses.xml");
        cout << xml.GetResult() << endl;
        cout << "bSuccess: " << bSuccess << endl;
        if(bSuccess == true)
        {
                cout << "plik JEST" << endl;
                xml.FindElem(); // main is TESTDOC, no child position
                xml.IntoElem();
            do
            {
                xml.FindElem();
                MCD_STR element_count = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                        cout << "trzy " << element_count << " cztery" << endl;
                        id = atoi(element_count.c_str());
                xml.FindElem();
                if(id == user_id)
                {
                    xml.FindElem();
                    xml.IntoElem();
                    xml.FindElem();
                    element_count = xml.GetData();
                    xml.SetData(id + 1);
                    xml.AddElem( "id", id + 1 );
                    xml.AddElem( "title", title );
                    //xml.AddElem( "date", date );
                    xml.AddElem( "day", Income_expense_date_separated.getDay());
                    xml.AddElem( "month", Income_expense_date_separated.getMonth());
                    xml.AddElem( "year", Income_expense_date_separated.getYear());
                    xml.AddElem( "amount", amount_to_save );
                    xml.OutOfElem();
                    check = 1;
                }
            }while(id != user_id);
            xml.ResetMainPos();
            if(check == 0)
            {
                xml.AddElem( "id", user_id);
                    //xml.ResetPos(); // no current position
                //xml.FindElem(); // main is TESTDOC, no child position
                //xml.IntoElem();
                xml.AddChildElem( "count", 1 );
                xml.AddElem( "id", 1 );
                xml.AddChildElem( "title", title );
                //xml.AddChildElem( "date", date );
                xml.AddChildElem( "day", Income_expense_date_separated.getDay());
                xml.AddChildElem( "month", Income_expense_date_separated.getMonth());
                xml.AddChildElem( "year", Income_expense_date_separated.getYear());
                xml.AddChildElem( "amount", amount_to_save );
                xml.OutOfElem();
            }
            xml.ResetPos();
                xml.Save( "C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_data_base\\expenses.xml" );
                xml.ResetMainPos();
                xml.RemoveElem();
        }
        else
        {
                cout << "pliku jeszcze nie ma" << endl;
                xml.AddElem("expenses");
                xml.AddChildElem( "id", user_id);
                xml.IntoElem();
                xml.AddChildElem( "count", 1 );
                xml.AddElem( "id", 1 );
                xml.AddChildElem( "title", title );
                xml.AddChildElem( "day", Income_expense_date_separated.getDay());
                xml.AddChildElem( "month", Income_expense_date_separated.getMonth());
                xml.AddChildElem( "year", Income_expense_date_separated.getYear());
                xml.AddChildElem( "amount", amount_to_save );
                xml.OutOfElem();
                xml.ResetPos();
                xml.Save( "C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_data_base\\expenses.xml" );
                xml.ResetMainPos();
                xml.RemoveElem();
        }
    }
}

vector <Income_expense> Income_expense_file::getIncomes_Expenses(int user_id, int kind_of_record, Auxiliary_date date_of_start, Auxiliary_date date_of_end)
{
    Income_expense Income_expense_object;
    vector <Income_expense> incomes_expenses;
    Auxiliary_date start_date, end_date;
    //start_date = Auxiliary_methods::create_date(date_of_start);
    //end_date = Auxiliary_methods::create_date(date_of_end);
    CMarkup xml;
    string data_to_insert;
    int check = 0, id = 0, i = 0, data_int = 0;
    double data_double = 0;
    bool bSuccess = false;

    bSuccess = xml.Load("C:\\incomes\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_data_base\\incomes.xml");
    cout << xml.GetResult() << endl;
    cout << "bSuccess: " << bSuccess << endl;
    if(bSuccess == true)
    {
        cout << "plik JEST" << endl;
        xml.FindElem(); // main is TESTDOC, no child position
        xml.IntoElem();
	    do
	    {
            xml.FindElem();
            MCD_STR element_count = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                    cout << "trzy " << element_count << " cztery" << endl;
                    id = atoi(element_count.c_str()) + 1;
            xml.FindElem();
            if(id == user_id)
            {
                xml.IntoElem();
                xml.FindElem();
                element_count = xml.GetData();
                i = 0;
                do
                {
                    xml.FindElem();
                    data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                    data_int = Auxiliary_methods::convert_string_to_int(data_to_insert);
                                Income_expense_object.setId(data_int);
                    xml.FindElem();
                    data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                                Income_expense_object.setTitle(data_to_insert);
                    //xml.FindElem();
                    //data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                    //data_int = data_to_insert;
                                //Income_expense_object.setDate(data_to_insert);
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
                        }
                        else if(Income_expense_object.getYear() == start_date.getYear())
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
                    else
                    {
                        check = 1;
                    }
                    if(check == 0)
                    {
                        incomes_expenses.push_back(Income_expense_object);
                    }
                    i++;
                }while(i < id);
            }
        }while(id != user_id);
        xml.OutOfElem();
	}
    return incomes_expenses;
}
