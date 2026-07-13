#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Window/Keyboard.hpp>
// #include <vector>
// #include <iostream>
#include <cmath>

class MainFrame {
public:    
    sf::RectangleShape main_frame;
    
    MainFrame(float size_x, float size_y, float pos_x, float pos_y) {
        main_frame.setSize(sf::Vector2f(size_x, size_y));
        main_frame.setFillColor(sf::Color::White);
        main_frame.setPosition(pos_x, pos_y);
        main_frame.setOutlineColor(sf::Color::Black);
        main_frame.setOutlineThickness(1.0f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(main_frame);
    }

    void draw_lines(sf::RenderWindow& window) {
        
        // for x 
        for (float x = main_frame.getPosition().x + 10.0f; x < 1150.0f; x += 10.0f) {
            sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x, 50)),
                    sf::Vertex(sf::Vector2f(x, 750))
            };
            line[0].color = sf::Color(0, 0, 0, 50);
            line[1].color = sf::Color(0, 0, 0, 50);
            window.draw(line, 2, sf::Lines);
        }

        // for y 
        for (float y = main_frame.getPosition().y + 10.0f; y < 750.0f; y += 10.0f) {
            sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(250, y)),
                    sf::Vertex(sf::Vector2f(1150, y))
            };
            line[0].color = sf::Color(0, 0, 0, 50);
            line[1].color = sf::Color(0, 0, 0, 50);
            window.draw(line, 2, sf::Lines);
        }
    }

    std::pair<float, float> getPosition() {
        return std::make_pair(main_frame.getPosition().x, main_frame.getPosition().y);
    }

    std::pair<float, float> getSize() {
        return std::make_pair(main_frame.getSize().x, main_frame.getSize().y);
    }

    ~MainFrame() = default;
};

class Rocket {
public:
    sf::RectangleShape rocket;

    Rocket(float size_x, float size_y, float pos_x, float pos_y) {
        rocket.setSize(sf::Vector2f(size_x, size_y));
        rocket.setFillColor(sf::Color::Green);
        rocket.setPosition(pos_x, pos_y);
        rocket.setOutlineColor(sf::Color::Black);
        rocket.setOutlineThickness(1.0f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(rocket);
    }

    std::pair<float, float> getPosition() {
        return std::make_pair(rocket.getPosition().x, rocket.getPosition().y);
    }

    std::pair<float, float> getSize() {
        return std::make_pair(rocket.getSize().x, rocket.getSize().y);
    }

    ~Rocket() = default;
};

float time_of_the_flight(float v0, float angle) {
    return (2 * v0 * sin(angle)) / 9.81f;
}

float max_height(float v0, float angle) {
    return (v0 * v0 * sin(angle) * sin(angle)) / (2 * 9.81f);
}

float distance_of_the_flight(float v0, float angle) {
    return (v0 * v0 * sin(2 * angle)) / 9.81f;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Simulator");
    window.setFramerateLimit(120);

    float scale_100_x = window.getSize().x / 12.0f;
    float scale_100_y = window.getSize().y / 8.0f;

    float scale_50_x = window.getSize().x / 24.0f;
    float scale_50_y = window.getSize().y / 16.0f;

    MainFrame main_frame(scale_100_x * 9, scale_100_y * 7, scale_100_x * 2 + scale_50_x, scale_50_y);

    Rocket rocket(scale_100_x / 8, scale_100_y / 4, 
        main_frame.getPosition().first + 50.0f, main_frame.getPosition().second + main_frame.getSize().second - scale_100_y / 4);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                window.close();
            }
        }

        window.clear(sf::Color(184, 183, 177, 255));

        main_frame.draw(window);
        main_frame.draw_lines(window);

        rocket.draw(window);

        window.display();
    }
}