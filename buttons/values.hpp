#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

struct RectInfo {
    float size_x;
    float size_y;
    float pos_x;
    float pos_y;
};

class Values {
public:
    sf::RectangleShape F_value;
    sf::RectangleShape m_value;

    sf::ConvexShape F_value_up;
    sf::ConvexShape F_value_down;

    sf::ConvexShape m_value_up;
    sf::ConvexShape m_value_down;

    Values(struct RectInfo F_info, struct RectInfo m_info) {
        F_value.setSize(sf::Vector2f(F_info.size_x, F_info.size_y));
        F_value.setFillColor(sf::Color(194, 194, 182));
        F_value.setPosition(F_info.pos_x, F_info.pos_y);
        F_value.setOutlineColor(sf::Color::Black);
        F_value.setOutlineThickness(1.0f);
           
        m_value.setSize(sf::Vector2f(m_info.size_x, m_info.size_y));
        m_value.setFillColor(sf::Color(194, 194, 182));
        m_value.setPosition(m_info.pos_x, m_info.pos_y);
        m_value.setOutlineColor(sf::Color::Black);
        m_value.setOutlineThickness(1.0f);

        F_value_up.setPointCount(3);
        F_value_up.setPoint(0, sf::Vector2f(F_info.pos_x / 2, F_info.pos_y));
        F_value_up.setPoint(1, sf::Vector2f(F_info.pos_x / 4, F_info.pos_y + F_info.size_y / 3));
        F_value_up.setPoint(2, sf::Vector2f(F_info.pos_x / 4 * 3, F_info.pos_y + F_info.size_y / 3));
        F_value_up.setOutlineColor(sf::Color::Black);
        F_value_up.setOutlineThickness(1.0f);
        F_value_up.setFillColor(sf::Color::Green);

        F_value_down.setPointCount(3);
        F_value_down.setPoint(0, sf::Vector2f(F_info.pos_x / 4 , F_info.pos_y + F_info.size_y / 3 * 2));
        F_value_down.setPoint(1, sf::Vector2f(F_info.pos_x / 4 * 3, F_info.pos_y + F_info.size_y / 3 * 2));
        F_value_down.setPoint(2, sf::Vector2f(F_info.pos_x / 2, F_info.pos_y + F_info.size_y));
        F_value_down.setOutlineColor(sf::Color::Black);
        F_value_down.setOutlineThickness(1.0f);
        F_value_down.setFillColor(sf::Color::Red);

        m_value_up.setPointCount(3);
        m_value_up.setPoint(0, sf::Vector2f(m_info.pos_x / 2, m_info.pos_y));
        m_value_up.setPoint(1, sf::Vector2f(m_info.pos_x / 4, m_info.pos_y + m_info.size_y / 3));
        m_value_up.setPoint(2, sf::Vector2f(m_info.pos_x / 4 * 3, m_info.pos_y + m_info.size_y / 3));
        m_value_up.setOutlineColor(sf::Color::Black);
        m_value_up.setOutlineThickness(1.0f);
        m_value_up.setFillColor(sf::Color::Green);

        m_value_down.setPointCount(3);
        m_value_down.setPoint(0, sf::Vector2f(m_info.pos_x / 4, m_info.pos_y + m_info.size_y / 3 * 2));
        m_value_down.setPoint(1, sf::Vector2f(m_info.pos_x / 4 * 3, m_info.pos_y + m_info.size_y / 3 * 2));
        m_value_down.setPoint(2, sf::Vector2f(m_info.pos_x / 2, m_info.pos_y + m_info.size_y));
        m_value_down.setOutlineColor(sf::Color::Black);
        m_value_down.setOutlineThickness(1.0f);
        m_value_down.setFillColor(sf::Color::Red);
    }

    void set_new_color(sf::Shape& shape, sf::Color color) {
        shape.setFillColor(color);
    }

    int intersection(sf::Shape& shape, sf::RenderWindow& window) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_pos))) {
            return 1;
        }
        return 0;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(F_value);
        window.draw(m_value);
        
        window.draw(F_value_up);

        window.draw(F_value_down);
        window.draw(m_value_up);
        window.draw(m_value_down);
    }

    ~Values() = default;
};