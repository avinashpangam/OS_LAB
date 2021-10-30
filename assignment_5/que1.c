#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int findmax(int* arr,int s,int e)
{
int maxi=INT_MIN;
for(int i=s;i<=e;i++)
{
    if(arr[i]>maxi)
    maxi=arr[i];
}
return maxi;
}
int main()
{
    int n;
    printf("enter size of array\n");
    scanf("%d",&n);
    srand(time(0));
    int arr[n];
    int fd[2];
    pipe(fd);
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%128;
    
    }
    printf("unsorted array by parent-");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    int pid =fork();
    if(pid!=0)
    {
        int num1=findmax(arr,0,n/2);
        close(fd[0]);
        write(fd[1],&num1,sizeof(int));
        close(fd[1]);

    }
    else
    {
        int num2=findmax(arr,(n/2)+1,n-1);
        close(fd[1]);
        int k;
        read(fd[0],&k,sizeof(int));
        close(fd[0]);
        if(k>num2)
        printf("max  by child is %d",k);
        else
        printf("max  by child is %d",num2);
    }
    return 0;
}