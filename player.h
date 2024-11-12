#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "table.cc"


using namespace std;
class player
{
private:
    int id;
public:
    player(string playerName, int id);
    ~player();

    string playerName;
    tableShips shipsTable;
    tableShots shotsTable;
    int wins = 0;

    void setPlayer();
    string getPlayerName();
    coordinates shootShips();
    damage isHit(coordinates place);
    void markShots(coordinates place, bool hit);
    bool isGameEnded();
};

#endif