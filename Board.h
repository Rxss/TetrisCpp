#ifndef _BOARD_
#define _BOARD_

#include "pieces.h"

#define BOARD_LINE_WIDTH 6 // Width of each of the two lines that delimit the board
#define BLOCK_SIZE 16 // Width and Height of each block of a piece
#define BOARD_POSITION 320 // Center position of the board from the left of the screen
#define BOARD_WIDTH 10 // Board width in blocks
#define BOARD_HEIGHT 20 // Board height in blocks
#define MIN_VERTICAL_MARGIN 20 // Minimum vertical margin for the board limit
#define MIN_HORIZONTAL_MARGIN 20 // Minimum horizontal margin for the board limit
#define PIECE_BLOCKS 5 // Number of horizontal and vertical blocks of a matrix piece

class Board {
public:

	Board(Pieces* Pieces, int ScreenHeight);

	int GetXPosInPixels(int pos);
	int GetYPosInPixels(int pos);
	bool IsFreeBlock(int x, int y);
	bool IsPossibleMovement(int x, int y, int piece, int rotation);
	void StorePiece(int x, int y, int piece, int rotation);
	void DeletePossibleLines();
	bool IsGameOver();

private:
	enum { POS_FREE, POS_FILLED};
	int board[BOARD_WIDTH][BOARD_HEIGHT]; // Board that contains the pieces
	Pieces* Pieces;
	int ScreenHeight;

	void InitBoard();
	void DeleteLine(int y);
};


#endif
