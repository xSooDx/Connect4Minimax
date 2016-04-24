#include <iostream>
#include "Board.h"

#include "Player.h"
#include "Human.h"
#include "AI.h"
using namespace std;

int main()
{
    cout<<"1)PvC\t 2)CvC\t 3)PvP\n";
    int a;
    cin>>a;
    Board board;
    Player *p1;
    Player *p2;
    const int maxTurns=BOARD_COLS*BOARD_ROWS;
    int turn=0;
    int gameState=0; //0-not started, 1-started, 2-finished
    char ch,d;
    switch(a)
    {
    case 1:
        cout<<"Welcome to Connect Four!\n"
            <<"Do you want to play first? (y/n)";

        cin>>ch;

        cout<<"Choose difficulty(1-4)";
        cin>>d;
        d=d-'0';
        if(ch=='Y'||ch=='y')
        {
            cout<<"You are x\n"
                <<"The Computer is o\n";
            p1 = new Human('x');
            //p2 = new Human('o');
            p2 = new AI('o',d);
        }
        else
        {
            cout<<"You are o\n"
                <<"The Computer is x\n";
            p1 = new AI('x',d);
            p2 = new Human('o');
        }
        break;
    case 2:
        cout<<"Choose difficulty(1-4)";
        cin>>d;
        d=d-'0';
        p1 = new AI('x',d);
        p2 = new AI('o',d);
        break;
    case 3:

        p1 = new Human('x');
        p2 = new Human('o');
        break;
    }


    gameState=1;
    int p;
    while(gameState==1)
    {
         p = turn%2;
        board.printBoard(p);
        if(p==0)
        {
            cout<<"Player 1's Move\n";
            p1->makeMove(&board);
        }
        else
        {
            cout<<"Player 2's Move\n";
            p2->makeMove(&board);
        }
        turn+=1;

        if(board.checkForFours())
        {
            if(p==0)
                cout<<"Player 1 Wins!"<<endl;
            else
                cout<<"Player 2 Wins!"<<endl;
            gameState=2;
        }
        if(turn==maxTurns)
        {
            cout<<"Draw";
        }

    }

    board.printBoard(p);


}
