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
    EXPECT_EQ(winner(0, 0, 1), "It's a tie!\n");
    EXPECT_EQ(winner(0, 1, 1), "Computer wins!\n");
    EXPECT_EQ(winner(0, 2, 1), "You win!\n");
    EXPECT_EQ(winner(1, 0, 1), "You win!\n");
    EXPECT_EQ(winner(1, 1, 1), "It's a tie!\n");
    EXPECT_EQ(winner(1, 2, 1), "Computer wins!\n");
    EXPECT_EQ(winner(2, 0, 1), "Computer wins!\n");
    EXPECT_EQ(winner(2, 1, 1), "You win!\n");
    EXPECT_EQ(winner(2, 2, 1), "It's a tie!\n");
    EXPECT_EQ(winner(0, 0, 0), "Invalid input\n");
    EXPECT_EQ(winner(0, 1, 0), "Invalid input\n");
    EXPECT_EQ(winner(0, 2, 0), "Invalid input\n");
    EXPECT_EQ(winner(1, 0, 0), "Invalid input\n");
    EXPECT_EQ(winner(1, 1, 0), "Invalid input\n");
    EXPECT_EQ(winner(1, 2, 0), "Invalid input\n");
    EXPECT_EQ(winner(2, 0, 0), "Invalid input\n");
    EXPECT_EQ(winner(2, 1, 0), "Invalid input\n");
    EXPECT_EQ(winner(2, 2, 0), "Invalid input\n");
}

TEST(RockPaperScissorsTest, GetComputerOption) {
    std::set<int> valid_options = {0, 1, 2};

    for (int i = 0; i < 100; i ++) {
        int option = get_computer_option();
        
        EXPECT_TRUE(valid_options.find(option) != valid_options.end());
    }
}

TEST(RockPaperScissorsTest, ComputerAnswer) { 
    EXPECT_EQ(computer_answer(0, 1), "Computer chose: paper\n");
    EXPECT_EQ(computer_answer(1, 1), "Computer chose: scissors\n");
    EXPECT_EQ(computer_answer(2, 1), "Computer chose: rock\n");
    EXPECT_EQ(computer_answer(0, 0), "");
    EXPECT_EQ(computer_answer(1, 0), "");
    EXPECT_EQ(computer_answer(2, 0), "");
}