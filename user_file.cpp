#include "user_file.h"

using namespace std;

string name, surname, login, password;
bool bSuccess = true;

void User_file::registration()
{
    int id , check = 0;
    User_menager user_menager;
    cout << "podaj imie: ";
    cin >> name;
    cout << "podaj nazwisko: ";
    cin >> surname;
    do{
        if(check != 2)
        {
            cout << "podaj login: ";
            cin >> login;
            check = user_menager.check_if_login_exists(login);
            cout << "check " << check << endl;
        }
        if(check == 1)
        {
            cout << "podany login juz istnieje - wcisnij enter i podaj kolejna propozycje loginu" << endl;
        }
        else
        {
            check = 0;
            cout << "podaj haslo: ";
            cin >> password;
            check = user_menager.check_if_password_exists(password);
            if(check == 2)
            {
                cout << "podane haslo juz istnieje - wcisnij enter i podaj kolejna propozycje hasla" << endl;
                check = 2;
            }
            else
            {
                check = 0;
            }
        }
    }while(check != 0);
    CMarkup xml;
    bSuccess = xml.Load("C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\users.xml");
    if(bSuccess == true)
    {
            xml.FindElem();
            xml.IntoElem();
            xml.FindElem();
                MCD_STR element_count = xml.GetData();
                id = atoi(element_count.c_str()) + 1;
                xml.SetData(id);
            xml.AddElem( "user");
            xml.AddChildElem( "id", id );
            xml.AddChildElem( "login", login );
            xml.AddChildElem( "password", password );
            xml.AddChildElem( "name", name );
            xml.AddChildElem( "surname", surname );
            xml.OutOfElem();
            xml.ResetMainPos();
            xml.Save( "C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\users.xml" );
            xml.ResetMainPos();
            while ( xml.FindElem() )
                xml.RemoveElem();
    }
    else
    {
            id = 1;
            xml.AddElem( "users" );
            xml.AddChildElem( "count", id );
            xml.AddChildElem( "user");
            xml.FindElem();
            xml.IntoElem();
            xml.AddChildElem( "id", id);
            xml.AddChildElem( "login", login );
            xml.AddChildElem( "password", password );
            xml.AddChildElem( "name", name );
            xml.AddChildElem( "surname", surname );
            xml.OutOfElem();
            xml.ResetPos();
            xml.Save( "C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\users.xml" );
            xml.ResetMainPos();
            while ( xml.FindElem() )
                xml.RemoveElem();
    }
}

vector <User> User_file::getUsers()
{
    int id, user_id , count_index, check = 0;
    User user;
    vector <User> users;
     CMarkup xml;
    bSuccess = xml.Load("C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\users.xml");
    cout << xml.GetResult() << endl;
    if(bSuccess == true)
    {
            xml.FindElem();
            xml.IntoElem();
            xml.FindElem();
                MCD_STR element_count = xml.GetData();
                id = atoi(element_count.c_str()) + 1;
                count_index = 1;
            do{
                    xml.FindElem();
                    xml.IntoElem();
                    xml.FindElem();
                    MCD_STR data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                    user_id = atoi(data_to_insert.c_str());
                    user.setId(user_id);
                    xml.FindElem(); // main is TESTDOC, no child position
                    data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                    user.setLogin(data_to_insert);
                    xml.FindElem(); // main is TESTDOC, no child position
                    data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                    user.setPassword(data_to_insert);
                    xml.FindElem(); // main is TESTDOC, no child position
                    data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                    user.setName(data_to_insert);
                    xml.FindElem(); // main is TESTDOC, no child position
                    data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                    user.setSurname(data_to_insert);
                    users.push_back(user);
                xml.OutOfElem();
                count_index++;
            }while(id != count_index);
    }
    return users;
}
void User_file::change_password(int user_id)
{
    //xml.FindElem();
    //akcja = xml.GetData();
    //cout << "akcja: " << akcja << endl;
    int id , check = 0;
    User_menager user_menager;

    do{
            check = 0;
            cout << "podaj nowe haslo: ";
            cin >> password;
            check = user_menager.check_if_password_exists(password);
            if(check == 2)
            {
                cout << "podane haslo juz istnieje - wcisnij enter i podaj kolejna propozycje hasla" << endl;
                check = 2;
            }
            else
            {
                check = 0;
            }
    }while(check != 0);
    CMarkup xml;
    bSuccess = xml.Load("C:\\Users\\wojci\\Documents\\PACZKA_55\\PLUS\\financial_project\\users.xml");
    if(bSuccess == true)
    {
            xml.FindElem(); // main is TESTDOC, no child position
            xml.IntoElem();
            xml.FindElem();
                MCD_STR element_count = xml.GetData();
                id = atoi(element_count.c_str()) + 1;
            do{
                xml.FindElem(); // ewentualnie usun
                xml.IntoElem();
                    xml.FindElem(); // main is TESTDOC, no child position
                    xml.FindElem(); // main is TESTDOC, no child position
                    xml.FindElem(); // main is TESTDOC, no child position
                    MCD_STR data_to_insert = xml.GetData();// ODCZYTAÆ WARTOŒÆ COUNT
                    id = Auxiliary_methods::convert_string_to_int(data_to_insert);
                    if(id == user_id)
                    {
                        check = 1;
                    }
                    xml.FindElem();
                    xml.FindElem(); // main is TESTDOC, no child position
                    if(check == 1)
                    {
                        xml.SetData(password);
                    }
                    xml.FindElem();
                    xml.FindElem();
                xml.OutOfElem();
            }while(check != 1);
    }
}
