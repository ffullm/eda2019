typedef long long unsigned luint - TIPO DOS VALORES


typedef signed long long int lint - TIPO DOS VALORES POSSIVEIS A CADA CPF


no_padrao - TIPO DE NO USADO PELA PILHA E FILA


no_lista - TIPO DE NO USADO PELA LISTA

no_padrao *iniciar_no_padrao(luint v_cpfc, luint v_cpft, char v_op, lint v_valor) 


no_lista *iniciar_no_lista(luint v_cpf)


pilha **criar_arr_pilha(int k)


int pilha_vazia(pilha *p) - RETORNA 1 SE VERDADEIRO, 0 SE FALSO


no_padrao *add_no_pilha(pilha *p, no_padrao *n) 


no_padrao *rem_no_pilha(pilha *p) 


no_padrao *buscar_pilha(pilha* p, luint cpf) - RETORNA O NÓ SE ACHAR, RETORNA NULL CASO NÃO


int del_pilha(pilha *p) 

	
int lista_vazia(lista *l) - RETORNA 1 SE VERDADEIRO, 0 SE FALSO


lista *criar_lista();


no_lista *add_no_lista(lista *l, luint pos, no_lista *n)


no_lista *rem_no_lista(lista *l, no_lista *n)


no_lista *buscar_lista(lista *l, luint cpf) - RETORNA O NÓ SE ACHAR, RETORNA NULL CASO NÃO


int del_lista(lista *l)


fila *criar_fila(luint tam)


int fila_vazia(fila *f) - RETORNA 1 SE VERDADEIRO, 0 SE FALSO


int fila_cheia(fila *f)


int add_no_fila(fila *f, no_padrao *n)


no_padrao *rem_no_fila(fila *f)


int del_fila(fila *f)

