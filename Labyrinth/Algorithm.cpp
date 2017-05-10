#include "stdafx.h"

Algorithm::Algorithm()
{

}

Algorithm::~Algorithm()
{

}

BOOL Algorithm::Attach(IRobot *iRobot)
{
	this->iRobot = iRobot;

	return true;
}
int Algorithm::Execute()
{
	return 0;
}