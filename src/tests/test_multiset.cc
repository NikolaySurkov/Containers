#include "test_containers.h"

TEST(MULTISET_CONSTRUCTOR, test_xxx_1) {
  ns::multiset<int> multiset_int;
  ns::multiset<double> multiset_double;
  ns::multiset<std::string> multiset_string;

  EXPECT_EQ(multiset_int.size(), 0U);
  EXPECT_EQ(multiset_double.size(), 0U);
  EXPECT_EQ(multiset_string.size(), 0U);
}

TEST(MULTISET_CONSTRUCTOR, test_xxx_2) {
  ns::multiset<int> multiset_int{1, 2, 3, 4, 5};
  ns::multiset<double> multiset_double{1.30359, 2847.4925, 923.39281};
  ns::multiset<std::string> multiset_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(multiset_int.size(), 5U);
  EXPECT_EQ(multiset_double.size(), 3U);
  EXPECT_EQ(multiset_string.size(), 4U);
}

TEST(MULTISET_CONSTRUCTOR, test_xxx_3) {
  ns::multiset<int> multiset_ref_int{1, 2, 3, 4, 5};
  ns::multiset<int> multiset_res_int{multiset_ref_int};

  ns::multiset<double> multiset_ref_double{1.30359, 2847.4925, 923.39281};
  ns::multiset<double> multiset_res_double{multiset_ref_double};

  ns::multiset<std::string> multiset_ref_string{"Hello", ",", "world", "!"};
  ns::multiset<std::string> multiset_res_string{multiset_ref_string};

  EXPECT_EQ(multiset_ref_int.size(), multiset_res_int.size());
  EXPECT_EQ(multiset_ref_double.size(), multiset_res_double.size());
  EXPECT_EQ(multiset_ref_string.size(), multiset_res_string.size());
}

TEST(MULTISET_CONSTRUCTOR, test_xxx_4) {
  ns::multiset<int> multiset_ref_int{1, 2, 3, 4, 5};
  ns::multiset<int> multiset_res_int = std::move(multiset_ref_int);

  ns::multiset<double> multiset_ref_double{1.30359, 2847.4925, 923.39281};
  ns::multiset<double> multiset_res_double = std::move(multiset_ref_double);

  ns::multiset<std::string> multiset_ref_string{"Hello", ",", "world", "!"};
  ns::multiset<std::string> multiset_res_string =
      std::move(multiset_ref_string);

  EXPECT_EQ(multiset_ref_int.size(), 0U);
  EXPECT_EQ(multiset_res_int.size(), 5U);

  EXPECT_EQ(multiset_ref_double.size(), 0U);
  EXPECT_EQ(multiset_res_double.size(), 3U);

  EXPECT_EQ(multiset_ref_string.size(), 0U);
  EXPECT_EQ(multiset_res_string.size(), 4U);
}

TEST(MULTISET_CONSTRUCTOR, test_xxx_5) {
  ns::multiset<int> multiset_ref_int{1, 2, 3, 4, 5};
  ns::multiset<int> multiset_res_int;
  multiset_res_int = std::move(multiset_ref_int);

  ns::multiset<double> multiset_ref_double{1.30359, 2847.4925, 923.39281};
  ns::multiset<double> multiset_res_double;
  multiset_res_double = std::move(multiset_ref_double);

  ns::multiset<std::string> multiset_ref_string{"Hello", ",", "world", "!"};
  ns::multiset<std::string> multiset_res_string;
  multiset_res_string = std::move(multiset_ref_string);

  EXPECT_EQ(multiset_ref_int.size(), 0U);
  EXPECT_EQ(multiset_res_int.size(), 5U);

  EXPECT_EQ(multiset_ref_double.size(), 0U);
  EXPECT_EQ(multiset_res_double.size(), 3U);

  EXPECT_EQ(multiset_ref_string.size(), 0U);
  EXPECT_EQ(multiset_res_string.size(), 4U);
}

TEST(MULTISET_CONSTRUCTOR, test_xxx_7) {
  ns::multiset<int> multiset_ref_int{1, 2, 3, 4};
  ns::multiset<int> multiset_res_int{multiset_ref_int};

  ns::multiset<double> multiset_ref_double{1.30359, 2847.4925, 923.39281, 1.23};
  ns::multiset<double> multiset_res_double{multiset_ref_double};

  ns::multiset<std::string> multiset_ref_string{"Hello", ",", "world", "!"};
  ns::multiset<std::string> multiset_res_string{multiset_ref_string};

  auto it_res_int = multiset_res_int.begin();
  for (auto it_ref_int = multiset_ref_int.begin();
       it_ref_int != multiset_ref_int.end(); ++it_ref_int) {
    EXPECT_EQ(*it_res_int, *it_ref_int);
    it_res_int++;
  }

  auto it_res_double = multiset_res_double.begin();
  for (auto it_ref_double = multiset_ref_double.begin();
       it_ref_double != multiset_ref_double.end(); ++it_ref_double) {
    EXPECT_EQ(*it_res_double, *it_ref_double);
    it_res_double++;
  }

  auto it_res_string = multiset_res_string.begin();
  for (auto it_ref_string = multiset_ref_string.begin();
       it_ref_string != multiset_ref_string.end(); ++it_ref_string) {
    EXPECT_EQ(*it_res_string, *it_ref_string);
    it_res_string++;
  }
}

