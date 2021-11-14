#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int main(){
    int fd1;
    char * myfifo = "myfifo";
    mkfifo(myfifo, 0666);

    char str1[100], str2[80];
    int roll;
    while (1){
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, 100);
        printf("Server: %s\n", str1);
        close(fd1);
       
        fd1 = open(myfifo,O_WRONLY);
        scanf("%d",&roll);
        write(fd1,&roll,sizeof(int));
        close(fd1);
        
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str2, 80);
        printf("Server: Name - %s\n", str2);
        close(fd1);
    }
    return 0;
}
