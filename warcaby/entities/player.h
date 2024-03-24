//
// Created by david on 03.11.2023.
//

#ifndef WARCABY_PLAYER_H
#define WARCABY_PLAYER_H

#include <utility>
#include <string>

#include "../core/timer.h"

namespace game {

    class Player {
        Timer timer;
        std::string name;

    public:
        Player() = default;

        explicit Player(std::string name) : name(std::move(name)) {};

        [[nodiscard]] Timer *getTimer() {
            return &timer;
        }
    };

} // game

#endif //WARCABY_PLAYER_H
