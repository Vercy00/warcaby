
#ifndef WARCABY_BOARD_H
#define WARCABY_BOARD_H

#include <array>
#include "pawn.h"
#include "SFML/Graphics.hpp"
#include "player.h"
#include "../helpers/draw_helper.h"
#include <optional>


namespace game {
    typedef std::array<std::array<std::optional<Pawn>, 10>, 10> board_t;

    struct coordinates {
        int x, y;

        bool operator==(const coordinates &c) const {
            return this->x == c.x && this->y == c.y;
        }
    };

    class Board {
        board_t board;

    public:
        Board() = default;

        Board(Player *player1, Player *player2);

        void deletePawn(coordinates c);

        void movePawn(coordinates c, coordinates newC);

        void draw(sf::RenderTarget &target, const std::string &timerVal1, const std::string &timerVal2);

        [[nodiscard]] std::optional<Pawn> &getPawnAt(coordinates c) {
            return board[c.x][c.y];
        }
    };

} // game

#endif //WARCABY_BOARD_H
