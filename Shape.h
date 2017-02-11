#pragma once

#include <SFML/graphics.hpp>
#include <cmath>
#include <vector>
#include <memory>

class Shape
{
    // Help functions for intersect()
    //Vector math functions
private:
    float dotProduct(const sf::Vector2f& lhs, const sf::Vector2f& rhs);
    sf::Vector2f unitVector(const sf::Vector2f& vector);
    sf::Vector2f perpendicularVector(const sf::Vector2f& vector);
    sf::Vector2f getPoint(const sf::Shape& shape, unsigned int index);
    sf::Vector2f projectShapeOn(const sf::Shape& shape, const sf::Vector2f& axis);
    bool existsSeparatingAxisForFirst(const sf::Shape& shape_1, const sf::Shape& shape_2);

public:
    bool intersect(const sf::Shape& shape_1, const sf::Shape& shape_2);
};
