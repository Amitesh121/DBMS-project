#include <iostream>
#include "user.h"
#include "../dataBase.hpp"
#include "../mFile.hpp"

void User::displayMenu() {
    std::cout << "\nWelcome to our DB\n";
    std::cout << "1. Create Database\n";
    std::cout << "2. Delete Database\n";
    std::cout << "3. Create Table\n";
    std::cout << "4. Delete Table\n";
    std::cout << "5. View Databases\n";
    std::cout << "6. View Tables\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

void User::handleUserInput() {
    //std::cout<<"USER INPUT LOADING";
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            createDatabase();
            break;
        case 2:
            deleteDatabase();
            break;
        case 3:
            createTable();
            break;
        case 4:
            deleteTable();
            break;
        case 5:
            viewDatabases();
            break;
        case 6:
            viewTables();
            break;
        case 7:
            std::cout << "Exiting the program.\n";
            break;
            case 8:
            saveDatabase();
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

void User::createDatabase() {
    std::string dbName;
    std::cout << "Enter database name: ";
    std::cin >> dbName;
    for (Database* db : databases) {
        if (db->getName() == dbName) {
            std::cout << "Database already exists.\n";
            return;
        }
    }
    Database* db = new Database(dbName);
    db->saveDatabase(); 
    databases.push_back(db);
    std::cout << "Database created successfully.\n";
}

void User::deleteDatabase() {
    std::string dbName;
    std::cout << "Enter database name to delete: ";
    std::cin >> dbName;
    for (auto it = databases.begin(); it != databases.end(); ++it) {
        if ((*it)->getName() == dbName) {
            (*it)->saveDatabase(); 
            delete *it;
            databases.erase(it);
            std::cout << "Database deleted successfully.\n";
            return;
        }
    }
    std::cout << "Database not found.\n";
}

void User::createTable() {
    std::string dbName, tableName;
    std::cout << "Enter database name: ";
    std::cin >> dbName;
    for (Database* db : databases) {
        if (db->getName() == dbName) {
            std::cout << "Enter table name: ";
            std::cin >> tableName;
            if (db->addTable(tableName)) {
                std::cout << "Table created successfully.\n";
            } else {
                std::cout << "Table already exists.\n";
            }
            return;
        }
    }
    std::cout << "Database not found.\n";
}

void User::deleteTable() {
    std::string dbName, tableName;
    std::cout << "Enter database name: ";
    std::cin >> dbName;
    for (Database* db : databases) {
        if (db->getName() == dbName) {
            std::cout << "Enter table name to delete: ";
            std::cin >> tableName;
            if (db->removeTable(tableName)) {
                std::cout << "Table deleted successfully.\n";
            } else {
                std::cout << "Table not found.\n";
            }
            return;
        }
    }
    std::cout << "Database not found.\n";
}

void User::viewDatabases() {
    std::cout << "Databases:\n";
    for (Database* db : databases) {
        std::cout << "- " << db->getName() << "\n";
    }
}

void User::viewTables() {
    std::string dbName;
    std::cout << "Enter database name: ";
    std::cin >> dbName;
    for (Database* db : databases) {
        if (db->getName() == dbName) {
            std::cout << "Tables in " << dbName << ":\n";
            for (auto& table : db->getTablesNameList()) {
                std::cout << "- " << table.first << "\n";
            }
            return;
        }
    }
    std::cout << "Database not found.\n";
}

void User::loadDatabase() {
    MFile file("databases_list.csv");
    if (MFile::fileExists(file.getFilePath())) {
        std::vector<std::string> lines = file.readAllLines();
        for (const std::string& dbName : lines) {
            Database* db = new Database(dbName);
            db->loadDatabase(); 
            databases.push_back(db);
        }
    }
}

void User::saveDatabase() {
    MFile file("databases_list.csv");
    std::vector<std::string> dbNames;
    for (Database* db : databases) {
        db->saveDatabase(); 
        dbNames.push_back(db->getName());
    }
    file.overwriteFile(dbNames);
}