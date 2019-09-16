#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "eda2019_no.h"
#include "eda2019_pilha_denc.h"
#include "eda2019_fila_ec.h"
#include "eda2019_lista_dencsc.h"
#define MOD %


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void relatorio_parcial(pilha **p, int n_pilhas){
  printf("-:| RELATÓRIO PARCIAL |:-\n");
  printf("%d\n", n_pilhas);
  for (int i=0; i<n_pilhas; i++){
	luint l_pcont=0;
	no_padrao *aux=p[i]->topo;
  	while(aux!=NULL){l_pcont++; aux=aux->prox;}
	printf("Guiche %d: %llu\n", i+1, l_pcont);
	aux = p[i]->topo;
  	for (luint q = 0; q<l_pcont; q++){
		no_padrao *n_atual = aux;
		printf("[%llu,%llu,%c,%lld]\n", n_atual->cpfc, n_atual->cpft, n_atual->op, n_atual->valor);
		aux = n_atual->prox;
	}
  }
}

no_padrao *entradas(){
    	luint v_cpfc, v_cpft,v_valor;
    	char v_op;
    	scanf("%llu %llu %c %lld", &v_cpfc, &v_cpft, &v_op, &v_valor);
	no_padrao *no = iniciar_no_padrao(v_cpfc, v_cpft, v_op, v_valor);
	return no;
}

void relatorio_final(lista *l){
	luint i=0;
	no_lista *aux=l->primeiro;
	while(aux!=NULL){if(aux->n_op!=0)i++; aux=aux->prox;}
	printf("\n-:| RELATÓRIO FINAL |:-\n %llu\n", i);
	aux=l->primeiro;
	while(aux!=NULL){	
		if(aux->n_op!=0)printf("-:[ %llu : %llu %lld\n", aux->cpf, aux->n_op, aux->valor);
		aux=aux->prox;
	}
}

no_lista *proc_no_lista(lista *l, luint cpf){
	if(buscar_lista(l, cpf)!=NULL){//BUSCAR O CPF PRA DEPOSITAR
		no_lista *noaux = buscar_lista(l, cpf);
		return noaux; 
	}
 	else{
		no_lista *noaux = iniciar_no_lista(cpf);
		no_lista* auxl = l->primeiro;//auxliar pra percorrer a lista
		luint i=1;
			while(auxl!=NULL&&cpf>auxl->cpf){//Percorre a lista até achar cpf maior que o cpf do no
			auxl=auxl->prox;
			i++;
		}
		add_no_lista(l, i, noaux);
		auxl = l->primeiro;
		return noaux;
        }
}

void processar_dados(fila *f, luint n_clientes, lista *l){
	for(luint i=0; i<n_clientes; i++){
		no_padrao *no=rem_no_fila(f);
		switch(no->op){
			case('D'):{
				no_lista *auxnol=proc_no_lista(l, no->cpft);
				auxnol->valor+=no->valor;
				auxnol->n_op++;
				proc_no_lista(l, no->cpfc)->n_op++;
				break;
			}
			case('S'):{
				no_lista *auxnol=proc_no_lista(l, no->cpfc);
				auxnol->valor-=no->valor;
				auxnol->n_op++;
				break;
			}
			case('T'):{
				proc_no_lista(l, no->cpfc)->valor-=no->valor;
				proc_no_lista(l, no->cpft)->valor+=no->valor;
				proc_no_lista(l, no->cpfc)->n_op++;
				proc_no_lista(l, no->cpft)->n_op++;
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
  p = criar_arr_pilha(n_pilhas);
  fila* f = criar_fila(n_clientes);
  lista *l = criar_lista();
  for(luint i=0; i<n_clientes; i++){
	  int nGuiche = i MOD n_pilhas;
	  no_padrao *no=entradas();
	  add_no_fila(f, no);
	  add_no_pilha(p[nGuiche], no);
  }
  relatorio_parcial(p, n_pilhas);
  processar_dados(f, n_clientes, l);
  relatorio_final(l);
  for(int k=0; k<n_pilhas; k++){
	  del_pilha(p[k]);
  }
  free(p);
  del_lista(l);
  del_fila(f);
}
