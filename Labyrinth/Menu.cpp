#include "stdafx.h"

Menu::Menu()
{
	this->_pSubMenus["MainSub"] = &Menu::MainSub;
	this->_pSubMenus["BuilderAlgorithmsSub"] = &Menu::BuilderAlgorithmsSub;

}
Menu::Menu(boost::shared_ptr<Startup> pStartup)
{
	this->pStartup = pStartup;

	this->_pSubMenus["MainSub"] = &Menu::MainSub;
	this->_pSubMenus["BuilderAlgorithmsSub"] = &Menu::BuilderAlgorithmsSub;

}
Menu::Menu(Menu& menu)
{
}
Menu::~Menu()
{
}

void Menu::Show()
{
	char wait;

	std::cout << "Welcome to Labyrinth!" << std::endl;

	std::string nextSubMenu = "MainSub";
	while (nextSubMenu != "Exit")
	{
		system("cls");
		nextSubMenu = (this->*(this->_pSubMenus[nextSubMenu]))();
	}

	std::cout << "Goodbye! Press Enter to exit." << std::endl;

	std::cin.ignore();
	std::cin.get(wait);
}

std::string Menu::MainSub()
{
	std::string option = "0";

	std::cout << "Choose option:" << std::endl
		<< "1: New labyrinth" << std::endl
		<< "2: Exit" << std::endl;
	std::cin >> option;

	switch (std::stoi(option))
	{
	case 1:
		return "BuilderAlgorithmsSub";
	case 2:
		return "Exit";
	default:
		std::cout << "Please, choose correct option" << std::endl;
		Sleep(1000);
		return "MainSub";
	}
}
std::string Menu::BuilderAlgorithmsSub()
{
	std::cout << "Choose builder algorithm:" << std::endl;
	int options = 1;
	for each (std::string algorithmName in *this->pStartup.get()->builderAlgorithmList.get())
	{
		std::cout << options << ": "
			<< algorithmName << std::endl;

		options++;
	}
	std::cout << options << ": "
		<< "Exit" << std::endl;

	std::string sOption = "1";
	std::cin >> sOption;
	int iOption = std::stoi(sOption);
	if (iOption >= 1 && iOption <= options - 1)
	{
		BOOL chosen = this->pStartup.get()->ChooseBuilderAlgorithm(iOption);
		if (chosen == FALSE)
		{
			std::cout << "Unable to load chosen builder algorithm." << std::endl
				<< "Please, choose another one" << std::endl;
			return "BuilderAlgorithmsSub";
		}
		return "MainSub";
	}
	if (iOption == options)
	{
		return "Exit";
	}
	std::cout << "Please, choose correct option" << std::endl;
	Sleep(1000);
	return "BuilderAlgorithmsSub";
}