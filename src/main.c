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
void input(int x, int y, int width, int height, char *label);
void inputInt(int *var, char *label);

int width = 100, height = 20, intInputY = 2, intInputX = 2;

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

	makeWindow(1, 1, width, height);
}

void input(int x, int y, int width, int height, char *label)
{
	makeWindow(x, y, x + width, y + ++height);

	gotoxy(x + 1, y + 1);

	printf("%s", label);
}

void inputInt(int *var, char *label)
{
	if (intInputY >= height)
	{
		intInputY = 2;
		intInputX += 22;
	}

	input(intInputX, intInputY, 17, 1, label);

	intInputY += 3;

	scanf("%d", var);
}