TEST(MULTISET_INSERT, test_xxx_1) {
  ns::multiset<int> multiset_ns;

  std::pair<ns::multiset<int>::iterator, bool> insert1 = multiset_ns.insert(9);
  EXPECT_EQ(*insert1.first, 9);
  EXPECT_EQ(insert1.second, true);

  std::pair<ns::multiset<int>::iterator, bool> insert2 = multiset_ns.insert(9);
  std::pair<ns::multiset<int>::iterator, bool> insert3 = multiset_ns.insert(9);
  EXPECT_EQ(insert2.second, true);
  EXPECT_EQ(insert3.second, true);

  std::pair<ns::multiset<int>::iterator, bool> insert4 = multiset_ns.insert(23);
  EXPECT_EQ(*insert4.first, 23);
  EXPECT_EQ(insert4.second, true);

  std::pair<ns::multiset<int>::iterator, bool> insert5 = multiset_ns.insert(98);
  EXPECT_EQ(*insert5.first, 98);
  EXPECT_EQ(insert5.second, true);

  EXPECT_EQ(multiset_ns.size(), 5U);
}

TEST(MULTISET_INSERT, test_xxx_2) {
  ns::multiset<double> multiset_ns;

  std::pair<ns::multiset<double>::iterator, bool> insert1 =
      multiset_ns.insert(1.4);
  EXPECT_EQ(*insert1.first, 1.4);
  EXPECT_EQ(insert1.second, true);

  std::pair<ns::multiset<double>::iterator, bool> insert2 =
      multiset_ns.insert(2.77);
  EXPECT_EQ(*insert2.first, 2.77);
  EXPECT_EQ(insert2.second, true);

  std::pair<ns::multiset<double>::iterator, bool> insert3 =
      multiset_ns.insert(3.9);
  EXPECT_EQ(*insert3.first, 3.9);
  EXPECT_EQ(insert3.second, true);

  std::pair<ns::multiset<double>::iterator, bool> insert4 =
      multiset_ns.insert(2.77);
  std::pair<ns::multiset<double>::iterator, bool> insert5 =
      multiset_ns.insert(3.9);
  EXPECT_EQ(insert4.second, true);
  EXPECT_EQ(insert5.second, true);

  EXPECT_EQ(multiset_ns.size(), 5U);
}

TEST(MULTISET_INSERT, test_xxx_3) {
  ns::multiset<std::string> multiset_ns;

  std::pair<ns::multiset<std::string>::iterator, bool> insert1 =
      multiset_ns.insert("hello");
  EXPECT_EQ(*insert1.first, "hello");
  EXPECT_EQ(insert1.second, true);

  std::pair<ns::multiset<std::string>::iterator, bool> insert2 =
      multiset_ns.insert("hi");
  EXPECT_EQ(*insert2.first, "hi");
  EXPECT_EQ(insert2.second, true);

  std::pair<ns::multiset<std::string>::iterator, bool> insert3 =
      multiset_ns.insert("hi");
  EXPECT_EQ(insert3.second, true);

  std::pair<ns::multiset<std::string>::iterator, bool> insert4 =
      multiset_ns.insert("holli");
  EXPECT_EQ(*insert4.first, "holli");
  EXPECT_EQ(insert4.second, true);

  std::pair<ns::multiset<std::string>::iterator, bool> insert5 =
      multiset_ns.insert("hello");
  EXPECT_EQ(insert5.second, true);

  EXPECT_EQ(multiset_ns.size(), 5U);
}

TEST(MULTISET_INSERT, test_xxx_4) {
  ns::multiset<int> multiset_ns;

  std::pair<ns::multiset<int>::iterator, bool> insert1 = multiset_ns.insert(9);
  EXPECT_EQ(*insert1.first, 9);
  EXPECT_EQ(insert1.second, true);

  std::pair<ns::multiset<int>::iterator, bool> insert2 = multiset_ns.insert(9);
  std::pair<ns::multiset<int>::iterator, bool> insert3 = multiset_ns.insert(9);
  EXPECT_EQ(insert2.second, true);
  EXPECT_EQ(insert3.second, true);

  EXPECT_EQ(multiset_ns.size(), 3U);
}

TEST(MULTISET_INSERT, test_xxx_5) {
  ns::multiset<double> multiset_ns = {21};

  std::pair<ns::multiset<double>::iterator, bool> insert1 =
      multiset_ns.insert(1.4);
  EXPECT_EQ(insert1.second, true);

  EXPECT_EQ(multiset_ns.size(), 2U);
}

TEST(MULTISET_INSERT, test_xxx_6) {
  ns::multiset<std::string> multiset_ns = {"hello"};

  std::pair<ns::multiset<std::string>::iterator, bool> insert1 =
      multiset_ns.insert("hi");
  EXPECT_EQ(*insert1.first, "hi");
  EXPECT_EQ(insert1.second, true);

  EXPECT_EQ(multiset_ns.size(), 2U);
}

TEST(MULTISET_BEGIN, test_xxx_1) {
  ns::multiset<int> multiset_ns = {9, 15, 7, 23, 2};

  EXPECT_EQ(*multiset_ns.begin(), 2);
}

