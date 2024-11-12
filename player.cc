#include <iostream>
#include <string>

#include "player.h"

using namespace std;

player::player(string playerName, int id)
{
    this->playerName = playerName;
    this->id = id;
    wins = 0;
}

player::~player()
{
    
}

void player::setPlayer()
{    
    shipsTable.setShipsPositions();
}

string player::getPlayerName()
{
    return this -> playerName;
}

coordinates player::shootShips()
{
    coordinates results;
    int x, y;
    char letter;   
    
    shipsTable.showTable(1,6);
    shotsTable.showTable(39,6);
    
    do
    {    
        SetCursorPosition(1,24);
        cout << "Shoot at another player fleet! (x y) " << endl;
        while (true)
        {    
            SetCursorPosition(1,25);
            cout << "X = (A - J):            ";
            SetCursorPosition(1,25);
            cout << "X = (A - J): ";
            cin >> letter; 
            letter = toupper(letter);
            results.x = letter - 'A' + 1;
            if (results.x > 0 && results.x < 11)
            {
                break;
            }
        }
        while(true)
        {
            while (true)
            {    
                SetCursorPosition(25,25);
                cout << "Y = (1 - 10):          ";
                SetCursorPosition(25,25);
                cout << "Y = (1 - 10): ";
                cin >> results.y; 

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    break;
                }
            }

            if (results.y > 0 && results.y < 11)
            {
                break;
            }
        }
    }while (shotsTable.playerTable[results.x - 1][results.y - 1] != '.');
    
    return results;
}

damage player::isHit(coordinates place)
{
    damage results;
    results.isSunk = false;
    bool isHit = false;

    if(shipsTable.playerTable[place.x-1][place.y-1] == SHIP)
    {
        shipsTable.playerTable[place.x-1][place.y-1] = HIT;
        results.isShot = true;
        for (int i = 0; i < 10; i++)
        {
            if (shipsTable.ships[i].markShots(place))
            {
                if(shipsTable.ships[i].isSunk())
                {
                    results.isSunk = true;
                    results.shipsStart.x = shipsTable.ships[i].hull[0][0];
                    results.shipsStart.y = shipsTable.ships[i].hull[1][0];
                    results.shipsEnd.x = shipsTable.ships[i].hull[0][shipsTable.ships[i].size-1];
                    results.shipsEnd.y = shipsTable.ships[i].hull[1][shipsTable.ships[i].size-1];
                    break;
                }
            }                   
        }
        return results;
    }
    else
    {
        shipsTable.playerTable[place.x-1][place.y-1] = MISHIT;
        results.isShot = false;
        return results;
    }
    
}

void player::markShots(coordinates place, bool hit)
{
    if(hit == true)
    {
        shotsTable.playerTable[place.x-1][place.y-1] = HIT;
    }
    else
    {
        shotsTable.playerTable[place.x-1][place.y-1] = MISHIT;
    }
    
}

bool player::isGameEnded()
{
    for (int i = 0; i < 10; i++)
    {
        if (!shipsTable.ships[i].isSunk())
        {
            return false;
        }
        
    }
    return true;
}