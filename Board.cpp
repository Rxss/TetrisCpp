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

void Board::DeletePossibleLines()
{
	for (int j = 0; j < BOARD_HEIGHT; j++) {
		int i = 0;
		while (i < BOARD_WIDTH) {
			if (board[i][j] != POS_FILLED) break;
			i++;
		}
		if (i == BOARD_WIDTH) DeleteLine(j);
	}
}

bool Board::IsFreeBlock(int x, int y)
{
	if (board[x][y] == POS_FREE) 
		return true; 
	else return false;
}

int Board::GetXPosInPixels(int pos)
{
	return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pos * BLOCK_SIZE));
}

int Board::GetYPosInPixels(int pos)
{
	return ((ScreenHeight - (BLOCK_SIZE)) * (BOARD_HEIGHT) + (pos * BLOCK_SIZE));
}

bool Board::IsPossibleMovement(int x, int y, int piece, int rotation)
{
	for (int i1 = x,int i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++) {
		for (int j1 = y, int j2 = 0; j1 < y + PIECE_BLOCKS; i1++, i2++) {
			if (i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 > BOARD_HEIGHT - 1) {
				if (Pieces->GetBlockType(piece, rotation, j2, i1) != 0) {
					return 0;
				}

				if (j1 >= 0) {
					if ((Pieces->GetBlockType(piece, rotation, j2, i2) != 0) && (!IsFreeBlock(i1, j1))) {
						return false;

					}
				}
			}
		}
		return true;
	}
}
