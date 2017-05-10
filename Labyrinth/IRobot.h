#pragma once

class IRobot
{
public:
	virtual void SetBreadCrumb(int what) = 0;

	virtual int CheckHere() = 0;
	virtual int CheckNorth() = 0;
	virtual int CheckSouth() = 0;
	virtual int CheckWest() = 0;
	virtual int CheckEast() = 0;

	virtual void StepNorth() = 0;
	virtual void StepSouth() = 0;
	virtual void StepWest() = 0;
	virtual void StepEast() = 0;
};