#pragma once

class IAlgorithm
{
public:
	virtual BOOL Attach(IRobot* iRobot) = 0;
	virtual int Execute() = 0;
};