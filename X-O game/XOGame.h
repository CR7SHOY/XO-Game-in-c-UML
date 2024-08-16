#pragma once
#include "board.h"


class XOGame
{
private:
	board Board;
	int Moves;
	string str;
	bool Used[9];
public:
	XOGame();
	void Put(int index,char XO);
	void PrintBoard();
	void UpdateBoard();
	bool GameEnded();
	void NextMove();
	void Print();
	

private:
	bool checkRows();
	bool checkCols();
	bool checkDiagonals();
};

