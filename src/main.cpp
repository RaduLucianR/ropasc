#include <cstdint>
#include <array>
#include <iostream>
#include "game.hpp"

int main() {
    std::string player_input;
    
    std::cout << "Welcome to Rock-Paper-Scissors!\n";
    std::cout << "Enter rock, paper, or scissors (or 'q' to quit): ";

    while (std::cin >> player_input && player_input != "q") {
        std::cout << game_round(player_input);
        std::cout << "Enter rock, paper, or scissors (or 'q' to quit): ";
    }

    std::cout << "Goodbye!";
    return 0;
}