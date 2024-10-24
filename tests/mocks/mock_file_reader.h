#ifndef MOCK_FILE_READER_H
#define MOCK_FILE_READER_H

#include "i_file_reader.h"
#include <gmock/gmock.h>

class MockFileReader : public IFileReader {
public:
    MOCK_METHOD(bool, open, (const std::string& filename), (override));
    MOCK_METHOD(std::string, read, (), (override));
};

#endif