TEST(MULTISET_BEGIN, test_xxx_2) {
  ns::multiset<double> multiset_ns = {11.4, 2.770001, 3.901, 2.77, 3.9};

  EXPECT_EQ(*multiset_ns.begin(), 2.77);
}

TEST(MULTISET_BEGIN, test_xxx_3) {
  ns::multiset<std::string> multiset_ns = {"hello", "hi", "hi-hi", "holli",
                                           "hello, hamlet"};

  EXPECT_EQ(*multiset_ns.begin(), "hello");
}

TEST(MULTISET_BEGIN, test_xxx_5) {
  ns::multiset<double> multiset_ns = {1.4, 1.4};

  EXPECT_EQ(*multiset_ns.begin(), 1.4);
}

TEST(MULTISET_BEGIN, test_xxx_6) {
  ns::multiset<std::string> multiset_ns = {"hello", "hello", "hello"};

  EXPECT_EQ(*multiset_ns.begin(), "hello");
}

TEST(MULTISET_END, test_xxx_1) {
  ns::multiset<int> multiset_ns = {9, 15, 7, 23, 2};

  EXPECT_EQ(*--multiset_ns.end(), 23);
}

TEST(MULTISET_END, test_xxx_2) {
  ns::multiset<double> multiset_ns = {11.4, 2.770001, 3.901, 11.400000001, 3.9};

  EXPECT_EQ(*--multiset_ns.end(), 11.400000001);
}

TEST(MULTISET_END, test_xxx_3) {
  ns::multiset<std::string> multiset_ns = {"hello", "hi", "holliwood", "holli",
                                           "hello, hamlet"};

  EXPECT_EQ(*--multiset_ns.end(), "holliwood");
}

TEST(MULTISET_END, test_xxx_5) {
  ns::multiset<double> multiset_ns = {1.4, 1.4};

  EXPECT_EQ(*--multiset_ns.end(), 1.4);
}

TEST(MULTISET_END, test_xxx_6) {
  ns::multiset<std::string> multiset_ns = {"hello", "hello", "hello"};

  EXPECT_EQ(*--multiset_ns.end(), "hello");
}

TEST(MULTISET_BALANCE, test_xxx_1) {
  ns::multiset<int> multiset_ns = {1, 15, 5};

  EXPECT_EQ(*--multiset_ns.end(), 15);
  EXPECT_EQ(multiset_ns.size(), 3U);
}

TEST(MULTISET_BALANCE, test_xxx_2) {
  ns::multiset<double> multiset_ns = {11.4, 2.770001, 3.901};

  EXPECT_EQ(*--multiset_ns.end(), 11.4);
  EXPECT_EQ(multiset_ns.size(), 3U);
}

TEST(MULTISET_BALANCE, test_xxx_3) {
  ns::multiset<std::string> multiset_ns = {"hello", "hi", "holliwood", "holli",
                                           "hello, hamlet"};

  EXPECT_EQ(*--multiset_ns.end(), "holliwood");
  EXPECT_EQ(multiset_ns.size(), 5U);
}

TEST(MULTISET_BALANCE, test_xxx_4) {
  ns::multiset<int> multiset_ns = {10, 5, 20, 30, 1543};

  EXPECT_EQ(*--multiset_ns.end(), 1543);
  EXPECT_EQ(*multiset_ns.begin(), 5);
  EXPECT_EQ(multiset_ns.size(), 5U);
}

TEST(MULTISET_BALANCE, test_xxx_5) {
  ns::multiset<int> multiset_ns = {30, 5, 43, 1, 20, 40, 60, 35, 32, 32, 35};

  EXPECT_EQ(*--multiset_ns.end(), 60);
  EXPECT_EQ(*multiset_ns.begin(), 1);
  EXPECT_EQ(multiset_ns.size(), 11U);
}

TEST(MULTISET_ERASE, test_xxx_1) {
  std::set<int> multiset_ns = {10, 5, 15, 4, 18, 13, 16};

  auto it = multiset_ns.begin();
  it++;
  it++;
  it++;
  it++;
  multiset_ns.erase(it);
  EXPECT_EQ(*multiset_ns.begin(), 4);
  EXPECT_EQ(*--multiset_ns.end(), 18);
  EXPECT_EQ(multiset_ns.size(), 6U);

  it = multiset_ns.begin();
  multiset_ns.erase(it);
  EXPECT_EQ(*multiset_ns.begin(), 5);
  EXPECT_EQ(*--multiset_ns.end(), 18);
  EXPECT_EQ(multiset_ns.size(), 5U);

  it = multiset_ns.begin();
  it++;
  multiset_ns.erase(it);
  EXPECT_EQ(*multiset_ns.begin(), 5);
  EXPECT_EQ(*--multiset_ns.end(), 18);
  EXPECT_EQ(multiset_ns.size(), 4U);

  it = --multiset_ns.end();
  multiset_ns.erase(it);
  EXPECT_EQ(*multiset_ns.begin(), 5);
  EXPECT_EQ(*--multiset_ns.end(), 16);
  EXPECT_EQ(multiset_ns.size(), 3U);

  it = multiset_ns.begin();
  it++;
  multiset_ns.erase(it);

  it = multiset_ns.begin();
  it++;
  multiset_ns.erase(it);

  it = multiset_ns.begin();
  multiset_ns.erase(it);

  EXPECT_EQ(multiset_ns.size(), 0U);
}

