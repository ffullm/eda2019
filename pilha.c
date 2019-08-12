#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MOD %
//implementação de guiche
struct s_no{
 	int cpfc;
	char op;
	int valor;
	int cpft;
	struct s_no* prox;
};
typedef struct s_no no;
struct s_guiche{
	no* topo; //topo da lista
	int cont;
};
typedef struct s_guiche guiche;
no* init_no(int v_cpfc, int v_cpft, char v_op, int v_valor){
	no* n;
	n = (no*)malloc(sizeof(no));
 	n->cpfc = v_cpfc;
  	n->op = v_op;
  	n->valor = v_valor;
  	n->cpft = v_cpft;
	return n;
}
void init_arr_guiche(guiche*** p, int k){
	*p = (guiche**)malloc(sizeof(guiche*)*k);
  	for (int i = 0; i<k; i++){
    		(*p)[i] = (guiche*)malloc(sizeof(guiche));
    		(*p)[i]->topo = NULL;
    		(*p)[i]->cont = 0;
  }
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
			no* aux = rem_no(p);
			free(aux);
		}
		return 0;			
	}
}

int main(){
  int n;
  scanf("%d", &n);
  int n_guiche = 3;
  guiche** p;
  init_arr_guiche(&p, n_guiche);
  for (int i = 0; i<n; i++){
  	int nGuiche = i MOD n_guiche;
    	int v_cpfc, v_cpft, v_valor;
    	char v_op;
    	scanf("%d%d %c%d", &v_cpfc, &v_cpft, &v_op, &v_valor);
    	add_no(p[nGuiche], init_no(v_cpfc, v_cpft, v_op, v_valor));
  }
  printf("-:| RELATÓRIO PARCIAL |:-\n");
  for (int i =0; i<n_guiche; i++){
  	int l_pcont = p[i]->cont;
	printf("%d\n", l_pcont);
  	for (int q = 0; q<l_pcont; q++){
		no* n_atual =  rem_no(p[i]);
		printf("%d %d %c %d\n", n_atual->cpfc, n_atual->cpft, n_atual->op, n_atual->valor);
	}
      	del_guiche(p[i]);	
  }
}
