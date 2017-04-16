#include "MineField.h"

#include <stdio.h>
#include <cstdlib>
#include <ctime>

int main()
{
	int width = 10;
	int height = 5;

	MineField field(5, width, height);
	field.PrintField();

	std::srand(std::time(0)); // use current time as seed for random generator

	int x = std::rand() % width;
	int y = std::rand() % height;



	getchar();
	return 0;
}