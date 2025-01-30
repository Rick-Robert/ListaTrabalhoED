#ifndef LISTA_H
#define LISTA_H

typedef struct Passageiro 
{
    char nome[101];
    char RG[101];
    char Assento[3]; 
    char Destino[101];
} Passageiro;

typedef struct 
{
    Passageiro passageiro;
    Passageiro *anterior;
    Passageiro *posterior;
} EleList;

int criar (); 
int destruir (); 
int addinicio (); 
int addfim (); 
int reminicio (); 
int remfim (); 
int vazio ();  

#endif