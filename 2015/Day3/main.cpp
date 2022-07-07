#include <vector>
#include <fstream>
#include <iostream>
#include <exception>

#define FILENAME "C:\\Users\\jonse\\Source\\Repos\\Advent_of_Code\\2015\\Day3\\input.txt"

enum Direction
{
	UP, 
	DOWN,
	LEFT,
	RIGHT
};


std::vector<Direction> importData()
{
	std::ifstream ifs(FILENAME);
	if (!ifs.is_open()) throw std::runtime_error("Could not open input file");
	
	std::vector<Direction> vd(1);
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
		vd.emplace_back(d);
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


	//deliver gifts

	//tally results
	
	return 0;
}