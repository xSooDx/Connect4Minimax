#include "AI.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#define Max(a,b) a>b?a:b
#define Min(a,b) a>b?b:a
using namespace std;

AI::AI(char c,int d)
{
    color=c;
    diff=d+1;
}

void AI::makeMove(Board* b)
{

    mem=new Board(*b);

    int m;
    clock_t start = clock();
    m=bestMove();
    clock_t stop = clock();
    b->place(m,color);
    clock_t ticks=stop-start;
    double time = ticks/(double)CLOCKS_PER_SEC;
    cout<<"AI>> Time taken:"<<time<<" sec"<<endl;
    delete mem;
}



int AI::bestMove()
{
    int moves[BOARD_COLS];
    char op = color=='x'?'o':'x';
    for(int i = 0; i<BOARD_COLS;i++)
    {
        if(mem->isLegal(i))
        {
            mem->place(i,color);
            moves[i]=-searchDepth(diff-1,op);
            mem->undo(i);

        }
        else
        {
            moves[i]=-9999999;
        }
    }
    int best = 0;
    for(int i = 0; i<BOARD_COLS;i++)
    {

        if(moves[i]>moves[best])
            best=i;

    }

    cout<<"AI>> Move value = "<<moves[best]<<endl;

    return best;

}



int AI::searchDepth(int d,char p)
{
    //uses Negmax, a form of minimax to search
    char op = p=='x'?'o':'x';
    int f=0;
    for(int i =0; i<BOARD_COLS;i++)
    {
        if(mem->isLegal(i))
        {
            f=1;
            break;
        }

    }
    if(d==0 || f==0)
        return -value(op);
    int alpha=-9999999;
    for(int i = 0; i<BOARD_COLS;i++)
    {
        if(mem->isLegal(i))
        {
            mem->place(i,p);

            alpha = max(alpha,-searchDepth(d-1,op));

            mem->undo(i);
        }
    }


    return alpha;
}

int AI::value(char p)
{

    char opp= p=='x'?'o':'x';

    int opp4 = checkForStreak(opp,4);
    int my4 = checkForStreak(p,4);
    if(opp4>0)
    {
        return -100000;
    }
    else if(my4>0)
        return 100000;

    int my2 = checkForStreak(p,2);
    int my3 = checkForStreak(p,3);


    return 100000*my4+100*my3+my2;



}

int AI::checkForStreak(char p,int streak)
{

    int count = 0;
    for(int i = 0; i<BOARD_ROWS;i++)
    {
        for(int j = 0; j<BOARD_COLS;j++)
            if(mem->check(i,j)== p)
            {
                count+= mem->verticalCheck(i,j,streak);

                count+= mem->horizontalCheck(i,j,streak);

                count+= mem->diagonalCheck(i,j,streak);

            }
    }

    return count;
}

AI::~AI()
{

}
