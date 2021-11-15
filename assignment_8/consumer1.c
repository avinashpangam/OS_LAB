#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
   int shmid,status;
   int *b;
   
   key_t key = ftok("shmfile",65);
   shmid=shmget(key,sizeof(int),0666|IPC_CREAT);

   b=(int*)shmat(shmid,0,0);
 
   int count=*b;
   while(count>0){
       printf("consumer-1 taking one prod \n");
       count--;
       (*b)--;
       fflush(stdout);
       count=*b;
       sleep(1);
   }    
   
   printf("no goods found");
   



  
}
