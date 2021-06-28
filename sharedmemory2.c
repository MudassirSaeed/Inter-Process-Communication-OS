#include<stdio.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<stdlib.h>
#define MAXSIZE 20
int main()
{
    int shmid;
    key_t keyA;
    int *shmA;
    int n=20;
    int c,i,count;
    FILE *ff;
    keyA = 2001;
    int array[20];

    if((shmid = shmget(keyA, MAXSIZE, IPC_CREAT | 0666)) < 0)
    {
        perror("Error: in creating shared memory i.e. shmget error\n");
    }
    if ((shmA = shmat(shmid, NULL, 0)) == (int *) -1)
    {
        perror("Error: in attaching shared memory i.e. shmat error\n");
    }
    ff = fopen("array.txt","r");  
		for(i=0;i<n;i++)
		{
			fscanf(ff, "%d", &array[i]);
		}
	fclose(ff);

	for ( c = 0 ; c < n ; c++ )
		{
			if ( array[c] == *shmA )    
			{
				printf("%d is present at location %d.\n", *shmA, c+1);
				count++;
			}
		}
		if ( count == 0 )
			printf("%d is not present in array.\n", *shmA);
		else
			printf("%d is present %d times in array.\n", *shmA, count);
	
		// linear search algorithm ends
		printf("searching complete....\n");
   
	*shmA=-1;


    exit(0);
    return 0;
}
