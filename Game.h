#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "pieces.h"
#include "IO.h"
#include <time.h>

#define WAIT_TIME 700 // Number of Miliseconds that the piece remains before going 1 block down

class Game {
public:
	Game(Board* board, Pieces* Pieces, IO* IO, int ScreenHeight);

	void DrawScene();
	void CreateNewPiece();

	int posX, posY; //position of the falling piece
	int piece, rotation; // Kind and rotation of the falling piece

private:
	int mScreenHeight; // Screen height in pixels
	int mNextPosX, mNextPosY; // Position of the next piece
	int mNextPiece, mNextRotation; // Kind and rotation of the next piece

	Board* mBoard;
	Pieces* mPieces;
	IO* mIO;

	int GetRand(int pA, int pB);
	void InitGame();
	void DrawPiece(int pX, int pY, int pPiece, int pRotation);
	void DrawBoard();
};



#endif
