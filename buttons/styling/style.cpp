#include "style.hpp"

void hover(sf::Shape& shape) {
    sf::Color original = shape.getFillColor();
    shape.setFillColor(sf::Color(original.r + 10, original.g + 10, original.b + 10));
}

void on_click(sf::Shape& shape) {
    sf::Color original = shape.getFillColor();
    shape.setFillColor(sf::Color(original.r - 10, original.g - 10, original.b - 10));
}