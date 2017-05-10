#pragma once

class Algorithm: public IAlgorithm
{
public:
	IRobot *iRobot;

	Algorithm();
	virtual ~Algorithm();

	BOOL Attach(IRobot* iRobot);
	int Execute();
};