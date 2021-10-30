#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<wait.h>



int main()
{
    int n;
    printf("enter the size of array-");
    scanf("%d",&n);
    int arr[n];
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand() % 128;
    }
    printf("\n unsorted array- ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    int pivot;
    printf("\nenter the pivot element- ");
    scanf("%d",&pivot);
    int fd[2];
    
    pipe(fd);
    
    int id =fork();
        if(id==0)
        { int res[n],j=0;
            for(int i=0;i<n;i++)
            {
                if(arr[i]<pivot)
                res[j++]=arr[i];
            }
            close(fd[0]);
            
            write(fd[1],&j,sizeof(int));
            write(fd[1],res,sizeof(int)*j);
            
            close(fd[1]);
            close(fd[1]);
            wait(0);

        }
        else{
            close(fd[1]);
            close(fd[1]);
            int ans[n];
            int c;
            
            read(fd[0],&c,sizeof(int));
            read(fd[0],ans,sizeof(int)*c);
            close(fd[0]);
            close(fd[0]);
            printf("lesser values printed by parent- ");
            for(int i=0;i<c;i++)
            {
                printf("%d ",ans[i]);
            }
            printf("\n");
        }
return 0;
}