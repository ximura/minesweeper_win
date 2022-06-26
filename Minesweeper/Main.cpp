#include "MineField.h"

#include <stdio.h>

int main()
{
    int size = 10;
    int bombs = 5;

    printf("Enter fied size:\n");
    scanf("%i", &size);

    printf("Enter bomb count:\n");
    scanf("%i", &bombs);

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

        scanf("%i %i", &x, &y);

        if (field.IsMine(x, y))
        {
            printf("BOOM!!!");
            break;
        }

        field.PrintField();
    }

    return 0;
}