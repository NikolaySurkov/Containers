#include <stack>

#include "test_containers.h"

TEST(STACK, default_constructor_test_1) {
  ns::stack<int> a;
  EXPECT_EQ(a.size(), 0U);
  EXPECT_TRUE(a.empty());
}

TEST(STACK, init_list_constructor_test_2) {
  ns::stack<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(a.size(), 9U);
}

TEST(STACK, move_constructor_test_3) {
  ns::stack<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(a.size(), 9U);
  ns::stack<int> b(std::move(a));
  EXPECT_EQ(a.size(), 0U);
  EXPECT_EQ(b.size(), 9U);
}

TEST(STACK, copy_constructor_test_4) {
  ns::stack<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(a.size(), 9U);
  ns::stack<int> b(a);
  EXPECT_EQ(a.size(), 9U);
  EXPECT_EQ(b.size(), 9U);
}

TEST(STACK, move_operator_eq_test_5) {
  ns::stack<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(a.size(), 9U);
  ns::stack<int> b;
  b = std::move(a);
  EXPECT_EQ(a.size(), 0U);
  EXPECT_EQ(b.size(), 9U);
}

TEST(STACK, copy_operator_eq_test_6) {
  ns::stack<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(a.size(), 9U);
  ns::stack<int> b;
  b = a;
  EXPECT_EQ(a.size(), 9U);
  EXPECT_EQ(b.size(), 9U);
}

TEST(STACK, top_test_7) {
  ns::stack<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.top(), 9);
}

TEST(STACK, push_test_8) {
  ns::stack<int> a;  //{1,2,3,4,5,6,7,8,9};
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
  EXPECT_EQ(a.top(), 9);
}

TEST(STACK, push_test_9) {
  ns::stack<int> a;  //{1,2,3,4,5,6,7,8,9};
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(8);
  a.push(9);
  a.push(1);
  a.push(2);
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.top(), 2);
}

TEST(STACK, swap_test_7) {
  ns::stack<int> a;
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(8);
  a.push(9);
  a.push(1);
  a.push(2);
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.top(), 2);
  ns::stack<int> b;
  b.push(777);
  a.swap(b);
  EXPECT_EQ(a.top(), 777);
  EXPECT_EQ(b.top(), 2);
  EXPECT_EQ(a.size(), 1U);
  EXPECT_EQ(b.size(), 9U);
}

TEST(STACK, pop_test_10) {
  ns::stack<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.top(), 9);
  a.pop();
  EXPECT_EQ(a.top(), 8);
  a.pop();
  EXPECT_EQ(a.top(), 7);
  a.pop();
  EXPECT_EQ(a.top(), 6);
  a.pop();
  EXPECT_EQ(a.top(), 5);
  a.pop();
  EXPECT_EQ(a.top(), 4);
  a.pop();
  EXPECT_EQ(a.top(), 3);
  a.pop();
  EXPECT_EQ(a.top(), 2);
  a.pop();
  EXPECT_EQ(a.top(), 1);
  a.pop();
  EXPECT_TRUE(a.empty());
}

TEST(STACK, empty_test_11) {
  ns::stack<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_FALSE(a.empty());
}

TEST(STACK, insert_many_front_test_12) {
  ns::stack<char> a{'a', 'b', 'c', 'd', 'e', '6', '7', '8', '9'};
  EXPECT_FALSE(a.empty());
  a.insert_many_front('s', '2', '1');
  EXPECT_EQ(a.top(), '1');
}

TEST(STACK, insert_many_front_test_13) {
  ns::stack<char> a{'a', 'b', 'c', 'd', 'e', '6', '7', '8', '9'};
  EXPECT_FALSE(a.empty());
  a.insert_many_front('1', '2', 's');
  EXPECT_EQ(a.top(), 's');
}

TEST(STACK, PushPop_14) {
  ns::stack<int> a;
  std::stack<int> b;
  for (int i = 0; i < 1000; i++) {
    a.push(i);
    b.push(i);
  }

  for (int i = 1000 - 1; i >= 0; i--) {
    ASSERT_EQ(a.top(), b.top());
    a.pop();
    b.pop();
  }
}

