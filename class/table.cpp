#include "table.hpp"

Table::Table(std::string name) {
    this->name = name;
}

bool Table::setName(std::string name) {
    this->name = name;
    return true;
}

std::string Table::getName() {
    return this->name;
}

int Table::getNoOfColumns() {
    return columns.size();
}

std::vector<std::pair<std::string, Column*>> Table::getColumnsNameList() {
    std::vector<std::pair<std::string, Column*>> columnsNameList;
    for (Column* column : columns) {
        columnsNameList.push_back(std::make_pair(column->getName(), column));
    }
    return columnsNameList;
}

bool Table::addColumn(std::string columnName) {
    for (Column* column : columns) {
        if (column->getName() == columnName) {
            return false;
        }
    }
    Column* column = new Column(columnName);
    columns.push_back(column);
    return true;
}

bool Table::removeColumn(std::string columnName) {
    for (auto it = columns.begin(); it != columns.end(); ++it) {
        if ((*it)->getName() == columnName) {
            delete *it;
            columns.erase(it);
            return true;
        }
    }
    return false;
}