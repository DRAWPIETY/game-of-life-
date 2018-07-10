#include "life.h"
#include "utility.h"

int Life::neighbor_count(int row, int col)
{
	int i, j;
	int count = 0;
	for (i = row - 1; i <= row + 1; i++)
		for (j = col - 1; j <= col + 1; j++)
			count += grid[i][j];
	count -= grid[row][col];
	return count;
}

void Life::update()
{
	int row, col;
	int new_grid[maxrow + 2][maxcol + 2];
	for(row = 1; row <= maxrow; row++)
		for(col = 1; col <= maxcol; col++)
			switch (neighbor_count(row, col))
			{
			case 2:new_grid[row][col] = grid[row][col]; break;
			case 3:new_grid[row][col] = 1; break;
			default:new_grid[row][col] = 0;
			}
	for (row = 1; row <= maxrow; row++)
		for (col = 1; col <= maxcol; col++)
			grid[row][col] = new_grid[row][col];
}

void Life::initialize()
{
	cout << "Would you like to use a file to 初始化表格？" << endl;
	cout << "'(y,n)?'" << endl;
	char ch;
	cin >> ch;
	vector<int> vec;
	int row, col;
	if (ch == 'y' || ch == 'Y')
	{
		string file_name;
		cout << "请输入文件地址:";
		cin >> file_name;
		for (row = 0; row <= maxrow + 1; row++)
			for (col = 0; col <= maxcol + 1; col++)
				grid[row][col] = 0;
		read(file_name, vec);
		
		for (unsigned i=0; i < vec.size(); i+=2)
		{
			row = vec[i];
			col = vec[i + 1];
			if (row >= 1 && row <= maxrow)
				if (col >= 1 && col <= maxcol)
					grid[row][col] = 1;
				else
					cout << "Column" << col << "is out of range." << endl;
			else
				cout << "Row" << col << "is out of range." << endl;
		}
	}
	else {
		for (row = 0; row <= maxrow + 1; row++)
			for (col = 0; col <= maxcol + 1; col++)
				grid[row][col] = 0;
		cout << "List the coordinates for living cells." << endl;
		cout << "Terminate the list with the the special pair -1-1" << endl;
		cin >> row >> col;
		while (row != -1 || col != -1)
		{
			if (row >= 1 && row <= maxrow)
				if (col >= 1 && col <= maxcol)
					grid[row][col] = 1;
				else
					cout << "Column" << col << "is out of range." << endl;
			else
				cout << "Row" << col << "is out of range." << endl;
			cin >> row >> col;
		}
	}
}

void Life::print()
{
	int row, col;
	cout << "\nThe current Life configuration is." << endl;
	for (row = 1; row <= maxrow; row++)
	{
		for (col = 1; col <= maxcol; col++)
			if (grid[row][col] == 1) cout << 'x';
			else cout << ' ';
			cout << endl;
	}
	cout << endl;
}
