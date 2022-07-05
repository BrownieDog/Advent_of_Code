#include <fstream>
#include <iostream>
#include <vector>
#include <exception>
//#include <string>

#define INPUT_FILE "C:\\Users\\jonse\\Source\\Repos\\Advent_of_Code\\2015\\Day2\\input.txt"
//#define MAX_FILE_LINES 10000
#define MAX_LINE_SIZE 20

int min(int x, int y, int z)
{
	if (x <= y && x <= z)
		return x;
	if (y <= x && y <= z)
		return y;
	return z;
}

int linesInFile()
{
	std::ifstream ifs(INPUT_FILE);

	if (!ifs.is_open()) throw std::runtime_error("Couldn't Open File to Count Lines");

	
	int lines = 0;
	char s[MAX_LINE_SIZE];
	for (; !ifs.eof(); lines++) ifs.getline(s, MAX_LINE_SIZE);

	ifs.close();
	return lines;
}



int main()
{
	int lines = linesInFile();

	std::ifstream ifs(INPUT_FILE);

	if (!ifs.is_open()) throw std::runtime_error("Couldn't Open File to Get Dimensions");

	std::vector<int> vh(lines), vw(lines), vl(lines);
	char x; //filler


	for (int i = 0; i<lines; i++)
	{
		std::cin >> vh[i] >> x >> vw[i] >> x >> vl[i];
		
	}
	
	ifs.close();

	int totalPaper = 0;
	int hw, hl, lw;
	for (int i = 0; i < vh.size(); i++)
	{
		hw = vh[i] * vw[i];
		hl = vh[i] * vl[i];
		lw = vl[i] * vw[i];
		totalPaper += 2 * hw + 2 * hl + 2 * lw + min(hw, hl, lw);
	}

	std::cout << "Total Paper Needed: " << totalPaper << std::endl;
	

	return 0;
}