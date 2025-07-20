#include "Board.h"

void Board::InitBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
		for (int j = 0; j < BOARD_HEIGHT; j++)
			board[i][j] = POS_FREE; // loop to init all board blocks to free
}

void Board::StorePiece(int x, int y, int piece, int rotation)
{
	// Store each block of the piece into the board
	for (int i1 = x, i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = y, j2 = 0; j1 < y + PIECE_BLOCKS; j1++, j2++)
		{
			// Store only the blocks of the piece that are not holes
			if (Pieces->GetBlockType(piece, rotation, j2, i2) != 0)
				board[i1][j1] = POS_FILLED;
		}
	}
}

bool Board::IsGameOver()
{
	//If the first line has blocks, then the game is over
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		if (board[i][0] == POS_FILLED) return true; // checks all blocks across are filled on the first line(0) 
	}

	return false;
}

void Board::DeleteLine(int y)
{
	// Moves all the upper lines one row down
	for (int j = y; j > 0; j--)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			board[i][j] = board[i][j - 1];
		}
	}
}