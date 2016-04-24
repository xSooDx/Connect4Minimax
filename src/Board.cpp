#include "Board.h"
#include <iostream>


using namespace std;

Board::Board()
{
    int i;
    for(i=0;i<BOARD_COLS;i++)
    {
        int j;
        for(j=0;j<BOARD_ROWS;j++)
            board[j][i]=' ';

        top[i]=BOARD_COLS-1;
    }
    win=0;
}
void Board::undo(int i)
{

    board[top[i]][i]=' ';
    top[i]+=1;
    //cout<<"Top["<<i<<"] :"<<top[i]<<endl;
}

Board::Board(const Board &b)
{
    int i;
    for(i=0;i<BOARD_COLS;i++)
    {
        int j;
        for(j=0;j<BOARD_ROWS;j++)
            board[j][i]=b.board[j][i];
        top[i]=b.top[i];
    }
    lastMove=b.lastMove;

    win=b.win;
}

void Board::place(int c, char color)
{
    int i;
    for(i=5;i>=0;i--)
    {
        if (board[i][c]==' ')
        {
            board[i][c]=color;
            top[c]--;
            lastMove=c;
            break;
        }
    }
}

bool Board::isLegal(int c)
{

    for(int i=0; i<BOARD_ROWS;i++)
    {
        if(board[i][c]==' ')
            return true;
    }

    return false;
}



void Board::printBoard(int turn)
{

    cout<<"\n   ";
    for (int k=0; k<7;k++)

        cout<<"---";
    cout<<endl;

    for (int i=0; i<6;i++)
    {
        for(int j=0; j<7; j++)
        {
            if(j==0)
            {
                cout<<"  |";
            }
            cout<<" "<<board[i][j]<<" ";
            if(j==6)
            {
                cout<<"|\n";
            }


        }

        if(i == 5)
        {
            cout<<"   ";
            for (int k=0; k<7;k++)
                cout<<"---";

            cout<<"\n   ";

            for (int k=1; k<=7;k++)
                cout<<" "<< k <<" ";
        }

        cout<<endl;
    }
   /* if (finished == true)
    {
        cout<<"\n\n Player "<<winner<<" is the winner!\n";
    }*/
}


bool Board::checkForFours()
{
    if(verticalCheck(top[lastMove],lastMove,4)||horizontalCheck(top[lastMove],lastMove,4)||diagonalCheck(top[lastMove],lastMove,4))
    {

        return true;
    }

}

char Board::check(int r, int c)
{
    return board[r][c];
}
bool Board::verticalCheck(int row,int col,int streak)
{
    int consecutiveCount = 0;
    int i;
    for(i=row;i<BOARD_ROWS;i++)
    {
        if(tolower(board[i][col])==tolower(board[row][col]))
        {
            consecutiveCount +=1;
        }

        else
            break;
    }
    if (consecutiveCount>=streak)
    {

        return true;
    }

    return false;
}

bool Board::horizontalCheck(int row,int col,int streak)
{
    int consecutiveCount = 0;
    int i;
    for(i=col;i<BOARD_COLS;i++)
    {

        if(tolower(board[row][i])==tolower(board[row][col]))
        {

            consecutiveCount +=1;
        }
        else break;
    }
    for(i = col-1; i>=0;i--)
    {
        if(tolower(board[row][i])==tolower(board[row][col]))
        {

            consecutiveCount +=1;
        }
        else break;
    }
    if (consecutiveCount>=streak)
    {
        return true;
    }

    return false;
}

int Board::diagonalCheck(int row,int col,int streak)
{

    int total = 0;
    int consecutiveCount = 0;
    int i,j;

    //+ve slope
    for(i = row, j = col;i<BOARD_ROWS,j<BOARD_COLS;i++,j++)
    {
        if(tolower(board[i][j])==tolower(board[row][col]))
        {

            consecutiveCount +=1;
        }
        else break;
    }
    for(i = row-1, j = col-1;i>=0,j>=0;i--,j--)
    {
        if(tolower(board[i][j])==tolower(board[row][col]))
        {

            consecutiveCount +=1;
        }
        else break;
    }
    if(consecutiveCount>=streak)
    {
        total+=1;
    }

    //-ve Slope
    consecutiveCount=0;
    for(i = row, j = col;i<BOARD_ROWS,j>=0;i++,j--)
    {
        if(tolower(board[i][j])==tolower(board[row][col]))
        {

            consecutiveCount +=1;
        }
        else break;
    }
    for(i = row-1, j = col+1;i>=0,j<BOARD_COLS;i--,j++)
    {
        if(tolower(board[i][j])==tolower(board[row][col]))
        {

            consecutiveCount +=1;
        }
        else break;
    }
    if(consecutiveCount>=streak)
    {
        total+=1;
    }


    return total;


}

void Board::highlightFour(int row,int col ,int direction,int sl)
{

}

Board::~Board()
{


}
