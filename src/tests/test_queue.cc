#include <queue>

#include "test_containers.h"

TEST(QUEUE, default_constructor_test_1) {
  ns::queue<int> a;
  EXPECT_EQ(a.size(), 0U);
  EXPECT_TRUE(a.empty());
}

TEST(QUEUE, init_list_constructor_test_2) {
  ns::queue<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(a.size(), 9U);
  EXPECT_EQ(a.front(), 1);
}

TEST(QUEUE, move_constructor_test_3) {
  ns::queue<int> a;  //{1,2,3,4,5,6,7,8,9};
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(8);
  a.push(9);
  EXPECT_EQ(a.size(), 9U);
  ns::queue<int> b(std::move(a));
  EXPECT_EQ(a.size(), 0U);
  EXPECT_EQ(b.size(), 9U);
  EXPECT_EQ(b.back(), 9);
  EXPECT_EQ(b.front(), 1);
}

TEST(QUEUE, copy_constructor_test_4) {
  ns::queue<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(8);
  a.push(9);
  EXPECT_EQ(a.size(), 9U);
  ns::queue<int> b(a);
  EXPECT_EQ(a.size(), 9U);
  EXPECT_EQ(b.size(), 9U);
  EXPECT_EQ(b.back(), 9);
  EXPECT_EQ(b.front(), 1);
  EXPECT_EQ(a.back(), 9);
  EXPECT_EQ(a.front(), 1);
}

TEST(QUEUE, move_operator_eq_test_5) {
  ns::queue<int> a;  //{1,2,3,4,5,6,7,8,9};
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(8);
  a.push(9);
  EXPECT_EQ(a.size(), 9U);
  ns::queue<int> b;
  b = std::move(a);
  EXPECT_EQ(a.size(), 0U);
  EXPECT_EQ(b.size(), 9U);
  EXPECT_EQ(b.back(), 9);
  EXPECT_EQ(b.front(), 1);
}

TEST(QUEUE, copy_operator_eq_test_6) {
  ns::queue<int> a;  //{1,2,3,4,5,6,7,8,9};
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(8);
  a.push(9);
  EXPECT_EQ(a.size(), 9U);
  EXPECT_EQ(a.size(), 9U);
  ns::queue<int> b;
  b = a;
  EXPECT_EQ(a.size(), 9U);
  EXPECT_EQ(b.size(), 9U);
  EXPECT_EQ(b.back(), 9);
  EXPECT_EQ(b.front(), 1);
  EXPECT_EQ(a.back(), 9);
  EXPECT_EQ(a.front(), 1);
}

TEST(QUEUE, front_test_7) {
  ns::queue<int> a;  //{1,2,3,4,5,6,7,8,9};
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(8);
  a.push(9);
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.back(), 9);
}

TEST(QUEUE, push_test_8) {
  ns::queue<std::string> a;  //{1,2,3,4,5,6,7,8,9};
  a.push("To be,");
  a.push("or not");
  a.push("to be:");
  a.push("that is the");
  a.push("question:");
  a.push("Whether");
  a.push("tis nobler");
  a.push("in the");
  a.push("mind to suffer");
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.front(), "To be,");
  EXPECT_EQ(a.back(), "mind to suffer");
}

TEST(QUEUE, push_test_9) {
  ns::queue<double> a;  //{1,2,3,4,5,6,7,8,9};
  a.push(0.000005);
  a.push(99.001);
  a.push(673.0045);
  a.push(-456.10004);
  a.push(0.9999999901);
  a.push(9999.456);
  a.push(7.775);
  a.push(1.1);
  a.push(22.19);
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.front(), 0.000005);
  EXPECT_EQ(a.back(), 22.19);
}

TEST(QUEUE, swap_test_7) {
  ns::queue<std::string> a;
  a.push("To be,");
  a.push("or not");
  a.push("to be:");
  a.push("that is the");
  a.push("question:");
  a.push("Whether");
  a.push("tis nobler");
  a.push("in the");
  a.push("mind to suffer");
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.front(), "To be,");
  ns::queue<std::string> b;
  b.push("The slings and arrows of outrageous fortune,");
  a.swap(b);
  EXPECT_EQ(a.front(), "The slings and arrows of outrageous fortune,");
  EXPECT_EQ(a.back(), "The slings and arrows of outrageous fortune,");
  EXPECT_EQ(b.front(), "To be,");
  EXPECT_EQ(a.size(), 1U);
  EXPECT_EQ(b.size(), 9U);
}

TEST(QUEUE, pop_test_10) {
  ns::queue<std::string> a;  //{1,2,3,4,5,6,7,8,9};
  a.push("To be,");
  a.push("or not");
  a.push("to be:");
  a.push("that is the");
  a.push("question:");
  a.push("Whether");
  a.push("tis nobler");
  a.push("in the");
  a.push("mind to suffer");
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.front(), "To be,");
  EXPECT_EQ(a.back(), "mind to suffer");
  a.pop();
  EXPECT_EQ(a.front(), "or not");
  EXPECT_EQ(a.back(), "mind to suffer");
  a.pop();
  EXPECT_EQ(a.front(), "to be:");
  EXPECT_EQ(a.back(), "mind to suffer");
  a.pop();
  EXPECT_EQ(a.front(), "that is the");
  EXPECT_EQ(a.back(), "mind to suffer");
  a.pop();
  EXPECT_EQ(a.front(), "question:");
  EXPECT_EQ(a.back(), "mind to suffer");
  a.pop();
  EXPECT_EQ(a.front(), "Whether");
  EXPECT_EQ(a.back(), "mind to suffer");
  a.pop();
  EXPECT_EQ(a.front(), "tis nobler");
  EXPECT_EQ(a.back(), "mind to suffer");
  a.pop();
  EXPECT_EQ(a.front(), "in the");
  EXPECT_EQ(a.back(), "mind to suffer");
  a.pop();
  EXPECT_EQ(a.front(), "mind to suffer");
  EXPECT_EQ(a.back(), "mind to suffer");
  a.pop();
  EXPECT_TRUE(a.empty());
}

TEST(QUEUE, insert_many_back_test_11) {
  ns::queue<int> a;  //{1,2,3,4,5,6,7,8,9};
  a.insert_many_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  EXPECT_EQ(a.front(), 1);
  EXPECT_EQ(a.back(), 10);
  EXPECT_FALSE(a.empty());
}

TEST(QUEUE, insert_many_back_test_12) {
  ns::queue<int> a{11, 12, 13, 14, 15, 16, 17, 18, 19};
  a.insert_many_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  EXPECT_EQ(a.front(), 11);
  EXPECT_EQ(a.back(), 10);
  EXPECT_FALSE(a.empty());
}