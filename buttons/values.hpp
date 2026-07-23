#pragma once
#include <SFML/Graphics.hpp>

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

private:
    sf::RectangleShape F_value;
    sf::RectangleShape m_value;

    sf::ConvexShape F_value_up;
    sf::ConvexShape F_value_down;

    sf::ConvexShape m_value_up;
    sf::ConvexShape m_value_down;
};
