#include <iostream>
#include <string>

#include "game.h"

using namespace std;

game::game() : firstPlayer("Player1", 0), secondPlayer("Player2", 1)
{
    
}

game::~game()
{

}



void game::playGame()
{
    char choice;
    int gameChoice;
    int gameCounter = 0;
    int helper;

    do
    {
        helper = 0;
        do
        {
            system("cls");
            SetCursorPosition(0,2);

            cout << " ____        _   _   _      ____  _     _           " << endl;
            cout << "| __ )  __ _| |_| |_| | ___/ ___|| |__ (_)_ __  ___ " << endl;
            cout << "|  _ \\ / _` | __| __| |/ _ \\___ \\| '_ \\| | '_ \\/ __|" << endl;
            cout << "| |_) | (_| | |_| |_| |  __/___) | | | | | |_) \\__ \\ " << endl;
            cout << "|____/ \\__,_|\\__|\\__|_|\\___|____/|_| |_|_| .__/|___/" << endl;
            cout << "                                       |_|          " << endl;

            cout << endl << "1) Play game!" << endl << "2) About" << endl << "3) Quit" << endl;
            cin >> gameChoice;
            
        }while(gameChoice != 1 && gameChoice != 2 && gameChoice != 3);
        
        if (gameChoice == 1)
        {
            
        }
        else if (gameChoice == 2)
        {
            system("cls");
            SetCursorPosition(0,2);

            cout << " ____        _   _   _      ____  _     _           " << endl;
            cout << "| __ )  __ _| |_| |_| | ___/ ___|| |__ (_)_ __  ___ " << endl;
            cout << "|  _ \\ / _` | __| __| |/ _ \\___ \\| '_ \\| | '_ \\/ __|" << endl;
            cout << "| |_) | (_| | |_| |_| |  __/___) | | | | | |_) \\__ \\ " << endl;
            cout << "|____/ \\__,_|\\__|\\__|_|\\___|____/|_| |_|_| .__/|___/" << endl;
            cout << "                                       |_|          " << endl;
            cout << endl << "Game made by Krzysztof Knaś" << endl;
            cout << "I am proudly presenting to you my first game ever called BattleShips!" << endl << "I made this game for my school OOP class for teacher Jarosław Galus" << endl;
            cout << "Press enter to return to home screen" << endl;
            helper = 1;
            fflush(stdin);
            getchar();
            
        }
        else if (gameChoice == 3)
        {
            system("cls");
            return;
        }                                                                           
    }while(helper == 1);

    setPlayers();

    do
    {
        if (gameCounter != 0)
        {
            resetGame();
        }
        setGame();
        runGame();
        gameCounter++;
        cout << "Do you want to play one more time? (y / anything else than y will close the game)" << endl;
        cin >> choice;
        choice = toupper(choice);

    }while(choice == 'Y');
}

void game::setPlayers()
{
    string name1, name2;
    system("cls");

    SetCursorPosition(1,0);
    cout << "== BattleShips ==";

    SetCursorPosition(1,1);
    cout << "Enter first player name: " << endl;

    SetCursorPosition(1,2);
    cin >> name1;
    
    system("cls");
    SetCursorPosition(1,0);
    cout << "== BattleShips ==";

    SetCursorPosition(1,1);
    cout << "Enter second player name: " << endl;

    SetCursorPosition(1,2);
    cin >> name2;

    
    
    firstPlayer.playerName = name1;
    firstPlayer.shipsTable.parentsName = name1;
    firstPlayer.shipsTable.tableName = "Ships Table";
    firstPlayer.shotsTable.tableName = "Shots Table";

    secondPlayer.shipsTable.parentsName = name2;
    secondPlayer.shipsTable.tableName = "Ships Table";
    secondPlayer.shotsTable.tableName = "Shots Table";
    secondPlayer.playerName = name2;
}

