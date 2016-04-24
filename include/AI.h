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

        int diff;
        int bestMove();
        int searchDepth(int d,char p);
        int value(char p);
        int checkForStreak(char p,int streak);

        Board *mem;

};

#endif // AI_H
