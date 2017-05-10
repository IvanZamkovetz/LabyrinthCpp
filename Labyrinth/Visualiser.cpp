#include "stdafx.h"

Visualiser::Visualiser()
{
	this->pLabyrinth.reset();

	this->_res = 0;
	this->_dwCursorPosition.X = 0;
	this->_dwCursorPosition.Y = 0;

	this->_hConsoleOutput = INVALID_HANDLE_VALUE;

}
Visualiser::Visualiser(boost::shared_ptr<Labyrinth> pLabyrinth)
{
	this->pLabyrinth = pLabyrinth;

	this->_res = 0;
	this->_dwCursorPosition.X = 0;
	this->_dwCursorPosition.Y = 0;

	this->_hConsoleOutput = INVALID_HANDLE_VALUE;
}

Visualiser::~Visualiser()
{}

BOOL Visualiser::Initialize()
{
	this->_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	if (this->_hConsoleOutput == INVALID_HANDLE_VALUE)
	{
		printf("error get console handle");
		return -1;
	}

	return 0;
}

void Visualiser::ShowBuilding()
{
	this->pLabyrinth.get()->ClearMatrix();
	//renderingCycle;
}
void Visualiser::ShowPassing()
{
	this->pLabyrinth.get()->BuildMatrix();
	//renderingCycle;
}

void Visualiser::ShowLabyrinth()
{
	this->pLabyrinth.get()->BuildMatrix();

	this->_dwCursorPosition.X = 10;
	this->_dwCursorPosition.Y = 10;
	this->_res = SetConsoleCursorPosition(this->_hConsoleOutput, this->_dwCursorPosition);

	if (this->_res == 0)
	{
		printf("error set cursor position");
		return;
	}

	return;
}