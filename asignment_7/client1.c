#include <stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<ctype.h>

int main()
{
   int fd1;
   char *myfifo="/tmp/myfifo";
   mkfifo(myfifo,0666);
   char str[80];
   while(1)
   {
       fd1=open(myfifo,O_RDONLY);
       read(fd1,str,80);
       printf("Server: %s\n",str);
       close(fd1);
       
        
       
           int len=strlen(str);
            
            int countupper=0;
            int countlower=0;
            int countvowel=0;
            int special=0;
            int word=0;
            int digit=0;
            
            for(int i=0;i<len;i++)
            {
                if(isupper(str[i]))
                countupper++;
                if(islower(str[i]))countlower++;
                if(str[i]>=48 && str[i]<=57)digit++;
                

                 if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'|| str[i]=='E' || str[i]=='I' ||str[i]=='O'||str[i]=='U')
                {
                        countvowel++;
                }
                
                else if(str[i]>=32 &&str[i]<=47 || str[i]>=58 &&str[i]<=64 || str[i]>=91&&str[i]<=96 ||str[i]>=123&&str[i]<=126)
                special++;
                if(str[i]==32)
                word++;
            }
            word++;
           
            
            fd1=open(myfifo,O_WRONLY);
            write(fd1,&len,sizeof(int));

            write(fd1,&word,sizeof(int));

            write(fd1,&countvowel,sizeof(int));
            
            write(fd1,&countupper,sizeof(int));

            write(fd1,&special,sizeof(int));
            write(fd1,&countlower,sizeof(int));
            write(fd1,&digit,sizeof(int));
             
            
            close(fd1);
           
       
      
      
   }
   return 0;
}
