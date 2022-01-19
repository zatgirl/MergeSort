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
#include <math.h>

#include "gl_canvas2d.h"
#include "mergesort.h"
#include "circles.h"

//variaveis globais
int screenWidth = 512, screenHeight = 512; //largura e altura inicial da tela. Alteram com o redimensionamento de tela.
int posMouseXfim = 0, posMouseYfim = 0, stateMouse;
int posMouseX, posMouseY, keyPress, desenhos;

using namespace std;

void render()
{
    //Desenha círculos
    if(keyPress != (109)){
        CV::color(1,0,0);
        CV::text(9,500, "Desenhe os circulos:");
        while(true){
            CV::circleFill(posMouseX, posMouseY, calcRadius(posMouseX, posMouseY, posMouseXfim, posMouseYfim), 20);
            saveCircle(posMouseX,posMouseY,calcRadius(posMouseX, posMouseY, posMouseXfim, posMouseYfim));
            if (keyPress == 109){
                break;
            }
            desenhos++;
        }
    }
    //Exibe circulos(raios)
    if(keyPress == 109){
        CV::color(1,0,0);
        CV::text(20,500, "Raio dos circulos desenhados:");
        CV::color(0,1,0);
        drawCircle();
    }

}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   printf("\nTecla: %d", key);
   keyPress = key;
}
//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou tecla: %d" , key);
}


//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
    if (state == 0){
        posMouseX = x;
        posMouseY = y;
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
