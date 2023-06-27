#include "./io.h"

#include <stdio.h>
#include <string.h>
#include "./utils.h"
#include "./window.h"

int Y = 2, X = 2, maxInputWidth = 0;

void ioH(int maxX, int maxY)
{
	wWidth = maxX;
	wHeight = maxY;
	Y = 2;
	X = 2;
};

inputLocation input(int width, char *label)
{
	inputLocation thisInput = {X + strlen(label) + 1, Y + 1};

	width += strlen(label) + 1;

	if (width > maxInputWidth)
		maxInputWidth = width;

	if (Y + 2 > wHeight)
	{
		Y = 2;

		X += maxInputWidth + 1;

		maxInputWidth = 0;
	}

	makeWindow(X, Y, X + width, Y + 2);

	gotoXY(X + 1, Y + 1);

	puts(label);

	Y += 3;

	return thisInput;
}

void inputInt(int *var, inputLocation location)
{
	gotoXY(location.x, location.y);

	scanf("%d", var);

	getchar();
}

void inputFloat(float *var, inputLocation location)
{
	gotoXY(location.x, location.y);

	scanf("%f", var);

	getchar();
}

void inputString(char *var, inputLocation location)
{
	gotoXY(location.x, location.y);

	scanf("%[^\n]s", var);

	getchar();
}

void output(char *message)
{
	gotoXY(X, Y++);

	puts(message);
}