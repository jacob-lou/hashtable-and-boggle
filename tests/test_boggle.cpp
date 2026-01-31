#include <gtest/gtest.h>
#include <set>
#include <vector>
#include "boggle.h"

TEST(Boggle, StraightLineFindsWords) {
  // board:
  // A B
  // C D
  std::vector<std::vector<char>> board = {{'A','B'},{'C','D'}};

  std::set<std::string> dict = {"AB", "AC", "AD", "ABC"};
  std::set<std::string> prefix = {"", "A", "AB", "AC", "AD", "ABC"};

  auto res = boggle(dict, prefix, board);
  EXPECT_TRUE(res.count("AB") > 0);
  EXPECT_TRUE(res.count("AC") > 0);
  // "ABC" 需要沿同一方向连续（你实现是固定方向），这里不强求
}
