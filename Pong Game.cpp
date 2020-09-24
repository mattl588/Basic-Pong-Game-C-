#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
bool gameOver;
const int length = 80;
const int height = 20;
int y; //y of the paddle's top portion.
int x = 4;
int ballx, bally; //ball's coordinates. 
int score;
enum eDirection {STOP = 0, UP, DOWN, LEFT, RIGHT};
eDirection dir;
eDirection balldirx;
eDirection balldiry;

void Setup()
{
    gameOver = false;
    score = 0;
    dir = STOP;
    balldirx = RIGHT;
    balldiry = UP;
    y = 9;
    ballx = 40;
    bally = 10;
}
void Sketch()
{
    system("cls");
    for (int i = 0; i <= length; i++)
    {
        cout << "=";
    }
    cout << endl;
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= length; j++)
        {
            if (j == 0) {
                cout << "=";
            }
            else if (j == length) {
                cout << "=";
                cout << endl;
            }
            else if (j == x && i == y || j == 4 && i == y-1 || j == 4 && i == y - 2) { //this makes the second paddle. Can I express it more eloquently?
                cout << "X";
            }
            else if (j == ballx && i == bally) {
                cout << "B";
            }
            else
                cout << " ";
        }
    }
    for (int i = 0; i <= length; i++) 
        cout << "=";
    cout << endl;
    cout << "Score:" << score;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'q':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    switch (dir)
    {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (ballx >= length - 1)
    {
        balldirx = LEFT;
    }
    else if (ballx == 5)
    {
        if (ballx == x + 1 && bally == y || ballx == x + 1 && bally == y - 1 || ballx == x + 1 && bally == y - 2) {
            balldirx = RIGHT;
            score += 10;
        }
        else {
            gameOver = true;
        }
    }
    if (bally == 0) {
        balldiry = DOWN;
        }
    else if (bally == height) {
        balldiry = UP;
    }

    switch (balldirx)
    {
    case LEFT:
        ballx--;
        break;
    case RIGHT:
        ballx++;
        break;
    }
    switch (balldiry) {
    case UP:
        bally--;
        break;
    case DOWN:
        bally++;
        break;
    }
}
int main()
{
    Setup();
    while (!gameOver) {

        Sketch();
        Input();
        Logic();
    }
}
