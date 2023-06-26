#include "utils.h"

#include <stdlib.h>
#include <stdio.h>

void gotoXY(int x, int y)
{
	printf("\033[%d;%dH", y, x);
}

void clearScreen()
{
	system("clear");
}