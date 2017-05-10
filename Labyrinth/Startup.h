#pragma once

class Startup
{
private:
	boost::shared_ptr<Labyrinth> _pLabyrinth;
	boost::scoped_ptr<AlgorithmLoader> _pAlgorithmLoader;

public:
	boost::shared_ptr<std::list<std::string>> builderAlgorithmList;
	boost::shared_ptr<std::list<std::string>> robotAlgorithmList;

	Startup();
	Startup(const std::string& builderLibrary, const std::string& robotLibrary);
	virtual ~Startup();

	BOOL ChooseBuilderAlgorithm(int builderAlgorithm);
	BOOL ChooseRobotAlgorithm(int robotAlgorithm);

	void BuildLabyrinth();
	void PassLabyrinth();

	void SetStartPoint();
	void SetFinishPoint();

	void TraceBuilding();
	void TracePassing();
};