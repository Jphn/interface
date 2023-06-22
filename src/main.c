#include <stdio.h>
#include "./modules/utils.h"
#include "./modules/window.h"

#define WIDTH 100
#define HEIGHT 20

void initializeScreen();

void input(int width, int height, char *label);
void inputInt(int *var, char *label);
void inputFloat(float *var, char *label);

int inputY = 2, inputX = 2, maxInputWidth = 0;

int main()
{
	initializeScreen();

	int age;

	while (1)
		inputInt(&age, "Idade: ");

	return 0;
}

void initializeScreen()
{
	clearScreen();

	makeWindow(1, 1, WIDTH, HEIGHT);
}

void input(int width, int height, char *label)
{
	++height;

	if (width > maxInputWidth)
		maxInputWidth = width;

	if (inputY + height > HEIGHT)
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