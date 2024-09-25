#include <gtest/gtest.h>
#include <gmock/gmock.h> 
#include "game.hpp"

TEST(RockPaperScissorsTest, GetPlayerOptionValidInput) {
    EXPECT_EQ(get_player_option("paper",    1), 0);
    EXPECT_EQ(get_player_option("scissors", 1), 1);
    EXPECT_EQ(get_player_option("rock",     1), 2);
}

TEST(RockPaperScissorsTest, GetPlayerOptionInvalidInput) {
    EXPECT_EQ(get_player_option("pape",    0), 2);
    EXPECT_EQ(get_player_option("scissor", 0), 4);
    EXPECT_EQ(get_player_option("roc",     0), 3);
    EXPECT_EQ(get_player_option("",        0), -3);
    EXPECT_EQ(get_player_option("r",       0), 3);
    EXPECT_EQ(get_player_option("sBkqfIWvAVrh8pfyJQbSaa304aZtc1WlvBLO0yCUpA7MQpICBm", 0), 4);
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
}

TEST(RockPaperScissorsTest, WinnerInvalid) {
    EXPECT_EQ(winner(0, 0, 0), "Invalid input!\n");
    EXPECT_EQ(winner(0, 1, 0), "Invalid input!\n");
    EXPECT_EQ(winner(0, 2, 0), "Invalid input!\n");
    EXPECT_EQ(winner(1, 0, 0), "Invalid input!\n");
    EXPECT_EQ(winner(1, 1, 0), "Invalid input!\n");
    EXPECT_EQ(winner(1, 2, 0), "Invalid input!\n");
    EXPECT_EQ(winner(2, 0, 0), "Invalid input!\n");
    EXPECT_EQ(winner(2, 1, 0), "Invalid input!\n");
    EXPECT_EQ(winner(2, 2, 0), "Invalid input!\n");
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

TEST(RockPaperScissorsTest, MainLogicValidInput) { 
    EXPECT_THAT(game_round("rock"), testing::AnyOf(
        testing::Eq("Computer chose: paper\nComputer wins!\n"), 
        testing::Eq("Computer chose: rock\nIt's a tie!\n"), 
        testing::Eq("Computer chose: scissors\nYou win!\n")
        ));

    EXPECT_THAT(game_round("paper"), testing::AnyOf(
        testing::Eq("Computer chose: paper\nIt's a tie!\n"), 
        testing::Eq("Computer chose: rock\nYou win!\n"), 
        testing::Eq("Computer chose: scissors\nComputer wins!\n")
        ));

    EXPECT_THAT(game_round("scissors"), testing::AnyOf(
        testing::Eq("Computer chose: paper\nYou win!\n"), 
        testing::Eq("Computer chose: rock\nComputer wins!\n"), 
        testing::Eq("Computer chose: scissors\nIt's a tie!\n")
        ));
}

TEST(RockPaperScissorsTest, MainLogicInvalidInput) { 
    EXPECT_THAT(game_round("r"), "Invalid input!\n");
    EXPECT_THAT(game_round("a"), "Invalid input!\n");
    EXPECT_THAT(game_round("roc"), "Invalid input!\n");
    EXPECT_THAT(game_round("0"), "Invalid input!\n");
    EXPECT_THAT(game_round(""), "Invalid input!\n");
    EXPECT_THAT(game_round("sBkqfIWvAVrh8pfyJQbSaa304aZtc1WlvBLO0yCUpA7MQpICBm"), "Invalid input!\n");
}