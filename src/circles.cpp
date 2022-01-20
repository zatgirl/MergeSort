#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include "gl_canvas2d.h"
#include "circles.h"

Circle circ[50];

float calcRadius(int xini, int yini, int xfim, int yfim){
    return(std::sqrt(std::pow(xfim-xini,2)+std::pow(yfim-yini,2)));
}

void saveCircle(int x, int y, float radius){
    circ[iCircle].x = x;
    circ[iCircle].y = y;
    circ[iCircle].radius = radius;
    iCircle ++;
}

void drawCircle(int x, int y, int pos){
    printf("-%d, %d, %d\n", x, y, pos); //debug
    char* temp = (char*)malloc(10);
    CV::color(0,0,1);
    //for(int i = 0; i < iCircle; i ++){
        CV::circleFill(x, y, 10, 20);
        std::sprintf(temp, "%.5f", circ[pos].radius);
        CV::color(0,0,0);
        CV::text(x, y, temp);
    //}
}
