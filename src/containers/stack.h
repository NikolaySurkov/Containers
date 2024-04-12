/* Copyright 2023 ns */
#ifndef SRC_CONTAINERS_STACK_H_
#define SRC_CONTAINERS_STACK_H_
#include <utility>

#include "../containers/list.h"

namespace ns {

template <typename T, typename Container = ns::list<T>>
class stack {
 public:
  using container_type = Container;
  using value_type = typename Container::value_type;
  using size_type = typename Container::size_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;

  stack() : container_{} {}
  // explicit stack(const_reference item) : container_{item} {}
  explicit stack(std::initializer_list<value_type> const &items)
      : container_{items} {}
  explicit stack(const stack &other) : container_(other.container_) {}
  explicit stack(stack &&other) : container_(std::move(other.container_)) {}
  ~stack() = default;
  stack &operator=(const stack &other) {
    container_ = other.container_;
    return *this;
  }
  stack &operator=(stack &&other) {
    container_ = std::move(other.container_);
    return *this;
  }

  const_reference top() { return *--container_.cend(); }

  void push(const_reference value) { container_.push_back(value); }
  void pop() { container_.pop_back(); }
  void swap(stack &other) { container_.swap(other.container_); }

  size_type size() { return container_.size(); }
  bool empty() { return container_.empty(); }

  template <typename... Args>
  void insert_many_front(Args &&...args) {
    container_.insert_many_back(std::forward<Args>(args)...);
  }

 private:
  container_type container_;
};

}  // namespace ns
#endif  // SRC_CONTAINERS_STACK_H_
