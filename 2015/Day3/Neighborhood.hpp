#ifndef NEIGHBORHOOD_HPP
#define NEIGHBORHOOD_HPP

#include <vector>

enum class Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Neighberhood
{
private:
	std::vector<std::vector<bool>> visited;
	size_t xloc;
	size_t yloc;
public:
	Neighberhood() = delete;
	Neighberhood(size_t radius);
	void traverse(std::vector<Direction> instructions);
	size_t numVisited();
};

#endif //NEIGHBORHOOD_HPP