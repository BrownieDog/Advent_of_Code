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

void fillInput(std::vector<int> &vh, std::vector<int> &vw, std::vector<int> &vl)
{
	std::ifstream ifs(INPUT_FILE);
	if (!ifs.is_open()) throw std::runtime_error("Couldn't Open File to Get Dimensions");

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
}

void partOne(std::vector<int> vh, std::vector<int> vw, std::vector<int> vl)
{
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

}

void partTwo(std::vector<int> vh, std::vector<int> vw, std::vector<int> vl)
{

}

int main()
{
	std::vector<int> vh(MAX_FILE_LINES), vw(MAX_FILE_LINES), vl(MAX_FILE_LINES);

	fillInput(vh, vw, vl);

	partOne(vh, vw, vl);
	partTwo(vh, vw, vl);

	return 0;
}