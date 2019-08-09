#include "pl.h"
int main(int argc, char* argv[]){
	pilha* p;
	init_pilha(&p);
	for (;;){
	printf("ESCOLHA UMA OPÇÃO: \n0->init_no&add_elem\n1->esta_vazia\n2->rem_elem\n3->topo\n");
	int value;
	scanf("%d", &value);
	printf("\n");
	if (value == 404) break;
	switch (value){
		case 0:{
			no* n;
			t_chave key;
			scanf("%d", &key);
			init_no(&n, key);
			add_elem(p, n);
			printf("\nO ELEMENTO %d foi adionado na pilha na posicao: %d\n\n", key, p->cont);
    }
			break;
		case 1:{
		(esta_vazia(p) == 0)? printf("a pilha esta vazia\n\n"):printf("a pilha tem elementos\n\n");
    }
			break;
		case 2:{
			rem_elem(p);
    }
      break;
    case 3:{
      printf("%d\n", topo(p));
    }
      break;
    default:
      printf("Vc tem que ta de sacanagem aspira. Só tem %d nessa pilha!\nRespeita a PMRJ irmão!\n\n", p->cont);
    }
  }
}
