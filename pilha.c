#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MOD %
typedef long long unsigned luint;
typedef struct s_no_lista{
	luint cpf;
	luint valor;
	luint n_op;
	struct s_no_lista *prox;
}no_lista;

no_lista *init_no_lista(luint v_cpf){
	no_lista *n;
	n = (no_lista*)malloc(sizeof(no_lista));
 	n->cpf = v_cpf;
  	n->valor=0;
  	n->n_op=1;
	return n;
}
//PILHA 
struct s_no{
 	luint cpfc;
	char op;
	luint valor;
	luint cpft;
	struct s_no* prox;
};
typedef struct s_no no;
struct s_pilha{
	no* topo; //topo da lista
	int cont;
};
typedef struct s_pilha pilha;
no* init_no(luint v_cpfc, luint v_cpft, char v_op, luint v_valor){
	no* n;
	n = (no*)malloc(sizeof(no));
 	n->cpfc = v_cpfc;
  	n->op = v_op;
  	n->valor = v_valor;
  	n->cpft = v_cpft;
	return n;
}
pilha** init_arr_pilha(int k){
	pilha** p = (pilha**)malloc(sizeof(pilha*)*k);
  	for (int i = 0; i<k; i++){
    		p[i] = (pilha*)malloc(sizeof(pilha));
    		p[i]->topo = NULL;
    		p[i]->cont = 0;
   	}
	return p;
}
int esta_vazia(pilha* p){
	if(p->topo == NULL)return 0;
	else return 1;
}

int add_no_pilha(pilha* p, no* n) {
  	n->prox = p->topo;
	p->topo = n;
	p->cont += 1;
	return 1;
}

no* busca_pilha(pilha* p, luint cpf){
	no* aux=p->topo;
	while(aux->cpfc!=cpf&&aux!=NULL){
		aux=aux->prox;
	}
	return aux;
}
no* rem_no_pilha(pilha* p){
	if(esta_vazia(p) == 0)return NULL;
	else{
		no* aux;
		aux = p->topo;
		p->topo = aux->prox;
		aux->prox = NULL;
		p->cont -= 1;
		return aux;
  }
}
int del_pilha(pilha* p){
	if (esta_vazia(p) == 0)return 1;
	else{
		int n_no = p->cont;
		for (int i = 0; i<n_no; i++){
				free(rem_no_pilha(p));
		}
		free(p);
		return 0;
	}
}

//////////////////////////////////////////////////////////////////FILA//
typedef struct s_lista{
	no_lista* primeiro;

}lista;

int lista_vazia(lista* l){
	return (l->primeiro==NULL);
}

lista* criar_lista(){
	lista* l=(lista*)malloc(sizeof(lista));
	l=(lista*)malloc(sizeof(lista));
	l->primeiro=NULL;
	return l;
}

int inserir_no_lista(lista *l, int pos, no_lista *n){
	if(lista_vazia(l)|| pos==1){
		n->prox=l->primeiro;
		l->primeiro=n;
		return 0;
	}
	else{
		int i=1;
		no_lista* aux=l->primeiro;
		while(i!=pos+1 && aux->prox!=NULL){
			aux=aux->prox;
			i++;
		}
		n->prox=aux->prox;
		aux->prox=n;
	}
	return 0;
}

no_lista* remover_no_lista(lista *l, no_lista *n){
	if(lista_vazia(l))return NULL;
	if(l->primeiro==n){
		l->primeiro=l->primeiro->prox;
		return 0;
	}
	else{
		no_lista* aux=l->primeiro;
		while(aux->prox!=n){
			aux=aux->prox;
		}
		aux->prox=n->prox;
		n->prox=NULL;
		return n;
	}
}
no_lista* buscar_lista(lista *l, luint cpf){
	no_lista *aux=l->primeiro;
	while(aux->cpf!=cpf&&aux!=NULL){
		aux=aux->prox;
	}
	return aux;
}

int del_lista(lista *l){
	if(lista_vazia(l))return 1;
	while(!lista_vazia(l)){
		free(remover_no_lista(l, l->primeiro));
	}
	free(l);
	return 0;
}
/////////////////////////////////////////////////////////////FILA ESTATICA
typedef struct s_fila{
	no** valores;
       	luint inicio;
	luint fim;
	luint tam;
	luint qntelem;
}fila;

fila* criar_fila(luint tam){
	fila* f;
	f=(fila*)malloc(sizeof(fila));
	f->tam=tam;
	f->inicio=0;
	f->fim=0;
	f->qntelem=0;
	f->valores=(no**)malloc(sizeof(no*)*tam);
	return f;
}

