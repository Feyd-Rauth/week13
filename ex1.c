#include <stdio.h>
#include <stdlib.h>
int main()
{	
	int m = 3; // 3 types of resources
	int n = 5; // 5 processes

	int E[m];
	int A[m];

	int C[n][m];
	int R[n][m];

	FILE *input;
	input = fopen("input_corrupted.txt", "r");

	for(int i = 0; i < m; i++)
	{
		fscanf(input, "%d", &E[i]);
	}

	for(int i = 0; i < m; i++)
	{
		fscanf(input, "%d", &A[i]);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			fscanf(input, "%d", &C[i][j]);
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{ 
			fscanf(input, "%d", &R[i][j]);
		}
	}

	
	int* finish = (int*)calloc(sizeof(int), n);

	int k;
	int boolean = 1;
	while(boolean) 
	{	
		boolean = 0;
		for(int i = 0; i < n; i++)
		{
			if(!finish[i])
			{
				k = 1;
				for(int j = 0; j < m; j++)
				{
					if(R[i][j] > A[j])
					{
						k = 0;
						boolean = 0;
						break;
					}
					else
					{
						boolean = 1;
					}
				}

				if(k)
				{
					for(int j = 0; j < m; j++)
					{
						A[j] = A[j] + C[i][j];
						finish[i] = 1;
					}
				} 
				
			}
		}
	}


	k = 1;
	int deadlocks[n];

	for(int i = 0; i < n; i++)
	{
		if(!finish[i])
		{
			k = 0;
		}
	}
	if(!k)
	{
		printf("Deadlock detected with processes: ");
		for(int i = 0; i < n; i++)
		{
			if(!finish[i])
			{
				printf("%d ", i);
			}
		}
	}
	else
	{
		printf("No deadlocks detected\n");
	}

}
