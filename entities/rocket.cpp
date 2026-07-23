#include "rocket.hpp"
#include "../physics/formulas.hpp"

#include <algorithm>

namespace {
    constexpr float ground_y = 750.0f;
}

Rocket::Rocket(float size_x, float size_y, float pos_x, float pos_y) {
    rocket.setSize(sf::Vector2f(size_x, size_y));
    rocket.setFillColor(sf::Color::Green);
    rocket.setPosition(pos_x, pos_y);
    rocket.setOutlineColor(sf::Color::Black);
    rocket.setOutlineThickness(1.0f);
}

void Rocket::draw(sf::RenderWindow& window) {
    window.draw(rocket);
}

std::pair<float, float> Rocket::getPosition() const {
    return std::make_pair(rocket.getPosition().x, rocket.getPosition().y);
}

std::pair<float, float> Rocket::getSize() const {
    return std::make_pair(rocket.getSize().x, rocket.getSize().y);
}

void Rocket::apply_flight_physics(sf::Time elapsed, float thrust, float mass) {
    float h0 = rocket.getPosition().y;

    if (acceleration_up(thrust, mass, elapsed) >= 0) {
        float a = acceleration_up(thrust, mass, elapsed);
        float h = h_up(h0, a, elapsed);
        rocket.setPosition(rocket.getPosition().x, h);
    } else {
        float a = acceleration_down(thrust, mass, elapsed);
        float v = v_down(0, a, elapsed);
        float h = h_down(h0, v, elapsed);

        float ground_limit = ground_y - rocket.getSize().y;
        rocket.setPosition(rocket.getPosition().x, std::min(h, ground_limit));
    }
}
