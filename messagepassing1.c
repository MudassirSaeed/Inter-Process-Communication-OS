#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#define MAX 20 
  
// structure for message queue 
struct mystruct { 
    long mesg_type; 
    char mesg_text[100];
    int search; 
} message; 
  
int main() 
{ 
    key_t key; 
    int msgid; 
  
    // ftok to generate unique key 
    key = ftok("progfile", 65); 
  
    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    message.mesg_type = 1; 
  
    printf("Write Data : "); 
    fgets(message.mesg_text,MAX,stdin); 
  
   printf("Enter the number that you want to search:");
   scanf("%d",&message.search);
      
    // msgsnd to send message 
    msgsnd(msgid, &message, sizeof(message), 0); 
  
    // display the message 
    printf("Data send is : %s \n", message.mesg_text); 
    printf("Your Request For Searching Is  : %d \n", message.search);
    return 0; 
} 
