#include <fstream>
#include <iostream>
#include <vector>
#include <exception>
//#include <string>

#define INPUT_FILE "C:\\Users\\jonse\\Source\\Repos\\Advent_of_Code\\2015\\Day2\\input.txt"
#define MAX_FILE_LINES 10000
#define MAX_LINE_SIZE 20

int min(int x, int y, int z)
{
	if (x <= y && x <= z)
		return x;
	if (y <= x && y <= z)
		return y;
	return z;
}


int main()
{
	int lines = MAX_FILE_LINES;

	std::ifstream ifs(INPUT_FILE);

	if (!ifs.is_open()) throw std::runtime_error("Couldn't Open File to Get Dimensions");

	std::vector<int> vh(lines), vw(lines), vl(lines);
	//char x; //filler
	char bufh[MAX_LINE_SIZE], bufw[MAX_LINE_SIZE], bufl[MAX_LINE_SIZE];

	for (int i = 0; ifs.good() && i<lines-1; i++)
	{
		//std::cin >> vh[i] >> x >> vw[i] >> x >> vl[i];
		ifs.getline(bufh, MAX_LINE_SIZE, 'x');
		ifs.getline(bufw, MAX_LINE_SIZE, 'x');
		ifs.getline(bufl, MAX_LINE_SIZE);

		vh[i] = atoi(bufh);
		vw[i] = atoi(bufw);
		vl[i] = atoi(bufl);

		
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