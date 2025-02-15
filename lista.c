#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void CriarLista (lista** pplista){
    if(*pplista == NULL) *pplista = (lista*) malloc(sizeof(lista));
    (*pplista)->sentinela->prev = (*pplista)->sentinela->prox = (*pplista)->sentinela = (passageiro*) malloc(sizeof(passageiro));
    (*pplista)->quantidade = 0;
}

void DestruirLista (lista** pplista){
    while(VazioLista(*pplista) != 1) RemInicioLista(*pplista);
    free((*pplista)->sentinela);
    free(*pplista);
    *pplista = NULL;
    return;
}

void AddInicioLista(lista* pplista, char nome[], char RG[], char assento[], char destino[]) {
    struct passageiro* NovoPassageiro = (struct passageiro*)malloc(sizeof(struct passageiro));

    strcpy(NovoPassageiro->Nome, nome);
    strcpy(NovoPassageiro->RG, RG);
    strcpy(NovoPassageiro->Assento, assento);
    strcpy(NovoPassageiro->Destino, destino);

    NovoPassageiro->prox = pplista->sentinela->prox; 
    NovoPassageiro->prev = pplista->sentinela; 

    pplista->sentinela->prox->prev = NovoPassageiro; 
    pplista->sentinela->prox = NovoPassageiro;
    pplista->quantidade++;
    return;
}

void AddFimLista(lista* pplista, char nome[], char RG[], char assento[], char destino[]) {
    
    struct passageiro* NovoPassageiro = (struct passageiro*)malloc(sizeof(struct passageiro));
    
    strcpy(NovoPassageiro->Nome, nome);
    strcpy(NovoPassageiro->RG, RG);
    strcpy(NovoPassageiro->Assento, assento);
    strcpy(NovoPassageiro->Destino, destino);

    NovoPassageiro->prox = pplista->sentinela; 
    NovoPassageiro->prev = pplista->sentinela->prev; 

    pplista->sentinela->prev->prox = NovoPassageiro; 
    pplista->sentinela->prev = NovoPassageiro; 
 
    pplista->quantidade++;
    return;
}

void RemInicioLista (lista* pplista)
{
    struct passageiro* PassageiroRemovido = pplista->sentinela->prox;

    if (PassageiroRemovido != pplista->sentinela) 
    { 
        pplista->sentinela->prox = PassageiroRemovido->prox;
        PassageiroRemovido->prox->prev = PassageiroRemovido->prev;

        free(PassageiroRemovido);

        pplista->quantidade--;
    } 

    return;
} 

void RemFimLista (lista* pplista) 
{
    struct passageiro* PassageiroRemovido = pplista->sentinela->prev;

    if (PassageiroRemovido !=pplista->sentinela) 
    { 
        pplista->sentinela->prev = PassageiroRemovido->prev;
        PassageiroRemovido->prev->prox = PassageiroRemovido->prox;

        free(PassageiroRemovido);

        pplista->quantidade--;
    }

    return;
}

int VazioLista(lista* pplista){
    if(pplista->quantidade <= 0){
        pplista->quantidade = 0;
        return 1;
    }
    return 0;
}