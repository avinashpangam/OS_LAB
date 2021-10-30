#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    char str[100];
    printf("Dear user enter the string -");
    scanf("%[^\n]s",str);
    
    int fd[2];
    pipe(fd);
    int id=fork();

        if(id==0)
        {
            int len=strlen(str);
            
            int countupper=0;
            int countvowel=0;
            int special=0;
            int word=0;
            
            for(int i=0;i<len;i++)
            {
                if(isupper(str[i]))
                countupper++;

                 if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'|| str[i]=='E' || str[i]=='I' ||str[i]=='O'||str[i]=='U')
                {
                        countvowel++;
                }
                
                else if(str[i]>=32 &&str[i]<=47 || str[i]>=58 &&str[i]<=64 || str[i]>=91&&str[i]<=96 ||str[i]>=123&&str[i]<=126)
                special++;
                if(str[i]==32)
                word++;
            }
            close(fd[0]);
            write(fd[1],&len,sizeof(int));

            write(fd[1],&word,sizeof(int));

            write(fd[1],&countvowel,sizeof(int));
            
            write(fd[1],&countupper,sizeof(int));

            write(fd[1],&special,sizeof(int));
            close(fd[1]);
            exit(0);
        

                
        }
        else
        {

            wait(0);
            int len,word,vow,upp,special;
            printf("\n Parent  printing values-");
            close(fd[1]);
            
            read(fd[0],&len,sizeof(int));

            read(fd[0],&word,sizeof(int));

            read(fd[0],&vow,sizeof(int));

            read(fd[0],&upp,sizeof(int));

            read(fd[0],&special,sizeof(int));
            close(fd[0]);
            printf("\nEntered string is-");
             printf(" %s",str);  
            printf("\n string length- %d",len);
            printf("\n word count - %d",word+1);
            printf("\n number of vowels- %d",vow);
            printf("\n number of upper case letters-  %d",upp);
            printf("\n number of special characters- %d",special);
            printf("\n");

        }
        return 0;

}