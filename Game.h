#pragma once

#include <SFML/graphics.hpp>
#include <string>

#include "Paddle.h"
#include "Ball.h"

class Game {
public:
    Game();
    ~Game() {};



    void run();

private:
    void showShapes();
    void movePaddle();


    sf::RenderWindow window{};
    Paddle paddle{};
    Ball ball{};

};
