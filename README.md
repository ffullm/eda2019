#EDA2019

"PILHA.C"

IMPLEMENTAÇÃO DA ATIVIDADE DE EDA2019

FUNÇÕES:

init_no(int v_cpfc, int v_cpft, char v_op, int v_valor);        RETORNA O ENDEREÇO DE UM NÓ INICIADO COM OS PARAMETROS;

init_arr_guiche(int k);         RETORNA O ENDEREÇO DE UM ARRAY DE GUICHES COM K GUICHES;

esta_vazia(guiche* p);          RETORNA 0 CASO GUICHE ESTEJA VAZIO E 1 CASO NÃO ESTEJA;

add_no(guiche* p, no* n);       ADICIONA UM NÓ N NO GUICHE P;

rem_no(guiche* p);              REMOVE UM NO DA GUICHE P;

del_guiche(guiche* p);          REMOVE E LIBERA O GUICHE P;
