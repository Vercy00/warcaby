//
// Created by david on 26.10.2023.
//

#ifndef WARCABY_TIMER_H
#define WARCABY_TIMER_H

#include <functional>
#include <atomic>

namespace game {

    class Timer {
        std::atomic<bool> active{false}, paused{true};
        std::atomic<int> value{0};

        void setInterval(const std::function<void()> &fc);

    public:
        void init();

        void stop();

        void resume();

        void setValue(const int &startValue) {
            value = startValue;
        }

        [[nodiscard]] int getValue() const {
            return value;
        }

        [[nodiscard]] bool isPaused() const {
            return paused;
        }
    };

} // game

#endif //WARCABY_TIMER_H
