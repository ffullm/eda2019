# eda2019
Trabalho EDA 2019.2
Como usar:
A maneira mais simples de usar a minha implementação de pilha é simplesmente usando #include "pilha.c", sendo que o arquivo tem que estar na mesma pasta do arquivo que você está compilando.

QUAIS SÃO OS TIPOS:
PILHA: Guarda o elemento do topo e um inteiro que conta o numero de elementos.

NO: Guarda um tipo t_chave e um endereço para outro NO.
DESATUALIZADO MAIS TARDE EU TERMINO DE ARRUMAR TUDO
AS FUNÇÕES:

init_pilha(pilha** p) // inicia a pilha cujo ponteiro está apontando (IMPORTANTE NÃO ESQUECER DE INICIAR PILHA!)

init_no(no** n, t_chave c) // inicia o no cujo ponteiro está apontando com o valor t_chave c (IMPORTANTE NÃO ESQUECER DE INICIAR oO NO!)

esta_vazia(pilha* p) // retorna 1 a pilha está vazia e 0 e está cheia.

topo(pilha* p) // retorna o valor do topo da pilha e 1 se está vazia.

add_elem(pilha* p, no* n) // adiciona o no n na pilha p

rem_elem(pilha* p) // remove o atual topo da pilha

USANDO A BIBLIOTECA:
você deve, logo após criar uma pilha p, usar a função init_pilha para inicia-la. O mesmo passo deve ser feito para no. Todo o resto deve ser intuitivo :)
exemplo de uso

#include "pilha.c"
int main(){

        pilha* p;
        
        init_pilha(&p); // NAO ESQUECER DE PASSAR O ENDEREÇO DA PILHA
        
        no* n;
        
        t_chave b = 5;
        
        init_no(&n, b); // NAO ESQUECER DE PASSAR O ENDEREÇO DO NO
        
        add_elem(p,n);
        
}

Eu sei que essa não é a melhor maneira de implementar. Vou tentar melhorar ainda :D


Uma ultima coisa, t_chave está definido como int por padrão para propósito de teste. 
