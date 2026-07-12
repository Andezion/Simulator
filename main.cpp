#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Window/Keyboard.hpp>
// #include <vector>
#include <iostream>

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
        // for (float i = main_frame.getPosition().x; i < main_frame.getPosition().x + main_frame.getSize().x; i += main_frame.getSize().x / 12.0f) {
        //     sf::Vertex line[] = {
        //         sf::Vertex(sf::Vector2f(i, main_frame.getPosition().y)),
        //         sf::Vertex(sf::Vector2f(i, main_frame.getPosition().y + main_frame.getSize().y))
        //     };
        //     window.draw(line, 2, sf::Lines);
        // }

        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(260, 50)),
                sf::Vertex(sf::Vector2f(260, 750))
        };
        line[0].color = sf::Color::Black;
        line[1].color = sf::Color::Black;
        window.draw(line, 2, sf::Lines);

        sf::Vertex line2[] = {
                sf::Vertex(sf::Vector2f(250, 60)),
                sf::Vertex(sf::Vector2f(1150, 60))
        };
        line2[0].color = sf::Color::Black;
        line2[1].color = sf::Color::Black;
        window.draw(line2, 2, sf::Lines);
    }

    ~MainFrame() = default;
};

class Rocket {
    Rocket() = default;
    ~Rocket() = default;
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
        main_frame.draw_lines(window);

        window.draw(rectangle);

        window.display();
    }
}