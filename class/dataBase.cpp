#include "dataBase.hpp"
#include <bits/stdc++.h>

Database::Database(std:: string name){
    this->name = name;
}

bool Database::addTable(std::string name){
    tables.push_back(name);
    return true;
}

bool Database::removeTable(std::string name){
    for(std::string table : tables){
        if(table == name){
            tables.erase(std::remove(tables.begin(), tables.end(), name), tables.end());
            return true;
        }
    }
    return false;
}

std::vector<std::string> Database::getTables(){
    return tables;
}

int Database::getNoOfTables(){
    return tables.size();
}