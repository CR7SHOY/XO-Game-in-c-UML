#include "XOGame.h"

XOGame::XOGame()
{
	Board = 3;
	Moves = 0;
	str = "Its A Draw";
	for (int i = 0; i < 9; i++) Used[i] = false;
}

void XOGame::Put(int index, char XO)
{
	while (true)
	{
		if (index > 0 && index < 10)
		{
			if (!Used[index - 1])
				break;
		}
		Board.updateText(20, 6, " -----> U Stubied Choose Again : ");
		cin >> index;
	}
	Used[index - 1] = true;
	Board.updateText(20, 6, "                                                                          ");
	Board.updateText(0, 6, "                       ");
	Board.change(index, XO);
}  

void XOGame::PrintBoard()
{
	Board.print();
}

void XOGame::UpdateBoard()
{
	Board.update();
}

bool XOGame::GameEnded()
{
	if (checkRows()) return true;
	if (checkCols()) return true;
	if (checkDiagonals()) return true;
	if (Moves == 9) return true;

	return false;
}

void XOGame::NextMove()
{
	Moves++;
}

void XOGame::Print()
{
	cout << endl << str << endl;
}



bool XOGame::checkRows()
{
	if (Board.get(1) == Board.get(2) && Board.get(2) == Board.get(3))
	{
		if (Board.get(1) == 'X') str = "X Won";
		else str = "O won";
		return true;
	}
	if (Board.get(4) == Board.get(5) && Board.get(5) == Board.get(6))
	{
		if (Board.get(4) == 'X') str = "X Won";
		else str = "O won";
		return true;
	}
	if (Board.get(7) == Board.get(8) && Board.get(8) == Board.get(9))
	{
		if (Board.get(7) == 'X') str = "X Won";
		else str = "O won";
		return true;
	}

	return false;

}

bool XOGame::checkCols()
{
	if (Board.get(1) == Board.get(4) && Board.get(4) == Board.get(7))
	{
		if (Board.get(1) == 'X') str = "X Won";
		else str = "O won";
		return true;
	}
	if (Board.get(2) == Board.get(5) && Board.get(5) == Board.get(8))
	{
		if (Board.get(2) == 'X') str = "X Won";
		else str = "O won";
		return true;
	}
	if (Board.get(3) == Board.get(6) && Board.get(6) == Board.get(9))
	{
		if (Board.get(3) == 'X') str = "X Won";
		else str = "O won";
		return true;
	}

	return false;
}

bool XOGame::checkDiagonals()
{
	if (Board.get(1) == Board.get(5) && Board.get(5) == Board.get(9))
	{
		if (Board.get(1) == 'X') str = "X Won";
		else str = "O won";
		return true;
	}
	if (Board.get(3) == Board.get(5) && Board.get(5) == Board.get(7))
	{
		if (Board.get(3) == 'X') str = "X Won";
		else str = "O won";
		return true;
	}
	

	return false;
}
