#ifndef NUMCOLUMN_HPP
#define NUMCOLUMN_HPP

#include <bits/stdc++.h>
#include "column.hpp"

class NumColumn : public Column{
    public:
        NumColumn(std::string name);
        NumColumn(std::string name, std::string type);
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

        //some num specific functions
        int getSum();
        int getMin();
        int getMax();
};


#endif