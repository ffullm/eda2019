#include "heap.h"

heap *create_heap(int n)
{
	heap *retHeap =  (heap*)malloc(sizeof(heap));
	retHeap->data = (int*)malloc(sizeof(int)*n);
	retHeap->tam = n-1;
	retHeap->nelem = 0;
	return retHeap;
}
void swap(heap *h, int i, int l)
{
	int aux = h->data[l];
	h->data[l] = h->data[i];
	h->data[i] = aux;
}
void max_heapify(heap *h, int i)
{
	 int maior = i;
	 int esq = 2*i+1;
	 int dir = 2*i+2;
	 if(esq <= h->tam && h->data[esq] > h->data[maior])
	 {
	 	maior = esq;
	 }
	 if(dir <= h->tam && h->data[dir] > h->data[maior])
	 {
	 	maior = dir;
	 }
	 if (maior != i)
	 {
	 	swap(h,i,maior);
		max_heapify(h, maior);
	 }
}
void makeheap(heap *h)
{
	for(int i = floor(h->tam/2); i>=0; i--)
	{
		max_heapify(h, i);
	}
}
int inserir_elem(heap *h, int key)
{
	if(h->tam!=h->nelem)
	{
		h->data[h->tam] = key;
		h->nelem++;
		makeheap(h);
	}
}
//apenas vetores cheios
void heapsort(heap *h)
{
	makeheap(h);
	for(int i = h->tam;  i>=0; i--)
	{
		swap(h, 0, h->tam);
		h->tam--;
		max_heapify(h, 0);
	}
}
