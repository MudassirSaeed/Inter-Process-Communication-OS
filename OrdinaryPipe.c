#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
	int fd[2], nbytes;
	pid_t childpid;
	int arr[20],i,j,n=20;
	FILE *ff;
	int  c,search, count = 0;
	printf("Enter the number to search\n");
	scanf("%d",&search);

	pipe(fd); // declares pipe structure

	if((childpid = fork()) == -1)
	{	
		perror("fork");
  	}

	if(childpid == 0)
	{
		// Child process closes up input side of pipe 
   		close(fd[0]);
		ff = fopen("array.txt","r");  //open the file in which numbers are stored
		for(i=0;i<n;i++)
		{
			fscanf(ff, "%d", &arr[i]);
		}

		fclose(ff);  // close the file
		/* Send "array" through the output side of pipe */

		write(fd[1], &arr, sizeof(arr));
	}
	
	else
	{
		printf("reading and searching the data....\n");
		/* Parent process closes up output side of pipe */
		close(fd[1]);
		/* Read in a array from the pipe */
		nbytes = read(fd[0], &arr, sizeof(arr));
		// linear search algorithm starts    
		for ( c = 0 ; c < n ; c++ )
		{
			if ( arr[c] == search )    
			{
				printf("%d is present at location %d.\n", search, c+1);
				count++;
			}
		}
		if ( count == 0 )
			printf("%d is not present in array.\n", search);
		else
			printf("%d is present %d times in array.\n", search, count);
	
		// linear search algorithm ends
		printf("searching complete....\n");
		
	}

return(0);

}


