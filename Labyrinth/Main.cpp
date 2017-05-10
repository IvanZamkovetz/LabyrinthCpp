// Labyrinth.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"

struct Position
{
	int x;
	int y;

	bool operator ==(const Position& right) const { return(this->x == right.x && this->y == right.y); }
	bool operator <(const Position& right) const 
	{
		if (this->x < right.x)
		{
			return true;
		}
		if (this->x == right.x && this->y < right.y)
		{
			return true;
		}
		return false; 
	}

};
struct Step
{
	Position position;
	int value;
};
std::size_t hash_value(Position const& p)
{
	boost::hash<int> hasher;
	return ((hasher(p.x) << 16) | hasher(p.y));
}

/*
hashed_non_unique finds the last non unique node pushed thru sequenced interface
*/
typedef boost::multi_index_container<
	Step,
	boost::multi_index::indexed_by<
	boost::multi_index::sequenced<>,
	boost::multi_index::hashed_non_unique<
	boost::multi_index::member<
	Step, Position, &Step::position
	>
	>
	>
> trace;

int main()
{
	using std::cout;

	trace t;

	Position *p = new Position();
	p->x = 0;
	p->y = 0;

	Step *s = new Step();
	s->position = *p;
	s->value = 2;

	const trace::nth_index<1>::type& mapTrace = t.get<1>();
	t.push_back({ { 1, 1 }, 1 });
	t.push_back({ { 0, 0 }, 0 });
	t.push_back({ { 1, 1 }, 2 });
	t.push_back({ *p, 1 });
	t.push_back({ { 1, 1 }, 3 });
	t.push_back(*s);
	t.push_back({ { 1, 1 }, 4 });




	auto it = mapTrace.find(Position { 0, 0 });
	
	Step s2 = *it++;
	while (1)
	{
		s2 = *it++;
	}

	return 0;
}

//boost::shared_ptr<Startup> startup(new Startup("BuilderAlgorithms", "RobotAlgorithms"));
//boost::scoped_ptr<Menu> menu(new Menu(startup));
//menu.get()->Show();