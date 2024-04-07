#include <gtest/gtest.h>

#include <queue>

#include "my_queue.h"

TEST(test_queue, DefaultConstructor) {
  mynamespace::Queue<int> a;
  std::queue<int> b;
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
}

TEST(test_queue, InitConstructor) {
  mynamespace::Queue<int> a{1, 2, 3, 4};
  std::queue<int> b({1, 2, 3, 4});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  mynamespace::Queue<std::string> c{"Misha", "Max", "Sasha"};
  std::queue<std::string> d({"Misha", "Max", "Sasha"});
  ASSERT_EQ(c.size(), d.size());
  ASSERT_EQ(c.front(), d.front());
  ASSERT_EQ(c.back(), d.back());
  mynamespace::Queue<char> e{'a', 'b', 'c'};
  std::queue<char> f({'a', 'b', 'c'});
  ASSERT_EQ(e.size(), f.size());
  ASSERT_EQ(e.front(), f.front());
  ASSERT_EQ(e.back(), f.back());

  for (size_t i = b.size(); i > 0; --i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }
  for (size_t i = d.size(); i > 0; --i) {
    ASSERT_EQ(c.front(), d.front());
    c.pop();
    d.pop();
  }
  for (size_t i = f.size(); i > 0; --i) {
    ASSERT_EQ(e.front(), f.front());
    e.pop();
    f.pop();
  }
}

TEST(test_queue, CopyConstructor) {
  mynamespace::Queue<int> a{1, 2, 3, 4};
  mynamespace::Queue<int> b(a);
  std::queue<int> c({1, 2, 3, 4});
  std::queue<int> d(c);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(c.size(), d.size());
  ASSERT_EQ(b.size(), d.size());
  for (size_t i = d.size(); i > 0; --i) {
    ASSERT_EQ(b.front(), d.front());
    b.pop();
    d.pop();
  }
}

TEST(test_queue, MoveConstructor) {
  mynamespace::Queue<int> a{1, 2, 3, 4};
  mynamespace::Queue<int> b(std::move(a));
  std::queue<int> c({1, 2, 3, 4});
  std::queue<int> d(std::move(c));
  ASSERT_EQ(a.empty(), true);
  ASSERT_EQ(b.empty(), false);
  ASSERT_EQ(c.empty(), true);
  ASSERT_EQ(d.empty(), false);
  ASSERT_EQ(b.size(), d.size());
  for (size_t i = d.size(); i > 0; --i) {
    ASSERT_EQ(b.front(), d.front());
    b.pop();
    d.pop();
  }
}

TEST(test_queue, MoveAssig) {
  mynamespace::Queue<int> a{1, 2, 3, 4};
  mynamespace::Queue<int> b;
  b = std::move(a);
  std::queue<int> c({1, 2, 3, 4});
  std::queue<int> d;
  d = std::move(c);
  ASSERT_EQ(a.empty(), true);
  ASSERT_EQ(b.empty(), false);
  ASSERT_EQ(c.empty(), true);
  ASSERT_EQ(d.empty(), false);
  ASSERT_EQ(b.size(), d.size());
  for (size_t i = d.size(); i > 0; --i) {
    ASSERT_EQ(b.front(), d.front());
    b.pop();
    d.pop();
  }
}

TEST(test_queue, Push) {
  mynamespace::Queue<int> a;
  std::queue<int> b;
  a.push(3);
  a.push(5);
  b.push(3);
  b.push(5);
  ASSERT_EQ(a.size(), b.size());
}

TEST(test_queue, Swap) {
  mynamespace::Queue<int> a{1, 2, 3, 4};
  mynamespace::Queue<int> b{5, 6, 7, 8};
  std::queue<int> c({1, 2, 3, 4});
  std::queue<int> d({5, 6, 7, 8});
  a.swap(b);
  c.swap(d);
  ASSERT_EQ(a.size(), c.size());
  for (size_t i = c.size(); i > 0; --i) {
    ASSERT_EQ(a.front(), c.front());
    a.pop();
    c.pop();
  }
}

TEST(test_queue, InsertManyBack) {
  mynamespace::Queue<int> a{1, 2, 3, 4, 5, 6};
  std::queue<int> b({1, 2, 3, 4, 5, 6});
  a.insert_many_back(10, 20, 30);
  b.push(10);
  b.push(20);
  b.push(30);
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = b.size(); i > 0; --i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }
}
