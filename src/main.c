#include <stdio.h>
#include "./modules/utils.h"
#include "./modules/window.h"
#include "./modules/io.h"
#include "./modules/colorize.h"

#define WIDTH 100
#define HEIGHT 20

void initializeScreen();

int main()
{
	initializeScreen();

	int age, year;

	inputLocation inputs[2];

	inputs[0] = input(2, 1, "Idade: ");
	inputs[1] = input(4, 1, "Ano: ");

	inputInt(&age, inputs[0]);
	inputInt(&year, inputs[1]);

	return 0;
}

void initializeScreen()
{
	clearScreen();

	makeWindow(1, 1, WIDTH, HEIGHT);

	ioH(WIDTH, HEIGHT);
}