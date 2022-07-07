#include <vector>
#include <iostream>
#include <set>

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

	friend bool operator< (House const& left, House const& right)
	{
		return (left.x == right.x ? left.y < right.y : left.x < right.x);
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
	House h(0, 0);
	vistedHouses.emplace(h);

	int curx = 0;
	int cury = 0;
	int robox = 0;
	int roboy = 0;
	int count = 0;

	for(Direction d : instructions)
	{
		count++;
		switch (d)
		{
		case Direction::UP:
			if (count % 2 == 0)
				roboy++;
			else
				cury++;
			break;
		case Direction::DOWN:
			if (count % 2 == 0)
				roboy--;
			else
				cury--;
			break;
		case Direction::LEFT:
			if (count % 2 == 0)
				robox--;
			else
				curx--;
			break;
		case Direction::RIGHT:
			if (count % 2 == 0)
				robox++;
			else
				curx++;
			break;
		default:
			break;
		}

		if (count % 2 == 0)
		{
			h.x = robox;
			h.y = roboy;
		}
		else
		{
			h.x = curx;
			h.y = cury;
		}

		vistedHouses.insert(h);

	}

	return vistedHouses.size();
}


std::vector<Direction> importData()
{

	std::vector<Direction> vd(0);
	char c;
	Direction d;
	while(!std::cin.eof())
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
			return vd;
			break;
		}
		vd.emplace_back(d);
	}
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
	//tally results
	size_t visited_count = traverse(instructions);


	//display results
	std::cout << "Visited " << visited_count << " unique houses." << std::endl;
	
	return 0;
}