#ifndef HUMAN_H
#define HUMAN_H

#include <Player.h>


class Human : public Player
{
    public:
        Human(char c);

        void makeMove(Board* b);
        ~Human();
    protected:
    private:
};

#endif // HUMAN_H
