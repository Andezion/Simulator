#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>

struct ShapeInfo {
    sf::Shape &shape;
    int index;
    int is_pressed;
};

struct RectInfo {
    float size_x;
    float size_y;
    float pos_x;
    float pos_y;
};

class Values {
public:
    Values(const RectInfo& F_info, const RectInfo& m_info);

    void draw(sf::RenderWindow& window);
    void update_button_colors(sf::RenderWindow& window);
    int delegator(sf::Vector2f world_pos);

private:
    sf::RectangleShape F_value;
    sf::RectangleShape m_value;

    sf::ConvexShape F_value_up;
    sf::ConvexShape F_value_down;

    sf::ConvexShape m_value_up;
    sf::ConvexShape m_value_down;

    struct ShapeInfo F_value_up_info{F_value_up, 0, 0};
    struct ShapeInfo F_value_down_info{F_value_down, 1, 0};
    struct ShapeInfo m_value_up_info{m_value_up, 2, 0};
    struct ShapeInfo m_value_down_info{m_value_down, 3, 0};
};