int fila_vazia(fila *f){
	return (f->qntelem==0);
}

int fila_cheia(fila *f){
	return (f->tam==f->qntelem);
}

int enfileira_no(fila *f, no* n){
	if(fila_cheia(f))return 1;
	else{
		f->fim=(f->fim+1)%f->tam;
		f->valores[f->fim]=n;
		f->qntelem++;
		return 0;
	}
}

no* desinfileira_no(fila *f){
	if(fila_vazia(f))return NULL;
	else{
		luint x=f->inicio;
		f->qntelem--;
		f->inicio=(f->inicio+1)%f->tam;
		return f->valores[x];
	}
}

int del_fila(fila *f){
	free(f);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void relatorio_parcial(pilha **p, int n_pilhas){
  printf("-:| RELATÓRIO PARCIAL |:-\n");
  printf("%d\n", n_pilhas);
  for (int i =0; i<n_pilhas; i++){
  	int l_pcont = p[i]->cont;
	printf("Guiche %d: %d\n", i+1, l_pcont);
	no* aux = p[i]->topo;
  	for (int q = 0; q<l_pcont; q++){
		no* n_atual = aux;
		if(n_atual->op!='S')printf("[%llu, %llu, %c, %llu]\n", n_atual->cpfc, n_atual->cpft, n_atual->op, n_atual->valor);
		else printf("[%llu, %c, %llu]\n", n_atual->cpfc, n_atual->op, n_atual->valor);
	aux = n_atual->prox;
	}
  }
}

no* entradas(){
    	luint v_cpfc, v_cpft,v_valor;
    	char v_op;
    	scanf("%llu %llu %c %llu", &v_cpfc, &v_cpft, &v_op, &v_valor);
	no* no = init_no(v_cpfc, v_cpft, v_op, v_valor);
	return no;
}

void relatorio_final(lista *l){
	luint i=0;
	no_lista *aux=l->primeiro;
	while(aux!=NULL){i++; aux=aux->prox;}
	printf("-:| RELATÓRIO FINAL |:-\n%llu\n", i);
	aux=l->primeiro;
	while(aux!=NULL){
		printf("-:[ %llu: %llu %llu\n", aux->cpf, aux->n_op, aux->valor);
		aux=aux->prox;
	}
}

no_lista* proc_no_lista(lista *l, luint cpf){
	if(buscar_lista(l, cpf)!=NULL){//BUSCAR O CPF PRA DEPOSITAR
		no_lista *noaux = buscar_lista(l, cpf);
		noaux->n_op++;
		return noaux; 
	}
 	else{
		no_lista *noaux;
		noaux = init_no_lista(cpf);
		luint i=1;
		no_lista* auxl = l->primeiro;//auxliar pra percorrer a lista
		while(auxl!=NULL&&cpf<auxl->cpf){//Percorre a lista até achar cpf maior que o cpf do no
			auxl=auxl->prox;
			i++;
		}
		inserir_no_lista(l, i, noaux);
		return noaux;
        }
}

void processar_dados(fila *f, luint n_clientes, lista *l){
	for(luint i=0; i<n_clientes; i++){
		no* no=desinfileira_no(f);
		switch(no->op){
			case('D'):{
				proc_no_lista(l, no->cpft)->valor+=no->valor;
				break;
			}
			case('S'):{
				proc_no_lista(l, no->cpfc)->valor-=no->valor;
				break;
			}
			case('T'):{
				proc_no_lista(l, no->cpfc)->valor-=no->valor;
				proc_no_lista(l, no->cpft)->valor+=no->valor;
				break;
			}
		}
	}
}

int main(){
  luint n_clientes;
  int n_pilhas=3;
  scanf("%llu", &n_clientes);
  pilha** p;
  p = init_arr_pilha(n_pilhas);
  fila* f = criar_fila(n_clientes);
  lista *l = criar_lista();
  for(luint i=0; i<n_clientes; i++){
	  int nGuiche = i MOD n_pilhas;
	  no* no=entradas(i, n_pilhas);
	  enfileira_no(f, no);
	  add_no_pilha(p[nGuiche], no);
  }
  relatorio_parcial(p, n_pilhas);
  processar_dados(f, n_clientes, l);
  relatorio_final(l);
  for(int l=0; l<n_pilhas; l++){
  	del_pilha(p[l]);
  }
  free(p);
  del_lista(l);
  del_fila(f);
}
