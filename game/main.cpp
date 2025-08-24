#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Snake Game");

    sf::RectangleShape snakeHead({20.f, 20.f});
    snakeHead.setFillColor(sf::Color::Red);
    snakeHead.setPosition({100.f, 100.f});

    float speed = 3.f;

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            snakeHead.move(sf::Vector2f{-speed, 0.f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            snakeHead.move(sf::Vector2f{speed, 0.f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            snakeHead.move(sf::Vector2f{0.f, -speed});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            snakeHead.move(sf::Vector2f{0.f, speed});
        }

        // ✅ Border Collision Check
        sf::Vector2f pos = snakeHead.getPosition();

        if (pos.x < 0) pos.x = 0;
        if (pos.x > 800 - 20) pos.x = 800 - 20;
        if (pos.y < 0) pos.y = 0;
        if (pos.y > 600 - 20) pos.y = 600 - 20;

        snakeHead.setPosition(pos);

        // Drawing
        window.clear(sf::Color::Black);
        window.draw(snakeHead);
        window.display();
    }

    return 0;
}
