#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include <stdlib.h>
#include<time.h>

void generateRandom(int* arr)
{
	int i;
	srand(time(0));
	for(i=0;i<50;i++)
		arr[i]=rand()%100;	
} 
void sortarr(int *arr)
{
	int i=0;
	for(i=0;i<50;i++)
	{
		for(int j=i+1;j<50;j++)
		{
			if(arr[i]>arr[j])
			{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			}
		}
	}
}
int binarysearch(int* arr,int n)
{
	int l=0,r=n-1;
	while(l<r)
	{
	int m=(l+r)/2;
		if(arr[m]==n)
			return 1;
		else if(arr[m]>n)
		r=m-1;
		else
		l=m+1;
	}
	return -1;
}
int main()
{

	
	int pipe1[2];
	pipe(pipe1);
	int pipe2[2];
	pipe(pipe2);
	int pipe3[2];
	pipe(pipe3);
	int pipe4[2];
	pipe(pipe4);
	
	
	int A=fork();
	if(A==0)
	{
		int B=fork();
		if(B==0)
		{
		//process B
		int arrB[50];
		generateRandom(arrB);
		sortarr(arrB);
		
		write(pipe1[1],arrB,sizeof(int)*50);
		}
		else
		{
		//process A
		wait(0);
		int arrA[50];
		generateRandom(arrA);
		sortarr(arrA);
		
		write(pipe2[1],arrA,sizeof(int)*50);
		}
	}
	else
	{
		wait(0);
		int C=fork();
		if(C==0)
		{
			int D=fork();
			if(D==0)
			{
			//process D
			
			int arr1[50];
			int arr2[50];
			read(pipe1[0],arr1,sizeof(int)*50);
			read(pipe2[0],arr2,sizeof(int)*50);
			
			
			int mer[100];
			int i=0,j=0,p=0;
			while(i<50 && j<50)
			{
				if(arr1[i]<arr2[j])
					mer[p++]=arr1[i++];
				else
					mer[p++]=arr2[j++];
			}
			while(i<50)
				mer[p++]=arr1[i++];
			while(j<50)
				mer[p++]=arr2[j++];
			
			
			write(pipe3[1],mer,100*sizeof(int));
			}
			else
			{
			//process C
			int arrC[50];
			generateRandom(arrC);
			sortarr(arrC);
			
			write(pipe4[1],arrC,sizeof(int)*50);
			}
		}
		else
		{
		//process E
		//waitpid();
		wait(0);
		sleep(3);
		int arrfromD[100],arrfromC[50];
		int finalarray[150];
		read(pipe3[0],arrfromD,sizeof(int)*100);
		read(pipe4[0],arrfromC,sizeof(int)*50);
		
		int i=0,j=0,p=0;
			while(i<100 && j<50)
			{
				if(arrfromD[i]<arrfromC[j])
					finalarray[p++]=arrfromD[i++];
				else
					finalarray[p++]=arrfromC[j++];
			}
			while(i<100)
				finalarray[p++]=arrfromD[i++];
			while(j<50)
				finalarray[p++]=arrfromC[j++];
		

			
		int n;
		printf("Enter the number you want to search\n");
		scanf("%d",&n);
		int res=binarysearch(finalarray,n);
		if(res==-1)
			printf("The item is not found\n");
		else
			printf("The item is found\n");
			
		}
		
	}

}
