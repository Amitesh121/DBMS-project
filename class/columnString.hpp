#ifndef STRINGCOLUMN_HPP
#define STRINGCOLUMN_HPP
//Column class with type string

#include <bits/stdc++.h>
#include "column.hpp"

class StringColumn : public Column{
    public:
        StringColumn(std::string name);
        StringColumn(std::string name, std::string type);
        bool addData(std::string data);
        bool removeData(std::string data);
        std::vector<std::string> getData();
        int getNoOfData();
        std::string getName();
        bool setName(std::string name);
        std::string getType();
        bool setType(std::string type);
        std::string getParentTable();
        bool setParentTable(std::string parentTable);
        void loadColumn();
        void saveColumn();
};

#endif