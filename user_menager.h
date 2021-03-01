#ifndef USER_MENAGER_H
#define USER_MENAGER_H

#include<fstream>
#include<cstdlib>

#include "Markup.h"
#include "user.h"
#include "user_file.h"

using namespace std;

class User_menager
{
    //int id;
    //string login;
    //string password;
    //string name;
    //string surname;

public:

    int check_if_login_exists(string login_to_check);
    int check_if_password_exists(string password_to_check);
    int log_user();

};
#endif
