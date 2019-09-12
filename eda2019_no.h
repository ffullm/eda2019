#include <stdlib.h>
#ifndef EDA2019_NO
#define EDA2019_NO
typedef long long unsigned luint;
typedef struct s_no_padrao{
 	luint cpfc;
	char op;
	luint valor;
	luint cpft;
	struct s_no_padrao *prox;
}no_padrao;

typedef struct s_no_lista{
	luint cpf;
	luint valor;
	luint n_op;
	struct s_no_lista *prox;
}no_lista;

no_padrao *iniciar_no_padrao(luint v_cpfc, luint v_cpft, char v_op, luint v_valor);
no_lista *iniciar_no_lista(luint v_cpf);
#endif
