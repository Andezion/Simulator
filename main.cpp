#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
// #include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Simulator");
    window.setFramerateLimit(120);

    sf::RectangleShape rectangle(sf::Vector2f(window.getSize().x / 10.0f, window.getSize().y / 20.0f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(100.f, 100.f);

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
        window.draw(rectangle);
        window.display();
    }
}