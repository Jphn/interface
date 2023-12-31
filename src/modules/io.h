#ifndef IO_H
#define IO_H

int wWidth, wHeight, Y, X, maxInputWidth;

typedef struct InputLocation
{
	int x;
	int y;
} inputLocation;

void ioH(int maxX, int maxY);

inputLocation input(int width, char *label);
void inputInt(int *var, inputLocation location);
void inputFloat(float *var, inputLocation location);
void inputString(char *var, inputLocation location);

void output(char *message);

#endif