#ifndef WARCABY_ENGINE_H
#define WARCABY_ENGINE_H

#include "timer.h"
#include "../entities/player.h"
#include "../entities/board.h"
#include "SFML/Graphics.hpp"
#include "gtest/gtest_prod.h"

namespace game {

    class Engine {
        friend class EngineTests;
        FRIEND_TEST(EngineTests, isGameStarting);
        FRIEND_TEST(EngineTests, isTimerSwapped);
        FRIEND_TEST(EngineTests, isMoveValid);
        FRIEND_TEST(EngineTests, isGameRunning);
        FRIEND_TEST(EngineTests, isTimeChecked);
        FRIEND_TEST(EngineTests, isQueen);
        FRIEND_TEST(EngineTests, reDraw);
        FRIEND_TEST(EngineTests, inputHandler);

        Board board;
        Player *players[2];
        Player *activePlayer;
        Player *winner;
        bool isActive;
        sf::RenderWindow window;

        void reDraw();

        void checkPlayerTimers();

        void timeEnded(const Player *lost);

        void swapActivePlayer();

        void startGame();

        bool validateMove(coordinates c, coordinates newC);

        bool makeMove(coordinates c, coordinates newC);

        void queenCheck(coordinates c);

        void pawnCapture(coordinates c);

        void endGame();

        void inputHandler(const sf::Event &event);

    public:
        explicit Engine(int gameTime = 120);

        void run();
    };

} // game

#endif //WARCABY_ENGINE_H
