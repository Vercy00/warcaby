//
// Created by david on 26.10.2023.
//

#include <thread>
#include "timer.h"

namespace game {
    void Timer::setInterval(const std::function<void()> &fc) {
        active = true;
        std::thread t([=]() {
            while (active.load()) {
                if (paused.load()) continue;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                if (!active.load()) return;
                fc();
            }
        });
        t.detach();
    }

    void Timer::init() {
        setInterval([=]() {
            value--;

            if (value.load() <= 0) {
                active = false;
                value = 0;
            }
        });
    }

    void Timer::stop() {
        paused = true;
    }

    void Timer::resume() {
        paused = false;
    }
} // game