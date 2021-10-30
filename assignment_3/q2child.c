
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc,char arr[]){
int n = atoi(arr[1]);
int a = atoi(arr[2]);
int b = atoi(arr[2]);
for(int i=2;i<n+2;i++){
    int x = atoi(arr[i]);
    if(x>=a){
    b = a;
    a = x;
    }
    else if(x>b) x = b;
}
printf("The second largest number is %d",b);
return 0;
}
