#ifndef AI_H
#define AI_H

#include <Player.h>


class AI : public Player
{
    public:
        AI(char c,int d);
        void makeMove(Board* b);
        ~AI();
    protected:
    private:

        int diff; //Depth to search
        int bestMove(); //finds the best move
        int searchDepth(int d,char p); // searches at depth for best move
        int value(char p); //heuristic value of a state
        int checkForStreak(char p,int streak);

        Board *mem;

};

#endif // AI_H
