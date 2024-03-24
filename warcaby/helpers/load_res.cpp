//
// Created by david on 05.11.2023.
//

#include "load_res.h"
#include "SFML/Graphics/Texture.hpp"

namespace game {
    sf::Sprite loadSprite(const std::string &filename) {
        auto *txt = new sf::Texture();

        txt->loadFromFile(filename);
        txt->setSmooth(true);

        sf::Sprite temp(*txt);

        return temp;
    }
} // game