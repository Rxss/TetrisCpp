

#ifndef LINUX
#include <windows.h>
#endif

#include "Game.h"

void Game::InitGame()
{
	// Init random numbers
	srand((unsigned int)time(NULL));

	// First piece
	piece = GetRand(0, 6);
	rotation = GetRand(0, 3);
	posX = (BOARD_WIDTH / 2) + pieces->GetXInitialPosition(piece, rotation);
	posY = pieces->GetYInitialPosition(piece, rotation);

	// Next piece
	nextPiece = GetRand(0, 6);
	nextRotation = GetRand(0, 3);
	nextPosX = BOARD_WIDTH + 5;
	nextPosY = 5;
}

void Game::CreateNewPiece()
{
	piece = nextPiece;
	rotation = nextRotation;
	posX = (BOARD_WIDTH / 2) + pieces->GetXInitialPosition(piece, rotation);

	posY = pieces->GetYInitialPosition(piece, rotation);

	// Random next piece
	nextPiece = GetRand(0, 6);
	nextRotation = GetRand(0, 3);
}

void Game::DrawPiece(int x, int y, int piece, int rotation)
{
	color colour; // Colour of the block

	// Obtain the position in pixel in the screen of the block we want to draw
	int pixelsX = board->GetXPosInPixels(x);
	int pixelsY = board->GetYPosInPixels(y);

	// Travel the matrix of blocks of the piece and draw the blocks that are filled
	for (int i = 0; i < PIECE_BLOCKS; i++)
	{
		for (int j = 0; j < PIECE_BLOCKS; j++)
		{
			// Get the type of the block and draw it with the correct color
			switch (pieces->GetBlockType(piece, rotation, j, i))
			{
			case 1: colour = GREEN; break; // For each block of the piece except the pivot
			case 2: colour = BLUE; break; // For the pivot
			}

			if (pieces->GetBlockType(piece, rotation, j, i) != 0)
				IO->DrawRectangle(pixelsX + i * BLOCK_SIZE,
					pixelsY + j * BLOCK_SIZE,
					(pixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
					(pixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
					colour);
		} 
	}
}

void Game::DrawBoard()
{

	// Calculate the limits of the board in pixels
	int x1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
	int x2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
	int y = screenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

	// Check that the vertical margin is not to small
	//assert (y  > MIN_VERTICAL_MARGIN);

	// Rectangles that delimits the board
	IO->DrawRectangle(x1 - BOARD_LINE_WIDTH, y, x1, screenHeight - 1, BLUE);

	IO->DrawRectangle(x2, y, x2 + BOARD_LINE_WIDTH, screenHeight - 1, BLUE);

	// Check that the horizontal margin is not to small
	//assert (x1 > MIN_HORIZONTAL_MARGIN);

	// Drawing the blocks that are already stored in the board
	x1 += 1;
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			// Check if the block is filled, if so, draw it
			if (!board->IsFreeBlock(i, j))
				IO->DrawRectangle(x1 + i * BLOCK_SIZE,
					y + j * BLOCK_SIZE,
					(x1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
					(y + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
					RED);
		}
	}
}