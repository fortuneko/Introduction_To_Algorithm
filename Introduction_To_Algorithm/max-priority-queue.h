#ifndef MAX_PRIORITY_QUEUE_ALGORITHM
#define MAX_PRIORITY_QUEUE_ALGORITHM

#include "heap-sort.h"
#define INT_MAX_32 2^32 - 1


#include <stdlib.h>	//for srand
#include <time.h>       /* time */

int HEAP_MAXIMUM(HeapInfo *A)
{
	return A->buffer[0];
}

int HEAP_EXTRACT_MAX(HeapInfo *A)
{
	if(A->heapSize < 0)
	{
		return -INT_MAX_32;
	}
	int max = A->buffer[0];
	A->buffer[0] = A->buffer[A->heapSize-1];
	A->heapSize -= 1;

	MAX_HEAPIFY(A,0);

	return max;
}

void HEAP_INCREASE_KEY(HeapInfo*A,int i,int key)
{
	if(key < A->buffer[i])
		return;

	A->buffer[i] = key;
	while(i > 0 && A->buffer[PARENT(i)] < A->buffer[i])
	{
		//exchange 
		int srcParent = A->buffer[PARENT(i)] ;
		A->buffer[PARENT(i)] = A->buffer[i];
		A->buffer[i] = srcParent;
		i = PARENT(i);
	}
}

void MAX_HEAP_INSERT(HeapInfo*A, int key)
{
	if(A->heapSize == A->length)
		return;
	A->heapSize += 1;
	A->buffer[A->heapSize-1] = -INT_MAX_32;
	
	HEAP_INCREASE_KEY(A,A->heapSize-1,key);
}

void test_max_priority_queue()
{
	int p[10] = {3,5,8,0,2,1,4,7,9,6};
	HeapInfo *A = new HeapInfo();

	A->length = 10;
	A->buffer = new int[A->length];
	for(int i = 0; i < A->length; i++)
		A->buffer[i] = p[i];

	BUILD_MAX_HEAP(A);
	A->heapSize = A->length;	//after heap sort, heap size turns to 1, needs to reset it
	printf("source queue is :\n");
	for(int i = 0; i <  A->heapSize; i++)
		printf("%d ",A->buffer[i]);
	printf("\n");

	for(int i = 0; i < 5; i++)
	{
		int val = HEAP_EXTRACT_MAX(A);
		printf("extract heap max: %d\n",val);
	}
	
	time_t t;
	
	srand((unsigned) time(&t));

	for(int i = 0; i < 5; i++)
	{
		int val = rand()%100 + 10;	//rand() return val from 0 to RAND_MAX
		MAX_HEAP_INSERT(A,val);
		printf("insert %d \n",val);
	}
	printf("after process,queue is :\n");
	for(int i = 0; i <  A->heapSize; i++)
		printf("%d ",A->buffer[i]);
}

#endif