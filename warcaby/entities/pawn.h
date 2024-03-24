//
// Created by david on 03.11.2023.
//

#ifndef WARCABY_PAWN_H
#define WARCABY_PAWN_H


#include "player.h"

namespace game {
    class PawnBuilder;

    class Pawn {
        Player *owner;
        int color;
        bool selected;
        bool isQueen;

        Pawn() : owner(nullptr), color(0), isQueen(false), selected(false) {}

        friend PawnBuilder;

    public:
        explicit Pawn(Player *owner, int color) : color(color), isQueen(false), selected(false), owner(owner) {}

        [[nodiscard]] int getColor() const {
            return color;
        }

        void setSelected(bool val) {
            selected = val;
        }

        void setQueenStatus(bool val) {
            isQueen = val;
        }

        [[nodiscard]] Player *getOwner() const {
            return owner;
        }

        [[nodiscard]] bool isSelected() const {
            return selected;
        }

        [[nodiscard]] bool queenStatus() const {
            return isQueen;
        }

        static PawnBuilder builder();

    };

    class PawnBuilder {
        Pawn pawn;

    public:
        PawnBuilder() : pawn() {}

        PawnBuilder &owner(Player *val) {
            pawn.owner = val;
            return *this;
        }

        PawnBuilder &color(int val) {
            pawn.color = val;
            return *this;
        }

        PawnBuilder &selected(bool val) {
            pawn.selected = val;
            return *this;
        }

        PawnBuilder &queenStatus(bool val) {
            pawn.isQueen = val;
            return *this;
        }

        Pawn &build() {
            return pawn;
        }
    };
} // game

#endif //WARCABY_PAWN_H
