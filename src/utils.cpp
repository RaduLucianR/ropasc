#include "utils.hpp"
#include <random>
#include <array>

// Globals
std::random_device seeder;
std::mt19937 engine(seeder());
std::uniform_int_distribution<int> dist(0, 2);

constexpr std::array<const char*, 4> results = {
        "It's a tie!\n", 
        "You win!\n", 
        "Computer wins!\n", 
        "Invalid input\n"
    };

constexpr std::array<const char*, 4> options = {
        "Computer chose: paper\n", 
        "Computer chose: scissors\n", 
        "Computer chose: rock\n",
        ""
    };

/**
 * Source: https://stackoverflow.com/a/12658061
 */
int get_computer_option() {
    return dist(engine);
}

/**
 * Hash based on the 2nd character of the option:
 * 'o' for rock     i.e. 111 in ASCII
 * 'c' for scissors i.e. 99  in ASCII
 * 'a' for paper    i.e. 97  in ASCII
 */
int get_player_option(const std::string& input) {
    return ((input[1] - 97) % 10) / 2;
}

/**
 * Index the possible results with modulo arithmetic.
 * 
 * Interpolating with the validInput has the same effect as an if-statement.
 * If the input is valid, then pick one of the three possible results:
 *      i.e. tie, player wins, computer wins.
 * If the input is not valid, then pick the last result, i.e. invalid input.
 */
std::string winner(int player, int computer, bool validInput) {
    return results[((player - computer + 3) % 3) * validInput + 3 * (1 - validInput)];
}

/**
 * Index the computer's answer (string) based on its integer choice.
 * 
 * Interpolating with the validInput has the same effect as an if-statement.
 * If the input is valid, then pick the corresponding string for the choice.
 *      e.g. if the computer's choice is 2 then pick "Computer chose: rock\n"
 * If the input is not valid, then pick the last result, i.e. an empty string.
 */
std::string computer_answer(int computer, bool validInput) {
    return options[computer * validInput + 3 * (1 - validInput)];
}