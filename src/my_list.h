#ifndef SRC_MY_LIST_H_
#define SRC_MY_LIST_H_

#include <iostream>
#include <limits>

namespace mynamespace {

template <class T>
class List {
  template <class value_type>
  class Node {
   public:
    value_type value_;
    Node *prev_;
    Node *next_;

    Node(value_type value = value_type(), Node *prev = nullptr,
         Node *next = nullptr)
        : value_(value), prev_(prev), next_(next) {}
  };

  template <class value_type>
  class ListIterator {
   public:
    Node<value_type> *it_;

    explicit ListIterator(Node<value_type> *it) : it_(it){};

    const value_type &operator*() const { return it_->value_; };

    ListIterator &operator++() {
      it_ = it_->next_;
      return *this;
    }

    ListIterator &operator--() {
      it_ = it_->prev_;
      return *this;
    }

    bool operator==(const ListIterator &it) const { return it_ = it.it_; };

    bool operator!=(const ListIterator &it) const { return it_ != it.it_; }
  };

  template <class value_type>
  class ListConstIterator : public ListIterator<value_type> {
   public:
    explicit ListConstIterator(Node<value_type> *it)
        : ListIterator<value_type>(it){};

    ListConstIterator(const ListConstIterator &it)
        : ListIterator<value_type>(it) {}

    const value_type &operator*() const { return this->it_->value_; }
  };

 public:
  // Member types
  using value_type = T;   // The type of an element
  using reference = T &;  // The type of the reference to an element
  using const_reference =
      const T &;             // The type of the constant reference to an element
  using size_type = size_t;  // The type of the container size
  using iterator =
      ListIterator<value_type>;  // The type for iterating through the container
  using const_iterator =
      ListConstIterator<value_type>;  // The constant type for iterating through
                                      // the container

  // Member functions
  List();                      // Default constructor
  explicit List(size_type n);  // Parameterized constructor
  List(std::initializer_list<value_type> const
           &items);                 // Initializer list constructor
  List(const List<value_type> &l);  // Copy constructor
  List(List &&l);                   // Move constructor
  ~List();                          // Destructor
  List &operator=(
      List &&l) noexcept;  // Assignment operator overload for moving object

  // Element access
  const_reference front() const;  // Access the first element
  const_reference back() const;   // Access the last element

  // Iterators
  iterator begin() noexcept;  // Returns an iterator to the beginning
  iterator end() noexcept;    // Returns an iterator to the end
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  // Capacity
  bool empty() const noexcept;      // Checks whether the container is empty
  size_type size() const noexcept;  // Returns the number of elements
  size_type max_size()
      const noexcept;  // Returns the maximum possible number of elements

  // Modifiers
  void clear() noexcept;  // Clears the contents
  iterator insert(
      iterator pos,
      const_reference value);  // Inserts element into concrete pos and returns
                               // the iterator that points to the new element
  void erase(iterator pos);    // Erases element at pos
  void push_back(const_reference value);   // Adds an element to the end
  void pop_back();                         // Removes the last element
  void push_front(const_reference value);  // Adds an element to the head
  void pop_front();                        // Removes the first element
  void swap(List &other) noexcept;         // Swaps the contents
  void merge(List &other);                 // Merges two sorted lists
  void splice(
      const_iterator pos,
      List &other);  // Transfers elements from list other starting from pos
  void reverse() noexcept;  // Reverses the order of the elements
  void unique();            // Removes consecutive duplicate elements
  void sort();              // Sorts the elements

  // Bonus

  template <class... Args>
  iterator insert_many(const_iterator pos,
                       Args &&...args);  // Inserts new elements into the
                                         // container directly before pos
  template <class... Args>
  void insert_many_back(
      Args &&...args);  // Appends new elements to the end of the container
  template <class... Args>
  void insert_many_front(
      Args &&...args);  // Appends new elements to the top of the container

