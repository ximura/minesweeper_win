#include "MineField.h"

#include <stdio.h>

int main()
{
	int width = 10;
	int height = 5;

	MineField field(5, width, height);
	field.PrintFullField();

	printf("\n------------------------------------------\n");

	while (true)
	{
		int x = 0;
		int y = 0;

		scanf("%i %i", &x, &y);

		if (field.IsMine(x, y))
		{
			printf("BOOM!!!");
			break;
		}

		field.PrintField();
	}

	getchar();
	return 0;
}