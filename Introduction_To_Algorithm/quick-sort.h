#ifndef QUICK_SORT_ALGORITHM
#define QUICK_SORT_ALGORITHM


void exchange(int *left,int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
int PARTITION(int *A,int p,int r)
{
	int x = A[r];
	int i = p - 1;
	for(int j = p; j <= r-1; j++)
	{
		if(A[j] < x)
		{
			i += 1;
			exchange(&A[i],&A[j]);
		}
	}
	exchange(&A[i+1],&A[r]);
	return i+1;
}

void QUICK_SORT(int *A,int p,int r)
{
	if(p < r)
	{
		int q = PARTITION(A,p,r);
		QUICK_SORT(A,p,q-1);
		QUICK_SORT(A,q+1,r);
	}
}

void QUICK_SORT_X(int *A,int p,int r)
{
	while( p < r)
	{
		int q = PARTITION(A,p,r);
		QUICK_SORT_X(A,p,q-1);
		p = q + 1;
	}
}

void test_quick_sort()
{
	int p[10] = {3,5,8,0,2,1,4,7,9,6};
	//QUICK_SORT(p,0,9);
	QUICK_SORT_X(p,0,9);
	for(int i = 0; i < 10; i++)
		printf("%d ",p[i]);
}
#endif