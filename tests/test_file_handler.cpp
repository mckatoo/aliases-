#include "mocks/mock_file_handler.h"
#include <gtest/gtest.h>

using ::testing::Return;

TEST(FileHandlerTest, WriteToMockFile) {
  MockFileHandler mockFileHandler;

  EXPECT_CALL(mockFileHandler, open("testfile.txt")).WillOnce(Return(true));

  EXPECT_CALL(mockFileHandler, write("This is test data"))
      .WillOnce(Return(true));

  ASSERT_TRUE(mockFileHandler.open("testfile.txt"));
  EXPECT_TRUE(mockFileHandler.write("This is test data"));
}

TEST(FileHandlerTest, CheckFileExistence) {
  MockFileHandler mockFileHandler;

  EXPECT_CALL(mockFileHandler, exists("existingfile.txt"))
      .WillOnce(Return(true));

  EXPECT_TRUE(mockFileHandler.exists("existingfile.txt"));
}

TEST(FileHandlerTest, RemoveFile) {
    MockFileHandler mockFileHandler;

    EXPECT_CALL(mockFileHandler, remove("filetoremove.txt"))
        .WillOnce(Return(true));

    EXPECT_TRUE(mockFileHandler.remove("filetoremove.txt"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
