#ifndef HEAP_SORT_ALGORITHM
#define HEAP_SORT_ALGORITHM

typedef struct _HeapInfo
{
	int heapSize;
	int length;
	int *buffer;
}HeapInfo;

int LEFT(int i)
{
	return 2*i;
}
int RIGHT(int i)
{
	return 2*i + 1;
}
int PARENT(int i)
{
	return i/2;
}

void MAX_HEAPIFY(HeapInfo *A,int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest = -1;
	if(l < A->heapSize && A->buffer[l] > A->buffer[i])
		largest = l;
	else
		largest = i;

	if(r < A->heapSize && A->buffer[r] > A->buffer[largest])
		largest = r;
	
	if(largest != i)
	{
		int temp = A->buffer[i];
		A->buffer[i] = A->buffer[largest];
		A->buffer[largest] = temp;
		MAX_HEAPIFY(A,largest);
	}
}

void BUILD_MAX_HEAP(HeapInfo *A)
{
	A->heapSize = A->length;
	for(int i = A->length/2 ; i >= 0; i--)
		MAX_HEAPIFY(A,i);
}

//void HEAP_SORT(HeapInfo *A)
void HEAP_SORT(HeapInfo *A)
{
	BUILD_MAX_HEAP(A);
	for(int i = A->length-1; i >= 1; i--)
	{
		//exchange A[0] with A[i];
		int temp = A->buffer[i];
		A->buffer[i] = A->buffer[0];
		A->buffer[0] = temp;
		A->heapSize -= 1;
		MAX_HEAPIFY(A,0);
	}
}

void test_heap_sort()
{
	int p[10] = {3,5,8,0,2,1,4,7,9,6};
	HeapInfo *A = new HeapInfo();

	A->length = 10;
	A->buffer = new int[A->length];
	for(int i = 0; i < A->length; i++)
		A->buffer[i] = p[i];

	HEAP_SORT(A);
	for(int i = 0; i <  A->length; i++)
		printf("%d ",A->buffer[i]);

	delete [] A->buffer;
	delete A;
}
#endif