TEST(MULTISET_ERASE, test_xxx_2) {
  ns::multiset<int> multiset_ns = {30, 1543};

  auto it = multiset_ns.begin();
  ++it;
  multiset_ns.erase(it);
  it = multiset_ns.begin();
  multiset_ns.erase(it);

  EXPECT_EQ(multiset_ns.size(), 0U);
}

TEST(MULTISET_ERASE, test_xxx_3) {
  ns::multiset<std::string> multiset_ns = {"hello", "hi", "holliwood", "holli",
                                           "hello, hamlet"};

  auto it = --multiset_ns.end();
  multiset_ns.erase(it);
  EXPECT_EQ(*--multiset_ns.end(), "holli");
  EXPECT_EQ(multiset_ns.size(), 4U);

  it = --multiset_ns.end();
  multiset_ns.erase(it);
  EXPECT_EQ(*--multiset_ns.end(), "hi");
  EXPECT_EQ(multiset_ns.size(), 3U);

  multiset_ns.insert("holliwood");
  multiset_ns.insert("holli");
  it = --multiset_ns.end();
  multiset_ns.erase(it);
  EXPECT_EQ(*--multiset_ns.end(), "holli");
  EXPECT_EQ(multiset_ns.size(), 4U);
}

TEST(MULTISET_ERASE, test_xxx_4) {
  ns::multiset<double> multiset_ns = {22.2, 12.4457, 56.84, 941.44, 45.11};

  auto it = --multiset_ns.end();
  it--;
  multiset_ns.erase(it);
  it = --multiset_ns.end();
  EXPECT_EQ(*it, 941.44);
  EXPECT_EQ(multiset_ns.size(), 4U);

  it = multiset_ns.begin();
  ++it;
  ++it;
  ++it;
  multiset_ns.erase(it);
  it = multiset_ns.begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(*--multiset_ns.end(), 45.11);
  EXPECT_EQ(multiset_ns.size(), 3U);
}

TEST(MULTISET_ERASE, test_xxx_5) {
  ns::multiset<double> multiset_ns = {22.2, 45.11, 12.4457, 1.44};

  auto it = multiset_ns.begin();
  --it;
  --it;
  --it;
  multiset_ns.erase(it);
  it = multiset_ns.begin();
  ++it;
  ++it;
  EXPECT_EQ(*it, 45.11);
  EXPECT_EQ(multiset_ns.size(), 3U);
}

TEST(MULTISET_ERASE, test_xxxX_5) {
  ns::multiset<double> multiset_ns = {22.2,  45.11, 45.11,   45.11,
                                      45.11, 45.11, 12.4457, 1.44};
  multiset_ns.erase(45.11);
  multiset_ns.erase(12.4457);
  EXPECT_EQ(multiset_ns.size(), 2U);
}

TEST(MULTISET_ERASE, test_xxx_6) {
  ns::multiset<double> multiset_ns = {22.2, 45.11, 12.4457, 6.84, 1.44};

  auto it = multiset_ns.begin();
  ++it;
  ++it;
  ++it;
  multiset_ns.erase(it);
  it = multiset_ns.begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(*it, 45.11);
  EXPECT_EQ(multiset_ns.size(), 4U);
}

TEST(MULTISET_ERASE, test_xxx_7) {
  ns::multiset<double> multiset_ns = {22.2, 12.4457, 56.84, 941.44, 45.11};

  auto it = multiset_ns.begin();
  ++it;
  multiset_ns.erase(it);
  it = multiset_ns.begin();
  ++it;
  EXPECT_EQ(*it, 45.11);
  EXPECT_EQ(multiset_ns.size(), 4U);
}

TEST(MULTISET_ERASE, test_xxx_8) {
  ns::multiset<double> multiset_ns = {22.2, 45.11, 12.4457, 1.44};

  auto it = multiset_ns.begin();
  ++it;
  multiset_ns.erase(it);
  it = multiset_ns.begin();
  ++it;
  EXPECT_EQ(*it, 22.2);
  EXPECT_EQ(multiset_ns.size(), 3U);
}

TEST(MULTISET_ERASE, test_xxx_9) {
  ns::multiset<double> multiset_ns = {22.2,  45.11, 12.4457, 32.45,
                                      65.12, 66.32, 40.54,   6.4};

  auto it = --multiset_ns.end();
  --it;
  --it;
  --it;
  --it;
  multiset_ns.erase(it);
  it = multiset_ns.begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(*it, 40.54);
  EXPECT_EQ(multiset_ns.size(), 7U);
}

TEST(MULTISET_ERASE, test_xxx_10) {
  ns::multiset<double> multiset_ns = {22.2};

  auto it = --multiset_ns.end();
  --it;
  ++it;
  multiset_ns.erase(it);
  EXPECT_EQ(multiset_ns.size(), 0U);
}

TEST(MULTISET_EMPTY, test_xxx_1) {
  ns::multiset<double> multiset_ns = {22.2, 45.11, 12.4457, 1.44};

  EXPECT_EQ(multiset_ns.empty(), 0);
}

