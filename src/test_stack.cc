#include <gtest/gtest.h>

#include <stack>

#include "my_stack.h"

TEST(tests_stack, DefaultConstructor) {
  mynamespace::Stack<int> a;
  std::stack<int> b;
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
}

TEST(tests_stack, InitConstructor) {
  mynamespace::Stack<int> a{1, 2, 3, 4};
  std::stack<int> b({1, 2, 3, 4});
  ASSERT_EQ(a.size(), b.size());
  mynamespace::Stack<std::string> c{"Misha", "Max", "Sasha"};
  std::stack<std::string> d({"Misha", "Max", "Sasha"});
  ASSERT_EQ(c.size(), d.size());
  mynamespace::Stack<char> e{'a', 'b', 'c'};
  std::stack<char> f({'a', 'b', 'c'});
  ASSERT_EQ(e.size(), f.size());

  for (size_t i = b.size(); i > 0; --i) {
    ASSERT_EQ(a.top(), b.top());
    a.pop();
    b.pop();
  }
  for (size_t i = d.size(); i > 0; --i) {
    ASSERT_EQ(c.top(), d.top());
    c.pop();
    d.pop();
  }
  for (size_t i = f.size(); i > 0; --i) {
    ASSERT_EQ(e.top(), f.top());
    e.pop();
    f.pop();
  }
}

TEST(tests_stack, CopyConstructor) {
  mynamespace::Stack<int> a{1, 2, 3, 4};
  mynamespace::Stack<int> b(a);
  std::stack<int> c({1, 2, 3, 4});
  std::stack<int> d(c);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(c.size(), d.size());
  ASSERT_EQ(b.size(), d.size());
  for (size_t i = d.size(); i > 0; --i) {
    ASSERT_EQ(b.top(), d.top());
    b.pop();
    d.pop();
  }
}

TEST(tests_stack, MoveConstructor) {
  mynamespace::Stack<int> a{1, 2, 3, 4};
  mynamespace::Stack<int> b(std::move(a));
  std::stack<int> c({1, 2, 3, 4});
  std::stack<int> d(std::move(c));
  ASSERT_EQ(a.empty(), true);
  ASSERT_EQ(b.empty(), false);
  ASSERT_EQ(c.empty(), true);
  ASSERT_EQ(d.empty(), false);
  ASSERT_EQ(b.size(), d.size());
  for (size_t i = d.size(); i > 0; --i) {
    ASSERT_EQ(b.top(), d.top());
    b.pop();
    d.pop();
  }
}

TEST(tests_stack, MoveAssig) {
  mynamespace::Stack<int> a{1, 2, 3, 4};
  mynamespace::Stack<int> b;
  b = std::move(a);
  std::stack<int> c({1, 2, 3, 4});
  std::stack<int> d;
  d = std::move(c);
  ASSERT_EQ(a.empty(), true);
  ASSERT_EQ(b.empty(), false);
  ASSERT_EQ(c.empty(), true);
  ASSERT_EQ(d.empty(), false);
  ASSERT_EQ(b.size(), d.size());
  for (size_t i = d.size(); i > 0; --i) {
    ASSERT_EQ(b.top(), d.top());
    b.pop();
    d.pop();
  }
}

TEST(tests_stack, Push) {
  mynamespace::Stack<int> a;
  std::stack<int> b;
  a.push(3);
  a.push(5);
  b.push(3);
  b.push(5);
  ASSERT_EQ(a.size(), b.size());
}

TEST(tests_stack, Swap) {
  mynamespace::Stack<int> a{1, 2, 3, 4};
  mynamespace::Stack<int> b{5, 6, 7, 8};
  std::stack<int> c({1, 2, 3, 4});
  std::stack<int> d({5, 6, 7, 8});
  a.swap(b);
  c.swap(d);
  ASSERT_EQ(a.size(), c.size());
  for (size_t i = c.size(); i > 0; --i) {
    ASSERT_EQ(a.top(), c.top());
    a.pop();
    c.pop();
  }
}

TEST(tests_stack, InsertManyFront) {
  mynamespace::Stack<int> a{1, 2, 3, 4, 5, 6};
  std::stack<int> b({1, 2, 3, 4, 5, 6});
  a.insert_many_front(10, 20, 30);
  b.push(10);
  b.push(20);
  b.push(30);
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = b.size(); i > 0; --i) {
    ASSERT_EQ(a.top(), b.top());
    a.pop();
    b.pop();
  }
}
