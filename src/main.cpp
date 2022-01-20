/*********************************************************************
// Canvas para desenho, criada sobre a API OpenGL. Nao eh necessario conhecimentos de OpenGL para usar.
//  Autor: Cesar Tadeu Pozzer
//         05/2020
//
//  Pode ser utilizada para fazer desenhos, animacoes, e jogos simples.
//  Tem tratamento de mouse e teclado
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp

//  Todos os arquivos do projeto devem ser .cpp
//
//  Versao 2.0
//
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <math.h>

#include "gl_canvas2d.h"
#include "mergesort.h"
#include "circles.h"

//variaveis globais
int screenWidth = 512, screenHeight = 512; //largura e altura inicial da tela. Alteram com o redimensionamento de tela.
int posMouseXfim = 0, posMouseYfim = 0, stateMouse;
int posMouseXini, posMouseYini, keyPress, desenhos;
int posCircleX = 100, posCircleY = 100;

using namespace std;

void render()
{
    //Drawing circles
    if(keyPress != 109){
        CV::color(1,0,0);
        CV::text(9,500, "Desenhe os circulos: (Aperte D a cada novo c�rculo desenhado");
        if (stateMouse == -2){
            CV::color(1,0,1);
            CV::circleFill(posMouseXini, posMouseYini, calcRadius(posMouseXini, posMouseYini, posMouseXfim, posMouseYfim), 20);
            CV::color(0,0,0);
            sprintf(temp, "%.5f", calcRadius(posMouseXini, posMouseYini, posMouseXfim, posMouseYfim));
            CV::text(posMouseXini, posMouseYini, temp);
            if(keyPress == 101){
                saveCircle(posMouseXini,posMouseYini,calcRadius(posMouseXini, posMouseYini, posMouseXfim, posMouseYfim));
                printf(" cont %d\n", iCircle); //debug
            }
        }
    }
    /*if(keyPress != 109){
        CV::text(9,500, "Desenhe os circulos: (Aperte D a cada novo c�rculo");
        if(keyPress == 101){
            CV::circleFill(posMouseXini, posMouseYini, calcRadius(posMouseXini, posMouseYini, posMouseXfim, posMouseYfim), 20);
            saveCircle(posMouseXini,posMouseYini,calcRadius(posMouseXini, posMouseYini, posMouseXfim, posMouseYfim));
        }
    }*/
    //Display circles (radius)
    if(keyPress == 109){
        CV::text(20,500, "Raio dos circulos desenhados:(Pixels)");
        for(int pos = 0; pos < iCircle; pos++){
            posCircleX += posCircleX;
            drawCircle(posCircleX, posCircleY, pos);
            printf("-- %d, %d, %d\n",posCircleX, posCircleY, pos); //debug
        }
    }

}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   //printf("\nTecla: %d", key);
   keyPress = key;
}
//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   //printf("\nLiberou tecla: %d" , key);
}


//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   //printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
    if (state == 0){
        posMouseXini = x;
        posMouseYini = y;
    }
    if (state == 1){
        posMouseXfim = x;
        posMouseYfim = y;
    }
    stateMouse = state;

}

int main(void)
{
   CV::init(&screenWidth, &screenHeight, "MergeSort");

   CV::run();
}
