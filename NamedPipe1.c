#include <fcntl.h>//O_create,O_EXEC
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
int main()
{

	int arr[20];
	int fd,c;
	int n=20;
	//char * myfifo = "/tmp/myfifo";

	fflush(stdin);
	mkfifo( "/tmp/myfifo", 0666);

	printf("\nWaiting for the other process\n");
    
	FILE *ff,*ff1;
	ff = fopen("arraynamed.txt","r"); //open the file in which numbers are stored

	for (c = 0 ; c < n  ; c++ )
	{
    	int num;
    	fscanf(ff, "%d",&num);
    	arr[c]=num;
	}
    
	fd = open("/tmp/myfifo", O_WRONLY);
	write(fd,arr,sizeof(arr));  //writes the data
	close(fd);

	//unlink(myfifo);
	return 0;
}

