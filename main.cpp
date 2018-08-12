#include <gtest/gtest.h>

int main(int argc, char** argv) {
  // this will discover all linked tests and run them
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
