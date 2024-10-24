#ifndef __FILE_READER_H
#define __FILE_READER_H

#include "i_file_reader.h"
#include <fstream>
#include <sstream>

class FileReader : public IFileReader {
private:
    std::ifstream file;
public:
    bool open(const std::string& filename) override {
        file.open(filename);
        return file.is_open();
    }

    std::string read() override {
        if (!file.is_open()) {
            return "";
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
};

#endif // FILE_READER_H
