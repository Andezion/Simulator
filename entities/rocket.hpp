#pragma once
#include <SFML/Graphics.hpp>
#include <utility>

class Rocket {
public:
    Rocket(float size_x, float size_y, float pos_x, float pos_y);

    void draw(sf::RenderWindow& window);

    std::pair<float, float> getPosition() const;
    std::pair<float, float> getSize() const;

    // simulates one frame of vertical flight under thrust + gravity
    void apply_flight_physics(sf::Time elapsed, float thrust, float mass);

private:
    sf::RectangleShape rocket;
};
