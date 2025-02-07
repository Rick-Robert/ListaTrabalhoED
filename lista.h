#ifndef LISTA_H
#define LISTA_H

struct passageiro{
  char nome[101];
  char RG[101];
  char Assento [3];
  char Destino [101];
};

typedef struct lista lista;
struct lista{
    passageiro *prox, *prev;
    passageiro passageiro;
};

int CriarLista (lista** lista); 
int DestruirLista (lista** lista); 
int AddInicioLista (lista* lista, passageiro passageiro); 
int AddFimLista (lista* lista, passageiro passageiro); 
int RemInicioLista (lista* lista); 
int RemFimLista (lista* lista); 
int VazioLista (lista* lista);  
#endif
