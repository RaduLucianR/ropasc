#include <gtest/gtest.h>
#include <utils.hpp>

TEST(RockPaperScissorsTest, GetPlayerOption) {
    EXPECT_EQ(get_player_option("paper"), 0);
    EXPECT_EQ(get_player_option("scissors"), 1);
    EXPECT_EQ(get_player_option("rock"), 2);
}

/**
 * 0 is paper
 * 1 is scissors
 * 2 is rock
 */
TEST(RockPaperScissorsTest, Winner) {
    EXPECT_EQ(winner(0, 0), "It's a tie!");
    EXPECT_EQ(winner(0, 1), "Computer wins!");
    EXPECT_EQ(winner(0, 2), "You win!");
    EXPECT_EQ(winner(1, 0), "You win!");
    EXPECT_EQ(winner(1, 1), "It's a tie!");
    EXPECT_EQ(winner(1, 2), "Computer wins!");
    EXPECT_EQ(winner(2, 0), "Computer wins!");
    EXPECT_EQ(winner(2, 1), "You win!");
    EXPECT_EQ(winner(2, 2), "It's a tie!");
}

TEST(RockPaperScissorsTest, GetComputerOption) {
    std::set<int> valid_options = {0, 1, 2};

    for (int i = 0; i < 100; i ++) {
        int option = get_computer_option();
        
        EXPECT_TRUE(valid_options.find(option) != valid_options.end());
    }
}