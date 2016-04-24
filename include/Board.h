#ifndef BOARD_H
#define BOARD_H
#define BOARD_ROWS 6
#define BOARD_COLS 7

class Board
{
    public:
        Board();
        Board(const Board &b);
        bool isLegal(int c);

        bool checkForFours();

        void printBoard(int turn);

        void highlightFour(int row,int col ,int direction,int sl);

        void place(int c, char color);


        bool verticalCheck(int row,int col,int streak);
        bool horizontalCheck(int row,int col,int streak);
        int diagonalCheck(int row,int col,int streak);
        void undo(int i);

        char check(int r, int c);

        virtual ~Board();

    private:


        int win;

        int top[BOARD_COLS];
        char board[BOARD_ROWS][BOARD_COLS];
        int lastMove;
};

#endif // BOARD_H