TEST(MULTISET_EMPTY, test_xxx_2) {
  ns::multiset<double> multiset_ns;

  EXPECT_EQ(multiset_ns.empty(), 1);
}

TEST(MULTISET_SWAP, test_xxx_1) {
  ns::multiset<double> multiset_ref = {22.2, 45.11};
  ns::multiset<double> multiset_res = {12.4457, 1.44, 22.2};

  multiset_ref.swap(multiset_res);

  EXPECT_EQ(multiset_ref.size(), 3U);
  EXPECT_EQ(*multiset_ref.begin(), 1.44);

  EXPECT_EQ(multiset_res.size(), 2U);
  EXPECT_EQ(*multiset_res.begin(), 22.2);
}

TEST(MULTISET_SWAP, test_xxx_2) {
  ns::multiset<double> multiset_ref = {22.2, 45.11};
  ns::multiset<double> multiset_res;

  multiset_ref.swap(multiset_res);

  EXPECT_EQ(multiset_ref.size(), 0U);

  EXPECT_EQ(multiset_res.size(), 2U);
  EXPECT_EQ(*multiset_res.begin(), 22.2);
}

TEST(MULTISET_SWAP, test_xxx_3) {
  ns::multiset<double> multiset_ref;
  ns::multiset<double> multiset_res = {12.4457, 1.44, 22.2};

  multiset_ref.swap(multiset_res);

  EXPECT_EQ(multiset_ref.size(), 3U);
  EXPECT_EQ(*multiset_ref.begin(), 1.44);

  EXPECT_EQ(multiset_res.size(), 0U);
}

TEST(MULTISET_SWAP, test_xxx_4) {
  ns::multiset<double> multiset_ref;
  ns::multiset<double> multiset_res;

  multiset_ref.swap(multiset_res);

  EXPECT_EQ(multiset_ref.size(), 0U);
  EXPECT_EQ(multiset_res.size(), 0U);
}

TEST(MULTISET_CONTAINS, test_xxx_1) {
  ns::multiset<double> multiset_ns = {22.2, 45.11};

  EXPECT_EQ(multiset_ns.contains(22.2), true);
  EXPECT_EQ(multiset_ns.contains(45.11), true);
}

TEST(MULTISET_CONTAINS, test_xxx_2) {
  ns::multiset<double> multiset_ref = {22.2, 45.11};
  ns::multiset<double> multiset_res;

  multiset_ref.swap(multiset_res);

  EXPECT_EQ(multiset_ref.size(), 0U);
  EXPECT_EQ(multiset_ref.contains(22.2), false);
  EXPECT_EQ(multiset_ref.contains(45.11), false);

  EXPECT_EQ(multiset_res.size(), 2U);
  EXPECT_EQ(multiset_res.contains(22.2), true);
  EXPECT_EQ(multiset_res.contains(45.11), true);
}

TEST(MULTISET_CONTAINS, test_xxx_3) {
  ns::multiset<double> multiset_ref;
  ns::multiset<double> multiset_res = {12.4457, 1.44, 22.2};

  multiset_ref.swap(multiset_res);

  EXPECT_EQ(multiset_ref.size(), 3U);
  EXPECT_EQ(multiset_ref.contains(12.4457), true);
  EXPECT_EQ(multiset_ref.contains(1.44), true);
  EXPECT_EQ(multiset_ref.contains(22.2), true);

  EXPECT_EQ(multiset_res.size(), 0U);
  EXPECT_EQ(multiset_res.contains(12.4457), false);
  EXPECT_EQ(multiset_res.contains(1.44), false);
  EXPECT_EQ(multiset_res.contains(22.2), false);
}

TEST(MULTISET_CONTAINS, test_xxx_4) {
  ns::multiset<double> multiset_ns;

  EXPECT_EQ(multiset_ns.size(), 0U);
  EXPECT_EQ(multiset_ns.contains(12.4457), false);
}

TEST(MULTISET_FIND, test_xxx_1) {
  std::set<double> multiset_ns;

  EXPECT_TRUE(multiset_ns.find(23.4) == multiset_ns.end());
}

TEST(MULTISET_FIND, test_xxx_2) {
  ns::multiset<double> multiset_ns = {12.4457, 1.44, 22.2};

  auto it = multiset_ns.begin();
  ++it;
  EXPECT_EQ(*multiset_ns.find(12.4457), *it);

  it--;
  EXPECT_EQ(*multiset_ns.find(1.44), *it);

  ++it;
  ++it;
  EXPECT_EQ(*multiset_ns.find(22.2), *it);
}

TEST(MULTISET_INSERT_MANY, test_xxx_1) {
  ns::multiset<int> multiset_ns;

  std::vector<std::pair<ns::multiset<int>::iterator, bool>> ins_many1 =
      multiset_ns.insert_many(99, 99, 99, 230, 98);

  EXPECT_EQ(*ins_many1[3].first, 230);
  EXPECT_EQ(ins_many1[1].second, true);
  EXPECT_EQ(multiset_ns.size(), 5U);
}

