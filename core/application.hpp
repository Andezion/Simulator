#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

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

    std::optional<MainFrame> main_frame;
    std::optional<Values> values;
    std::optional<Rocket> rocket;

    void handle_events();
    void update();
    void render();
};
