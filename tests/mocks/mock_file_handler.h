#ifndef __MOCK_FILE_HANDLER_H
#define __MOCK_FILE_HANDLER_H

#include "IFileHandler.h"
#include <gmock/gmock.h>

class MockFileHandler : public IFileHandler {
public:
  MOCK_METHOD(bool, open, (const std::string &filename), (override));
  MOCK_METHOD(std::string, read, (), (override));
  MOCK_METHOD(bool, write, (const std::string &data), (override));
  MOCK_METHOD(bool, exists, (const std::string &filename), (const, override));
  MOCK_METHOD(bool, remove, (const std::string &filename), (override));
};

#endif
