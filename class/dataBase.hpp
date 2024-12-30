#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <bits/stdc++.h>
#include "table.hpp"

//Database class
class Database{
    private:
        std::string name;
        std::vector<Table*> tables;
        
    public:
        Database(std::string name);
        bool setName(std::string name);
        std::string getName();
        int getNoOfTables();
        std::vector<std::pair<std::string, Table*>> getTablesNameList();
        bool addTable(std::string tableName);
        bool removeTable(std::string tableName);
        void loadDatabase();
        void saveDatabase();
};

#endif // DATABASE_HPP