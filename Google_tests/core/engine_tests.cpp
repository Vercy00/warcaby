//
// Created by david on 03.01.2024.
//
#include "gtest/gtest.h"
#include "core/engine.h"

namespace game {

    class EngineTests : public testing::Test {
    protected:
        virtual void SetUp() {
            engine = new Engine();

            engine->startGame();
        }

        virtual void TearDown() {
            delete engine;
        }

        Engine *engine;
    };

    TEST_F(EngineTests, isGameStarting) {
        EXPECT_TRUE(engine->isActive);

        engine->endGame();
        EXPECT_FALSE(engine->isActive);
    }

    TEST_F(EngineTests, isTimerSwapped) {
        EXPECT_FALSE(engine->players[0]->getTimer()->isPaused());
        EXPECT_TRUE(engine->players[1]->getTimer()->isPaused());

        engine->swapActivePlayer();

        EXPECT_TRUE(engine->players[0]->getTimer()->isPaused());
        EXPECT_FALSE(engine->players[1]->getTimer()->isPaused());
    }

    TEST_F(EngineTests, isMoveValid) {
        bool isValid = engine->validateMove({1, 6}, {2, 5});
        EXPECT_TRUE(isValid);

        isValid = engine->validateMove({1, 6}, {2, 6});
        EXPECT_FALSE(isValid);

        isValid = engine->validateMove({1, 6}, {2, 3});
        EXPECT_FALSE(isValid);

        isValid = engine->validateMove({1, 3}, {2, 8});
        EXPECT_FALSE(isValid);

        isValid = engine->validateMove({1, 6}, {0, 5});
        EXPECT_TRUE(isValid);

        isValid = engine->validateMove({1, 6}, {1, 5});
        EXPECT_FALSE(isValid);

        isValid = engine->validateMove({0, 7}, {2, 5});
        EXPECT_FALSE(isValid);
    }

    TEST_F(EngineTests, isGameRunning) {
        Board &board = engine->board;
        EXPECT_TRUE(board.getPawnAt({1, 6}).has_value());
        EXPECT_FALSE(board.getPawnAt({2, 5}).has_value());

        EXPECT_TRUE(engine->makeMove({1, 6}, {2, 5}));
        EXPECT_FALSE(board.getPawnAt({1, 6}).has_value());
        EXPECT_TRUE(board.getPawnAt({2, 5}).has_value());

        EXPECT_FALSE(engine->makeMove({3, 6}, {2, 8}));
        EXPECT_TRUE(board.getPawnAt({3, 6}).has_value());
        EXPECT_FALSE(board.getPawnAt({2, 8}).has_value());
    }

    TEST_F(EngineTests, isTimeChecked) {
        engine->checkPlayerTimers();
        EXPECT_TRUE(engine->isActive);

        engine->activePlayer->getTimer()->setValue(0);
        engine->checkPlayerTimers();
        EXPECT_FALSE(engine->isActive);
    }

    TEST_F(EngineTests, isQueen) {
        Board &board = engine->board;

        EXPECT_FALSE(board.getPawnAt({1, 6})->queenStatus());
        engine->queenCheck({1, 6});
        EXPECT_FALSE(board.getPawnAt({1, 6})->queenStatus());

        board.movePawn({1, 6}, {1, 0});
        engine->queenCheck({1, 0});
        EXPECT_TRUE(board.getPawnAt({1, 0})->queenStatus());
    }

    TEST_F(EngineTests, reDraw) {
        EXPECT_NO_THROW(engine->reDraw());
    }

    TEST_F(EngineTests, inputHandler) {
        EXPECT_NO_THROW(engine->inputHandler({}));
    }

} // game