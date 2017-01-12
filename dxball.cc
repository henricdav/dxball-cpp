#include <iostream>
#include <exception>

#include "Game.h"

int main() {
    Game game{};

    try
    {
        game.run();
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
