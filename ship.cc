#include <iostream>
#include <string>

#include "ship.h"

using namespace std;

ship::ship(int size)
{
    this->size = size;
}

ship::~ship()
{
}

void ship::setPosition(int x1, int y1, int x2, int y2)
{
    y1 = y1 - 1;
    x2 = x2 - 1;
    y2 = y2 - 1;

    hull[2][0] = 0; // there is no damage to hull
    hull[2][1] = 0;
    hull[2][2] = 0;
    hull[2][3] = 0;

    hull[0][0] = x1;
    hull[1][0] = y1;

    if (size == 2) {
        hull[0][1] = x2;
        hull[1][1] = y2;
    }
    else if (size == 3) {
        //if the ship is horizontal
        if (y1 == y2)
        {
            hull[0][1] = min(x1, x2) + 1;
            hull[1][1] = y1;
            hull[0][2] = x2;
            hull[1][2] = y2;
        }
        // if the ship is vertical
        else
        {
            hull[0][1] = x1;
            hull[1][1] = min(y1, y2) + 1;
            hull[0][2] = x2;
            hull[1][2] = y2;
        }

    }
    else
    {
        //if the ship is horizontal
        if (y1 == y2)
        {
            hull[0][1] = min(x1, x2) + 1;
            hull[1][1] = y1;
            hull[0][2] = min(x1, x2) + 2;
            hull[1][2] = y1;
            hull[0][3] = x2;
            hull[1][3] = y2;
        }
        // if the ship is vertical
        else
        {
            hull[0][1] = x1;
            hull[1][1] = min(y1, y2) + 1;
            hull[0][2] = x1;
            hull[1][2] = min(y1, y2) + 2;
            hull[0][3] = x2;
            hull[1][3] = y2;
        }

    }
}

void ship::setPosition(int x1, int y1){
    hull[0][0] = x1;
    hull[1][0] = y1;

    hull[2][0] = 0; // there is no damage to hull
    hull[2][1] = 0;
    hull[2][2] = 0;
    hull[2][3] = 0;
}

bool ship::markShots(coordinates cords)
{
    for (int i = 0; i < size; i++)
    {
        if (cords.x-1 == hull[0][i] && cords.y-1 == hull[1][i])
        {
            hull[2][i] = 1;
            return true;
        }
    }
    return false;
}

bool ship::isSunk()
{
    for (int i = 0; i < size; i++)
    {
        if (hull[2][i] == 0)
        {
            return false;
        }
    }
    return true;
}

void ship::resetShips()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            hull[j][i] = 0;
        }
    }
}
