#include <string>

/**
 * @brief Get random computer option. 
 * 
 * @return A random integer from [0, 2].
 */ 
int get_computer_option();

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
int get_player_option(const std::string& input);

/**
 * @brief Compute rock-paper-scissors result.
 * 
 * @param player The option chosen by the player.
 * @param computer The option chosen by the computer.
 * @param validInput Whether the player's input is valid.
 * @return String that states the result.
 * 
 * @pre `player` and `computer` shall be 0, 1 or 2.
 * @pre `validInput` shall be 0 or 1.
 */
std::string winner(int player, int computer, bool validInput);

/**
 * @brief Return the string that states the computer's answer.
 * 
 * @param computer The option chosen by the computer.
 * @param validInput Whether the player's input is valid.
 * @return String that states the computer's answer if input is valid.
 * If the input is not valid, then return an empty string.
 * 
 * @pre `player` and `computer` shall be 0, 1 or 2.
 * @pre `validInput` shall be 0 or 1.
 */
std::string computer_answer(int computer, bool validInput);