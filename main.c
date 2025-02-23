#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "lista.h"

//Uma rodoviara que utiliza uma lista para guardar os passageiros de cada onibus e uma fila para gerenciar a recepcao
typedef struct Onibus{
    char linha[101], placa[10], hora_saida[10];
    lista* passageiros;
}Onibus;

void add_passageiro(Onibus base_dados[], char linha[], passageiro add, int position);

int main(){
    fila* recepcao; //fila para comprar ticket
    recepcao = criarFila(1000);
    Onibus rodoviaria[1000];
    return 0;
}

void add_passageiro(Onibus base_dados[], char linha[], passageiro add, int position){ //adiciona passageiros dependendo da linha do onibus
    int i = 0;
    int size = sizeof(base_dados)/sizeof(base_dados[0]);
    char temp[size+10];
    strcpy(temp, base_dados[0].linha);
    while(i < size){
        if(strcmp(temp, linha) == 0){
            if(position == 0)
                AddInicioLista(base_dados[i].passageiros, add.Nome, add.RG, add.Assento, add.Destino);
            else
                AddFimLista(base_dados[i].passageiros, add.Nome, add.RG, add.Assento, add.Destino);
            
            break;
        }
        i++;
        strcpy(temp, base_dados[i].linha);
    }
}