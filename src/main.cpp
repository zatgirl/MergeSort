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
int screenWidth = 650, screenHeight = 836; //largura e altura inicial da tela. Alteram com o redimensionamento de tela.
int posMouseXfim = 0, posMouseYfim = 0, stateMouse;
int posMouseXini, posMouseYini, keyPress, desenhos;
using namespace std;

void render()
{
    switch (keyPress){
    case 0:
        CV::color(1,0,0);
        CV::text(9,820, "Desenhe os circulos: (Aperte D para salvar o circulo desenhado)");
        CV::text(9,795, "ou E para exibir os circulos apos desenhar!");
        if (stateMouse == -2)
        {
            CV::color(1,0,1);
            CV::circleFill(posMouseXini, posMouseYini, calcRadius(posMouseXini, posMouseYini, posMouseXfim, posMouseYfim), 20);
            CV::color(0,0,0);
            sprintf(tempFtoChar, "%.5f", calcRadius(posMouseXini, posMouseYini, posMouseXfim, posMouseYfim));
            CV::text(posMouseXini, posMouseYini, tempFtoChar);
        }
        break;
    case 100:
        CV::color(1,0,0);
        CV::text(9,820, "Desenhe os circulos: (Aperte D para salvar o circulo desenhado)");
        CV::text(9,795, "ou E para exibir os circulos apos desenhar!");
        saveCircle(posMouseXini,posMouseYini,calcRadius(posMouseXini, posMouseYini, posMouseXfim, posMouseYfim));
        keyPress = 0;
        break;
    case 109:
        //Display MergeSort step by step
        CV::text(20,820, "Raio dos circulos desenhados:(Pixels)");
        drawCircle();
        CV::text(20,700, "Ordenacao MergeSort:");
        //callMerge();
        break;
    }
}

/*FGAPI int     FGAPIENTRY glutCreateWindow( const char* title );
FGAPI int     FGAPIENTRY glutCreateSubWindow( int window, int x, int y, int width, int height );
FGAPI void    FGAPIENTRY glutDestroyWindow( int window );
FGAPI void    FGAPIENTRY glutSetWindow( int window );
FGAPI int     FGAPIENTRY glutGetWindow( void );
FGAPI void    FGAPIENTRY glutSetWindowTitle( const char* title );
FGAPI void    FGAPIENTRY glutSetIconTitle( const char* title );
FGAPI void    FGAPIENTRY glutReshapeWindow( int width, int height );
FGAPI void    FGAPIENTRY glutPositionWindow( int x, int y );
FGAPI void    FGAPIENTRY glutShowWindow( void );
FGAPI void    FGAPIENTRY glutHideWindow( void );
FGAPI void    FGAPIENTRY glutIconifyWindow( void );
FGAPI void    FGAPIENTRY glutPushWindow( void );
FGAPI void    FGAPIENTRY glutPopWindow( void );
FGAPI void    FGAPIENTRY glutFullScreen( void );
*/

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   printf("\nTecla: %d", key);
}
//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   //printf("\nLiberou tecla: %d" , key);
   keyPress = key;
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
