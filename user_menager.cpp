#include "user_menager.h"

using namespace std;

int User_menager::check_if_login_exists(string login_to_check)
{
    int answer = 0;
    vector <User> users;
    User_file userFile;
    string login = "", password = "";

    users = userFile.getUsers();

    vector <User>::iterator itr = users.begin();
    while (itr < users.end())
    {
        if (itr -> getLogin() == login_to_check)
        {
            answer = 1;
            itr = users.end();
            cout << "Jest juz User z takim loginem" << endl << endl;
        }
        itr++;
    }
    return answer;
}
int User_menager::check_if_password_exists(string password_to_check)
{
    int answer = 0;
    User_file userFile;
    vector <User> users;

    users = userFile.getUsers();
    vector <User>::iterator itr = users.begin();
    while (itr < users.end())
    {
        if (itr -> getPassword() == password_to_check)
        {
            answer = 2;
            itr = users.end();
            cout << "Jest juz User z takim haslem" << endl << endl;
        }
        itr++;
    }
    return answer;
}
int User_menager::log_user()
{
    bool check = true;
    int user_id = 0;
    vector <User> users;
    User_file userFile;
    string login = "", password = "", login2 = "", password2 = "";

    users = userFile.getUsers();
    cout << endl << "Podaj login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            check = true;
            for (int attempt_number = 3; attempt_number > 0; attempt_number--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attempt_number << ": ";
                cin >> password;

                if (itr -> getPassword() == password)
                {
                    user_id  = itr -> getId();
                    check = true;
                    attempt_number = 0;
                    itr = users.end() - 1;
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                }
                else
                {
                    check = false;
                }
            }
            if(check == false)
            {
                cout << "Wprowadzono 3 razy bledne password." << endl;
                system("pause");
            }
        }
        else
        {
            check = false;
        }
        itr++;
    }
    if(check == false)
    {
        cout << "Nie ma Usera z takim loginem" << endl << endl;
        system("pause");
    }
    return user_id;
}
