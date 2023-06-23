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

void input(int width, int height, char *label)
{
	++height;

	width += strlen(label) + 1;

	if (width > maxInputWidth)
		maxInputWidth = width;

	if (inputY + height > wHeight)
	{
		inputY = 2;

		inputX += maxInputWidth + 1;
	}

	makeWindow(inputX, inputY, inputX + width, inputY + height);

	gotoXY(inputX + 1, inputY + 1);

	printf("%s", label);

	inputY += height + 1;
}

void inputInt(int *var, char *label)
{
	input(17, 1, label);

	scanf("%d", var);
}

void inputFloat(float *var, char *label)
{
	input(17, 1, label);

	scanf("%f", var);
}