#pragma once

class AlgorithmLoader
{
private:
	IAlgorithm *_pBuilderAlgorithm;
	IAlgorithm *_pRobotAlgorithm;

public:
	AlgorithmLoader();
	AlgorithmLoader(const std::string& builderLibrary, const std::string& robotLibrary);
	virtual ~AlgorithmLoader();

	boost::shared_ptr<std::list<std::string>> GetBuilderAlgorithmList();
	boost::shared_ptr<std::list<std::string>> GetRobotAlgorithmList();

	BOOL LoadBuilderAlgorithm(int builderAlgorithm);
	BOOL LoadRobotAlgorithm(int robotAlgorithm);

	IAlgorithm* GetBuilderAlgorithm();
	IAlgorithm* GetRobotAlgorithm();

	__declspec(property(get = GetBuilderAlgorithm)) IAlgorithm * BuilderAlgorithm;
	__declspec(property(get = GetRobotAlgorithm)) IAlgorithm * RobotAlgorithm;
};