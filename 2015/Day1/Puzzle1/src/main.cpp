#include <iostream>
#include <fstream>
#include <string>

//Takes a file name as a command line argument, then prints the floor santa will end on
int main(int argc, char* argv[])
{
	if (argc > 2)
	{
		std::cout << "use as \"[COMMAND] [FILENAME]\"" << std::endl;
		exit(1);
	}

	std::string filename;
	if (argc == 2)
	{
		filename = argv[1];
	}
	else
	{
		std::cout << "File with instructions: ";
		char charbuffer[FILENAME_MAX];
		std::cin.getline(charbuffer, FILENAME_MAX);
		filename = charbuffer;
	}

	std::ifstream ifs;

	ifs.open(filename, std::ifstream::in);

	int floor = 0;
	int count = 0;

	if (!ifs.is_open())
	{
		std::cout << "File " << filename << " could not be opened" << std::endl;
		exit(2);
	}
	else
	{
		char next;
		while (ifs.good() && floor>-1)
		{
			next = ifs.get();
			switch (next)
			{
			case '(':
				floor++;
				count++;
				break;
			case ')':
				floor--;
				count++;
				break;
			default:
				//do not change floor if not one of the above symbols
				break;
			}
		}

		ifs.close();
		std::cout << "Santa would be on floor " << floor << " after following " << count << " instructions." << std::endl;

		return 0;
	}
}