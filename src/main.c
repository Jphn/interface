#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILL_V printf("-")
#define FILL_H printf("|")

#define CORNER printf("+")

void gotoxy(int x, int y);
void clearScreen();

void fillInterval(int xInitial, int xFinal, int yInitial, int yFinal);
void makeWindow(int x, int y, int X, int Y);
void initializeScreen();

void input(int width, int height, char *label);
void inputInt(int *var, char *label);
void inputFloat(float *var, char *label);

int wWidth = 100, wHeight = 20, inputY = 2, inputX = 2, maxInputWidth = 0;

int main()
{
	initializeScreen();

	int age;

	while (1)
		inputInt(&age, "Idade: ");

	return 0;
}

void gotoxy(int x, int y) { printf("\033[%d;%dH", y, x); }

void clearScreen()
{
	system("clear");
}

void fillInterval(int xInitial, int xFinal, int yInitial, int yFinal)
{
	for (int i = xInitial + 1; i < xFinal; i++)
	{
		gotoxy(i, yInitial);

		FILL_V;

		gotoxy(i, yFinal);

		FILL_V;
	}

	for (int i = yInitial + 1; i < yFinal; i++)
	{
		gotoxy(xInitial, i);

		FILL_H;

		gotoxy(xFinal, i);

		FILL_H;
	}
}

void makeWindow(int x, int y, int X, int Y)
{
	gotoxy(x, y);

	CORNER;

	gotoxy(X, y);

	CORNER;

	gotoxy(x, Y);

	CORNER;

	gotoxy(X, Y);

	CORNER;

	fillInterval(x, X, y, Y);
}

void initializeScreen()
{
	clearScreen();

	makeWindow(1, 1, wWidth, wHeight);
}

void input(int width, int height, char *label)
{
	++height;

	if (width > maxInputWidth)
		maxInputWidth = width;

	if (inputY + height > wHeight)
	{
		inputY = 2;

		inputX += maxInputWidth + 1;
	}

	makeWindow(inputX, inputY, inputX + width, inputY + height);

	gotoxy(inputX + 1, inputY + 1);

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