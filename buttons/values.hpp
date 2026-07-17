#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Window/Keyboard.hpp>

struct RectInfo {
    float size_x;
    float size_y;
    float pos_x;
    float pos_y;
};

class Values {
public:
    sf::RectangleShape F_value;
    sf::RectangleShape m_value;

    sf::ConvexShape F_value_up;
    sf::ConvexShape F_value_down;

    sf::ConvexShape m_value_up;
    sf::ConvexShape m_value_down;

    Values(struct RectInfo F_info, struct RectInfo m_info) {
        F_value.setSize(sf::Vector2f(F_info.size_x, F_info.size_y));
        F_value.setFillColor(sf::Color(194, 194, 182));
        F_value.setPosition(F_info.pos_x, F_info.pos_y);
        F_value.setOutlineColor(sf::Color::Black);
        F_value.setOutlineThickness(1.0f);
           
        m_value.setSize(sf::Vector2f(m_info.size_x, m_info.size_y));
        m_value.setFillColor(sf::Color(194, 194, 182));
        m_value.setPosition(m_info.pos_x, m_info.pos_y);
        m_value.setOutlineColor(sf::Color::Black);
        m_value.setOutlineThickness(1.0f);

        F_value_up.setPointCount(3);
        F_value_down.setPointCount(3);
        m_value_up.setPointCount(3);
        m_value_down.setPointCount(3);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(F_value);
        window.draw(m_value);
    }

    ~Values() = default;
};