 private:
  // attributes
  size_type size_;
  Node<value_type> *fake_node_;
};

// Member functions

template <class value_type>
List<value_type>::List() : size_(0) {
  fake_node_ = new Node<value_type>;
  if (!fake_node_) throw std::out_of_range("No memory allocated");
  fake_node_->prev_ = fake_node_->next_ = fake_node_;
}

template <class value_type>
List<value_type>::List(size_type n) : List() {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
};

template <class value_type>
List<value_type>::List(std::initializer_list<value_type> const &items)
    : List() {
  for (auto item : items) {
    push_back(item);
  }
}

template <class value_type>
List<value_type>::List(const List<value_type> &l) : List() {
  for (auto it = l.cbegin(); it != l.cend(); ++it) {
    push_back(it.it_->value_);
  }
}

template <class value_type>
List<value_type>::List(List &&l) : size_(l.size_), fake_node_(l.fake_node_) {
  l.size_ = 0;
  l.fake_node_ = nullptr;
}

template <class value_type>
List<value_type>::~List() {
  clear();
  delete fake_node_;
}

template <class value_type>
typename mynamespace::List<value_type>
    &mynamespace::List<value_type>::operator=(List &&l) noexcept {
  swap(l);
  return *this;
}

// Element access

template <class value_type>
typename List<value_type>::const_reference List<value_type>::front() const {
  return fake_node_->next_->value_;
}

template <class value_type>
typename List<value_type>::const_reference List<value_type>::back() const {
  return fake_node_->prev_->value_;
}

// Iterators

template <class value_type>
typename List<value_type>::iterator List<value_type>::begin() noexcept {
  return iterator(fake_node_->next_);
}

template <class value_type>
typename List<value_type>::iterator List<value_type>::end() noexcept {
  return iterator(fake_node_);
}

template <class value_type>
typename List<value_type>::const_iterator List<value_type>::cbegin()
    const noexcept {
  return const_iterator(fake_node_->next_);
}

template <class value_type>
typename List<value_type>::const_iterator List<value_type>::cend()
    const noexcept {
  return const_iterator(fake_node_);
}

// Capacity

template <class value_type>
bool List<value_type>::empty() const noexcept {
  return size_ == 0;
}

template <class value_type>
typename List<value_type>::size_type List<value_type>::size() const noexcept {
  return size_;
}

template <class value_type>
typename List<value_type>::size_type List<value_type>::max_size()
    const noexcept {
  return (std::numeric_limits<size_type>::max() / sizeof(Node<value_type>) - 1);
}

// Modifiers

template <class value_type>
void List<value_type>::clear() noexcept {
  while (size_ > 0) pop_back();
}

template <class value_type>
typename List<value_type>::iterator List<value_type>::insert(
    iterator pos, const_reference value) {
  Node<value_type> *p = new Node<value_type>(value, pos.it_->prev_, pos.it_);
  if (!p) throw std::out_of_range("No memory allocated");
  pos.it_->prev_->next_ = p;
  pos.it_->prev_ = p;
  ++size_;
  --pos;
  return pos;
}

template <class value_type>
void List<value_type>::erase(iterator pos) {
  if (size_ > 0) {
    pos.it_->prev_->next_ = pos.it_->next_;
    pos.it_->next_->prev_ = pos.it_->prev_;
    delete pos.it_;
    --size_;
  }
}

template <class value_type>
void List<value_type>::push_back(const_reference value) {
  Node<value_type> *p = new Node<value_type>(value);
  if (!p) throw std::out_of_range("No memory allocated");
  p->prev_ = fake_node_->prev_;
  p->next_ = fake_node_;
  fake_node_->prev_->next_ = p;
  fake_node_->prev_ = p;
  ++size_;
}

template <class value_type>
void List<value_type>::pop_back() {
  if (size_ > 0) {
    Node<value_type> *p = fake_node_->prev_;
    fake_node_->prev_ = fake_node_->prev_->prev_;
    fake_node_->prev_->next_ = fake_node_;
    delete p;
    --size_;
  }
}

template <class value_type>
void List<value_type>::push_front(const_reference value) {
  Node<value_type> *p = new Node<value_type>(value);
  if (!p) throw std::out_of_range("No memory allocated");
  p->prev_ = fake_node_;
  p->next_ = fake_node_->next_;
  fake_node_->next_->prev_ = p;
  fake_node_->next_ = p;
  ++size_;
}

template <class value_type>
void List<value_type>::pop_front() {
  if (size_ > 0) {
    Node<value_type> *p = fake_node_->next_;
    fake_node_->next_ = fake_node_->next_->next_;
    fake_node_->next_->prev_ = fake_node_;
    delete p;
    --size_;
  }
}

template <class value_type>
void List<value_type>::swap(List &other) noexcept {
  std::swap(size_, other.size_);
  std::swap(fake_node_, other.fake_node_);
}

template <class value_type>
void List<value_type>::merge(List &other) {
  if (this != &other) {
    for (iterator it = other.begin(); it != other.end();) {
      ++it;
      push_back(other.front());
      other.pop_front();
    }
    sort();
  }
}

template <class value_type>
void List<value_type>::splice(const_iterator pos, List &other) {
  if (this != &other) {
    for (iterator it = other.begin(); it != other.end();) {
      ++it;
      insert(pos, other.front());
      other.pop_front();
    }
  }
}

template <class value_type>
void List<value_type>::reverse() noexcept {
  size_type mid = 0;
  iterator it1 = begin();
  iterator it2 = --end();
  for (; mid < size_ / 2; ++it1, --it2, ++mid) {
    std::swap(it1.it_->value_, it2.it_->value_);
  }
}

template <class value_type>
void List<value_type>::unique() {
  for (iterator it = begin(); it != end(); ++it) {
    iterator temp = it;
    ++temp;
    if (*it == *temp && temp.it_ != fake_node_) {
      erase(temp);
      --it;
    }
  }
}

template <class value_type>
void List<value_type>::sort() {
  for (iterator it1 = begin(); it1 != end(); ++it1) {
    for (iterator it2 = it1; it2 != end(); ++it2) {
      if (*it2 < *it1) std::swap(it1.it_->value_, it2.it_->value_);
    }
  }
}

template <class value_type>
template <class... Args>
typename List<value_type>::iterator List<value_type>::insert_many(
    const_iterator pos, Args &&...args) {
  for (auto it : {args...}) {
    insert(pos, it);
  }
  return pos;
}

template <class value_type>
template <class... Args>
void List<value_type>::insert_many_back(Args &&...args) {
  auto pos = cend();
  insert_many(pos, args...);
}

template <class value_type>
template <class... Args>
void List<value_type>::insert_many_front(Args &&...args) {
  auto pos = cbegin();
  insert_many(pos, args...);
}

}  // namespace mynamespace

#endif
