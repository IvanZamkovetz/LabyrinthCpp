#pragma once

class Labyrinth
{
private:
	int _field[25][50];

	COORD _position;
	COORD _start;
	COORD _finish;

	std::vector<std::vector<int>> _matrix;

	std::vector<std::pair<COORD, int>> _buildingTrace;
	std::vector<std::pair<COORD, int>> _passingTrace;

public:

	Labyrinth();
	~Labyrinth();

	void ClearBuildingTrace();
	void ClearPassingTrace();

	void ClearMatrix();
	void BuildMatrix();

	COORD GetPosition();
	void SetPosition(COORD position);
	__declspec(property(get = GetPosition, put = SetPosition)) COORD Position;
	COORD GetStart();
	void SetStart(COORD start);
	__declspec(property(get = GetStart, put = SetStart)) COORD Start;
	COORD GetFnish();
	void SetFnish(COORD finish);
	__declspec(property(get = GetFnish, put = SetFnish)) COORD Finish;

	void Set(int what);
	int Get(COORD where);
};