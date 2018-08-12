#include "list.h"

#include <gtest/gtest.h>

class TestList : public ::testing::Test {
 public:
  TestList() {
    // runs before each unit test
    list = new List();
  }

  ~TestList() {
    // runs after each unit test completes
    delete list;
  }

 protected:
  List* list;
};

TEST_F(TestList, TestAdd) {
  ASSERT_EQ(0, list->count());
  list->add(1);
  ASSERT_EQ(1, list->count());
  list->add(2);
  ASSERT_EQ(2, list->count());
}

TEST_F(TestList, TestRemove) {
  list->add(1);
  ASSERT_EQ(1, list->count());
  list->remove(0);
  ASSERT_EQ(0, list->count());
}

TEST_F(TestList, TestGet) {
  list->add(1);
  list->add(2);

  ASSERT_EQ(2, list->count());
  EXPECT_EQ(1, list->get(0));
  EXPECT_EQ(2, list->get(1));
}
