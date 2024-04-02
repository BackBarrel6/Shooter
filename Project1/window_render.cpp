#include "window_render.hpp"

void window_render(sf::RenderWindow& window, Player& player, std::vector<Bullet>& bullets, sf::Event& event) {
    window.clear();
    window.draw(player.playerent);
    window.draw(player.posx);
    window.draw(player.posy);

    // Render bullets
    for (const auto& bullet : bullets) {
        window.draw(bullet.bulletent);
    }

    window.display();

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}
