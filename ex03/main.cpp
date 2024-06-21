#include <iostream>
#include "Point.hpp"

void testPoint(Point const &a, Point const &b, Point const &c, Point const &point) {
    if (bsp(a, b, c, point))
        std::cout << "Point (" << point.getX() << ", " << point.getY() << ") is inside the triangle." << std::endl;
    else
        std::cout << "Point (" << point.getX() << ", " << point.getY() << ") is outside the triangle." << std::endl;
}

int main() {
    Point a(0, 0);
    Point b(3, 0);
    Point c(0, 3);

    testPoint(a, b, c, Point(1, 1));   // Inside
    testPoint(a, b, c, Point(2, 0));   // On the edge
    testPoint(a, b, c, Point(3, 3));   // Outside
    testPoint(a, b, c, Point(0.5, 0.5)); // Inside

    return 0;
}