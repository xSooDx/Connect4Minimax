#include "Minimax.h"
#include <string.h>

Minimax::Minimax()
{
    colors[0]='X';
    colors[1]='O';
    int i,j;
    for(i=0;i<BOARD_ROWS;i++)
    {
        for(j=0;j<BOARD_COLS;j++)
        {
            board[i][j]=' ';

        }

    }
}

Minimax::Minimax(char state[BOARD_ROWS][BOARD_COLS])
{
   /* colors[0]='X';
    colors[1]='O';
    int i,j;
    for(i=0;i<BOARD_ROWS;i++)
    {
        for(j=0;j<BOARD_COLS;j++)
        {
            board[i][j]=state[i][j];
        }

    }*/

}

int Minimax::bestMove(char state[BOARD_ROWS][BOARD_COLS],int depth,char player)
{

    return 0;
}

Minimax::~Minimax()
{
    //dtor
}
