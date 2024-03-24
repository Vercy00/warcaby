//
// Created by david on 08.11.2023.
//

#include "formatter.h"

namespace game {
    std::string formatTime(int seconds) {
        int min = seconds / 60;
        seconds %= 60;
        std::string str;

        if (min < 10)
            str.append("0");

        str.append(std::to_string(min));
        str.append(":");

        if (seconds < 10)
            str.append("0");

        str.append(std::to_string(seconds));

        return str;
    }
} // game