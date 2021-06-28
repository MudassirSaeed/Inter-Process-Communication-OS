#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
  
// structure for message queue 
struct mystruct { 
    long mesg_type; 
    char mesg_text[100]; 
    int search;
} message; 
  
int main() 
{ 
    key_t key; 
    int msgid,c,i,count;
    int n=20;
    int array[20]; 
    FILE *ff;
    // ftok to generate unique key 
    key = ftok("progfile", 65); 
  
    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
  
    // msgrcv to receive message 
    msgrcv(msgid, &message, sizeof(message), 1, 0); 
  
    // display the message 
    printf("Message Received is : %s \n",message.mesg_text);
    printf("Number that is recieved to search is : %d \n", message.search); 
    ff = fopen("array.txt","r");  
		for(i=0;i<n;i++)
		{
			fscanf(ff, "%d", &array[i]);
		}
	fclose(ff);

	for ( c = 0 ; c < n ; c++ )
		{
			if ( array[c] == message.search )    
			{
				printf("%d is present at location %d.\n", message.search, c+1);
				count++;
			}
		}
		if ( count == 0 )
			printf("%d is not present in array.\n", message.search);
		else
			printf("%d is present %d times in array.\n", message.search, count);
	
		// linear search algorithm ends
		printf("searching complete....\n");
    // to destroy the message queue 
    msgctl(msgid, IPC_RMID, NULL); 
  
    return 0; 
} 
