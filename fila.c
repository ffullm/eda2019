#include <stdio.h>
#define TRUE 0
#define FALSE 1
struct s_filaseq{
	int fim;
	int inicio;
	int tam;
	int qntelem;
	int* dados;
};
typedef struct s_filaseq filaseq;
int filaseq_vazia(filaseq* f){
	return  (f->qntelem==0)?TRUE:FALSE;

}
int filaseq_cheia(filaseq* f){
	return (f->qntelem==f->tam)?TRUE:FALSE;
}
int filaseq_add_no(filaseq* f, int n){
	if (filaseq_cheia)return FALSE;
	else{
		f->fim=(f->fim=1)%f->tam;
		f->dados[f->fim]=n;
	       	f->qntelem++;
		return TRUE;	
	}
}

int filaseq_rem_no(filaseq* f){
	if (filaseq_vazia==TRUE) return FALSE;
	else{
		int temp=f->dados[f->inicio];
		f->inicio=(f->inicio+1)%f->tam;
		f->qntelem++;
		return temp;
	}
}

///////////////////////////////////////////////////////////////////
struct f_no{
	//typedef 
	int dados;
	struct f_no* prox;
};
typedef struct f_no no;
struct fenc{
	no* inicio;
	no* fim;
};
typedef struct fenc fenc;

int fenc_vazia(fenc* f){
	return (f->inicio==NULL)?TRUE:FALSE;
}
int fenc_add_no(fenc* f, no* n){
	if (fenc_vazia==TRUE){
		f->inicio=n;
		f->fim=n;
	}
	else{
		f->fim->prox=n;
		f->fim=n;
		n->prox=NULL;
	}
	return TRUE;
}

no* fenc_rem_no(fenc* f){
	if (fenc_vazia)return NULL;
	else{
		no* aux = f->inicio;
		f->inicio=f->inicio->prox;
		aux->prox=NULL;
		if(f->inicio==NULL){
			f->fim=NULL;
		}
		aux->prox=NULL;
		return aux;
	}
}