TEST(STACK_VEC, default_constructor_test_1) {
  ns::stack<int, std::vector<int>> a;
  EXPECT_EQ(a.size(), 0U);
  EXPECT_TRUE(a.empty());
}

TEST(STACK_VEC, init_list_constructor_test_2) {
  ns::stack<int, std::vector<int>> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(a.size(), 9U);
}

TEST(STACK_VEC, move_constructor_test_3) {
  ns::stack<int, std::vector<int>> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(a.size(), 9U);
  ns::stack<int, std::vector<int>> b(std::move(a));
  EXPECT_EQ(a.size(), 0U);
  EXPECT_EQ(b.size(), 9U);
}

TEST(STACK_VEC, copy_constructor_test_4) {
  ns::stack<int, std::vector<int>> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(a.size(), 9U);
  ns::stack<int, std::vector<int>> b(a);
  EXPECT_EQ(a.size(), 9U);
  EXPECT_EQ(b.size(), 9U);
}

TEST(STACK_VEC, move_operator_eq_test_5) {
  ns::stack<int, std::vector<int>> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(a.size(), 9U);
  ns::stack<int, std::vector<int>> b;
  b = std::move(a);
  EXPECT_EQ(a.size(), 0U);
  EXPECT_EQ(b.size(), 9U);
}

TEST(STACK_VEC, copy_operator_eq_test_6) {
  ns::stack<int, std::vector<int>> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(a.size(), 9U);
  ns::stack<int, std::vector<int>> b;
  b = a;
  EXPECT_EQ(a.size(), 9U);
  EXPECT_EQ(b.size(), 9U);
}

TEST(STACK_VEC, top_test_7) {
  ns::stack<int, std::vector<int>> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.top(), 9);
}

TEST(STACK_VEC, push_test_8) {
  ns::stack<int, std::vector<int>> a;  //{1,2,3,4,5,6,7,8,9};
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
  EXPECT_EQ(a.top(), 9);
}

TEST(STACK_VEC, push_test_9) {
  ns::stack<int, std::vector<int>> a;  //{1,2,3,4,5,6,7,8,9};
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(8);
  a.push(9);
  a.push(1);
  a.push(2);
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.top(), 2);
}

TEST(STACK_VEC, swap_test_7) {
  ns::stack<int, std::vector<int>> a;
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(8);
  a.push(9);
  a.push(1);
  a.push(2);
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.top(), 2);
  ns::stack<int, std::vector<int>> b;
  b.push(777);
  a.swap(b);
  EXPECT_EQ(a.top(), 777);
  EXPECT_EQ(b.top(), 2);
  EXPECT_EQ(a.size(), 1U);
  EXPECT_EQ(b.size(), 9U);
}

TEST(STACK_VEC, pop_test_10) {
  ns::stack<int, std::vector<int>> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_FALSE(a.empty());
  EXPECT_EQ(a.top(), 9);
  a.pop();
  EXPECT_EQ(a.top(), 8);
  a.pop();
  EXPECT_EQ(a.top(), 7);
  a.pop();
  EXPECT_EQ(a.top(), 6);
  a.pop();
  EXPECT_EQ(a.top(), 5);
  a.pop();
  EXPECT_EQ(a.top(), 4);
  a.pop();
  EXPECT_EQ(a.top(), 3);
  a.pop();
  EXPECT_EQ(a.top(), 2);
  a.pop();
  EXPECT_EQ(a.top(), 1);
  a.pop();
  EXPECT_TRUE(a.empty());
}

TEST(STACK_VEC, empty_test_11) {
  ns::stack<int, std::vector<int>> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_FALSE(a.empty());
}

TEST(STACK_VEC, PushPop_14) {
  ns::stack<int, std::vector<int>> a;
  std::stack<int, std::vector<int>> b;
  for (int i = 0; i < 1000; i++) {
    a.push(i);
    b.push(i);
  }

  for (int i = 1000 - 1; i >= 0; i--) {
    ASSERT_EQ(a.top(), b.top());
    a.pop();
    b.pop();
  }
}