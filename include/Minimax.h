#ifndef MINIMAX_H
#define MINIMAX_H
#define BOARD_ROWS 6
#define BOARD_COLS 7

class Minimax
{
    public:
        Minimax();
        Minimax(char [BOARD_ROWS][BOARD_COLS]);

        int bestMove(char state[BOARD_ROWS][BOARD_COLS],int depth,char player); // Returns best move by column no.
        int searchMove(char state[BOARD_ROWS][BOARD_COLS],int depth,char player); // Searches at depth for value of a move.



        virtual ~Minimax();
    protected:
    private:

        char board[BOARD_ROWS][BOARD_COLS];
        char colors[2];
};

#endif // MINIMAX_H
