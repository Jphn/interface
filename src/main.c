#include <stdio.h>
#include "./modules/utils.h"
#include "./modules/window.h"
#include "./modules/io.h"
#include "./modules/colorize.h"

#define WIDTH 100
#define HEIGHT 20

typedef struct Person
{
	char name[30];
	int age;
	char email[50];
} person;

void initializeScreen();

int main()
{
	initializeScreen();

	person user;

	inputLocation inputs[3];

	inputs[0] = input(30, 1, "Nome: ");
	inputs[1] = input(2, 1, "Idade: ");
	inputs[2] = input(40, 1, "Email: ");

	inputString(user.name, inputs[0]);
	inputInt(&user.age, inputs[1]);
	inputString(user.email, inputs[2]);

	printf("Nome: %s\nIdade: %d\nEmail: %s", user.name, user.age, user.email);

	return 0;
}

void initializeScreen()
{
	clearScreen();

	makeWindow(1, 1, WIDTH, HEIGHT);

	ioH(WIDTH, HEIGHT);
}