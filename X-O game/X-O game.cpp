#include <iostream>
#include "XOGame.h"




int main()
{
	XOGame Game;
	Game.PrintBoard();
	while (true)
	{
		int index;

		cout << "X player turn : ";
		cin >> index;
		Game.Put(index, 'X');
		cout << endl;
		Game.UpdateBoard();
		Game.NextMove();
		if (Game.GameEnded()) break;

		cout << "O player turn : ";
		cin >> index;
		Game.Put(index, 'O');
		cout << endl;
		Game.UpdateBoard();
		Game.NextMove();
		if (Game.GameEnded()) break;

	}
    
	Game.Print();

}