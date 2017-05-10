#pragma once
namespace Torus
{


	/*
	-every new @step make copy of values stack's top
	-every new @set push new value to stack's top
	-structure's lifeTime == startUp lifetime, only traces are cleared every new action, inserted cells can't be deleted
	*/
	class Torus
	{
	public:
		CellIterator originIt;

		CellIterator meridianIt;
		CellIterator parallelIt;
		CellIterator positionIt;

		CellIterator currentIt;

		Cell origin;
	};
}