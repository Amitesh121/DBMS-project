#include <bits/stdc++.h>
#include "column.hpp"

Column::Column(std::string name){
    this->name = name;
}

Column::Column(std::string name, std::string type){
    this->name = name;
    this->type = type;
}

bool Column::setName(std::string name){
    this->name = name;
    return true;
}

std::string Column::getName(){
    return name;
}

int Column::getNoOfData(){
    return data.size();
}

std::vector<std::string> Column::getData(){
    return data;
}

bool Column::addData(std::string data){
    this->data.push_back(data);
    return true;
}

bool Column::removeData(std::string data){ //bugs fixed here
    for(int i = 0; i < this->data.size(); i++){
        if(this->data[i] == data){
            this->data.erase(this->data.begin() + i);
            return true;
        }
    }
    std::cout << "Data not found" << std::endl;
    return false;
}