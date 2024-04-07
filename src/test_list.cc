#include <gtest/gtest.h>

#include <list>

#include "my_list.h"

TEST(test_list, DefaultConstructor) {
  mynamespace::List<int> a;
  std::list<int> b;
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
}

TEST(test_list, ParamConstructor) {
  mynamespace::List<int> a(3);
  std::list<int> b(3);
  ASSERT_EQ(a.size(), b.size());
  mynamespace::List<std::string> c(5);
  std::list<std::string> d(5);
  ASSERT_EQ(c.size(), d.size());
}

TEST(test_list, InitConstructor) {
  mynamespace::List<int> a{1, 2, 3, 4};
  std::list<int> b{1, 2, 3, 4};
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  mynamespace::List<std::string> c{"Misha", "Max", "Sasha"};
  std::list<std::string> d{"Misha", "Max", "Sasha"};
  ASSERT_EQ(c.size(), d.size());
  ASSERT_EQ(c.front(), d.front());
  ASSERT_EQ(c.back(), d.back());
  mynamespace::List<char> e{'a', 'b', 'c'};
  std::list<char> f{'a', 'b', 'c'};
  ASSERT_EQ(e.size(), f.size());
  ASSERT_EQ(e.front(), f.front());
  ASSERT_EQ(e.back(), f.back());

  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  auto it3 = c.begin();
  auto it4 = d.begin();
  for (; it4 != d.end(); ++it3, ++it4) {
    ASSERT_EQ(*it3, *it4);
  }
  auto it5 = e.begin();
  auto it6 = f.begin();
  for (; it6 != f.end(); ++it5, ++it6) {
    ASSERT_EQ(*it5, *it6);
  }
}

TEST(test_list, CopyConstructor) {
  mynamespace::List<int> a{1, 2, 3, 4};
  mynamespace::List<int> b(a);
  std::list<int> c{1, 2, 3, 4};
  std::list<int> d(c);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(c.size(), d.size());
  ASSERT_EQ(b.size(), d.size());
  auto it1 = b.begin();
  auto it2 = d.begin();
  for (; it2 != d.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(test_list, MoveConstructor) {
  mynamespace::List<int> a{1, 2, 3, 4};
  mynamespace::List<int> b(std::move(a));
  std::list<int> c{1, 2, 3, 4};
  std::list<int> d(std::move(c));
  ASSERT_EQ(a.empty(), true);
  ASSERT_EQ(b.empty(), false);
  ASSERT_EQ(c.empty(), true);
  ASSERT_EQ(d.empty(), false);
  ASSERT_EQ(b.size(), d.size());
  auto it1 = b.begin();
  auto it2 = d.begin();
  for (; it2 != d.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(test_list, MoveAssig) {
  mynamespace::List<int> a{1, 2, 3, 4};
  mynamespace::List<int> b;
  b = std::move(a);
  std::list<int> c{1, 2, 3, 4};
  std::list<int> d;
  d = std::move(c);
  ASSERT_EQ(a.empty(), true);
  ASSERT_EQ(b.empty(), false);
  ASSERT_EQ(c.empty(), true);
  ASSERT_EQ(d.empty(), false);
  ASSERT_EQ(b.size(), d.size());
  auto it1 = b.begin();
  auto it2 = d.begin();
  for (; it2 != d.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(test_list, End) {
  mynamespace::List<int> a{1, 2, 3, 4};
  std::list<int> b{1, 2, 3, 4};
  auto it1 = a.end();
  auto it2 = b.end();
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
}

TEST(test_list, MaxSize) {
  mynamespace::List<int> a;
  std::list<int> b;
  mynamespace::List<double> c;
  std::list<double> d;
  mynamespace::List<char> e;
  std::list<char> f;
  mynamespace::List<std::string> g;
  std::list<std::string> h;
  ASSERT_DOUBLE_EQ(a.max_size(), b.max_size());
  ASSERT_DOUBLE_EQ(c.max_size(), d.max_size());
  ASSERT_DOUBLE_EQ(e.max_size(), f.max_size());
  ASSERT_DOUBLE_EQ(g.max_size(), h.max_size());
}

TEST(test_list, InsertErase) {
  mynamespace::List<int> a{1, 2, 3, 4};
  std::list<int> b{1, 2, 3, 4};
  auto it1 = a.begin();
  auto it2 = b.begin();
  a.insert(it1, 5);
  b.insert(it2, 5);
  ASSERT_EQ(a.front(), 5);
  ASSERT_EQ(b.front(), 5);
  ++it1;
  ++it2;
  a.insert(it1, 5);
  b.insert(it2, 5);
  a.erase(it1);
  b.erase(it2);
  auto it3 = a.begin();
  auto it4 = b.begin();
  for (; it4 != b.end(); ++it3, ++it4) {
    ASSERT_EQ(*it3, *it4);
  }
}

TEST(test_list, PushPopFront) {
  mynamespace::List<int> a;
  std::list<int> b;
  a.push_front(3);
  a.push_front(5);
  b.push_front(3);
  b.push_front(5);
  a.pop_front();
  b.pop_front();
  ASSERT_EQ(a.size(), b.size());
}

TEST(test_list, Merge) {
  mynamespace::List<int> a{1, 2, 3, 4};
  mynamespace::List<int> b{5, 6, 7, 8};
  std::list<int> c{1, 2, 3, 4};
  std::list<int> d{5, 6, 7, 8};
  a.merge(b);
  c.merge(d);
  ASSERT_EQ(a.size(), c.size());
  auto it1 = a.begin();
  auto it2 = c.begin();
  for (; it2 != c.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}
TEST(test_list, Splice) {
  mynamespace::List<int> a{1, 2, 3, 4};
  mynamespace::List<int> b{5, 6, 7, 8};
  std::list<int> c{1, 2, 3, 4};
  std::list<int> d{5, 6, 7, 8};
  auto it1 = a.cbegin();
  a.splice(it1, b);
  auto it2 = c.cbegin();
  c.splice(it2, d);
  ASSERT_EQ(a.size(), c.size());
  for (; it2 != c.cend(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(test_list, Reverse) {
  mynamespace::List<int> a{1, 2, 3, 4};
  std::list<int> b{1, 2, 3, 4};
  a.reverse();
  b.reverse();
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(test_list, Unique) {
  mynamespace::List<int> a{1, 2, 2, 3, 4, 5, 5, 5, 6};
  std::list<int> b{1, 2, 2, 3, 4, 5, 5, 5, 6};
  a.unique();
  b.unique();
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(test_list, InsertMany) {
  mynamespace::List<int> a{1, 2, 3, 4, 5, 6};
  std::list<int> b{1, 2, 3, 4, 5, 6};
  auto it1 = a.cbegin();
  ++it1;
  auto it2 = b.cbegin();
  ++it2;
  a.insert_many(it1, 10, 20, 30);
  b.insert(it2, {10, 20, 30});
  auto it3 = a.begin();
  auto it4 = b.begin();
  for (; it4 != b.end(); ++it3, ++it4) {
    ASSERT_EQ(*it3, *it4);
  }
}

TEST(test_list, InsertManyBack) {
  mynamespace::List<int> a{1, 2, 3, 4, 5, 6};
  std::list<int> b{1, 2, 3, 4, 5, 6};
  a.insert_many_back(10, 20, 30);
  b.insert(b.end(), {10, 20, 30});
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(test_list, InsertManyFront) {
  mynamespace::List<int> a{1, 2, 3, 4, 5, 6};
  std::list<int> b{1, 2, 3, 4, 5, 6};
  a.insert_many_front(10, 20, 30);
  b.insert(b.begin(), {10, 20, 30});
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}
