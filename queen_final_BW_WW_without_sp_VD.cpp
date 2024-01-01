#include<iostream>
using namespace std;

int k;

void printSolution(int board[8][8])
{
    k++;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            if (board[i][j] == 1) cout << "WW"; //<<" ";
                else if (((j%2 == 0) && (i%2 == 0)) || ((j%2 != 0) && (i%2 != 0))) wcout <<(wchar_t)178<<(wchar_t)178;//<<" ";
                            else wcout <<(wchar_t)176<< (wchar_t)176;//<<" ";
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[8][8], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    for (i=row, j=col; j>=0 && i<8; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solve8QUtil(int board[8][8], int col)
{
    if (col == 8)
    {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < 8; i++)
    {
        if ( isSafe(board, i, col) )
        {
            board[i][col] = 1;
            res = solve8QUtil(board, col + 1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

void solve8Q()
{
    int board[8][8];
    for(int i=0; i<8; i++)
         for(int j=0; j<8; j++)
         board[i][j]=0;

    if (solve8QUtil(board, 0) == false)
    {
        cout <<"Solution does not exist";
        return ;
    }
    return ;
}

// driver program to test above function
int main()
{
    solve8Q();
    cout << "Results' number: " << k;
    return 0;
}
