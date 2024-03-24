//
// Created by david on 03.01.2024.
//
#include "gtest/gtest.h"
#include "helpers/load_res.h"

namespace game {
    TEST(LoadResTests, formatTime) {
        EXPECT_NO_THROW(loadSprite("img/board.png"));
    }
} // game