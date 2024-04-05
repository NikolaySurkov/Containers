#ifndef SRC_TESTS_TEST_CONTAINERS_H_
#define SRC_TESTS_TEST_CONTAINERS_H_
#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../containers/list.h"
#include "../containers/map.h"
#include "../containers/multiset.h"
#include "../containers/queue.h"
#include "../containers/rb_tree.h"
#include "../containers/set.h"
#include "../containers/stack.h"

class NotDefaultConstructor {
 public:
  NotDefaultConstructor() = delete;
  NotDefaultConstructor(std::string x, std::string y, std::string z)
      : x_(x), y_(y), z_(z) {}
  void print() const { std::cout << x_ << ' ' << y_ << ' ' << z_ << '\n'; }
  bool operator<(const NotDefaultConstructor &other) const {
    return x_ < other.x_;
  }
  std::string sum() noexcept { return x_ + y_ + z_; }

 private:
  std::string x_;
  std::string y_;
  std::string z_;
};

#endif  //  SRC_TESTS_TEST_CONTAINERS_H_
