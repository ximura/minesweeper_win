#include "MineField.h"

#include <stdio.h>

int main()
{
    int size = 10;
    int bombs = 5;

    printf("Enter fied size:\n");
    scanf_s("%i", &size);

    printf("Enter bomb count:\n");
    scanf_s("%i", &bombs);

    if (bombs > size * size) {
        printf("We can't have bombs more then field size");
        return 0;
    }

    MineField field(bombs, size, size);
    field.PrintFullField();

    printf("\n------------------------------------------\n");

    while (true)
    {
        int x = 0;
        int y = 0;

        printf("Enter coordinate to open from (0-%i)\n", size-1);
        scanf_s("%i %i", &x, &y);

        if (field.IsMine(x, y))
        {
            printf("BOOM!!!");
            break;
        }

        field.Check(x, y);
        field.PrintField();
    }

    return 0;
}