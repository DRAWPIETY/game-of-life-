#include "utility.h"

void instructions();
void help();
int user_says_yes();
void read(string fname, vector<int>& t);

const int maxrow = 20, maxcol = 60;

class Life
{
public :
	void initialize();
	void print();
	void update();
private:
	int grid[maxrow + 2][maxcol + 2];
	int neighbor_count(int row, int col);
};