#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <optional>
#include <format>

#include "../entities/main_frame.hpp"
#include "../entities/rocket.hpp"
#include "../buttons/values.hpp"

class Application {
public:
    Application();

    void run();

private:
    sf::RenderWindow window;
    sf::Clock clock;

    sf::Font font;

    sf::Text text_F;
    sf::Text text_m;
    sf::Text input_F;
    sf::Text input_m;

    std::optional<MainFrame> main_frame;
    std::optional<Values> values;
    std::optional<Rocket> rocket;

    void handle_events();
    void update();
    void render();
};
