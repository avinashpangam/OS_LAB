#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int findsum(int* arr,int n,int pivot)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        
        if(arr[i]>pivot)
        {
            sum+=arr[i];
        }
    }
    return sum;
}

int main()
{
    int n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    srand(time(0));
    for (int i=0;i<n;i++)
    {
        arr[i]=rand()%128;
    }
    printf("unsorted array-\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    int pivot;
    printf("\nenter the pivot element-");
    scanf("%d",&pivot);
    int fd[2];
    pipe(fd);
    int id=fork();
    if(id==0)
    {
        int sum=findsum(arr,n,pivot);
        close(fd[0]);
        write(fd[1],&sum,sizeof(int));
        close(fd[1]);
    }
    else
    { int result;
        close(fd[1]);
        read(fd[0],&result,sizeof(int));
        close(fd[0]);
        printf("\n parent printing sum-  %d \n",result);
    }
    return 0;

}