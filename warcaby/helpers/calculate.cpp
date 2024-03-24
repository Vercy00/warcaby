#include "calculate.h"

namespace game {
    coordinates calcCoord(coordinates c, float size) {
        return {static_cast<int>(((float) c.x - size) / size),
                static_cast<int>(((float) c.y - size) / size)};
    }
} // game
