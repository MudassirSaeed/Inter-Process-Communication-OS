# Inter-Process-Communication-OS
This project contains the 4 methods to achieve the InterProcess Communication
1)Message passing:
  Message passing model allows multiple processes to read and write data to the message queue without being connected to each other.
  Messages are stored on the queue until their recipient retrieves them. Message queues are quite useful for interprocess communication
  and are used by most operating systems.
 
2) Ordinary Pipe:
   ordinary pipes are unidirectional, allowing only one-way communication-Ordinary pipes allow two processes to communicate in standard
   producer– consumer fashion: the producer writes to one end of the pipe (the write-end) and the consumer reads from the other end (the read-end).
   
3)Named Pipe:
  A named pipe is a named, one-way or duplex pipe for communication between the pipe server and one or more pipe clients.
  Named pipes can be used to provide communication between processes on the same computer or between processes on different computers across a network.
  
4)Shared Memory:
  The shared memory in the shared memory model is the memory that can be simultaneously accessed by multiple processes. This is done so that the processes
  can communicate with each other. All POSIX systems, as well as Windows operating systems use shared memory
