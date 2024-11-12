#include <iostream>
#include <string>
#include <windows.h>

#include "table.h"

using namespace std;


table::table()
{
    setTable();
}

table::~table()
{

}

void table::setTable()
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            playerTable[x][y] = '.';
        }
    }
}

void table::showTable(short PosX, short PosY)
{
    string axisX = "ABCDEFGHIJ";

    SetCursorPosition(1,2);
    cout << "Player name: " << parentsName << endl;
    SetCursorPosition(PosX + 8,PosY);
    cout << ":: Table: " << tableName << " ::" << endl;

    SetCursorPosition(PosX, PosY + 2);
   // Axis'x Letters
    cout << "     ";
    for (int a = 0; a < 10; a++)
    {
        cout << axisX[a] << "  ";
    }
    cout << endl;

    SetCursorPosition(PosX, PosY+3);
    // Top Border
    changeColor(Yellow);
    cout << "   " << char(201);
    for (int a = 0; a < 30; a++)
    { 
        cout << char(205);
    }
    cout << char(187) << endl;

    SetCursorPosition(PosX, PosY+4);
    changeColor(White);
    
    // Side Borders and Table
    for (int y = 0; y < 10; y++)
    {
        if (y < 9) 
            {
                cout << " " << y+1 << " ";
            }
            else
            {
                cout << "10 ";
            }
            changeColor(Yellow);
            cout << char(186);
            changeColor(White);    
        
        for (int x = 0; x < 10; x++)
        {
            if (playerTable[x][y] == SHIP)
            {
                cout << SHIP << SHIP << SHIP;
            }
            else if(playerTable[x][y] == HIT)
            {
                cout << HIT << HIT << HIT;
            }
            else
            {
            cout << " " << playerTable[x][y] << " ";  
            }
        }
        changeColor(Yellow);
        cout << char(186) << " ";
        changeColor(White);    
        cout << endl;
        SetCursorPosition(PosX, PosY+5+y);
    }
    
    // Bottom border
    changeColor(Yellow);
    cout << "   " << char(200);
    for (int a = 0; a < 30; a++) 
    {
        cout << char(205);
    }
    cout << char(188) << endl;
    changeColor(White);

}

void table::resetTable()
{
    setTable();
}

tableShips::tableShips(): table()
{

}

tableShips::~tableShips()
{

}


void tableShips::setShipsPositions()
{
    int choice = 1;
    // a == 1 play with human
    // a == 0 play with ai
    if (choice == 1) 
    {
        setPositionManually();       
    }
    else if (choice == 0)
    {

    }
}

void tableShips::setPositionManually()
{
    int x = 1;
    int y = 6;

    for (int i = 0; i < 10; i++) 
    {
        modifyShips(i, x, y);
    }   
}

