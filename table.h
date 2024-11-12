#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>

#include "ship.cc"

using namespace std;

class table
{
private:
    
public:
    table();
    ~table();
    void setTable();
    void showTable(short PosX, short PosY);
    char playerTable[10][10];
    void resetTable();
    string parentsName;
    string tableName;
};

class tableShips : public table 
{
private:
    int count = 0;
    void modifyShips(int counter, int x, int y);
public:
    tableShips();
    ~tableShips();
    ship ships[10] = {ship(4), ship(3), ship(3), ship(2), ship(2), ship(2), ship(1), ship(1), ship(1), ship(1)}; 
    void setShipsPositions();
    void setPositionManually();
    short x1, y1, x2, y2;
    bool isValidPlacement(int size, int cordsX1, int cordsY1, int cordsX2, int cordsY2);  
    void placeShip(ship boat);
};

class tableShots : public table
{
private:
    
public:
    tableShots();
    ~tableShots();
    void markSunkenShip(coordinates start, coordinates end);
};

#endif