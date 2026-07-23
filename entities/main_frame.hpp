#pragma once
#include <SFML/Graphics.hpp>
#include <utility>

class MainFrame {
public:
    MainFrame(float size_x, float size_y, float pos_x, float pos_y);

    void draw(sf::RenderWindow& window);
    void draw_grid(sf::RenderWindow& window);

    std::pair<float, float> getPosition() const;
    std::pair<float, float> getSize() const;

private:
    sf::RectangleShape main_frame;
};
