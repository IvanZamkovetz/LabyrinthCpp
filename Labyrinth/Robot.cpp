#include "stdafx.h"

Robot::Robot()
{

}
Robot::Robot(boost::shared_ptr<Labyrinth> pLabyrinth)
{
	this->pLabyrinth = pLabyrinth;

}
Robot::~Robot()
{

}

void Robot::SetBreadCrumb(int what)
{
	if (this->state == destroyed) return;
	if (what == 1) return;

	this->pLabyrinth.get()->Set(what);
}

int Robot::CheckHere()
{
	if (this->state == destroyed) return -1;
	 
	Torus::CellIterator it = this->pTorus->positionIt;
	(*it).value;

	COORD here = this->pLabyrinth.get()->Position;
	int what = this->pLabyrinth.get()->Get(here);

	return what;
}
int Robot::CheckNorth()
{
	if (this->state == destroyed) return -1;

	COORD northen = this->pLabyrinth.get()->Position;
	++northen.Y;
	int what = this->pLabyrinth.get()->Get(northen);

	return what;
}
int Robot::CheckSouth()
{
	return 0;
}
int Robot::CheckWest()
{
	return 0;
}
int Robot::CheckEast()
{
	return 0;
}

void Robot::StepNorth()
{
	if (this->state == destroyed) return;

	COORD northen = this->pLabyrinth.get()->Position;
	++northen.Y;
	this->pLabyrinth.get()->Position = northen;

	if (this->pLabyrinth.get()->Get(northen) == 1)
	{
		this->state = destroyed;
	}

	return;
}
void Robot::StepSouth() {}
void Robot::StepWest() {}
void Robot::StepEast() {}