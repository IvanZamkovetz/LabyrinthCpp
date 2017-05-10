#pragma once
namespace Torus
{
	class Cell
	{
	private:

	public:
		int value;
		int GetValue() { return this->value; }
		__declspec(property(get = GetValue)) int Value;

		int x;
		int y;

		Cell* next;

		Cell* north;
		Cell* south;
		Cell* west;
		Cell* east;
	};

	class Step
	{

	};

	class CellIterator
	{
	public:
		Cell *pCell;
		Cell& operator *() { return *(this->pCell); }

	};

	class StepIterator
	{

	};
}