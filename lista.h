#ifndef LISTA_H
#define LISTA_H

typedef struct passageiro{
  char Nome[101];
  char RG[101];
  char Assento [11];
  char Destino [101];

  struct passageiro* prox;
  struct passageiro* prev;
  
} passageiro;

typedef struct lista{
    passageiro* sentinela;
    int quantidade;
} lista;

void CriarLista (lista** pplista); 
void DestruirLista (lista** pplista); 
void AddInicioLista (lista* pplista, char nome[], char RG[], char assento[], char destino[]); 
void AddFimLista (lista* pplista, char nome[], char RG[], char assento[], char destino[]); 
void RemInicioLista (lista* pplista); 
void RemFimLista (lista* pplista); 
int VazioLista (lista* pplista);  

#endif