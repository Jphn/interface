#ifndef WINDOW_H
#define WINDOW_H

#define FILL_V printf("═")
#define FILL_H printf("║")

#define CORNER_LU printf("╔")
#define CORNER_RU printf("╗")
#define CORNER_LD printf("╚")
#define CORNER_RD printf("╝")

void fillInterval(int xInitial, int xFinal, int yInitial, int yFinal);
void makeWindow(int x, int y, int X, int Y);

#endif