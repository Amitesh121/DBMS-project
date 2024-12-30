#ifndef MFILE_HPP
#define MFILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class MFile {
private:
    std::string filePath;
    std::fstream fileStream;

public:

    MFile(const std::string& path);

    
    bool openFile(std::ios::openmode mode);
    void closeFile();

   
    std::vector<std::string> readAllLines();
    void writeLine(const std::string& line);
    void overwriteFile(const std::vector<std::string>& lines);

    
    void appendRow(const std::vector<std::string>& row);
    void editCell(int rowIndex, int colIndex, const std::string& newValue);

   
    static bool fileExists(const std::string& path);

    
    std::string getFilePath() const;

   
    ~MFile();
};

#endif // MFILE_HPP
