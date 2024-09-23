#include <iostream>
#include <cstdint>
#include <utils.hpp>
#include <array>

constexpr std::array<const char*, 3> options = {"paper", "scissors", "rock"};

int main() {
    std::string player_input;
    
    std::cout << "Welcome to Rock-Paper-Scissors!" << std::endl;
    std::cout << "Enter rock, paper, or scissors (or 'q' to quit): ";

    while (std::cin >> player_input) {
        if (player_input == "q") break;

        try {
            int player_option = get_player_option(player_input);
            int computer_option = get_computer_option();
            
            std::cout << "Computer chose: " << options[computer_option] << std::endl;
            std::cout << winner(player_option, computer_option) << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
        
        std::cout << "Enter rock, paper, or scissors (or 'q' to quit): ";
    }

    std::cout << "Goodbye!" << std::endl;
    return 0;
}