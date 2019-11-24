#ifndef HEAP
#include <stdlib.h>
#include <math.h>
#define HEAP
typedef struct heap{
	int *data;
	int tam;
	int nelem;
} heap;
heap *create_heap(int n);
void swap(heap *h, int i, int l);
int inserir_elem(heap *h, int key);
int remover_elem(heap *h);
void max_heapify(heap *h, int i);
void makeheap(heap *h); 
void heapsort(heap *h);
#endif
