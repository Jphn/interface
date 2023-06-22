#ifndef WINDOW_H
#define WINDOW_H

#define FILL_V printf("-")
#define FILL_H printf("|")

#define CORNER printf("+")

void fillInterval(int xInitial, int xFinal, int yInitial, int yFinal);
void makeWindow(int x, int y, int X, int Y);

#endif