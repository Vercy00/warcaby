
#include "board.h"
#include "../helpers/load_res.h"


namespace game {
    Board::Board(Player *player1, Player *player2) {
        for (int i = 0; i < 10; i += 2)
            for (int j = 0; j < 4; j++) {
                board[(j % 2 == 0 ? 1 : 0) + i][6 + j] = Pawn::builder().owner(player1).color(1).build();
                board[(j % 2 == 0 ? 1 : 0) + i][0 + j] = Pawn::builder().owner(player2).color(2).build();
            }
    }

    void Board::deletePawn(coordinates c){
        board[c.x][c.y].reset();
    }

    void Board::movePawn(coordinates c, coordinates newC) {
        board[c.x][c.y].swap(board[newC.x][newC.y]);
    }

    void Board::draw(sf::RenderTarget &target, const std::string &timerVal1, const std::string &timerVal2) {
        static sf::Sprite back = loadSprite("img/board.png");
        static sf::Sprite whitePawn = loadSprite("img/whitepwn.png");
        static sf::Sprite blackPawn = loadSprite("img/blackpwn.png");
        static sf::Sprite whiteQueen = loadSprite("img/whiteQ.png");
        static sf::Sprite blackQueen = loadSprite("img/blackQ.png");
        static sf::Sprite selectedB = loadSprite("img/selected.png");

        selectedB.setScale(1, 1.025);

        sf::Font font;
        font.loadFromFile("fonts/KoHo-Bold.ttf");

        sf::Text timer1;
        sf::Text timer2;

        timer1.setFont(font);
        timer2.setFont(font);
        timer1.setCharacterSize(64);
        timer2.setCharacterSize(64);

        target.draw(back);

        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++){
                if(board[i][j] && board[i][j]->getColor() == 1)
                    drawPawn(board[i][j]->queenStatus(), i, j, whitePawn, whiteQueen, target);
                else if(board[i][j] && board[i][j]->getColor() == 2)
                    drawPawn(board[i][j]->queenStatus(), i, j, blackPawn, blackQueen, target);
                if(board[i][j] && board[i][j]->isSelected())
                    drawSelected(i, j, selectedB, target);
            }

        timer1.setPosition(sf::Vector2f(768, 452));
        timer2.setPosition(sf::Vector2f(768, 77));
        timer1.setString(timerVal1);
        timer2.setString(timerVal2);
        target.draw(timer1);
        target.draw(timer2);
    }
} // game