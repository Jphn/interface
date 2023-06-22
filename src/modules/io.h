#ifndef IO_H
#define IO_H

int wWidth, wHeight, inputY, inputX, maxInputWidth;

void ioH(int maxX, int maxY);

void input(int width, int height, char *label);
void inputInt(int *var, char *label);
void inputFloat(float *var, char *label);

#endif