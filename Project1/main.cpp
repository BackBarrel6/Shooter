#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Bullet.hpp"
#include "keyboard_input.hpp"
#include "window_render.hpp"
#include <vector>

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!"), &windowref = window;
sf::Font font;

int main() {
    Player player;
    Bullet bullet(player.bulletspeed),bulletref=bullet; // Initial speed of bullet
    player.playerent.setRadius(10);
    player.posx.setCharacterSize(12);
    player.posy.setCharacterSize(12);
    player.posx.setPosition(0.f, 0.f);
    player.posy.setPosition(0.f, 20.f);

    if (!font.loadFromFile("C:/Users/flori/Downloads/ARIAL.TTF")) {
        return EXIT_FAILURE;
    }
        
    player.posx.setFont(font);
    player.posy.setFont(font);
    player.playerent.setFillColor(sf::Color::Green);

    std::vector<Bullet> bullets;

    while (window.isOpen()) {
        sf::Event event;
        player.position = player.playerent.getPosition();
        player.posx.setString(std::to_string(player.position.x));
        player.posy.setString(std::to_string(player.position.y));
        keyboard_input(player, windowref, bullets);
        window_render(windowref, player, bullets, event);

        // Update bullet positions
        for (auto& bullet : bullets) {
            bullet.update();
        }
    }

    return 0;
}
