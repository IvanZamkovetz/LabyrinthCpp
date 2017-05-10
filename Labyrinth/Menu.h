#pragma once

class Menu
{
private:
	std::map<std::string, std::string(Menu::*)()> _pSubMenus;//std::string(Menu::*)()

public:
	boost::shared_ptr<Startup> pStartup;

	Menu();
	Menu(boost::shared_ptr<Startup> pStartup);
	Menu(Menu& menu);
	virtual ~Menu();

	void Show();

	std::string MainSub();
	std::string BuilderAlgorithmsSub();
};