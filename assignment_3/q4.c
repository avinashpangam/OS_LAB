#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int n;
	int i=0,j=0;
	printf("How many filename you want to enter ? ");
	scanf("%d",&n);
	char str[n][10];
	printf("Enter Filename and Press Enter\n");
	for(i =0; i < n; i++)
    scanf("%s", str[i]);
    for(j=0;j<n;j++)
	{
		pid_t pid = fork();
		if(pid!=0)
		{
			printf("Parent PID %d, created a child %d \n",getpid() ,pid);
		}
		else
		{
			char *path="./reader";
			char *argv[]={"./reader",str[j], NULL};
			execv(path, argv);
		}
	}
	return 0;
}
