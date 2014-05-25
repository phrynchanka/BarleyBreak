#include "function.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

int main()
{
    char button;
    char push;
    bool flag = true;
    int row;
    int column;
    Barley_break play;
    play.initBoard();
    play.mixBoard();
    play.locateEmpty(row, column);
    while (flag)
    {
        cout << "Hello,please,choose you action:\n";
        cout << "Instructions - 1\n";
        cout << "Game - 2\n";
        flag = false;
        push = getch();
        if(push == '1')
        {
            cout << "Control:\n";
            cout << "up - w\n";
            cout << "down - s\n";
            cout << "left - a\n";
            cout << "right - d\n";
            cout << "There are exist unsolvable cases, be careful";
            cout << "Good luck:)\n";
            flag = true;
        }
        if(push == '2')
        {
            if( play.isSolved(row))
            {
                while ( !play.checkRegulation() )
                {
                    system("cls");
                    play.printBoard();
                    button = getch();
                    play.moveElement(row,column,button);
                    play.locateEmpty(row,column);
                    system("cls");
                    play.printBoard();
                }
            }
            else
            {
                play.printBoard();
                cout << "Solution does not exist!!!";
                play.isSolved(row);
            }
        }
    }
    return 0;
}