TEST(MULTISET_INSERT_MANY, test_xxx_2) {
  ns::multiset<double> multiset_ns;

  std::vector<std::pair<ns::multiset<double>::iterator, bool>> ins_many1 =
      multiset_ns.insert_many(11.4, 27., 39., 27., 39.);

  EXPECT_EQ(*ins_many1[4].first, 39);
  EXPECT_EQ(ins_many1[1].second, true);
  EXPECT_EQ(multiset_ns.size(), 5U);
}

TEST(MULTISET_INSERT_MANY, test_xxx_3) {
  ns::multiset<std::string> multiset_ns;

  std::vector<std::pair<ns::multiset<std::string>::iterator, bool>> ins_many1 =
      multiset_ns.insert_many("hello", "hi", "hi", "holli", "hello");

  EXPECT_EQ(*ins_many1[4].first, "hello");
  EXPECT_EQ(ins_many1[0].second, true);
  EXPECT_EQ(multiset_ns.size(), 5U);
}

TEST(MULTISET_INSERT_MANY, test_xxx_4) {
  ns::multiset<int> multiset_ns;

  std::vector<std::pair<ns::multiset<int>::iterator, bool>> ins_many1 =
      multiset_ns.insert_many(9);

  EXPECT_EQ(*ins_many1[0].first, 9);
  EXPECT_EQ(ins_many1[0].second, true);
  EXPECT_EQ(multiset_ns.size(), 1U);
}

TEST(MULTISET_INSERT_MANY, test_xxx_5) {
  ns::multiset<double> multiset_ns = {1.4};

  std::vector<std::pair<ns::multiset<double>::iterator, bool>> ins_many1 =
      multiset_ns.insert_many(1.4);

  EXPECT_EQ(ins_many1[0].second, true);
  EXPECT_EQ(multiset_ns.size(), 2U);
}

TEST(MULTISET_INSERT_MANY, test_xxx_6) {
  ns::multiset<std::string> multiset_ns = {"hello"};

  std::vector<std::pair<ns::multiset<std::string>::iterator, bool>> ins_many1 =
      multiset_ns.insert_many("hi");

  EXPECT_EQ(*ins_many1[0].first, "hi");
  EXPECT_EQ(ins_many1[0].second, true);
  EXPECT_EQ(multiset_ns.size(), 2U);
}

TEST(MULTISET, DEFAULT_CONSTRUCTOR_TEST_1) {
  ns::multiset<NotDefaultConstructor> a;
  EXPECT_EQ(a.size(), 0U);
}

TEST(MULTISET, CONSTRUCTOR_INIT_LIST_TEST_2) {
  ns::multiset<int> a{12, 13, 14, 15, 16, 17};
  EXPECT_EQ(a.size(), 6U);
  EXPECT_EQ(*a.begin(), 12);
}

TEST(MULTISET, CONSTRUCTOR_COPY_TEST_3) {
  ns::multiset<int> a{12, 13, 14, 15, 16, 17};
  ns::multiset<int> b(a);
  EXPECT_EQ(a.size(), 6U);
  EXPECT_EQ(*a.begin(), 12);
  EXPECT_EQ(b.size(), 6U);
  EXPECT_EQ(*b.begin(), 12);
}

TEST(MULTISET, CONSTRUCTOR_MOVE_TEST_4) {
  ns::multiset<int> a{12, 13, 14, 15, 16, 17};
  ns::multiset<int> b(std::move(a));
  const auto it_begin = a.begin();
  const auto it_end = a.end();
  EXPECT_EQ(a.size(), 0U);
  EXPECT_TRUE(a.begin() == a.end());
  EXPECT_TRUE(it_begin == it_end);
  EXPECT_TRUE(a.cbegin() == a.cend());
  EXPECT_EQ(b.size(), 6U);
  EXPECT_EQ(*b.begin(), 12);
}

TEST(MULTISET, OPERATOR_EQ_MOVE_TEST_5) {
  ns::multiset<int> a{12, 13, 14, 15, 16, 17};
  ns::multiset<int> b;
  b = std::move(a);
  const auto it_begin = a.begin();
  const auto it_end = a.end();
  EXPECT_EQ(a.size(), 0U);
  EXPECT_TRUE(a.empty());
  EXPECT_TRUE(a.begin() == a.end());
  EXPECT_TRUE(it_begin == it_end);
  EXPECT_TRUE(a.cbegin() == a.cend());
  EXPECT_EQ(b.size(), 6U);
  EXPECT_EQ(*b.begin(), 12);
}

TEST(MULTISET, OPERATOR_EQ_COPY_TEST_6) {
  ns::multiset<int> a{12, 13, 14, 15, 16, 17};
  ns::multiset<int> b;
  b = a;
  EXPECT_EQ(a.size(), 6U);
  EXPECT_EQ(*a.begin(), 12);
  EXPECT_EQ(b.size(), 6U);
  EXPECT_EQ(*b.begin(), 12);
}

TEST(MULTISET, INSERT_TEST_7) {
  ns::multiset<int> a{12, 13, 14, 15, 16, 17, 4, -1000, 8};
  ns::multiset<int> b;
  ns::multiset<int> c;
  for (auto item : a) {
    b.insert(item);
  }
  for (auto i = (--b.end()); i != b.end(); --i) {
    c.insert(*i - 1);
  }
  EXPECT_EQ(a.size(), 9U);
  EXPECT_EQ(*a.begin(), -1000);
  EXPECT_EQ(b.size(), 9U);
  EXPECT_EQ(*b.begin(), -1000);
  EXPECT_EQ(*c.begin(), -1001);
  EXPECT_TRUE(++b.end() == b.begin());
}

