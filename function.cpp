#include "function.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

Barley_break :: Barley_break()
{
    n = 4;
    board = new int*[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
    }
}
Barley_break :: ~Barley_break()
{
    for (int i = 0; i < n; ++i)
    {
        delete []board[i];
    }
    delete []board;
    board = nullptr;
}
void Barley_break :: initBoard()
{
    int in = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            board[i][j] = in;
            ++in;
        }
    }
}
void Barley_break :: printBoard()
{
    cout << "*";
    for (int k = 0; k < 4; ++k)
    {
        cout << "*" << "*"<< '|';
    }
    cout << "*";
    cout << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << '*';
        for(int j = 0; j < n; ++j)
        {
            cout.setf(ios::right);
            cout.width(2);
            if (board[i][j] == 16)
            {
                cout << ' ' << "|";
            }
            else
            {
                cout << board[i][j] << "|" ;
            }
        }
        cout << '*' << endl;
        cout << '*' ;
        for (int k = 0; k < 4; ++k)
        {
            cout << "*" << "*" << '|';
        }
        cout << '*';
        cout << endl;
    }
}
void Barley_break :: locateEmpty(int &row, int &column)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(board[i][j] == 16)
            {
                row = i;
                column = j;
            }
        }
    }
}
void Barley_break :: moveElement(int row, int column, char button)
{
    int mrow;
    int mcolumn;
    if(button == 'w')
    {
        mrow = row + 1;
        mcolumn = column;
        if ( (mrow >= 0 && mrow < n) && (mcolumn >=0 && mcolumn < n) )
        {
            board[row][column] = board[mrow][mcolumn];
            board[mrow][mcolumn] = 16;
        }
    }
    if(button == 's')
    {
        mrow = row - 1;
        mcolumn = column;
        if ( (mrow >= 0 && mrow < n) && (mcolumn >=0 && mcolumn < n) )
        {
            board[row][column] = board[mrow][mcolumn];
            board[mrow][mcolumn] = 16;
        }
    }
    if(button == 'a')
    {
        mrow = row;
        mcolumn = column + 1;
        if ( (mrow >= 0 && mrow < n) && (mcolumn >=0 && mcolumn < n) )
        {
            board[row][column] = board[mrow][mcolumn];
            board[mrow][mcolumn] = 16;
        }
    }
    if(button == 'd')
    {
        mcolumn = column - 1;
        mrow = row;
        if ( (mrow >= 0 && mrow < n) && (mcolumn >=0 && mcolumn < n) )
        {
            board[row][column] = board[mrow][mcolumn];
            board[mrow][mcolumn] = 16;
        }
    }
}
void Barley_break :: mixBoard()
{
    srand(time(NULL));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            swap(board[i][j],board[rand()%n][rand()%n]);
        }
}
bool Barley_break :: isSolved(int row)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = i; k < n; ++k)
            {
                for(int u = j; u < n; ++u)
                {
                    if(board[i][j] == 16)
                    {
                        continue;
                    }
                    else
                    {
                        if( (cmp(board[i][j],board[k][u+1])) > 0 )
                        {
                            ++sum;
                        }
                    }
                }
            }
        }
    }
    sum = sum + row +1;
    return !(sum%2);
}
int Barley_break :: cmp(int a, int b)
{
    return a-b;
}
bool Barley_break :: checkRegulation()
{
    int in = 1;
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            if(board[i][j] == in)
            {
                s += board[i][j];
                ++in;
            }
    }
    s = s/136;
    if (s == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
