#ifndef SRC_MY_STACK_H_
#define SRC_MY_STACK_H_

#include "my_list.h"

namespace mynamespace {

template <class T, class Container = mynamespace::List<T>>
class Stack {
 public:
  // Member types
  using value_type = typename Container::value_type;  // The type of an element
  using reference =
      typename Container::reference;  // The type of the reference to an element
  using const_reference =
      typename Container::const_reference;  // The type of the constant
                                            // reference to an element
  using size_type =
      typename Container::size_type;  // The type of the container size

  // Member functions
  Stack() : c_() {}  // Default constructor

  explicit Stack(std::initializer_list<value_type> const &items)
      : c_(items) {}  // Initializer list constructor

  Stack(const Stack &s) : c_(s.c_) {}  // Copy constructor

  Stack(Stack &&s) : c_(std::move(s.c_)) {}  // Move constructor

  ~Stack() {}  // Destructor

  Stack &operator=(Stack &&s) {
    c_ = std::move(s.c_);
    return *this;
  }  // Assignment operator overload for moving object

  // Element access

  const_reference top() const { return c_.back(); }  // Accesses the top element

  // Capacity

  bool empty() const {
    return c_.empty();
  }  // Checks whether the container is empty

  size_type size() const {
    return c_.size();
  }  // Returns the number of elements

  // Modifiers

  void push(const_reference value) {
    return c_.push_back(value);
  }  // Inserts element at the end

  void pop() { return c_.pop_back(); }  // Removes the first element

  void swap(Stack &other) noexcept {
    std::swap(c_, other.c_);
  }  // Swaps the contents

  template <class... Args>
  void insert_many_front(Args &&...args) {
    return c_.insert_many_back(args...);
  }  // Appends new elements to the top of the container

 private:
  Container c_;
};

}  // namespace mynamespace

#endif  // SRC_MY_STACK_H_
