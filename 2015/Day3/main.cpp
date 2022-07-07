#include <vector>
//#include <fstream>
#include <iostream>
//#include <exception>
#include <set>

// #define FILENAME_W "C:\\Users\\jonse\\Source\\Repos\\Advent_of_Code\\2015\\Day3\\input.txt"
// #define FILENAME_U "~/Source/Repos/Advent_of_Code/input_files/2015_Day3.txt"

enum Direction
{
	UP, 
	DOWN,
	LEFT,
	RIGHT
};

struct House
{
	int x;
	int y;

	House() 
	: x(0), y(0)
	{}

	House(int xPos, int yPos)
	: x(xPos), y(yPos)
	{}

	inline bool operator< (House& other)
	{
		if (x == other.x)
		{
			return y < other.y;
		}
		return x < other.x;
	}
};


/**
 * @brief Walks through Santa's instructions, adding all
 * viseted houses to a list.
 * 
 * @param instructions list of instructions to traverse
 * @return size_t The number of houses visited
 */
size_t traverse(std::vector<Direction> const& instructions)
{
	std::set<House> vistedHouses;
	int curx = 0;
	int cury = 0;
	House h(0,0);

	vistedHouses.emplace(h);
	for(Direction d : instructions)
	{
		switch (d)
		{

		}
	}
}


std::vector<Direction> importData()
{
	//std::ifstream ifs(FILENAME_U);
	//if (!ifs.is_open()) throw std::runtime_error("Could not open input file");
	
	std::vector<Direction> vd(0);
	char c;
	Direction d;
	while(!std::cin.eof())//for(int i=0; i<1000; i++) //while (ifs.good())
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
			//throw std::runtime_error("Tried to parse character other that ^v<>");
			return vd;
			break;
		}
		vd.emplace_back(d);
	}

	//ifs.close();

	return vd;
}


int main()
{
	//import data
	std::vector<Direction> instructions;
	instructions = importData();

	std::cout << "Imported: ";
	for (Direction d : instructions)
	{
		std::cout << (
			(d == Direction::UP)   ? '^' :
			(d == Direction::DOWN) ? 'v' :
			(d == Direction::LEFT) ? '<' :
									 '>'//Direction::RIGHT
			); 
	}
	std::cout << std::endl;

	//create neighborhood
	//give presents
	traverse(instructions);


	//tally results
	
	return 0;
}