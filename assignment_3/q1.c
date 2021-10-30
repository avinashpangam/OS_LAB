#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
FILE *fileptr1,*fileptr2,*fileptr3;
fileptr1 = fopen("text1.txt","r");
fileptr2 = fopen("text1.txt","a");
int child_status;
pid_t pid=fork();
if(pid!=0)
{
fprintf(fileptr2,"%s","Hi I am Parent\n");
wait(&child_status);
fclose(fileptr1);
fclose(fileptr2);
fileptr3 = fopen("text1.txt","r");
printf("\nContents of File:\n");
char ch;
ch=fgetc(fileptr3);
while(ch!=EOF)
{
printf("%c",ch);
ch=fgetc(fileptr3);
}
fclose(fileptr3);
}
else
{
fprintf(fileptr2,"%s","Hi I am Child\n");
exit(0);
}
return 0;
}
