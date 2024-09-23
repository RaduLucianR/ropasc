#include "utils.hpp"
#include <random>
#include <array>

// Globals
std::random_device seeder;
std::mt19937 engine(seeder());
std::uniform_int_distribution<int> dist(0, 2);
constexpr std::array<const char*, 3> results = {"It's a tie!", "You win!", "Computer wins!"};

/**
 * @brief Get random computer option. 
 * Source: https://stackoverflow.com/a/12658061
 * 
 * @return A random integer from [0, 2].
 */ 
int get_computer_option() {
    return dist(engine);
}

/**
 * @brief Map options to numbers
 * 
 * @param input String with the player's option
 * 
 * @return Based on the mapping:
 *  "paper"    => 0 
 *  "scissors" => 1 
 *  "rock"     => 2
 * 
 * @pre `input` shall be "rock" or "paper" or "scissors".
 */
int get_player_option(const std::string& input) {
    return ((input[1] - 97) % 10) / 2;
}

/**
 * @brief Compute rock-paper-scissors result.
 * 
 * @param player The option chosen by the player.
 * @param computer The option chosen by the computer.
 * @return String that states the result.
 * 
 * @pre `player` and `computer` shall be 0, 1 or 2.
 */
std::string winner(int player, int computer) {
    return results[(player - computer + 3) % 3];
}