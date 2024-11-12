const int Red = 12, Yellow = 14, White = 7, Blue = 9, Green = 10;
const char SHIP = char(219), HIT = char(177), MISHIT = char(120);

struct coordinates
{
    int x, y;
};

struct damage
{
    bool isShot;
    bool isSunk;
    coordinates shipsStart;
    coordinates shipsEnd;
};


void changeColor(int desiredColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void SetCursorPosition(short x, short y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}