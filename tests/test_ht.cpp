#include <gtest/gtest.h>
#include <string>
#include "ht.h"
#include "hash.h"

TEST(HashTable, InsertFindRemove) {
  using HT = HashTable<std::string, int, MyStringHash, LinearProber<std::string>>;
  HT ht(0.7);

  ht.insert({"a", 1});
  ht.insert({"b", 2});
  EXPECT_EQ(ht.at("a"), 1);
  EXPECT_EQ(ht.at("b"), 2);

  ht.remove("a");
  EXPECT_EQ(ht.find("a"), nullptr);
  EXPECT_EQ(ht.at("b"), 2);
}
