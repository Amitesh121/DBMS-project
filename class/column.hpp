#ifndef COLUMN_HPP
#define COLUMN_HPP
//Column class

#include <bits/stdc++.h>

class Column{
    protected:
        std::string name;
        std::string type;
        std::string parentTable;
        std::vector<std::string> data;
        void loadColumn(); //not implemented yet
        void saveColumn(); //not implemented yet
    public:
        Column(std::string name);
        Column(std::string name, std::string type);
        bool setName(std::string name);
        std::string getName();
        int getNoOfData();
        std::vector<std::string> getData();
        bool addData(std::string data);
        bool removeData(std::string data);
};


#endif