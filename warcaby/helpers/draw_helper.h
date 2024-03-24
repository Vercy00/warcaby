//
// Created by Oski on 09.11.2023.
//

#ifndef WARCABY_DRAW_HELPER_H
#define WARCABY_DRAW_HELPER_H

#include "../entities/board.h"
#include "../entities/pawn.h"

namespace game {

    void drawPawn(bool isQueen, int i, int j, sf::Sprite sprite, sf::Sprite sprite2, sf::RenderTarget &target);
    void drawSelected(int i, int j, sf::Sprite sprite, sf::RenderTarget &target);

} // game

#endif //WARCABY_DRAW_HELPER_H
