#include "Ball.h"
#include <iostream>

Ball::Ball()
{
    shape.setPosition(position);
    shape.setRadius(size);
    shape.setFillColor(sf::Color::White);
}

void Ball::update(Paddle paddle)
{
    position += speed;
    shape.setPosition(position); // Preliminary position
    if (intersect(this->getShape(), paddle.getShape()))
    {
        position.y = HEIGHT - 20 - size * 2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            speed.y *= -1.1f;
        }
        else
        {
            speed.y *= -0.9f;
        }
    }
    else
    {
        speed += GRAVITY;
    }
    shape.setPosition(position); // Definite position


}
