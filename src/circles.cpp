#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include "gl_canvas2d.h"
#include "circles.h"
#include "mergesort.h"
struct Circle circ[50];
float calcRadius(int xini, int yini, int xfim, int yfim)
{
    return(std::sqrt(std::pow(xfim-xini,2)+std::pow(yfim-yini,2)));
}

void saveCircle(int x, int y, float radius)
{

    circ[iCircle].x = x;
    circ[iCircle].y = y;
    circ[iCircle].radius = radius;
    circ[iCircle].r = 0+(rand()%2);
    circ[iCircle].g = 0+(rand()%2);
    circ[iCircle].b = 0+(rand()%2);
    if (((circ[iCircle].r == 0) && (circ[iCircle].g == 1) && (circ[iCircle].b == 0))
        ||((circ[iCircle].r == 1) && (circ[iCircle].g == 1) && (circ[iCircle].b == 1))
        ||((circ[iCircle].r == 0) && (circ[iCircle].g == 0) && (circ[iCircle].b == 0)))
    {
        circ[iCircle].r = 1; circ[iCircle].g = 0; circ[iCircle].b = 0;
    }
    iCircle ++;
}

void drawCircle()
{
    for(int i = 0; i < iCircle; i ++)
    {
        CV::color(circ[i].r,circ[i].g,circ[i].b);
        if(i == 0)
        {
            CV::circleFill(30, 770, 30, 20);
            std::sprintf(tempFtoChar, "%.2f", circ[i].radius);
            CV::color(0,0,0);
            CV::text(6, 770, tempFtoChar);
        }
        if ((i == 1))
        {
            CV::circleFill((i*5)+betweenCircles, 770, 30, 20);
            std::sprintf(tempFtoChar, "%.2f", circ[i].radius);
            CV::color(0,0,0);
            CV::text((i*5)+65, 770, tempFtoChar);
        }
        if ((i >= 2))
        {
            CV::circleFill(((i*5)+(i-1)*betweenRadius)+betweenCircles, 770, 30, 20);
            std::sprintf(tempFtoChar, "%.2f", circ[i].radius);
            CV::color(0,0,0);
            CV::text(((i*5)+(i-1)*betweenRadius)+65, 770, tempFtoChar);
        }
    }
}

void callMerge()
{
    MergeSort(circ[].radius, iCircle);
}
