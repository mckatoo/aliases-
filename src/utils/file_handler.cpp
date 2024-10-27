#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "IFileHandler.h"
#include <fstream>
#include <sstream>
#include <sys/stat.h>

using namespace std;

class FileHandler : public IFileHandler {
private:
  fstream file;

public:
  bool open(const string &filename) override {
    file.open(filename, ios::in | ios::out);
    return file.is_open();
  }

  string read() override {
    if (!file.is_open()) {
      return "";
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
  }

  bool write(const string &data) override {
    if (!file.is_open()) {
      return false;
    }
    file << data;
    return true;
  }

  bool exists(const string &filename) const override {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
  }

  bool remove(const string &filename) override {
    return (std::remove(filename.c_str()) == 0);
  }
};

#endif
