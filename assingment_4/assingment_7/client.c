#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int fd;
    char *myfifo="/myfifopipe";
    mkfifo(myfifo,0666);
    char arr1[100],arr2[100];
    while(1)
    {
      

        fd=open(myfifo,O_WRONLY);
        fgets(arr2,100,stdin);
        write(fd,arr2,strlen(arr2)+1);
        close(fd);

        fd=open(myfifo,O_RDONLY);
        read(fd,arr1,80);

        printf("%s\n",arr1);
        close(fd);


    }
    return 0;
}