//
// Created by Oski on 09.11.2023.
//

#include "draw_helper.h"

namespace game{

    void drawSelected(int i, int j, sf::Sprite sprite, sf::RenderTarget &target){
        sprite.setPosition(sf::Vector2f(65 + 1.1 * i + (65 * i), 65 + j * 2 + (65 * j)));
        target.draw(sprite);
    }

    void drawPawn(bool isQueen, int i, int j, sf::Sprite sprite, sf::Sprite sprite2, sf::RenderTarget &target){
        if(!isQueen) {
            sprite.setPosition(sf::Vector2f(69 + 1.3 * i + (65 * i), 69 + j * 2.3 + (65 * j)));
            target.draw(sprite);
        }
        else
        {
            sprite2.setPosition(sf::Vector2f(69 + 1.3 * i + (65 * i), 69 + j * 2.3 + (65 * j)));
            target.draw(sprite2);
        }
    }
}
