#ifndef __I_FILE_READER_H
#define __I_FILE_READER_H

#include <string>

using namespace std;

class IFileReader {
public:
  virtual ~IFileReader() = default;
  virtual bool open(const string &filename) = 0;
  virtual string read() = 0;
};

#endif
