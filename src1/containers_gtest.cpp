// Copyright 2022 nolanhea
#include "sequence_container.h"
#include "gtest/gtest.h"
#include <list>
namespace my {
namespace project {
namespace {

// The fixture for testing class Foo.
class ContainersTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  ContainersTest() {
     // You can do set-up work for each test here.
  }

  ~ContainersTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
};
// Tests that the Foo::Bar() method does Abc.
TEST_F(ContainersTest, constructors_0) {
    std::list<int> original(10);
    s21::list<int> my(10);
    auto my_iterator = my.begin();
    for (auto i:original) {
       EXPECT_EQ(i, *my_iterator);
       my_iterator++;
    }
}
TEST_F(ContainersTest, constructors_1) {
    std::list<int> original({1, 2, 3, 4, 5});
    s21::list<int> my({1, 2, 3, 4, 5});
    auto my_iterator = my.begin();
    for (auto i:original) {
       EXPECT_EQ(i, *my_iterator);
       my_iterator++;
    }
}
TEST_F(ContainersTest, Size_0) {
    // Creating list from std library and inserting 3 values:
    std::list<int> original;
    EXPECT_EQ(original.size(), 0);
    EXPECT_EQ(original.empty(), 1);
    original.insert(original.begin(), 3);
    original.insert(original.begin(), 2);
    original.insert(original.begin(), 1);
    EXPECT_EQ(original.size(), 3);
    original.erase(original.begin());
    EXPECT_EQ(original.size(), 2);
    EXPECT_EQ(original.empty(), 0);
}
TEST_F(ContainersTest, ListInsert_0) {
    // Creating list from std library and inserting 3 values:
    std::list<int> original;
    original.insert(original.begin(), 3);
    original.insert(original.begin(), 2);
    original.insert(original.begin(), 1);
    // Creating list from s21 namespace and inserting 3 values, identical to previous:
    s21::list<int> my;
    my.insert(my.begin(), 3);
    my.insert(my.begin(), 2);
    my.insert(my.begin(), 1);
    // Expecting created lists from std and s21 namespaces to hold similar values:
    auto original_iterator = original.begin();
    auto my_iterator = my.begin();
    EXPECT_EQ(*(original_iterator++), *(my_iterator++));
    EXPECT_EQ(*(original_iterator++), *(my_iterator++));
    EXPECT_EQ(*(original_iterator), *(my_iterator));
}
TEST_F(ContainersTest, ListErase_0) {
    // Creating list from std library and inserting 3 values:
    std::list<char> original;
    original.insert(original.begin(), 'a');
    original.insert(original.begin(), 'b');
    original.insert(++original.begin(), 'd');
    original.insert(original.begin(), 'c');
    original.insert(original.end(), 'e');
    original.insert(--original.end(), 'f');
    
    original.erase(--original.end());
    original.erase(original.begin());
    original.erase(--original.end());
    // Creating list from s21 namespace and inserting 3 values, identical to previous:
    s21::list<char> my;
    my.insert(my.begin(), 'a');
    my.insert(my.begin(), 'b');
    my.insert(++my.begin(), 'd');
    my.insert(my.begin(), 'c');
    my.insert(my.end(), 'e');
    my.insert(--my.end(), 'f');
    
    my.erase(--my.end());
    my.erase(my.begin());
    my.erase(--my.end());
    // Expecting created lists from std and s21 namespaces to hold similar values:
    auto original_iterator = original.begin();
    auto my_iterator = my.begin();
    for (auto i:original) {
       EXPECT_EQ(i, *my_iterator);
       my_iterator++;
    }
}
TEST_F(ContainersTest, PushPop_0) {
    std::list<char> original;
    original.push_back('a');
    original.push_front('b');
    original.push_back('c');
    original.push_front('d');
    s21::list<char> my;
    my.push_back('a');
    my.push_front('b');
    my.push_back('c');
    my.push_front('d');
    auto original_iterator = original.begin();
    auto my_iterator = my.begin();
    for (auto i:original) {
       EXPECT_EQ(i, *my_iterator);
       my_iterator++;
    }
    original.pop_back();
    original.pop_front();
    my.pop_back();
    my.pop_front();
    my_iterator = my.begin();
   for (auto i:original) {
       EXPECT_EQ(i, *my_iterator);
       my_iterator++;
    }
}
// c c
// b b
// d a
// a e
// e trash

}  // namespace
}  // namespace project
}  // namespace my

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
