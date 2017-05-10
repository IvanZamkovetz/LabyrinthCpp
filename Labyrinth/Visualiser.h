#pragma once

class Visualiser
{
private:
	HANDLE _hConsoleOutput;
	BOOL _res;
	COORD  _dwCursorPosition;

public:
	boost::shared_ptr<Labyrinth> pLabyrinth;

	Visualiser();
	Visualiser(boost::shared_ptr<Labyrinth> pLabyrinth);
	~Visualiser();

	BOOL Initialize();

	void ShowBuilding();
	void ShowPassing();

	void ShowLabyrinth();
};