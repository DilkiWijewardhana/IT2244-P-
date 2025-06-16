//Single Thread
[2021ict60@fedora ~]$ vi Thread.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//A normal C function that is executed as a thread 
//when its name is specified in pthread_create()
void *helloworld(void *vargp)
{
	sleep(1);
	printf("Hello World!\n");
	return NULL;
}
int main(){
	pthread_t thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, helloworld, NULL);
	pthread_join(thread_id,NULL);
	printf("After Thread\n");
	exit(0);
}

[2021ict60@fedora ~]$ gcc Thread.c -o Thread
[2021ict60@fedora ~]$ ./Thread
Before Thread
Hello World!
After Thread
--------------------------------------------------------------------

//Multi Thread

[2021ict60@fedora ~]$ vi Multi_Thread.c

#include <stdio.h>
#include <pthread.h>

//Functio to be executed by the thread 
void* print_message(void * arg)
{
	char* message = (char*)arg;
	printf("%s\n", message);
	return NULL;
} 

int main(){
	pthread_t thread1, thread2;
	
	//Create first Thread
	pthread_create(&thread1, NULL, print_message,"Hello from Thread 1!");
	
	//Create second Thread
	pthread_create(&thread2, NULL, print_message,"Hello from Thread 2!");
	
	//Wait for both threads to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	printf("Both threads copleted.\n");
	return 0;
}

[2021ict60@fedora ~]$ gcc Multi_Thread.c -o Multi_Thread
[2021ict60@fedora ~]$ ./Multi_Thread
Hello from Thread 1!
Hello from Thread 2!
Both threads copleted.
--------------------------------------------------------------------

[2021ict60@fedora ~]$ vi Multi_Thread2.c

#include <stdio.h>
#include <pthread.h>

void* print_message(void* arg)
{
	char* message = (char*)arg;
	printf("%s\n", message);
	return NULL;
} 

int main(){
	pthread_t threads[3];
	char* message[] = {
		"Thread 1 says hi!",
		"Thread 2 says hello!",
		"Thread 3 says hey!"
	};
	
	for(int i = 0; i < 3; i++)
	{
		pthread_create(&threads[i], NULL, print_message, message[i]);
	}
	for(int i = 0; i < 3; i++)
	{
		pthread_join(threads[i], NULL);
	}
	printf("All threads done.\n");
	return 0;
}

[2021ict60@fedora ~]$ gcc Multi_Thread2.c -o Multi_Thread2
[2021ict60@fedora ~]$ ./Multi_Thread2
Thread 1 says hi!
Thread 2 says hello!
Thread 3 says hey!
All threads done.