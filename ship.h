#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>

#include "remainder.cc"

using namespace std;

class ship
{
    private:
        
    public:
        ship(int size);
        int size;      
        ~ship();
        void setPosition(int x1, int y1, int x2, int y2);
        void setPosition(int x1, int y1);
        bool markShots(coordinates cords); // mark shot and return true if hit
        bool isSunk();
        void resetShips();
        short hull[3][4]; //hull[a][b] -> a (0 - x, 1 = y, 2 hit) b (next hull element)
};

#endif