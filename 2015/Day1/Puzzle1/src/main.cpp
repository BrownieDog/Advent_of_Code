#include <iostream>
#include <fstream>

//Takes a file name as a command line argument, then prints the floor santa will end on
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "use as \"[COMMAND] [FILENAME]\"" << std::endl;
		std::exit(1);
	}

	std::ifstream ifs(argv[1], std::ifstream::in);


	char next;
	int floor = 0;
	while (ifs.good())
	{
		next = ifs.get();
		switch (next)
		{
		case '(':
			floor++;
			break;
		case ')':
			floor--;
			break;
		default:
			//do not change floor if not one of the above symbols
			break;
		}
	}

	std::cout << "Santa would be on floor " << floor << " after following these instructions." << std::endl;

	return 0;
}