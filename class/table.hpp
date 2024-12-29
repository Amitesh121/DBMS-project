#ifndef TABLE_HPP
#define TABLE_HPP
//Table class
#include <bits/stdc++.h>
#include "column.hpp"

class Table{
    private:
        std::string name;
        std::vector<Column*> columns;
    public:
        Table(std::string name);
        bool setName(std::string name);
        std::string getName();
        int getNoOfColumns();
        std::vector<std::pair<std::string, Column*>> getColumnsNameList();
        bool addColumn(std::string columnName);
        bool removeColumn(std::string columnName);
        bool addRow(std::vector<std::string> data);

        //function for loading data
        void loadTable();
        void saveTable();
};


#endif