#include "board.h"
#include <windows.h>

board::board(int size)
{
	int count = 1;
	vec.resize(size);
	for (int i = 0; i < size; i++)
	{
		vec.at(i).resize(size);
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			vec.at(i).at(j) = char(count++ + '0');
}

void board::change(int index, char p)
{
	int i = 0;
	while (index > 3)
	{
		index -= 3;
		i++;
	}
	vec.at(i).at(index - 1) = p;
}

char board::get(int index)
{
	int i = 0;
	while (index > 3)
	{
		index -= 3;
		i++;
	}
	return vec.at(i).at(index - 1);
}

void board::print()
{
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << vec.at(i).at(j);
			if (j != size - 1) cout << '|';
		}
		if (i != size - 1)
		{
			cout << endl;
			cout << "-----";
			cout << endl;
		}
	}
	cout << endl << endl;
}

void board::update()
{
	string str = "";
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			str += vec.at(i).at(j);
			if (j != size - 1) str += '|';
		}
		if (i != size - 1)
		{
			str += "\n";
			str += "-----";
			str += "\n";
		}
	}
	str += "\n";
	str += "\n";
	updateText(0,0,str);
}

void board::updateText(int x, int y, const std::string& text)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << text;
}

