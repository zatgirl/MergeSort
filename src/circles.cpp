#include <iostream>

#include "gl_canvas2d.h"
#include "circles.h"

Circle circ[50];

using namespace std;

double calcRadius(int xini, int yini, int xfim, int yfim){
    return(sqrt(pow(xfim-xini,2)+pow(yfim-yini,2)));
}

void saveCircle(int x, int y, double radius){
    circ[iCircle].x = x;
    circ[iCircle].y = y;
    circ[iCircle].radius = radius;
    iCircle ++;
}

void drawCircle(){
    CV::color(0,0,0);
    for(int i = 0; i < iCircle; i ++){
        CV::circleFill(circ[i].x, circ[i].y, circ[i].radius, 20);
        CV::text(circ[i].x, circ[i].y, std::ftoa(circ[i].radius);
    }
}
