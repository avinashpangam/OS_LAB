#include <stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
   
   int fd;
   char *myfifo="/tmp/myfifo";
   mkfifo(myfifo,0666);
   char arr2[80];
   while(1)
   {
       fd=open(myfifo,O_WRONLY);
       printf("Write the sentence: \n");
       fgets(arr2,80,stdin);
       write(fd,arr2,strlen(arr2)+1);
       close(fd);
       
       fd=open(myfifo,O_RDONLY);
       int len,vowel,countupper,countlower,digit,special,word;
       read(fd,&len,sizeof(int));
       read(fd,&word,sizeof(int));
       read(fd,&vowel,sizeof(int));
        read(fd,&countupper,sizeof(int));
         read(fd,&special,sizeof(int));
          read(fd,&countlower,sizeof(int));
           read(fd,&digit,sizeof(int));
        printf("Details fetched!! from client\n");
        printf("Length: %d ,Words: %d ,vowel:%d ,countupper: %d ,special: %d ,countlower: %d,digit: %d\n",len,word,vowel,countupper,special,countlower,digit);
       
      
       close(fd);
       
   }
   return 0;
}

