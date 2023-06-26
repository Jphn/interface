#include "./io.h"

#include <stdio.h>
#include <string.h>
#include "./utils.h"
#include "./window.h"

int inputY = 2, inputX = 2, maxInputWidth = 0;

void ioH(int maxX, int maxY)
{
	wWidth = maxX;
	wHeight = maxY;
};

inputLocation input(int width, char *label)
{
	inputLocation thisInput = {inputX + strlen(label) + 1, inputY + 1};

	width += strlen(label) + 1;

	if (width > maxInputWidth)
		maxInputWidth = width;

	if (inputY + 2 > wHeight)
	{
		inputY = 2;

		inputX += maxInputWidth + 1;

		maxInputWidth = 0;
	}

	makeWindow(inputX, inputY, inputX + width, inputY + 2);

	gotoXY(inputX + 1, inputY + 1);

	puts(label);

	inputY += 3;

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