void game::setGame()
{
    system("cls");
    SetCursorPosition(1,0);
    cout << "== BattleShips ==";
    SetCursorPosition(1,2);
    cout << "Player: " << firstPlayer.playerName << endl;
    SetCursorPosition(1,4);
    cout << "Press enter when you are ready!" << endl;
    fflush(stdin);
    getchar();

    system("cls");
    SetCursorPosition(1,1);
    firstPlayer.setPlayer();

    system("cls");
    SetCursorPosition(1,0);
    cout << "== BattleShips ==";

    SetCursorPosition(1,2);
    cout << "Player: " << secondPlayer.playerName << endl;

    SetCursorPosition(1,4);
    cout << "Press enter when you are ready!" << endl;
    fflush(stdin);
    getchar();

    system("cls");

    SetCursorPosition(1,1);
    secondPlayer.setPlayer();

    system("cls");
    SetCursorPosition(1,0);
    cout << "== BattleShips ==";

    SetCursorPosition(1,2);
    cout << "Game is ready to play!" << endl;

    SetCursorPosition(1,3);
    cout << "Press enter to continue";
    fflush(stdin);
    getchar();
}

void game::resetGame()
{
    firstPlayer.shipsTable.resetTable();
    firstPlayer.shotsTable.resetTable();

    secondPlayer.shipsTable.resetTable();
    secondPlayer.shotsTable.resetTable();
}

void game::runGame()
{
    damage takenDamage;
    coordinates shootingPlace;

    while(true)
    {
        system("cls");
        SetCursorPosition(1,0);
        cout << "== BattleShips ==";
        SetCursorPosition(1,2);
        cout << firstPlayer.playerName << " press enter when you're ready!";
        fflush(stdin);
        getchar();
        do
        {
            system("cls"); 
            SetCursorPosition(1,1);
            cout << secondPlayer.playerName << "'s wins: " << secondPlayer.wins << "  " << firstPlayer.playerName << "'s wins: " << firstPlayer.wins << endl;
            shootingPlace = firstPlayer.shootShips();
            takenDamage = secondPlayer.isHit(shootingPlace);
            
            if(takenDamage.isSunk)
            {
                firstPlayer.shotsTable.markSunkenShip(takenDamage.shipsStart, takenDamage.shipsEnd);
                if (secondPlayer.isGameEnded())
                {
                    system("cls");
                    SetCursorPosition(1,0);
                    cout << "== BattleShips ==";
                    SetCursorPosition(1,1);
                    cout << firstPlayer.playerName << " won the game!";
                    fflush(stdin);
                    getchar();
                    firstPlayer.wins++;
                    return;
                }
            }

            firstPlayer.markShots(shootingPlace, takenDamage.isShot);
        }while(takenDamage.isShot);

        system("cls");
        SetCursorPosition(1,0);
        cout << "== BattleShips ==";
        SetCursorPosition(1,2);
        cout << secondPlayer.playerName << " press enter when you're ready!";
        fflush(stdin);
        getchar();
        do
        {
            system("cls"); 
            SetCursorPosition(1,1);
            cout << secondPlayer.playerName << "'s wins: " << secondPlayer.wins << "  " << firstPlayer.playerName << "'s wins: " << firstPlayer.wins << endl;
            shootingPlace = secondPlayer.shootShips();
            takenDamage = firstPlayer.isHit(shootingPlace);
            
            if(takenDamage.isSunk)
            {
                secondPlayer.shotsTable.markSunkenShip(takenDamage.shipsStart, takenDamage.shipsEnd);
                if (firstPlayer.isGameEnded())
                {
                    system("cls");
                    SetCursorPosition(1,0);
                    cout << "== BattleShips ==";
                    SetCursorPosition(1,1);
                    cout << secondPlayer.playerName << " won the game!";
                    fflush(stdin);
                    getchar();
                    secondPlayer.wins++;
                    return;
                }
            }

            secondPlayer.markShots(shootingPlace, takenDamage.isShot);
        }while(takenDamage.isShot);
    }
}

void game::waitForEnter(player obj, string text)
{
    system("cls");
    cout << obj.playerName << text << endl;
    fflush(stdin);
    getchar();
}


