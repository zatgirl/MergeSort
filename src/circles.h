#ifndef __CIRCLES_H__
#define __CIRCLES_H__
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "gl_canvas2d.h"

static int iCircle = 0;

typedef struct{
    int x;
    int y;
    double radius;
} Circle;

double calcRadius(int xini, int yini, int xfim, int yfim);
void saveCircle(int x, int y, double radius);
void drawCircle();

#endif // __C_H__
