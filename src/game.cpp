#include "game.hpp"
#include <random>
#include <array>
#include <iostream>

/**
 * Global declarations to avoid instantiating
 * the RNG every time a new random number is needed.
 */
std::random_device seeder;
std::mt19937 engine(seeder());
std::uniform_int_distribution<int> dist(0, 2);

constexpr std::array<const char*, 4> results = {
        "It's a tie!\n",
        "You win!\n",
        "Computer wins!\n", 
        "Invalid input!\n"
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
int get_player_option(const std::string& input, bool validInput) {
    return ((input[1 * validInput] - 97) % 10) / 2;
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

/**
 * Integrate all the steps into one function.
 */
std::string game_round(std::string player_input) {
    // Check if the input is valid
    bool validInput = player_input == "rock" || player_input == "scissors" || player_input == "paper";

    // Convert player's option to integer
    int player_option = get_player_option(player_input, validInput);
    int computer_option = get_computer_option();

    // Get the result in a string
    std::string result = computer_answer(computer_option, validInput) +
                         winner(player_option, computer_option, validInput);

    return result;
}