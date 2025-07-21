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
	int screenHeight; // Screen height in pixels
	int nextPosX, nextPosY; // Position of the next piece
	int nextPiece, nextRotation; // Kind and rotation of the next piece

	Board* board;
	Pieces* pieces;
	IO* IO;

	int GetRand(int a, int b);
	void InitGame();
	void DrawPiece(int x, int y, int piece, int rotation);
	void DrawBoard();
};



#endif
