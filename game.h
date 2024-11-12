#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include "player.cc"

using namespace std;

class game
{
    private:
        
    public:
        game();
        ~game();
        void setGame();
        void runGame();
        void waitForEnter(player obj, string text);
        void setPlayers();
        void playGame();
        void resetGame();
        player firstPlayer;
        player secondPlayer;
};

#endif