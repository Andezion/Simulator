#include "application.hpp"
#include <SFML/Graphics/Font.hpp>
namespace {
    constexpr unsigned window_width = 1200;
    constexpr unsigned window_height = 800;
    constexpr unsigned framerate_limit = 120;

    constexpr float rocket_thrust = 100.0f;
    constexpr float rocket_mass = 10.0f;
}

Application::Application()
    : window(sf::VideoMode(window_width, window_height), "Simulator", sf::Style::Default) {
    window.setFramerateLimit(framerate_limit);

    float scale_100_x = window.getSize().x / 12.0f;
    float scale_100_y = window.getSize().y / 8.0f;
    float scale_50_x = window.getSize().x / 24.0f;
    float scale_50_y = window.getSize().y / 16.0f;
    float scale_10_x = window.getSize().x / 120.0f;
    float scale_10_y = window.getSize().y / 80.0f;

    main_frame.emplace(scale_100_x * 9, scale_100_y * 7, scale_100_x * 2 + scale_50_x, scale_50_y);

    RectInfo F_info{scale_100_x, scale_50_y, scale_100_x, scale_50_y};
    RectInfo m_info{scale_100_x, scale_50_y, scale_100_x, scale_100_y + scale_50_y};
    values.emplace(F_info, m_info);

    rocket.emplace(scale_100_x / 8, scale_100_y / 4,
        main_frame->getPosition().first + 50.0f,
        main_frame->getPosition().second + main_frame->getSize().second - scale_100_y / 4);

    if (!font.loadFromFile("Arial.ttf")) {
        // do smth plz
    }

    text_F.setFont(font);
    text_F.setString("F");
    text_F.setCharacterSize(24);
    text_F.setFillColor(sf::Color::Black);
    text_F.setPosition(scale_100_x * 2 + scale_10_x * 3 / 2, scale_50_y + scale_10_y / 4 * 3);

    input_F.setFont(font);
    
    input_F.setString(std::format("{:.2f}", rocket_thrust));
    input_F.setCharacterSize(24);
    input_F.setFillColor(sf::Color::Black);
    input_F.setPosition(scale_100_x + scale_10_x, scale_50_y + scale_10_y / 4 * 3);

    text_m.setFont(font);
    text_m.setString("m");
    text_m.setCharacterSize(24);
    text_m.setFillColor(sf::Color::Black);
    text_m.setPosition(scale_100_x * 2 + scale_10_x * 3 / 2, scale_100_y + scale_50_y + scale_10_y / 4 * 3);

    input_m.setFont(font);
    input_m.setString(std::format("{:.2f}", rocket_mass));
    input_m.setCharacterSize(24);
    input_m.setFillColor(sf::Color::Black);
    input_m.setPosition(scale_100_x + scale_10_x, scale_100_y + scale_50_y + scale_10_y / 4 * 3);
}

void Application::run() {
    while (window.isOpen()) {
        handle_events();
        update();
        render();
    }
}

void Application::handle_events() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            window.close();
        }
    }
}

void Application::update() {
    values->update_button_colors(window);
    rocket->apply_flight_physics(clock.getElapsedTime(), rocket_thrust, rocket_mass);
}

void Application::render() {
    window.clear(sf::Color(184, 183, 177, 255));

    main_frame->draw(window);
    main_frame->draw_grid(window);
    values->draw(window);
    rocket->draw(window);
    window.draw(text_F);
    window.draw(text_m);
    window.draw(input_F);
    window.draw(input_m);

    window.display();
}
