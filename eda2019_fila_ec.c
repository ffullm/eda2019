#include <stdlib.h>
#include "eda2019_no.h"
#include "eda2019_fila_ec.h"
//EMPLEMENTA FILA ESTATICA CIRCULAR PARA O TRABALHO EDA2019.2
fila *criar_fila(luint tam){
	fila* f;
	f=(fila*)malloc(sizeof(fila));
	f->tam=tam;
	f->inicio=0;
	f->fim=0;
	f->qntelem=0;
	f->valores=(no_padrao**)malloc(sizeof(no_padrao*)*tam);
	return f;
}
int fila_vazia(fila *f){
	return (f->qntelem==0);
}

int fila_cheia(fila *f){
	return (f->tam==f->qntelem);
}

int add_no_fila(fila *f, no_padrao *n){
	if(fila_cheia(f))return 0;
	else{
		f->fim=(f->fim+1)%f->tam;
		f->valores[f->fim]=n;
		f->qntelem++;
		return 1;
	}
}

no_padrao *rem_no_fila(fila *f){
	if(fila_vazia(f))return NULL;
	else{
		luint x=f->inicio;
		f->qntelem--;
		f->inicio=(f->inicio+1)%f->tam;
		return f->valores[x];
	}
}

int del_fila(fila *f){
	free(f->valores);
	free(f);
	return 1;
}
