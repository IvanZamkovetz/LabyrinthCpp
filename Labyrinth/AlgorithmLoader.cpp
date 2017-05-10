#include "stdafx.h"

AlgorithmLoader::AlgorithmLoader()
{
	LoadLibrary(TEXT("Algorithms"));
}
AlgorithmLoader::AlgorithmLoader(const std::string& builderLibrary, const std::string& robotLibrary)
{}
AlgorithmLoader::~AlgorithmLoader()
{}

boost::shared_ptr<std::list<std::string>> AlgorithmLoader::GetBuilderAlgorithmList()
{
	return boost::shared_ptr<std::list<std::string>>(new std::list<std::string>{ "Default", "BuilderAlg1" });
}
boost::shared_ptr<std::list<std::string>> AlgorithmLoader::GetRobotAlgorithmList()
{
	return boost::shared_ptr<std::list<std::string>>(new std::list<std::string>{"Default", "RobotAlg1"});
}

BOOL AlgorithmLoader::LoadBuilderAlgorithm(int builderAlgorithm)
{
	std::list<std::string> builderAlgorithms{ "Default", "BuilderAlg1" };
	std::list<std::string>::iterator itBuilderAlgorithms = builderAlgorithms.begin();

	if (builderAlgorithm > builderAlgorithms.size())
	{
		return FALSE;
	}

	std::advance(itBuilderAlgorithms, builderAlgorithm - 1);
	std::cout << *itBuilderAlgorithms;
	return TRUE;
}
BOOL AlgorithmLoader::LoadRobotAlgorithm(int robotAlgorithm)
{
	return TRUE;
}

IAlgorithm* AlgorithmLoader::GetBuilderAlgorithm()
{
	return this->_pBuilderAlgorithm;
}
IAlgorithm* AlgorithmLoader::GetRobotAlgorithm()
{
	return this->_pRobotAlgorithm;
}