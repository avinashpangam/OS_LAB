
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>


int main(){
   int shmid,status;
   int *a;
   
   key_t key = ftok("shmfile",65);

   shmid=shmget(key,sizeof(int),0666|IPC_CREAT);

   if(shmid<0)
       printf("shared memory unsuccesful");
   
   a=(int*) shmat(shmid,0,0);
   *a=5;
   
   printf("Value of stocks initialised to 5 \n");

   while(1){
      printf("Current stock count is %d \n",*a);
      if(*a<=0)
         {
            printf("Producer adding 1 stock \n");
            (*a)++;
         }
    
      fflush(stdout);
      sleep(1);   
   } 

   
   shmdt(a);

}