void tableShips::modifyShips(int counter, int x, int y)
{
    char letter;
    int numberOfChars;
    do
    {
        system("cls");
        showTable(x, y-2);

        for (int i = 0; i < 2; i++)
        {
            SetCursorPosition(x, y + 16 + (i * 2));
            if (counter > 5 && i == 1)
            {
                break;
            }
            
            if (i == 0)
            {
                cout << "Enter the starting coordinates for your size ";
            }
            else
            {
                cout << "Enter the ending coordinates for your size ";
            }

            cout << ships[counter].size << " ship" << endl;

            while (true)
            {    
                SetCursorPosition(x, y + 17 + (i * 2));
                cout << "X = (A - J):            ";
                SetCursorPosition(x, y + 17 + (i * 2));
                cout << "X = (A - J): ";
                cin >> letter; 
                letter = toupper(letter);
                if (i == 0)
                {
                    x1 = letter - 'A' + 1;
                }
                else
                {
                    x2 = letter - 'A' + 1;
                }                
                if (x1 > 0 && x1 < 11)
                {
                    break;
                }
                else if (x2 > 0 && x2 < 11)
                {
                    break;
                }
            }
            while(true)
            {
                while (true)
                {    
                    SetCursorPosition(x + 24, y + 17 + (i * 2));
                    cout << "Y = (1 - 10):          ";
                    SetCursorPosition(x + 24, y + 17 + (i * 2));
                    cout << "Y = (1 - 10): ";
                    if (i == 0)
                    {
                        cin >> y1; 
                    }
                    else
                    {
                        cin >> y2;
                    }
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
                if (y1 > 0 && y1 < 11)
                {
                    break;
                }
                else if (y2 > 0 && y2 < 11)
                {
                    break;
                }
            }
        }
    } while (!isValidPlacement(ships[counter].size, x1, y1, x2, y2));

    ships[counter].setPosition(x1-1, y1, x2, y2);
    placeShip(ships[counter]);
}

bool tableShips::isValidPlacement(int size, int cordsX1, int cordsY1, int cordsX2, int cordsY2)
{
    if(size == 1)
    {
        cordsX2 = cordsX1;
        cordsY2 = cordsY1;
    }
    // Does ship has coords within table?
    if (cordsX1 < 1 || cordsX1 > 10 || cordsY1 < 1 || cordsY1 > 10)
    {
        cout << endl << "Invalid coordinates. Please enter coordinates between 1 and 10." << endl << "Press enter to continue"<< endl;
        fflush(stdin);
        getchar();
        return false;
    }



    if(size > 1)
    {
        if (cordsX2 < 1 || cordsX2 > 10 || cordsY2 < 1 || cordsY2 > 10)
        {
            cout << endl << "Invalid coordinates. Please enter coordinates between 1 and 10." << endl << "Press enter to continue"<< endl;
            fflush(stdin);
            getchar();
            return false;
        }
        
        // horizontally or vertically
        if (cordsX1 != cordsX2 && cordsY1 != cordsY2)
        {
            cout << endl << "Invalid coordinates. Please enter coordinates that are horizontal or vertical to each other" << endl << "Press enter to continue"<< endl;
            fflush(stdin);
            getchar();
            return false;
        }
        // does length match the ship
        if (cordsX1 == cordsX2) 
        {
            if (abs(cordsY2 - cordsY1) + 1 != size)
            {
                cout << endl << "Invalid coordinates. Please enter coordinates matching the size" << endl << "Press enter to continue"<< endl;
                fflush(stdin);
                getchar();
                return false;
            }
        }   
        else 
        {
            if (abs(cordsX2 - cordsX1) + 1 != size)
            {
                cout << endl << "Invalid coordinates. Please enter coordinates matching the size" << endl << "Press enter to continue"<< endl;
                fflush(stdin);
                getchar();
                return false;
            }
        }
    }
        // Check if the ships are touching each other
        int startX = min(cordsX1, cordsX2);
        int endX = max(cordsX1, cordsX2);
        int startY = min(cordsY1, cordsY2);
        int endY = max(cordsY1, cordsY2);

        for (int x = startX - 1; x <= endX + 1; x++) 
        {
            for (int y = startY - 1; y <= endY + 1; y++) 
            {
                if (x >= 1 && x <= 10 && y >= 1 && y <= 10) 
                {                
                    if (playerTable[x-1][y-1] == char(219)) 
                    {
                        cout << endl << "Invalid coordinates. Ships cannot touch each other" << endl << "Press enter to continue"<< endl;
                        fflush(stdin);
                        getchar();
                        return false; 
                    }
                }
            }
        }  

    return true;
}

void tableShips::placeShip(ship boat)
{
    for (int i = 0; i < boat.size; i++)
    {
        playerTable[boat.hull[0][i]][boat.hull[1][i]] = char(219);
    }

}

tableShots::tableShots()
{
}

tableShots::~tableShots()
{

}

void tableShots::markSunkenShip(coordinates start, coordinates end)
{
    int x1 = min(start.x, end.x) - 1;
    int y1 = min(start.y, end.y) - 1;

    int x2 = max(start.x, end.x) + 1;
    int y2 = max(start.y, end.y) + 1;

    for (int i = y1; i < y2 + 1; i++)
    {
        if(x1 >= 0 && x1 < 10 && i >= 0 && i < 10)
        {
            playerTable[x1][i] = MISHIT;
        }
        if(x2 >= 0 && x2 < 10 && i >= 0 && i < 10)
        {
            playerTable[x2][i] = MISHIT;
        }
    }

    for (int i = x1; i < x2 + 1; i++)
    {
        if(i >= 0 && i < 10 && y1 >= 0 && y1 < 10)
        {
            playerTable[i][y1] = MISHIT;
        }
        if(i >= 0 && i < 10 && y2 >= 0 && y2 < 10)
        {
            playerTable[i][y2] = MISHIT;
        }
    }
}