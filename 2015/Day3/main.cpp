#include <vector>
#include <fstream>
#include <iostream>
#include <exception>

#define FILENAME_W "C:\\Users\\jonse\\Source\\Repos\\Advent_of_Code\\2015\\Day3\\input.txt"
#define FILENAME_U "~/Source/Repos/Advent_of_Code/input_files/2015_Day3.txt"

enum Direction
{
	UP, 
	DOWN,
	LEFT,
	RIGHT
};


std::vector<Direction> importData()
{
	std::ifstream ifs(FILENAME_U);
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