#include "mocks/mock_file_reader.h"
#include <gtest/gtest.h>

using ::testing::Return;

TEST(FileReaderTest, ReadFromMockFile) {
    MockFileReader mockFileReader;

    // Simular comportamento do método open
    EXPECT_CALL(mockFileReader, open("testfile.txt"))
        .WillOnce(Return(true));

    // Simular o conteúdo do arquivo
    EXPECT_CALL(mockFileReader, read())
        .WillOnce(Return("This is a mock file content"));

    // Testando o comportamento com mock
    ASSERT_TRUE(mockFileReader.open("testfile.txt"));
    std::string content = mockFileReader.read();
    EXPECT_EQ(content, "This is a mock file content");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
