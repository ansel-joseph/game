#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Snake Game");

    sf::RectangleShape snakeHead({ 20.f, 20.f });
    snakeHead.setFillColor(sf::Color::Red);
    snakeHead.setPosition({ 100.f, 100.f });

    float speed = 5.f;

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // SFML 3.0 uses sf::Keyboard::Key::Left (and so on)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            snakeHead.move(sf::Vector2f{ -speed, 0.f });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            snakeHead.move(sf::Vector2f{ speed, 0.f });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            snakeHead.move(sf::Vector2f{ 0.f, -speed });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            snakeHead.move(sf::Vector2f{ 0.f, speed });
        }

        
        window.draw(snakeHead);
        window.display();
    }

    return 0;
}
