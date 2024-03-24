//
// Created by david on 03.01.2024.
//
#include "gtest/gtest.h"
#include "helpers/calculate.h"

namespace game {
    TEST(CalculateTests, calcCoord) {
        EXPECT_EQ(calcCoord({65, 65}, 65), (coordinates{0, 0}));
    }
} // game