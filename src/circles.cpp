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

void drawCircle(){
    char* temp = (char*)malloc(10);
    CV::color(0,0,0);
    for(int i = 0; i < iCircle; i ++){
        CV::circleFill(circ[i].x, circ[i].y, circ[i].radius, 20);
        std::to_string(circ[i].radius);
        CV::text(circ[i].x, circ[i].y, temp);
    }
}
