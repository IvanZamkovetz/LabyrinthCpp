#include "stdafx.h"

Labyrinth::Labyrinth()
{

}
Labyrinth::~Labyrinth()
{

}

void Labyrinth::ClearBuildingTrace() 
{}
void Labyrinth::ClearPassingTrace()
{}
void Labyrinth::ClearMatrix()
{}
void Labyrinth::BuildMatrix()
{}

COORD Labyrinth::GetPosition()
{
	return this->_position;
}
void Labyrinth::SetPosition(COORD position)
{
	this->_position = position;
	std::pair<COORD, int> action(position, 0);
	this->_passingTrace.push_back(action);
}
COORD Labyrinth::GetStart()
{
	return this->_start;
}
void Labyrinth::SetStart(COORD start)
{
	if (this->_field[start.X][start.Y] == 1)
	{
		return;
	}
	this->_start = start;
}
COORD Labyrinth::GetFnish()
{
	return this->_finish;
}
void Labyrinth::SetFnish(COORD finish)
{
	if (this->_field[finish.X][finish.Y] == 1)
	{
		return;
	}
	this->_finish = finish;
}

void Labyrinth::Set(int what)
{
	this->_field[this->_position.X][this->_position.Y] = what;
	std::pair<COORD, int> action(this->_position, what);
	this->_passingTrace.push_back(action);
}
int Labyrinth::Get(COORD where)
{
	return this->_field[where.X][where.Y];
}
