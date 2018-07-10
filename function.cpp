#include "utility.h"
#include "life.h"

void instructions()
/* Pre: None.
Post: Instructions for using the Life program have been printed. */
{
	cout << "Welcome to Conway’s game of Life." << endl;
	cout << "This game uses a grid of size "
		<< maxrow << " by " << maxcol << " in which each" << endl;
	cout << "cell can either be occupied by an organism or not." << endl;
	cout << "The occupied cells change from generation to generation" << endl;
	cout << "according to how many neighboring cells are alive." << endl;
}

void help()
{
	cout << "边界为60*20，连续输入活单元的坐标（如1 4），要想停止输入，则输入-1 -1。" << endl;
	cout << "输入h 弹出帮助窗口，输入y更新单元，输入n停止更新。" << endl;
	cout << "更新原则：以确定单元为中心，活单元周围八个单元中有2或3个活单元则继续存活，否则死去。" << endl;
	cout << "死单元周围八个单元中有三个活单元则复活。" << endl;
	cout << endl;
}

int user_says_yes()
{
	char c;
	bool initial_response = true;
	do
	{
		if (initial_response)
			cout << "('y,n,h')?" << endl;
		else
			cout << "Respond with eother y or n or h:" << flush;
		do
		{
			c = cin.get();
		} while (c == '\n' || c == ' ' || c == '\t');
		initial_response = false;
	} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N' && c != 'h' && c != 'H');
	if (c == 'y' || c == 'Y') return 1;
	else if (c == 'h' || c == 'H') return 2;
	else return 0;
}

void read(string fname, vector<int> &t)
{
	ifstream ifile(fname);
	if (!ifile)
	{
		cout << "File open error." << endl;
		exit(1);
	}
	string s;
	int ifile_row = 0, ifile_col = 0;
	while (getline(ifile, s))
	{
		ifile_row++;
		for (unsigned i = 0; i < s.size(); i++)
		{
			if (s[i] != ' ')
			{
				ifile_col = i + 1;
				t.push_back(ifile_row);
				t.push_back(ifile_col);
			}
		}
	}
}