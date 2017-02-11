#include "Shape.h"

float Shape::dotProduct(const sf::Vector2f& lhs, const sf::Vector2f& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

sf::Vector2f Shape::unitVector(const sf::Vector2f& vector)
{
    return vector / std::sqrt(dotProduct(vector, vector));
}

sf::Vector2f Shape::perpendicularVector(const sf::Vector2f& vector)
{
    return {-vector.y, vector.x};
}

sf::Vector2f Shape::getPoint(const sf::Shape& shape, unsigned int index) {
    return shape.getTransform().transformPoint(shape.getPoint(index));
}

sf::Vector2f Shape::projectShapeOn(const sf::Shape& shape, const sf::Vector2f& axis) {

    auto point = getPoint(shape, 0);
    auto initial = dotProduct(point, axis);

    sf::Vector2f minmax(initial, initial);

    for (unsigned int i=1; i<shape.getPointCount(); ++i){
        auto point = getPoint(shape, i);
        auto projected = dotProduct(point, axis);

        if (projected < minmax.x)
            minmax.x = projected;
        if (projected > minmax.y)
            minmax.y = projected;
    }

    return minmax;
}

bool Shape::existsSeparatingAxisForFirst(const sf::Shape& shape_1, const sf::Shape& shape_2) {
    unsigned int pointCount = shape_1.getPointCount();

    for (unsigned int i=0; i<pointCount; ++i){
        unsigned int next_i = (i + 1) % pointCount;
        auto side = getPoint(shape_1, next_i) - getPoint(shape_1, i);
        auto perpendicular = unitVector(perpendicularVector(side));
        auto minmax_1 = projectShapeOn(shape_1, perpendicular);
        auto minmax_2 = projectShapeOn(shape_2, perpendicular);

        if ((minmax_1.y < minmax_2.x) || (minmax_2.y < minmax_1.x))
            return true;
    }

    return false;
}
///

bool Shape::intersect(const sf::Shape& shape_1, const sf::Shape& shape_2) {
    if (existsSeparatingAxisForFirst(shape_1, shape_2))
        return false;

    return (!existsSeparatingAxisForFirst(shape_2, shape_1));
}
