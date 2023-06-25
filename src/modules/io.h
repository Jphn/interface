#ifndef IO_H
#define IO_H

int wWidth, wHeight, inputY, inputX, maxInputWidth;

typedef struct InputLocation
{
	int x;
	int y;
} inputLocation;

void ioH(int maxX, int maxY);

inputLocation input(int width, int height, char *label);
void inputInt(int *var, inputLocation location);
void inputFloat(float *var, inputLocation location);

#endif