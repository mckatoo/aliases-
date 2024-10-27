#ifndef __IFILE_HANDLER_H
#define __IFILE_HANDLER_H

#include <string>

using namespace std;

class IFileHandler {
public:
  virtual ~IFileHandler() = default;

  virtual bool open(const string &filename) = 0;
  virtual string read() = 0;
  virtual bool write(const string &data) = 0;
  virtual bool exists(const string &filename) const = 0;
  virtual bool remove(const string &filename) = 0;
};

#endif
