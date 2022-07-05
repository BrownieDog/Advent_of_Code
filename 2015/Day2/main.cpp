#include <fstream> //ifstream
#include <iostream> //cout
#include <vector> 
#include <exception>

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
	std::ifstream ifs(INPUT_FILE);
	if (!ifs.is_open()) throw std::runtime_error("Couldn't Open File to Get Dimensions");

	std::vector<int> vh(MAX_FILE_LINES), vw(MAX_FILE_LINES), vl(MAX_FILE_LINES);
	char bufh[MAX_LINE_SIZE], bufw[MAX_LINE_SIZE], bufl[MAX_LINE_SIZE];
	for (int i = 0; ifs.good() && i < MAX_FILE_LINES - 1; i++)
	{
		ifs.getline(bufh, MAX_LINE_SIZE, 'x');
		ifs.getline(bufw, MAX_LINE_SIZE, 'x');
		ifs.getline(bufl, MAX_LINE_SIZE);

		vh[i] = atoi(bufh);
		vw[i] = atoi(bufw);
		vl[i] = atoi(bufl);	
	}

	ifs.close();

	int totalPaper = 0;
	int totalRibon = 0;
	int hw, hl, lw;
	int phw, phl, plw;
	for (int i = 0; i < vh.size(); i++)
	{
		hw = vh[i] * vw[i];
		hl = vh[i] * vl[i];
		lw = vl[i] * vw[i];
		totalPaper += 2 * hw + 2 * hl + 2 * lw + min(hw, hl, lw);

		phw = 2 * vh[i] + 2 * vw[i];
		phl = 2 * vh[i] + 2 * vl[i];
		plw = 2 * vl[i] + 2 * vw[i];
		totalRibon += hw * lw * hl + min(phw, phl, plw);
	}

	std::cout << "Total Paper Needed: " << totalPaper << std::endl;
	std::cout << "Total Ribon Needed: " << totalRibon << std::endl;
	
	return 0;
}