#ifndef __MERGESORT_H__
#define __MERGESORT_H__
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "gl_canvas2d.h"


void Juntar(float vetor[], int ini, int meio, int fim, int vetAux[]);
void MergeSort(float vetor[], int inicio, int fim, int vetorAux[]);
void MergeSort(float vetor[], int tamanho);

#endif // __AUXILIAR_H__
