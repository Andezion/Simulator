#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>

// #include <vector>
#include <iostream>

#include "physics/formulas.hpp"
#include "buttons/values.hpp"
#include "buttons/styling/style.hpp"


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

    void execute(float (*move) (float, float), float t) {
        rocket.setPosition(rocket.getPosition().x, move(rocket.getPosition().y, t));
    }

    void execute(float (*move) (float, float, float), float h0, float a, float t) {
        rocket.setPosition(rocket.getPosition().x, move(h0, a, t));
    }

    void flow_type_one(float h0, sf::Time t, float F, float m) {
        
        if (acceleration_up(F, m, t) >= 0) {
            float h = h_up(h0, acceleration_up(F, m, t), t);
            float v = v_up(0, acceleration_up(F, m, t), t);

            rocket.setPosition(rocket.getPosition().x, h);
        } else {
            float h1 = h_down(rocket.getPosition().y, v_down(0, acceleration_down(F, m, t), t), t);
            
            rocket.setPosition(rocket.getPosition().x, h1);
            if (rocket.getPosition().y > 750.0f - rocket.getSize().y) {
                //std::cout << "Rocket has hit the ground!" << std::endl;
                rocket.setPosition(rocket.getPosition().x, 750.0f - rocket.getSize().y);
                return;
            }
        }
        // std::cout << "h: " << rocket.getPosition().y << std::endl;
    }

    ~Rocket() = default;
};

int is_hover = 0;

int main() {
    // sf::ContextSettings settings;
    // settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Simulator", sf::Style::Default);
    window.setFramerateLimit(120);

    float scale_100_x = window.getSize().x / 12.0f;
    float scale_100_y = window.getSize().y / 8.0f;

    float scale_50_x = window.getSize().x / 24.0f;
    float scale_50_y = window.getSize().y / 16.0f;

    MainFrame main_frame(scale_100_x * 9, scale_100_y * 7, scale_100_x * 2 + scale_50_x, scale_50_y);

    struct RectInfo F_info = {scale_100_x, scale_50_y, scale_100_x, scale_50_y};
    struct RectInfo m_info = {scale_100_x, scale_50_y, scale_100_x, scale_100_y + scale_50_y};

    Values values(F_info, m_info);

    Rocket rocket(scale_100_x / 8, scale_100_y / 4, 
        main_frame.getPosition().first + 50.0f, main_frame.getPosition().second + main_frame.getSize().second - scale_100_y / 4);

    sf::Clock clock;

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

        if (values.intersection(values.F_value_up, window)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                values.set_new_color(values.F_value_up, sf::Color::Blue);
            } else {
                values.set_new_color(values.F_value_up, sf::Color::Cyan);
            }
        } else {
            values.set_new_color(values.F_value_up, sf::Color::Green);
        }

        if (values.intersection(values.F_value_down, window)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                values.set_new_color(values.F_value_down, sf::Color::Blue);
            } else {
                values.set_new_color(values.F_value_down, sf::Color::Cyan);
            }
        } else {
            values.set_new_color(values.F_value_down, sf::Color::Red);
        }

        if (values.intersection(values.m_value_up, window)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                values.set_new_color(values.m_value_up, sf::Color::Blue);
            } else {
                values.set_new_color(values.m_value_up, sf::Color::Cyan);
            }
        } else {
            values.set_new_color(values.m_value_up, sf::Color::Green);
        }

        if (values.intersection(values.m_value_down, window)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                values.set_new_color(values.m_value_down, sf::Color::Blue);
            } else {
                values.set_new_color(values.m_value_down, sf::Color::Cyan);
            }
        } else {
            values.set_new_color(values.m_value_down, sf::Color::Red);
        }

        

        values.draw(window);

        rocket.draw(window);
        rocket.flow_type_one(rocket.getPosition().second, clock.getElapsedTime(), 100.0f, 10.0f);

        window.display();
    }
}