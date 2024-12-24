#ifndef COLUMN_HPP
#define COLUMN_HPP
//Column class

#include <bits/stdc++.h>

class Column{
    private:
        std::string name;
        std::string type;
        std::string parentTable;
        std::vector<std::string> data;
    public:
        Column(std::string name);
        bool setName(std::string name);
        std::string getName();
        int getNoOfData();
        std::vector<std::string> getData();
        bool addData(std::string data);
        bool removeData(std::string data);
};


#endif