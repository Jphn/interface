#include <stdio.h>
#include "./modules/utils.h"
#include "./modules/window.h"
#include "./modules/io.h"

#define WIDTH 100
#define HEIGHT 20

void initializeScreen();

int main()
{
	initializeScreen();

	ioH(WIDTH, HEIGHT);

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