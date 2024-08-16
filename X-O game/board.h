#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;


class board
{
private:
	vector<vector<char>> vec;

public:
	board(int size = 3);
	void change(int index, char p);
	char get(int index);
	void print();
	void update();

public:

	void updateText(int x, int y, const std::string& text);
};

