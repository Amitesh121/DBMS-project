#include "mFile.hpp"
#include <sstream>
#include <filesystem>


MFile::MFile(const std::string& path) : filePath(path) {}


bool MFile::openFile(std::ios::openmode mode) {
    fileStream.open(filePath, mode);
    return fileStream.is_open();
}


void MFile::closeFile() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}


std::vector<std::string> MFile::readAllLines() {
    std::vector<std::string> lines;
    if (openFile(std::ios::in)) {
        std::string line;
        while (std::getline(fileStream, line)) {
            lines.push_back(line);
        }
        closeFile();
    }
    return lines;
}


void MFile::writeLine(const std::string& line) {
    if (openFile(std::ios::app)) { 
        fileStream << line << "\n";
        closeFile();
    }
}


void MFile::overwriteFile(const std::vector<std::string>& lines) {
    if (openFile(std::ios::out | std::ios::trunc)) { 
        for (const std::string& line : lines) {
            fileStream << line << "\n";
        }
        closeFile();
    }
}


void MFile::appendRow(const std::vector<std::string>& row) {
    std::ostringstream oss;
    for (size_t i = 0; i < row.size(); ++i) {
        oss << row[i];
        if (i < row.size() - 1) oss << ",";
    }
    writeLine(oss.str());
}


void MFile::editCell(int rowIndex, int colIndex, const std::string& newValue) {
    std::vector<std::string> lines = readAllLines();

    if (rowIndex < 0 || rowIndex >= static_cast<int>(lines.size())) {
        std::cerr << "Error: Invalid row index.\n";
        return;
    }

    std::istringstream iss(lines[rowIndex]);
    std::vector<std::string> cells;
    std::string cell;

    while (std::getline(iss, cell, ',')) {
        cells.push_back(cell);
    }

    if (colIndex < 0 || colIndex >= static_cast<int>(cells.size())) {
        std::cerr << "Error: Invalid column index.\n";
        return;
    }

    cells[colIndex] = newValue;

    std::ostringstream updatedRow;
    for (size_t i = 0; i < cells.size(); ++i) {
        updatedRow << cells[i];
        if (i < cells.size() - 1) updatedRow << ",";
    }

    lines[rowIndex] = updatedRow.str();
    overwriteFile(lines);
}

bool MFile::fileExists(const std::string& path) {
    return std::filesystem::exists(path);
}

std::string MFile::getFilePath() const {
    return filePath;
}

MFile::~MFile() {
    closeFile();
}
