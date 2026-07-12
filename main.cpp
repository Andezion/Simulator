#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
// #include <iostream>

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

    ~MainFrame() = default;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Simulator");
    window.setFramerateLimit(120);

    float scale_100_x = window.getSize().x / 12.0f;
    float scale_100_y = window.getSize().y / 8.0f;

    float scale_50_x = window.getSize().x / 24.0f;
    float scale_50_y = window.getSize().y / 16.0f;

    MainFrame main_frame(scale_100_x * 9, scale_100_y * 7, scale_100_x * 2 + scale_50_x, scale_50_y);

    sf::RectangleShape rectangle(sf::Vector2f(scale_100_x , scale_100_y / 2));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(scale_100_x, scale_100_y);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(1.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                window.close();
            }

            // if (event.type == sf::Event::Resized) {
            //     std::cout << "new width: " << event.size.width << std::endl;
            //     std::cout << "new height: " << event.size.height << std::endl;
            // }
        }

        window.clear(sf::Color(184, 183, 177, 255));

        main_frame.draw(window);
        window.draw(rectangle);

        window.display();
    }
}