#pragma once

#include <SFML/graphics.hpp>

#include "globaldefines.h"
#include "Shape.h"
#include "Paddle.h"

class Ball : public Shape
{
public:
    Ball();
    ~Ball() = default;

    sf::CircleShape & getShape() {return shape;};

    void update(Paddle);
private:
    sf::CircleShape shape{};

    int size{10};
    sf::Vector2f position{WIDTH/2,HEIGHT/2};
    sf::Vector2f speed{};
};
