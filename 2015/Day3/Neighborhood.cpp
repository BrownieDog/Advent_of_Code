#include "Neighborhood.hpp"

#include <stdexcept>

Neighberhood::Neighberhood(size_t radius)
{
	//make sure our type is big enough
	if (radius > SIZE_MAX / 2 - 1) throw std::runtime_error("radius too large for current type conventions");

	//reserve space
	visited.reserve(radius * 2 + 1);
	for (auto v : visited)
	{
		v.reserve(radius * 2 + 1);
	}

	//fill space with 0s
	for (auto outer = visited.begin(); outer != visited.end(); outer++)
	{
		for (auto inner = outer->begin(); inner != outer->end(); inner++) 
		{
			*inner = false;
		}
	}



	xloc = radius+1;
	yloc = radius+1;

	visited[xloc][yloc] = true;


}

void Neighberhood::traverse(vector<Direction> instructions)
{
	for (Direction d : instructions)
	{
		switch (d)
		{
		case Direction::UP:
			yloc--;
			break;
		case Direction::DOWN:
			yloc++;
			break;
		case Direction::LEFT:
			xloc--;
			break;
		case Direction::RIGHT:
			xloc++;
			break;
		default;
			//panic
			break;
		}
		visited[xloc][yloc] = true;
	}
}

size_t Neighberhood::numVisited()
{
	size_t n = 0;
	for (vector<Direction> vd : visited)
	{
		for (bool b : vd)
		{
			n += b ? 1 : 0;
		}
	}
	return n;
}
