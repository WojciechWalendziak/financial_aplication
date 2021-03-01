#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iostream>
#include "auxiliary_date.h"
#include "income_expense_file.h"
#include "balance.h"
#include "user_file.h"
#include "user_menager.h"

class Menu
{
    //Auxiliary_date * date_start;
    //Auxiliary_date * date_end;

 public:
     Menu();
    ~Menu();
     void choose_action();
};
#endif
