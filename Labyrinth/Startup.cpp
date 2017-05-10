#include "stdafx.h"

Startup::Startup()
{
	this->_pLabyrinth.reset(new Labyrinth());
	this->_pAlgorithmLoader.reset(new AlgorithmLoader());

	this->builderAlgorithmList = this->_pAlgorithmLoader.get()->GetBuilderAlgorithmList();
	this->robotAlgorithmList = this->_pAlgorithmLoader.get()->GetRobotAlgorithmList();

}
Startup::Startup(const std::string& builderLibrary, const std::string& robotLibrary)
{
	this->_pLabyrinth.reset(new Labyrinth());
	this->_pAlgorithmLoader.reset(new AlgorithmLoader(builderLibrary, robotLibrary));

	this->builderAlgorithmList = this->_pAlgorithmLoader.get()->GetBuilderAlgorithmList();
	this->robotAlgorithmList = this->_pAlgorithmLoader.get()->GetRobotAlgorithmList();

}
Startup::~Startup()
{}

BOOL Startup::ChooseBuilderAlgorithm(int builderAlgorithm)
{
	if (this->_pAlgorithmLoader.get()->LoadBuilderAlgorithm(builderAlgorithm) == FALSE)
	{
		return FALSE;
	}
	return TRUE;
}
BOOL Startup::ChooseRobotAlgorithm(int robotAlgorithm)
{
	if (this->_pAlgorithmLoader.get()->LoadRobotAlgorithm(robotAlgorithm) == FALSE)
	{
		return FALSE;
	}
	return TRUE;
}

void Startup::BuildLabyrinth()
{
	this->_pLabyrinth.get()->ClearBuildingTrace();
	this->_pLabyrinth.get()->ClearMatrix();
	//building;
	this->_pLabyrinth.get()->ClearMatrix();
}
void Startup::PassLabyrinth()
{
	IAlgorithm* robotAlgorithm = this->_pAlgorithmLoader.get()->RobotAlgorithm;
	if (robotAlgorithm == NULL)
	{
		return;
	}

	this->_pLabyrinth.get()->ClearPassingTrace();
	this->_pLabyrinth.get()->BuildMatrix();

	boost::scoped_ptr<Robot> pRobot{ new Robot(this->_pLabyrinth) };
	boost::scoped_ptr<Visualiser> pVisualiser{ new Visualiser(this->_pLabyrinth) };

	robotAlgorithm->Attach(static_cast<IRobot*>(pRobot.get()));
	robotAlgorithm->Execute();

	pVisualiser.get()->ShowPassing();
	this->_pLabyrinth.get()->ClearMatrix();
}

void Startup::SetStartPoint()
{}
void Startup::SetFinishPoint()
{}

void Startup::TraceBuilding()
{
	boost::scoped_ptr<Visualiser> pVisualiser{ new Visualiser(this->_pLabyrinth) };
	pVisualiser.get()->ShowBuilding();
}
void Startup::TracePassing()
{
	boost::scoped_ptr<Visualiser> pVisualiser{ new Visualiser(this->_pLabyrinth) };
	pVisualiser.get()->ShowPassing();
}