#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MOD %
typedef long long unsigned luint;
//implementação de guiche
struct s_no{
 	luint cpfc;
	char op;
	int valor;
	luint cpft;
	struct s_no* prox;
};
typedef struct s_no no;
struct s_guiche{
	no* topo; //topo da lista
	int cont;
};
typedef struct s_guiche guiche;
no* init_no(luint v_cpfc, luint v_cpft, char v_op, int v_valor){
	no* n;
	n = (no*)malloc(sizeof(no));
 	n->cpfc = v_cpfc;
  	n->op = v_op;
  	n->valor = v_valor;
  	n->cpft = v_cpft;
	return n;
}
guiche** init_arr_guiche(int k){
	guiche** p = (guiche**)malloc(sizeof(guiche*)*k);
  	for (int i = 0; i<k; i++){
    		p[i] = (guiche*)malloc(sizeof(guiche));
    		p[i]->topo = NULL;
    		p[i]->cont = 0;
   	}
	return p;
}
int esta_vazia(guiche* p){
	if(p->topo == NULL)return 0;
	else return 1;
}

void add_no(guiche* p, no* n) {
  	n->prox = p->topo;
	p->topo = n;
	p->cont += 1;
}
no* rem_no(guiche* p){
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
int del_guiche(guiche* p){
	if (esta_vazia(p) == 0)return 1;
	else{
		int n_no = p->cont;
		for (int i = 0; i<n_no; i++){
				free(rem_no(p));
		}
		free(p);
		return 0;		
	}
}

int main(){
  int n;
  scanf("%d", &n);
  int n_guiche = 3;
  guiche** p;
  p = init_arr_guiche(n_guiche);
  for (int i = 0; i<n; i++){
  	int nGuiche = i MOD n_guiche;
    	luint v_cpfc, v_cpft;
	int v_valor;
    	char v_op;
    	scanf("%llu %llu %c %d", &v_cpfc, &v_cpft, &v_op, &v_valor);
    	add_no(p[nGuiche], init_no(v_cpfc, v_cpft, v_op, v_valor));
  }
  printf("-:| RELATÓRIO PARCIAL |:-\n");
  printf("%d\n", n_guiche);
  for (int i =0; i<n_guiche; i++){
  	int l_pcont = p[i]->cont;
	printf("Guiche %d: %d\n", i+1, l_pcont);
	no* aux = p[i]->topo;
  	for (int q = 0; q<l_pcont; q++){
		no* n_atual = aux;
		printf("[%llu, %llu, %c, %d]\n", n_atual->cpfc, n_atual->cpft, n_atual->op, n_atual->valor);
		aux = n_atual->prox;
	}
      	del_guiche(p[i]);
  }
  free(p);
}
