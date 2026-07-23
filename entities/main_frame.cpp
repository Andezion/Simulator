#include "main_frame.hpp"

MainFrame::MainFrame(float size_x, float size_y, float pos_x, float pos_y) {
    main_frame.setSize(sf::Vector2f(size_x, size_y));
    main_frame.setFillColor(sf::Color::White);
    main_frame.setPosition(pos_x, pos_y);
    main_frame.setOutlineColor(sf::Color::Black);
    main_frame.setOutlineThickness(1.0f);
}

void MainFrame::draw(sf::RenderWindow& window) {
    window.draw(main_frame);
}

void MainFrame::draw_grid(sf::RenderWindow& window) {
    constexpr float grid_step = 10.0f;
    const sf::Color grid_color(0, 0, 0, 50);
    const sf::FloatRect bounds = main_frame.getGlobalBounds();

    for (float x = bounds.left + grid_step; x < bounds.left + bounds.width; x += grid_step) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, bounds.top), grid_color),
            sf::Vertex(sf::Vector2f(x, bounds.top + bounds.height), grid_color)
        };
        window.draw(line, 2, sf::Lines);
    }

    for (float y = bounds.top + grid_step; y < bounds.top + bounds.height; y += grid_step) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(bounds.left, y), grid_color),
            sf::Vertex(sf::Vector2f(bounds.left + bounds.width, y), grid_color)
        };
        window.draw(line, 2, sf::Lines);
    }
}

std::pair<float, float> MainFrame::getPosition() const {
    return std::make_pair(main_frame.getPosition().x, main_frame.getPosition().y);
}

std::pair<float, float> MainFrame::getSize() const {
    return std::make_pair(main_frame.getSize().x, main_frame.getSize().y);
}
