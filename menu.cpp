#include "menu.h"

void Menu::choose_action()
{
    int id = 1, count_index = 1, income_id = 0, choose = 0, user_id = 0, number_of_days = 0;
    bool bSuccess = true;
    string data_to_insert;
    Income_expense_file income_expense_file;
    Balance balance;
    User_file user_file;
    User_menager user_menager;

    Auxiliary_date date_start;
    Auxiliary_date date_end;

    cout << "wybierz jedno z ponizszych: " << endl;
    cout << " " << endl;
    cout << "Rejestarcja - wpisz cyfre 1" << endl;
    cout << "Logowanie - wpisz cyfre 2" << endl;
    cin >> choose;
    cout << "wybrales " << choose << endl;
    switch (choose)
    {
        case 1:
            user_file.registration();
            break;
        case 2:
            user_id = user_menager.log_user();
            while(user_id != 0)
            {
                cout << "wybierz jedno z ponizszych: " << endl;
                cout << " " << endl;
                cout << "Dodaj przychod - wpisz cyfre 1" << endl;
                cout << "Dodaj wydatek - wpisz cyfre 2" << endl;
                cout << "Bilans z biezacego meisiaca - wpisz cyfre 3" << endl;
                cout << "Bilans z poprzedniego miesiaca - wpisz cyfre 4" << endl;
                cout << "Bilans za wybrany okres - wpisz cyfre 5" << endl;
                cout << "Zmien haslo - wpisz cyfre 6" << endl;
                cout << "Wyloguj sie - wpisz cyfre 7" << endl;
                cin >> choose;
                switch (choose)
                {
                    case 1:
                        {
                            income_expense_file.save_new_Income_expense(user_id, 1);
                            break;
                        }
                    case 2:
                        {
                            income_expense_file.save_new_Income_expense(user_id, 2);
                            break;
                        }
                    case 3:
                        {
                            date_end = Auxiliary_methods::current_date();
                            date_start.setYear(date_end.getYear());
                            date_start.setMonth(date_end.getMonth());
                            date_start.setDay(1);
                            balance.show_balance(user_id, date_start, date_end);
                        break;
                        }
                    case 4:
                        {
                            date_end = Auxiliary_methods::current_date();
                            if (date_end.getMonth() != 1)
                            {
                                number_of_days = Auxiliary_methods::check_month_length(date_end.getMonth() - 1, date_end.getYear());
                            }
                            else
                            {
                                number_of_days = 31;
                            }
                            date_end.setDay(number_of_days);
                            date_start.setYear(date_end.getYear());
                            if (date_end.getMonth() != 1)
                            {
                                date_start.setMonth(date_end.getMonth() - 1);
                                date_end.setMonth(date_end.getMonth() - 1);
                            }
                            else
                            {
                                date_start.setMonth(12);
                                date_start.setYear(date_end.getYear() - 1);
                                date_end.setMonth(12);
                                date_end.setYear(date_end.getYear() - 1);
                            }
                            date_start.setDay(1);
                            balance.show_balance(user_id, date_start, date_end);
                            break;
                        }
                    case 5:
                        {
                            int check = 0;
                            string date;
                            while (check == 0)
                            {
                                cout << "podaj date poczatkowa (w formacie yyyy-mm-dd) : " << endl;
                                cin >> date;
                                if(Auxiliary_methods::check_date(date) == true)
                                {
                                    check = 1;
                                }
                                else
                                {
                                    check = 0;
                                }
                            }
                            date_start = Auxiliary_methods::create_date(date);
                            check = 0;
                            while (check == 0)
                            {
                                cout << "podaj date koncowa (w formacie yyyy-mm-dd) : " << endl;
                                cin >> date;
                                if(Auxiliary_methods::check_date(date) == true)
                                {
                                    check = 1;
                                }
                                else
                                {
                                    check = 0;
                                }
                            }
                            date_end = Auxiliary_methods::create_date(date);
                            balance.show_balance(user_id, date_start, date_end);
                            break;
                        }
                    case 6:
                        {
                            user_file.change_password(user_id);
                            break;
                        }
                     case 7:
                         {
                            user_id = 0;
                            break;
                         }
            }
        }
        break;
        default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
    }
}
