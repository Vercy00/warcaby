//
// Created by david on 03.01.2024.
//
#include "gtest/gtest.h"
#include "helpers/formatter.h"

namespace game {
    TEST(FormatterTests, formatTime) {
        EXPECT_EQ(formatTime(600), "10:00");
        EXPECT_EQ(formatTime(9), "00:09");
    }
} // game