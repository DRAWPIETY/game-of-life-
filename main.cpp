#include "utility.h"
#include "life.h"

int main()
{
	int Num;
	Life configuration;
	instructions();
	configuration.initialize();
	configuration.print();
	cout << "Continue viewing new generations?" << endl;
	while (Num=user_says_yes())
	{
		if (Num == 2) help();
		else
		{
			configuration.update();
			configuration.print();
			cout << "Continue viewing new generations?" << endl;
		}
	}
}