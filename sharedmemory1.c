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
    int search;
    keyA = 2001;
    
    if((shmid = shmget(keyA, MAXSIZE, IPC_CREAT | 0666)) < 0)
    {
        perror("Error: in creating shared memory i.e. shmget error\n");
    }
    if ((shmA = shmat(shmid, NULL, 0)) == (int *) -1)
    {
        perror("Error: in attaching shared memory i.e. shmat error\n");
    }
    printf("Enter the elemrnt you want to search");
    scanf("%d", &search);
   *shmA = search;
 
     while ((*shmA) != -1)
    {
    }
    
    
    exit(0);
    return 0;
}

