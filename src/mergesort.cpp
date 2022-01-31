#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "gl_canvas2d.h"
#include "circles.h"

 void Juntar(float vetor[], int ini, int meio, int fim, int vetAux[]) {
    int esq = ini;
    int dir = meio;
    for (int i = ini; i < fim; ++i) {
        if ((esq < meio) and ((dir >= fim) or (vetor[esq] < vetor[dir]))) {
            vetAux[i] = vetor[esq];
            ++esq;
        }
        else {
            vetAux[i] = vetor[dir];
            ++dir;
        }
    }
    //copiando o vetor de volta
    for (int i = ini; i < fim; ++i) {
        vetor[i] = vetAux[i];
    }
}

void MergeSort(float vetor[], int inicio, int fim, int vetorAux[]) {
    if ((fim - inicio) < 2) return;

    int meio = ((inicio + fim)/2);
    MergeSort(vetor, inicio, meio, vetorAux);
    MergeSort(vetor, meio, fim, vetorAux);
    Juntar(vetor, inicio, meio, fim, vetorAux);
}

void MergeSort(float vetor[], int tamanho) { //função que o usuario realmente chama
    //criando vetor auxiliar
    int vetorAux[tamanho];
    MergeSort(vetor, 0, tamanho, vetorAux);
}
