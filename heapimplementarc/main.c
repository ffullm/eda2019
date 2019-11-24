#include "heap.h"
#include <stdio.h>
int main()
{
	heap *h = create_heap(5);
	h->data[0] = 4;
	h->data[1] = 10;
	h->data[2] = 3;
	h->data[3] = 5;
	h->data[4] = 1;	
       	h->nelem = 5;
	makeheap(h);
	makeheap(h);
	for(int i = h->nelem-1; i>=0; i--)
	{
		printf("%d ", h->data[h->nelem-1-i]);
	}
	heapsort(h);
	printf("\n");
	for(int i = 0; i<h->nelem; i++)
	{
		printf("%d ", h->data[i]);
	}	

}