TEST(MULTISET, ERASE_TEST_8) {
  ns::multiset<int> a{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(a.size(), 27U);
  for (int i = -1000; i <= 1000; ++i) {
    a.insert(i);
  }
  while (!a.empty()) {
    a.erase(a.begin());
    a.erase(--a.end());
  }
  EXPECT_EQ(a.size(), 0U);
}

TEST(MULTISET, BINARY_EQ_STD_SET_TEST_9) {
  ns::multiset<int> multiset_ns;
  std::multiset<int> std_set;
  for (int i = -100; i <= 100; ++i) {
    std_set.insert(i);
    multiset_ns.insert(-i);
  }
  for (int i = 100; i <= 300; ++i) {
    std_set.insert(i);
    multiset_ns.insert(i);
  }
  auto it_ns = multiset_ns.begin();
  for (auto it = std_set.begin(); it != std_set.end(); ++it, ++it_ns) {
    EXPECT_EQ(*it_ns, *it);
  }
}

TEST(MULTISET, MERGE_TEST_10) {
  ns::multiset<int> multimultiset_a;
  ns::multiset<int> multimultiset_b;
  for (int i = -100; i <= 100; ++i) {
    multimultiset_a.insert(-i);
    multimultiset_b.insert(-i);
  }
  multimultiset_a.merge(multimultiset_b);
  EXPECT_EQ(0U, multimultiset_b.size());
  multimultiset_a.erase(multimultiset_a.begin());
  EXPECT_EQ(*multimultiset_a.begin(), -100);
  multimultiset_a.erase(multimultiset_a.begin());
  EXPECT_EQ(*multimultiset_a.begin(), -99);
  EXPECT_EQ(0U, multimultiset_b.size());
}

TEST(MULTISET, INSERT_MANY_TEST_11) {
  ns::multiset<int> a;
  a.insert_many(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8,
                9, 10);
  ns::multiset<char> b;
  b.insert_many('c', 'd', 'e', 'f', 'g', 'a', 'c');
  EXPECT_EQ(a.empty(), b.empty());
  EXPECT_EQ(a.size(), 22U);
  EXPECT_EQ(b.size(), 7U);
  EXPECT_TRUE(a.contains(12));
  EXPECT_TRUE(!a.contains(13));
  a.clear();
  EXPECT_FALSE(a.contains(12));
  EXPECT_EQ(a.size(), 0U);
  EXPECT_TRUE(b.contains('f'));
  EXPECT_TRUE(!b.contains('h'));
  b.clear();
  b.clear();
  EXPECT_EQ(b.size(), 0U);
}

TEST(MULTISET, SWAP_TEST_12) {
  ns::multiset<int> multimultiset_a;
  ns::multiset<int> multimultiset_b;
  for (int i = -100; i <= 100; ++i) {
    multimultiset_a.insert(-i);
  }
  EXPECT_EQ(multimultiset_a.size(), 201U);
  multimultiset_a.swap(multimultiset_b);
  EXPECT_EQ(*multimultiset_b.begin(), -100);
  EXPECT_EQ(multimultiset_b.size(), 201U);
  EXPECT_EQ(multimultiset_a.size(), 0U);
  EXPECT_TRUE(multimultiset_a.empty());
}

TEST(MULTISET, FIND_TEST_13) {
  ns::multiset<std::size_t> multimultiset_a;
  for (std::size_t i = 100; i <= 3000; ++i) {
    multimultiset_a.insert(i);
  }
  std::size_t max_s = multimultiset_a.max_size();
  multimultiset_a.insert(max_s);
  EXPECT_EQ(*(--multimultiset_a.end()), max_s);
  EXPECT_TRUE(multimultiset_a.contains(max_s));
  multimultiset_a.erase(multimultiset_a.find(max_s));
  EXPECT_TRUE(!multimultiset_a.contains(max_s));
  ns::multiset<int> const c{1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (const auto i : c) {
    EXPECT_TRUE(i);
  }
}

TEST(MULTISET_COUNT, test_xxx_14) {
  ns::multiset<double> multiset_ns = {22.2, 45.11, 22.2, 22.2, 22.2};

  EXPECT_EQ(multiset_ns.count(22.2), 4U);
  EXPECT_EQ(multiset_ns.count(45.11), 1U);
  EXPECT_EQ(multiset_ns.count(43.11), 0U);
}

TEST(MULTISET_LOWER_BOUND, test_xxx_1) {
  ns::multiset<int> multiset_ns = {1, 1,  2, 3, 4, 5, 1, 3, 7, 8,
                                   9, -9, 7, 8, 5, 4, 8, 9, 6};
  std::multiset<int> multiset_std = {1, 1,  2, 3, 4, 5, 1, 3, 7, 8,
                                     9, -9, 7, 8, 5, 4, 8, 9, 6};
  EXPECT_EQ(*multiset_ns.lower_bound(5), 5);
  EXPECT_EQ(*multiset_std.lower_bound(5), 5);

  EXPECT_EQ(*multiset_ns.lower_bound(-9), -9);
  EXPECT_EQ(*multiset_std.lower_bound(-9), -9);

  EXPECT_EQ(*multiset_ns.lower_bound(9), 9);
  EXPECT_EQ(*multiset_std.lower_bound(9), 9);

  EXPECT_TRUE(multiset_ns.lower_bound(44) == multiset_ns.end());
  EXPECT_TRUE(multiset_std.lower_bound(44) == multiset_std.end());

  EXPECT_EQ(*multiset_ns.lower_bound(-6), 1);
  EXPECT_EQ(*multiset_std.lower_bound(-6), 1);

  EXPECT_EQ(*multiset_ns.lower_bound(-11), -9);
  EXPECT_EQ(*multiset_std.lower_bound(-11), -9);
}

TEST(MULTISET_UPPER_BOUND, test_xxx_1) {
  ns::multiset<int> multiset_ns = {1, 1,  2, 3, 4, 5, 1, 3, 7, 8,
                                   9, -9, 7, 8, 5, 4, 8, 9, 6};
  std::multiset<int> multiset_std = {1, 1,  2, 3, 4, 5, 1, 3, 7, 8,
                                     9, -9, 7, 8, 5, 4, 8, 9, 6};
  EXPECT_EQ(*multiset_ns.upper_bound(5), 6);
  EXPECT_EQ(*multiset_std.upper_bound(5), 6);

  EXPECT_EQ(*multiset_ns.upper_bound(-9), 1);
  EXPECT_EQ(*multiset_std.upper_bound(-9), 1);

  EXPECT_EQ(*multiset_ns.upper_bound(7), 8);
  EXPECT_EQ(*multiset_std.upper_bound(7), 8);

  EXPECT_TRUE(multiset_ns.upper_bound(9) == multiset_ns.end());
  EXPECT_TRUE(multiset_std.upper_bound(9) == multiset_std.end());

  EXPECT_EQ(*multiset_ns.upper_bound(-6), 1);
  EXPECT_EQ(*multiset_std.upper_bound(-6), 1);

  EXPECT_EQ(*multiset_ns.upper_bound(-11), -9);
  EXPECT_EQ(*multiset_std.upper_bound(-11), -9);
}

TEST(MULTISET_EQUAL_RANGE, test_xxx_1) {
  ns::multiset<int> multiset_ns = {1, 1,  2, 3, 4, 5, 1, 3, 7, 8,
                                   9, -9, 7, 8, 5, 4, 8, 9, 6};
  std::multiset<int> multiset_std = {1, 1,  2, 3, 4, 5, 1, 3, 7, 8,
                                     9, -9, 7, 8, 5, 4, 8, 9, 6};
  EXPECT_EQ(*multiset_ns.equal_range(5).second, 6);
  EXPECT_EQ(*multiset_std.equal_range(5).second, 6);

  EXPECT_EQ(*multiset_ns.equal_range(-9).second, 1);
  EXPECT_EQ(*multiset_std.equal_range(-9).second, 1);

  EXPECT_EQ(*multiset_ns.equal_range(7).second, 8);
  EXPECT_EQ(*multiset_std.equal_range(7).second, 8);

  EXPECT_TRUE(multiset_ns.equal_range(9).second == multiset_ns.end());
  EXPECT_TRUE(multiset_std.equal_range(9).second == multiset_std.end());

  EXPECT_EQ(*multiset_ns.equal_range(-6).second, 1);
  EXPECT_EQ(*multiset_std.equal_range(-6).second, 1);

  EXPECT_EQ(*multiset_ns.equal_range(-11).second, -9);
  EXPECT_EQ(*multiset_std.equal_range(-11).second, -9);
}

TEST(MULTISET_EQUAL_RANGE, test_xxx_2) {
  ns::multiset<int> multiset_ns = {1, 1,  2, 3, 4, 5, 1, 3, 7, 8,
                                   9, -9, 7, 8, 5, 4, 8, 9, 6};
  std::multiset<int> multiset_std = {1, 1,  2, 3, 4, 5, 1, 3, 7, 8,
                                     9, -9, 7, 8, 5, 4, 8, 9, 6};
  EXPECT_EQ(*multiset_ns.equal_range(5).first, 5);
  EXPECT_EQ(*multiset_std.equal_range(5).first, 5);

  EXPECT_EQ(*multiset_ns.equal_range(-9).first, -9);
  EXPECT_EQ(*multiset_std.equal_range(-9).first, -9);

  EXPECT_EQ(*multiset_ns.equal_range(9).first, 9);
  EXPECT_EQ(*multiset_std.equal_range(9).first, 9);

  EXPECT_TRUE(multiset_ns.equal_range(44).first == multiset_ns.end());
  EXPECT_TRUE(multiset_std.equal_range(44).first == multiset_std.end());

  EXPECT_EQ(*multiset_ns.equal_range(-6).first, 1);
  EXPECT_EQ(*multiset_std.equal_range(-6).first, 1);

  EXPECT_EQ(*multiset_ns.equal_range(-11).first, -9);
  EXPECT_EQ(*multiset_std.equal_range(-11).first, -9);
}