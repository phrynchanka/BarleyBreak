#ifndef FUNCTION_H
#define FUNCTION_H

class Barley_break
{
public:
    Barley_break();
    ~Barley_break();
    void initBoard();
    void printBoard();
    void locateEmpty(int &row, int &column);
    void moveElement(int row,int column, char button);
    void mixBoard();
    bool isSolved(int row);
    bool checkRegulation();
    int cmp(int a,int b);
private:
    Barley_break (const  Barley_break &original);
    Barley_break & operator = (const  Barley_break & rhs);
    int row;
    int column;
    int** board;
    int n;
};

#endif // FUNCTION_H
