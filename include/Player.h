#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"


class Player
{
    public:
        virtual void makeMove(Board*)=0;
        virtual ~Player() {};
    protected:
        char color;
        int type;
    private:

};

#endif // PLAYER_H
