#include "Paddle.h"


Paddle::Paddle()
{
    shape.setPosition(WIDTH/2 - STARTWIDTH/2,HEIGHT-20);
    shape.setSize(sf::Vector2f(STARTWIDTH,10));
    shape.setFillColor(sf::Color::White);
}

void Paddle::move(bool left)
{
    if (left && shape.getPosition().x > 0)
    {
        shape.move(-speed,0);
    }
    if (!left && shape.getPosition().x < WIDTH - shape.getSize().x)
    {
        shape.move(speed,0);
    }
}
