#ifndef FILA_H
#define FILA_H

#include <stdlib.h>
#include <stdio.h>

typedef int T;

typedef struct {
  T *dado;
  T primeiro;
  T ultimo;
  T capacidade;
  T NumItens;
} fila;

fila* criarFila (int tamanho);

void inserir (fila *f, int elemento);

void remover(fila *f);

int primeiro(fila *f);

int ultimo(fila *f);

int vazia(fila *f);

int cheia(fila *f);

unsigned tamanho(fila *f);

void desalocarFila(fila *f);

#endif