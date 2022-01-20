#ifndef __CIRCLES_H__
#define __CIRCLES_H__
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "gl_canvas2d.h"
#define screen 512

static int iCircle = 0;
static int xMax = screen;
static int yMax = screen;

static char* temp = (char*)malloc(10);
static char* temp2 = (char*)malloc(10);

typedef struct{
    int x;
    int y;
    float radius;
} Circle;

float calcRadius(int xini, int yini, int xfim, int yfim);
void saveCircle(int x, int y, float radius);
void drawCircle(int x, int y, int pos);

#endif // __C_H__
