#include "values.hpp"

namespace {
    void init_panel(sf::RectangleShape& panel, const RectInfo& info) {
        panel.setSize(sf::Vector2f(info.size_x, info.size_y));
        panel.setFillColor(sf::Color(194, 194, 182));
        panel.setPosition(info.pos_x, info.pos_y);
        panel.setOutlineColor(sf::Color::Black);
        panel.setOutlineThickness(1.0f);
    }

    void init_triangle_up(sf::ConvexShape& triangle, const RectInfo& info) {
        triangle.setPointCount(3);
        triangle.setPoint(0, sf::Vector2f(info.pos_x / 2, info.pos_y));
        triangle.setPoint(1, sf::Vector2f(info.pos_x / 4, info.pos_y + info.size_y / 3));
        triangle.setPoint(2, sf::Vector2f(info.pos_x / 4 * 3, info.pos_y + info.size_y / 3));
        triangle.setOutlineColor(sf::Color::Black);
        triangle.setOutlineThickness(1.0f);
        triangle.setFillColor(sf::Color::Green);
    }

    void init_triangle_down(sf::ConvexShape& triangle, const RectInfo& info) {
        triangle.setPointCount(3);
        triangle.setPoint(0, sf::Vector2f(info.pos_x / 4, info.pos_y + info.size_y / 3 * 2));
        triangle.setPoint(1, sf::Vector2f(info.pos_x / 4 * 3, info.pos_y + info.size_y / 3 * 2));
        triangle.setPoint(2, sf::Vector2f(info.pos_x / 2, info.pos_y + info.size_y));
        triangle.setOutlineColor(sf::Color::Black);
        triangle.setOutlineThickness(1.0f);
        triangle.setFillColor(sf::Color::Red);
    }

    void update_button_color(struct ShapeInfo& info, sf::RenderWindow& window, sf::Color default_color) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        bool hovered = info.shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_pos));

        if (!hovered) {
            info.shape.setFillColor(default_color);
        } else {
            info.shape.setFillColor(sf::Color::Cyan);
        }
    }
}

Values::Values(const RectInfo& F_info, const RectInfo& m_info) {
    init_panel(F_value, F_info);
    init_panel(m_value, m_info);

    init_triangle_up(F_value_up, F_info);
    init_triangle_down(F_value_down, F_info);
    init_triangle_up(m_value_up, m_info);
    init_triangle_down(m_value_down, m_info);
}

int Values::delegator(sf::Vector2f world_pos) {
    if (F_value_up.getGlobalBounds().contains(world_pos)) {
        return 0;
    }
    if (F_value_down.getGlobalBounds().contains(world_pos)) {
        return 1;
    }
    if (m_value_up.getGlobalBounds().contains(world_pos)) {
        return 2;
    }
    if (m_value_down.getGlobalBounds().contains(world_pos)) {
        return 3;
    }
    return -1;
}

void Values::draw(sf::RenderWindow& window) {
    window.draw(F_value);
    window.draw(m_value);

    window.draw(F_value_up);
    window.draw(F_value_down);
    window.draw(m_value_up);
    window.draw(m_value_down);
}

void Values::update_button_colors(sf::RenderWindow& window) {
    update_button_color(F_value_down_info, window, sf::Color::Green);
    update_button_color(F_value_up_info, window, sf::Color::Red);
    update_button_color(m_value_down_info, window, sf::Color::Green);
    update_button_color(m_value_up_info, window, sf::Color::Red);
}
