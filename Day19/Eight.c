//MessageQueue

[2021ict60@fedora ~]$ vi MessageQueue.c

#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGKEY 1111
#define MAX_NAME_LEN 100
#define MAX_REGNO_LEN 100

struct person {
    long mtype; // Message type
    int age;
    char name[MAX_NAME_LEN];
    char regno[MAX_REGNO_LEN];
};

int main() {
    int msqid;
    struct person p1, p2;
    int f = fork();

    if (f == 0) {
        // Child process: Receiver
        msqid = msgget(MSGKEY, IPC_CREAT | 0666); 
        if (msqid == -1) {
            perror("msgget failed");
            exit(EXIT_FAILURE);
        }

        int msg_size = sizeof(struct person) - sizeof(long);

        if (msgrcv(msqid, &p2, msg_size, 0, 0) == -1) {
            perror("msgrcv failed");
            exit(EXIT_FAILURE);
        } else {
            printf("Received Name: %s\n", p2.name);
            printf("Received RegNo: %s\n", p2.regno);
            printf("Received Age: %d\n", p2.age);
        }

        if (msgctl(msqid, IPC_RMID, NULL) == -1) {
            perror("msgctl failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process: Sender
        msqid = msgget(MSGKEY, IPC_CREAT | 0666);
        if (msqid == -1) {
            perror("msgget failed");
            exit(EXIT_FAILURE);
        }

        p1.mtype = 1;

        printf("Enter Name: ");
        scanf("%s", p1.name);

        printf("Enter RegNo: ");
        scanf("%s", p1.regno);

        printf("Enter Age: ");
        scanf("%d", &p1.age);

        int msg_size = sizeof(struct person) - sizeof(long);

        if (msgsnd(msqid, &p1, msg_size, IPC_NOWAIT) == -1) {
            perror("msgsnd failed");
        } else {
            printf("Message sent successfully.\n");
        }

        exit(0);
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc MessageQueue.c -o MessageQueue
[2021ict60@fedora ~]$ ./MessageQueue
Enter Name: Dilki
Enter RegNo: 2021ICT60
Enter Age: 22
Message sent successfully.
Received Name: Dilki
Received RegNo: 2021ICT60
Received Age: 22

-----------------------------------------------------------------------
[2021ict60@fedora ~]$ vi Send.c

//send 

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10


//structure for message queue
struct mesg_buffer {
long mesg_type;
char mesg_text[100];
} message;
int main()
{
	key_t key;
	int msgid;
	
	//ftok to generate unique key
	
	key = ftok("progfile",60);
	
	//msgget creates a message queue and returns identifier
	
	msgid = msgget(key, 0666 | IPC_CREAT);
	message.mesg_type = 1;
	printf("Write Data : "); 
	fgets(message.mesg_text,MAX,stdin);
	//msgsnd to send message
	msgsnd(msgid, &message, sizeof(message), 0);
	//display the message
	printf("Data send is : %s \n", message.mesg_text);
	return 0;
}

[2021ict60@fedora ~]$ gcc Send.c -o Send
[2021ict60@fedora ~]$ ./Send
Write Data : Hello..!
Data send is : Hello..!


[2021ict60@fedora ~]$ vi Receive.c

//receive

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//structure for message queue
struct mesg_buffer {
long mesg_type;
char mesg_text[100];
} message;
int main()
{
	key_t key;
	int msgid;
	
	//ftok to generate unique key
	
	key = ftok("progfile",60);
	
	//msgget creates a message queue and returns identifier
	
	msgid = msgget(key, 0666 | IPC_CREAT);
	//msgrcv to receive message
	msgrcv(msgid, &message, sizeof(message), 1, 0);
	//display the message
    printf("Data Receive is : %s \n",message.mesg_text);
	
	//to destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
	
}

[2021ict60@fedora ~]$ gcc Receive.c -o Receive
[2021ict60@fedora ~]$ ./Receive
Data Receive is : Hello..!

-----------------------------------------------------------------------

Exercise1:

//IPC using Message Queue

read input from the parent process
Enter Name: hi
Enter RegNo: 2314
Enter Age: 24

Message sent successfully.

Give the output from the child process

Received Name: hi
Received RegNo: 2314
Received Age: 24

------------------------------------------------------------------------------------------
[2021ict60@fedora ~]$ vi Exercise1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>  

#define MSGKEY 1111
#define MAX_NAME_LEN 30

struct msg_buffer {
    long msg_type;        
    char name[MAX_NAME_LEN];
    int reg_no;
    int age;
};

#define MSGSIZE (sizeof(struct msg_buffer) - sizeof(long))

int main() {
    key_t key;
    int msgid;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }
    
    struct msg_buffer msg;

    if (fork() == 0) { 
        if (msgrcv(msgid, &msg, MSGSIZE, 1, 0) == -1) {
            perror("msgrcv failed");
            exit(EXIT_FAILURE);
        }
        printf("\nReceived Name: %s\n", msg.name);
        printf("Received RegNO: %d\n", msg.reg_no);
        printf("Received Age: %d\n", msg.age);

        if (msgctl(msgid, IPC_RMID, NULL) == -1) {
            perror("msgctl failed");
            exit(EXIT_FAILURE);
        }
        exit(0); 
    } else {
        msg.msg_type = 1;

        printf("Enter Name: ");
        scanf("%29s", msg.name);  
        printf("Enter RegNO: ");
        scanf("%d", &msg.reg_no);
        printf("Enter Age: ");
        scanf("%d", &msg.age);

        if (msgsnd(msgid, &msg, MSGSIZE, 0) == -1) {
            perror("msgsnd failed");
            exit(EXIT_FAILURE);
        }
        printf("\nMessage sent successfully.\n");

        wait(NULL);
    }

    return 0;
}


[2021ict60@fedora ~]$ gcc Exercise1.c -o Exercise1
[2021ict60@fedora ~]$ ./Exercise1
Enter Name: Dilki
Enter RegNO: 2021060
Enter Age: 22

Message sent successfully.

Received Name: Dilki
Received RegNO: 2021060
Received Age: 22