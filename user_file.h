#ifndef USER_FILE_H
#define USER_FILE_H

#include <iostream>
#include <vector>
#include<fstream>
#include<cstdlib>
#include <string>

#include "auxiliary_methods.h"
#include "Markup.h"
#include "user_menager.h"

using namespace std;

class User_file
{
    //int id;
    //string login;
    //string password;
    //string name;
    //string surname;

public:

    void registration();
    vector <User> getUsers();
    void change_password(int user_id);
    double calculate_summary(int user_id, int kind_of_record, string start_date, string end_date);

};
#endif
