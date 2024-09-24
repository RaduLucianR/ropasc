#include <iostream>
#include <cstdint>
#include <utils.hpp>
#include <array>

int main() {
    std::string player_input;
    
    std::cout << "Welcome to Rock-Paper-Scissors!" << std::endl;
    std::cout << "Enter rock, paper, or scissors (or 'q' to quit): ";

    while (std::cin >> player_input && player_input != "q") {
        bool validInput = player_input == "rock" || player_input == "scissors" || player_input == "paper";
        int player_option = get_player_option(player_input);    // Convert player's option to integer
        int computer_option = get_computer_option();            // Get integer computer option

        std::cout << computer_answer(computer_option, validInput); // Empty string for invalid input
        std::cout << winner(player_option, computer_option, validInput);
        std::cout << "Enter rock, paper, or scissors (or 'q' to quit): ";
    }

    std::cout << "Goodbye!";
    return 0;
}