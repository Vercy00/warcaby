//
// Created by david on 03.01.2024.
//
#include "gtest/gtest.h"
#include "entities/board.h"

namespace game {
    class BoardTests : public testing::Test {
    protected:
        virtual void SetUp() {
            board = new Board(new Player(), new Player());
        }

        virtual void TearDown() {
            delete board;
        }

        Board *board;
    };

    TEST_F(BoardTests, isPawnDeleted) {
        coordinates c{1, 6};
        auto &pawn = board->getPawnAt(c);
        EXPECT_TRUE(pawn.has_value());

        board->deletePawn(c);
        EXPECT_FALSE(pawn.has_value());
    }

    TEST_F(BoardTests, isPawnMoved) {
        coordinates c1{1, 6}, c2{2, 5};
        EXPECT_TRUE(board->getPawnAt(c1).has_value());
        EXPECT_FALSE(board->getPawnAt(c2).has_value());

        board->movePawn(c1, c2);
        EXPECT_FALSE(board->getPawnAt(c1).has_value());
        EXPECT_TRUE(board->getPawnAt(c2).has_value());
    }
} // game