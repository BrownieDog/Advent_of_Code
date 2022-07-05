#ifndef NEIGHBORHOOD_HPP
#define NEIGHBORHOOD_HPP

#include <vector>
using std::vector;

namespace hood
{

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
		vector<vector<bool>> visited;
		size_t xloc;
		size_t yloc;
	public:
		Neighberhood() = delete;
		Neighberhood(size_t radius);
		void traverse(vector<Direction> instructions);
		size_t numVisited();
	};


}
#endif //NEIGHBORHOOD_HPP