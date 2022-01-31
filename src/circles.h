#ifndef __CIRCLES_H__
#define __CIRCLES_H__
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "gl_canvas2d.h"
#define screen 650

static int iCircle = 0, betweenRadius = 60, betweenCircles = 90;

static int xMax = screen;
static int yMax = screen;

static char* tempFtoChar = (char*)malloc(5);
static char* temp2 = (char*)malloc(10);

struct Circle
{
    int x;
    int y;
    float radius;
    int r, g, b;
};
extern struct Circle circ[50];

float calcRadius(int xini, int yini, int xfim, int yfim);
void saveCircle(int x, int y, float radius);
void drawCircle();
//void callMerge()

#endif // __C_H__
