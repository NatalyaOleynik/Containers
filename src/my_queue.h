#ifndef SRC_MY_QUEUE_H_
#define SRC_MY_QUEUE_H_

#include "my_list.h"

namespace mynamespace {

template <class T, class Container = mynamespace::List<T>>
class Queue {
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
  Queue() : c_() {}  // Default constructor

  explicit Queue(std::initializer_list<value_type> const &items)
      : c_(items) {}  // Initializer list constructor

  Queue(const Queue &q) : c_(q.c_) {}  // Copy constructor

  Queue(Queue &&q) : c_(std::move(q.c_)) {}  // Move constructor

  ~Queue() {}  // Destructor

  Queue &operator=(Queue &&q) {
    c_ = std::move(q.c_);
    return *this;
  }  // Assignment operator overload for moving object

  // Element access

  const_reference front() const {
    return c_.front();
  }  // Access the first element

  const_reference back() const { return c_.back(); }  // Access the last element

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

  void pop() { return c_.pop_front(); };  // Removes the first element

  void swap(Queue &other) noexcept {
    std::swap(c_, other.c_);
  }  // Swaps the contents

  template <class... Args>
  void insert_many_back(Args &&...args) {
    return c_.insert_many_back(args...);
  }  // Appends new elements to the end of the container

 private:
  Container c_;
};

}  // namespace mynamespace

#endif  // SRC_MY_QUEUE_H_