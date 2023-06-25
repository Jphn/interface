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

inputLocation input(int width, int height, char *label)
{
	inputLocation thisInput = {inputX + strlen(label) + 1, inputY + 1};

	++height;

	width += strlen(label) + 1;

	if (width > maxInputWidth)
		maxInputWidth = width;

	if (inputY + height > wHeight)
	{
		inputY = 2;

		inputX += maxInputWidth + 1;

		maxInputWidth = 0;
	}

	makeWindow(inputX, inputY, inputX + width, inputY + height);

	gotoXY(inputX + 1, inputY + 1);

	puts(label);

	inputY += height + 1;

	return thisInput;
}

void inputInt(int *var, inputLocation location)
{
	gotoXY(location.x, location.y);

	scanf("%d", var);
}

void inputFloat(float *var, inputLocation location)
{
	gotoXY(location.x, location.y);

	scanf("%f", var);
}