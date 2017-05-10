#pragma once

enum RobotState
{
	ok,
	destroyed
};

class Robot : public IRobot
{
private:

public:
	boost::shared_ptr<Torus::Torus> pTorus;
	boost::shared_ptr<Labyrinth> pLabyrinth;

	COORD position;
	RobotState state;

	Robot();
	Robot(boost::shared_ptr<Labyrinth> pLabyrinth);
	virtual ~Robot();

	void SetBreadCrumb(int what);

	int CheckHere();
	int CheckNorth();
	int CheckSouth();
	int CheckWest();
	int CheckEast();

	void StepNorth();
	void StepSouth();
	void StepWest();
	void StepEast();
};