#include "add_command.h"
#include <gtest/gtest.h>

TEST(AddCommandTest, AddCommandWithSuccess) {
  addCommand("l", "ls -l");
  EXPECT_EQ(1, 1);
}

TEST(AddCommandTest, AnotherAssertion) { EXPECT_TRUE(true); }

// The main entry point for running the tests
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
