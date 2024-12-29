#include "dataBase.hpp"
#include "table.hpp"
#include <bits/stdc++.h> 


Database::Database(std:: string name){
    this->name = name;
}

bool Database::addTable(std::string name){
    for(Table* table : tables){
        if(table->getName() == name){
            return false;
        }
    }
    Table* table = new Table(name);
    tables.push_back(table);
    return true;
}

bool Database::removeTable(std::string name){ //bugs fixed here
    for(int i = 0; i < tables.size(); i++){
        if(tables[i]->getName() == name){
            delete tables[i];
            tables.erase(tables.begin() + i);
            return true;
        }
    }
    return false;
}

std::vector<std::pair<std::string, Table*>> Database::getTablesNameList(){
    std::vector<std::pair<std::string, Table*>> tablesNameList;
    for(Table* table : tables){
        tablesNameList.push_back(std::make_pair(table->getName(), table));
    }
    return tablesNameList;
}

int Database::getNoOfTables(){
    return tables.size();
}

std::string Database::getName(){
    return name;
}