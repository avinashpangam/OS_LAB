#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int n;
void createProcess(int t)
{
    if(t>n)return;
    int child_status;
    pid_t pid= fork();
    if(pid==0)
    {
       printf("Parent process creates %dth child\n",t);
        createProcess(t+1);
        printf("%dth child exited \n",t);
    }
    pid_t wpid=wait(&child_status);
    
    if(WIFEXITED(child_status))
    {
    if(t==1)
    {
    printf("parent of whole program exited\n");
    }
    exit (0);
    }
}

int main()
{
    
    printf("Enter a number: ");
    scanf("%d",&n);
    createProcess(1);

    return 0;
}
