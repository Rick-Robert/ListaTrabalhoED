#include "fila.h"
#include <stdlib.h>

fila* criarFila (int tamanho){
  fila *f;
  f = (fila*)malloc(sizeof(fila));
  f->capacidade = tamanho;
  f->dado = (T*)malloc(f->capacidade * sizeof(T));
  f->NumItens = 0;
  f->primeiro = 0;
  f->ultimo = -1;
  return f;
}

void inserir (fila *f, int elemento){
  if (!cheia(f)){
    if(f->ultimo == f->capacidade-1){
      f->ultimo = -1;
    }
    f->ultimo++;
    f->dado[f->ultimo] = elemento;
    f->NumItens++;
  }
}

void remover(fila *f) {
  if (!vazia(f)){
    f->primeiro++;

    if(f->primeiro == f->capacidade){
      f->primeiro = 0;
    }
    f->NumItens--;
  }
}

int vazia(fila *f){
  return (f->NumItens == 0);
}
int cheia(fila *f){
  return (f->NumItens == f->capacidade);
}

int primeiro(fila *f){
  return f->dado[f->primeiro];
}

int ultimo(fila *f){
  return f->dado[f->ultimo];
}

unsigned tamanho(fila *f){
  return f->NumItens;
}

void destruirFila(fila *f){
  free(f->dado);
  free(f);
}