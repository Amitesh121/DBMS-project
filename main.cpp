#include "./class/user/user.h"
#include "./class/dataBase.hpp"
#include "./class/table.hpp"
#include "./class/column.hpp"
#include "./class/mFile.hpp"

#include <iostream>

int main() {
    User user;
    for (Database* db : user.databases) {
        db->loadDatabase();
    }
   // std::cout<<"Usermenu is loading";
    user.handleUserInput();
    for (Database* db : user.databases) {
        db->saveDatabase();
    }
    return 0;
}
