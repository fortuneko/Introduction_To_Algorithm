#ifndef MERGE_SORT
#define MERGE_SORT

void Merge(int *A,int p,int q,int r)
{
	int n1 = q - p +1;
	int n2 = r - q ;
	int *L = new int[n1];
	int *R = new int[n2];
	
	int i = 0,j = 0;
	
	for(; i < n1; i++)
		L[i] = A[p + i];
	for(; j < n2; j++)
		R[j] = A[q+1+j];

	i = 0;
	j = 0;
	for(int k = p; k <= r; k++)
	{
		//这里未使用L[n1+1] = INT_MAX,R[n2+1]= INT_MAX，所以要进行越界判断
		bool bL =false;
		if(i == n1)
			bL = false;
		else if(j == n2)
			bL = true;
		else if( L[i] < R[j])
			bL = true;
		else
			bL = false;

		if( bL)
		{
			A[k] = L[i];
			i += 1;
		}
		else
		{
			A[k] = R[j];
			j += 1;
		}
	}
	delete []L;
	delete []R;
}

void Merge_Sort(int *A,int p,int r)
{
	if(p < r)
	{
		int q = (p + r)/2;
		Merge_Sort(A,p,q);
		Merge_Sort(A,q+1,r);
		Merge(A,p,q,r);
	}
}

void test_merge_sort()
{
	int p[10] = {3,5,8,0,2,1,4,7,9,6};
	Merge_Sort(p,0,9);
	for(int i = 0; i < 10; i++)
		printf("%d ",p[i]);
}








#endif