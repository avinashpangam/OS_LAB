
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
int n;
printf("Enter the size of the array\n");
scanf("%d",&n);
char *array[n];
array[0] = "./q2Child";
array[1] = (char)n;
for(int i=0;i<n;i++){
  int x;
  scanf("%d",&x);
  array[i+2] = (char)x;
}
array[n+2] = "NULL";
char *path = "./q2child";
if(fork()==0) execve(n,path,array);
printf("Error in execve call");
return 0;
}
