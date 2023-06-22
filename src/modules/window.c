#include "./window.h"

#include <stdio.h>
#include "./utils.h"

void fillInterval(int xInitial, int xFinal, int yInitial, int yFinal)
{
	for (int i = xInitial + 1; i < xFinal; i++)
	{
		gotoXY(i, yInitial);

		FILL_V;

		gotoXY(i, yFinal);

		FILL_V;
	}

	for (int i = yInitial + 1; i < yFinal; i++)
	{
		gotoXY(xInitial, i);

		FILL_H;

		gotoXY(xFinal, i);

		FILL_H;
	}
}

void makeWindow(int x, int y, int X, int Y)
{
	gotoXY(x, y);

	CORNER;

	gotoXY(X, y);

	CORNER;

	gotoXY(x, Y);

	CORNER;

	gotoXY(X, Y);

	CORNER;

	fillInterval(x, X, y, Y);
}