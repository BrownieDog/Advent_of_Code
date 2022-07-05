#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <stdexcept>
using std::runtime_error;

#include "Neighborhood.hpp"
using hood::Direction;
using hood::Neighberhood;

#define FILENAME "C:\\Users\\jonse\\Source\\Repos\\Advent_of_Code\\2015\\Day3\\input.txt"

vector<Direction> importData()
{
	ifstream ifs(FILENAME);
	if (!ifs.is_open()) throw runtime_error("Could not open input file");
	
	vector<Direction> vd;
	char c;
	Direction d;
	while (ifs.good())
	{
		cin >> c;
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
			throw runtime_error("Tried to parse character other that ^v<>");
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
	vector<Direction> instructions;
	instructions = importData();

	//create neighborhood
	Neighberhood n(instructions.size());

	//deliver gifts
	n.traverse(instructions);

	//tally results
	cout << "Delivered presents to " << n.numVisited() << " unique houses" << endl;
	
	return 0;
}