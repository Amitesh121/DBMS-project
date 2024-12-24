#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <bits/stdc++.h>

//Database class
class Database{
    private:
        std::string name;
        std::vector<std::string> tables;
    public:
        Database(std::string name);
        bool setName(std::string name);
        std::string getName();
        int getNoOfTables();
        std::vector<std::string> getTables();
        bool addTable(std::string tableName);
        bool removeTable(std::string tableName);
};

#endif // DATABASE_HPP