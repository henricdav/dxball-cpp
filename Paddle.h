#pragma once

#include <SFML/graphics.hpp>

#include "globaldefines.h"
#include "Shape.h"

class Paddle : public Shape
{
public:
    Paddle();
    ~Paddle() = default;

    void move(bool left);

    sf::RectangleShape & getShape() {return shape;};
private:
    sf::RectangleShape shape{};
    int speed{10};
};
