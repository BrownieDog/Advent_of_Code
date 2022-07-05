#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "Neighborhood.hpp"

#define FILENAME "C:\\Users\\jonse\\Source\\Repos\\Advent_of_Code\\2015\\Day3\\input.txt"

std::vector<Direction> importData()
{
	std::ifstream ifs(FILENAME);
	if (!ifs.is_open()) throw std::runtime_error("Could not open input file");
	
	std::vector<Direction> vd;
	char c;
	Direction d;
	while (ifs.good())
	{
		std::cin >> c;
		switch (c)
		{
		case '^':
			d = Direction::UP;
			break;
		case '<':
			d = Direction::LEFT;
			break;
		case '>':
			d = Direction::RIGHT;
			break;
		case 'v':
			d = Direction::DOWN;
			break;
		default:
			throw std::runtime_error("Tried to parse character other that ^v<>");
			break;
		}
		vd.insert(vd.end(), d);
	}

	ifs.close();

	return vd;
}


int main()
{
	//import data
	std::vector<Direction> instructions;
	instructions = importData();

	//create neighborhood
	Neighberhood n(instructions.size());

	//deliver gifts
	n.traverse(instructions);

	//tally results
	std::cout << "Delivered presents to " << n.numVisited() << " unique houses" << std::endl;
	
	return 0;
}