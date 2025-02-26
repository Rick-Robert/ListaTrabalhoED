## LISTA.H

void CriarLista (lista**)

	RECEBE: Um ponteiro para o ponteiro da lista que será criada.
	RETORNA: Void. A lista é somente inicializada.

void DestruirLista (lista**)

	RECEBE: Um ponteiro para o ponteiro da lista que será destruida.
	RETORNA: Void. Libera toda a memória alocada para a lista e "anula" o ponteiro.

void AddInicioLista (lista*, char[], char[], char[], char[])

	RECEBE: Um ponteiro para a lista e vetor de char (nome, RG, assento e destino).
	RETORNA: Void. Passageiro adicionado no inicio da lista.

void AddFimLista (lista*, char[], char[], char[], char[])
	
	RECEBE: Um ponteiro para a lista e vetor de char (nome, RG, assento e destino).
	RETORNA: Void. Passageiro adicionado no fim da lista.

void RemInicioLista (lista*)
	
	RECEBE: Um ponteiro para a lista.
	RETORNA: Void. Remove o passageiro do inicio da lista e libera a memoria alocada para ele.

void RemFimLista (lista*)

	RECEBE: Um ponteiro para a lista.
	RETORNA: Void. Remove o passageiro do fim da lista e libera a memoria alocada para ele.

int VazioLista (lista*)

	RECEBE: Um ponteiro para a lista.
	RETORNA: 1 para lista vazia ou 0 (lista com passageiro(s))



## FILA.H

fila* criarFila (int tamanho);

	RECEBE: O tamanho da fila (quantidade máxima de elementos que serão armazenados)
	RETORNA: O ponteiro de uma fila alocada dinamicamente


void inserir (fila *f, int elemento);

	RECEBE: o ponteiro de uma fila e o elemento que será inserido
	RETORNA: Não retorna nada (se a fila estiver cheia ele não consegue inserir)

void remover(fila *f);

	RECEBE: O ponteiro de uma fila
	RETORNA: Não retorna nada (se a fila tiver algum dado será retirado da fila)

int primeiro(fila *f);

	RECEBE: o ponteiro de uma fila
	RETORNA: o primeiro elemento da fila


int ultimo(fila *f);

	RECEBE: o ponteiro de uma fila
	RETORNA: o ultimo elemento da fila 

int vazia(fila *f);

	RECEBE: o ponteiro de uma fila
	RETORNA: o valor 1 se a fila está vazia ou 0 se não estiver vazia 

int cheia(fila *f);

	RECEBE: o ponteiro de uma fila
	RETORNA: o valor 1 se a fila está cheia ou 0 se não estiver cheia

unsigned tamanho(fila *f);

	RECEBE: o ponteiro de uma fila
	RETORNA: um inteiro com a quantidade de elementos que a fila possui


void desalocarFila(fila *f);

	RECEBE: o ponteiro de uma fila
	RETORNA: não retorna nada (libera toda a memoria alocada dinamicamente)


## Main

  Simulação de uma rodoviária utilizando a lista e a fila para o gerenciamento dos ônibus e passageiros.
