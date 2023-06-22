#include <stdio.h>
#include <unistd.h>
#include "./modules/utils.h"

#define FILL_V printf("-")
#define FILL_H printf("|")

#define CORNER printf("+")

#define WIDTH 100
#define HEIGHT 20

void fillInterval(int xInitial, int xFinal, int yInitial, int yFinal);
void makeWindow(int x, int y, int X, int Y);
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