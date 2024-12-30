#include "table.hpp"
#include "mFile.hpp"

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

bool Table::addRow(std::vector<std::string> data) { //bugs fixed here
    if(data.size() != columns.size()){
        std::cout << "Data size does not match with the number of columns" << std::endl;
        return false;
    }
    for(int i = 0; i < columns.size(); i++){
        columns[i]->addData(data[i]);
    }
    return true;
}

void Table::loadTable() {
    MFile file(name + ".csv");
    if (MFile::fileExists(file.getFilePath())) {
        std::vector<std::string> lines = file.readAllLines();
        for (const std::string& line : lines) {
            std::istringstream iss(line);
            std::vector<std::string> row;
            std::string cell;
            while (std::getline(iss, cell, ',')) {
                row.push_back(cell);
            }
            addRow(row);
        }
    }
}

void Table::saveTable() {
    MFile file(name + ".csv");
    std::vector<std::string> lines;
    for (int i = 0; i < columns[0]->getNoOfData(); ++i) {
        std::ostringstream oss;
        for (size_t j = 0; j < columns.size(); ++j) {
            oss << columns[j]->getData()[i];
            if (j < columns.size() - 1) oss << ",";
        }
        lines.push_back(oss.str());
    }
    file.overwriteFile(lines);
}