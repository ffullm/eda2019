#include <stdlib.h>
#include <stdio.h>
typedef int t_chave;
//implementação de pilha
struct s_no{
	t_chave chave; //valor da chave do no
	struct s_no* prox; 
};
typedef struct s_no no;
struct s_pilha{
	no* topo; //topo da lista
	int cont; //contador
};
typedef struct s_pilha pilha;
//definindo as funções
//NAO USAR UMA PILHA SEM INICIAR ANTES
void init_pilha(pilha** p){
	*p = (pilha*)malloc(sizeof(pilha)); 
	(*p)->topo = NULL; 
	(*p)->cont = 0;
}
//NAO USAR UM NO SEM INICIAR ANTES
void init_no(no** n, t_chave c){
	*n = (no*)malloc(sizeof(no));
	(*n)->chave = c;
}
//a função esta_vazia retorna 0 se está vazia e 1 se diferente
int esta_vazia(pilha* p){
	if(p->topo == NULL)return 0;
	else return 22;
}
//adiciona elemento na pilha
void add_elem(pilha* p, no* n){
	n->prox = p->topo;
	p->topo = n;
	p->cont += 1;
}
//remove elemento da pilha. se a função falhar, ela retorná 1, caso contrário ela retornará o elemento apagado.
t_chave rem_elem(pilha* p){
	if(esta_vazia(p) == 0)return 1;
	else{
	no* aux;
	aux = p->topo;
	p->topo = aux->prox;
	aux->prox = NULL;
	p->cont -= 1;
	return aux->chave;
	}
}
//retorna o valor do topo da pilha
t_chave topo(pilha* p){
	if (esta_vazia(p) == 0)return 1;
	else return (p->topo)->chave;
}
