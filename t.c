#include "pl.h"
int main(int argc, char* argv[]){
	pilha* p;
	init_pilha(&p);
	for (;;){
	printf("ESCOLHA UMA OPÇÃO: 0->init_no&add_elem\n1->esta_vazia\n2->rem_elem\n4->topo");
	int value;
	scanf("%d", &value);
	printf("\n");
	if (value == 404)break;
	switch (value):
		case (value == 0):
			no* n;
			t_chave key;
			scanf("%d", &key);
			init_no(&n, key);
			add_elem(p, n);
			printf("O ELEMENTO %d foi adionado na pilha na posicao: %d", key, p->cont);
			break;
		case (value == 1):
		(estavazia(p) == 0)? printf("a pilha esta vazia"):printf("a pilha tem elementos");
			break;
		case (value == 2):
			rem_elem(p);
}
}
