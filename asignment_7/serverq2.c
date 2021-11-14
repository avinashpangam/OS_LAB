#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int fd;
    char * myfifo = "myfifo";
    mkfifo(myfifo, 0666);

    char arr1[100];
    int roll;
    while (1)
    {
        fd = open(myfifo, O_WRONLY);
        fgets(arr1, 100, stdin);
        write(fd, arr1, strlen(arr1)+1);
        close(fd);

        fd = open(myfifo, O_RDONLY);
        read(fd,&roll,sizeof(int));
        printf("Client: Name asked for roll number: %d",roll);
        close(fd);
        FILE* file = fopen("Studentdetails.txt", "r"); 
    	char line[256]; 
    	int i = 0; 
    	while (fgets(line, sizeof(line), file)) { 	
        	i++; 
        	if(i == roll ) { 
           		fd = open(myfifo, O_WRONLY);
			write(fd,line,sizeof(line));
			close(fd);
			break;   
        	}	 
    	} 
    	char er[] = "Roll number not found";
    	if(i!=roll)
    	{
    		fd = open(myfifo, O_WRONLY);
		write(fd,er,sizeof(er));
		close(fd);
    	}
    }
    return 0;
}
