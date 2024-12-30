#ifndef USER_H
#define USER_H

#include "../dataBase.hpp"
#include <vector>

class User {
public:
    void displayMenu();
    void handleUserInput();
    void createDatabase();
    void deleteDatabase();
    void createTable();
    void deleteTable();
    void viewDatabases();
    void viewTables();
    void saveDatabase();
    void loadDatabase();

    std::vector<Database*> databases;
};

#endif
