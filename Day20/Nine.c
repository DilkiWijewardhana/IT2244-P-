//Writer Process1
[2021ict60@fedora ~]$ vi Writer.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // Size of shared memory segment

int main(){
	key_t key = ftok ("shmfile", 60);
	int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
	if(shmid == -1)
	{
		perror("shmget");
		exit(1);
	}
	char *shmaddr = (char*) shmat(shmid, NULL, 0);
	if(shmaddr == (char*) -1 )
	{
		perror("shmat");
		exit(1);
	}
	printf("Write Data: ");
	fgets(shmaddr, SHM_SIZE, stdin);
	
	printf("Data written in memmory: %s/n", shmaddr);
	
	shmdt(shmaddr);
	
	return 0;
}

[2021ict60@fedora ~]$ gcc Writer.c -o Writer
[2021ict60@fedora ~]$ ./Writer
Write Data: Hello!
Data written in memmory: Hello!


//Reader
[2021ict60@fedora ~]$ vi Reader.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // Size of shared memory segment

int main(){
	key_t key = ftok ("shmfile", 60);
	int shmid = shmget(key, SHM_SIZE, 0666);
	if(shmid == -1)
	{
		perror("shmget");
		exit(1);
	}
	char *shmaddr = (char*) shmat(shmid, NULL, 0);
	if(shmaddr == (char*) -1 )
	{
		perror("shmat");
		exit(1);
	}
	printf("Data read from memmory: %s/n", shmaddr);
	
	shmdt(shmaddr);
	
	shmctl(shmid, IPC_RMID, NULL);
	
	return 0;
}

[2021ict60@fedora ~]$ gcc Reader.c -o Reader
[2021ict60@fedora ~]$ ./Reader
Data read from memmory: Hello!

-------------------------------------------------------------------
[2021ict60@fedora ~]$ vi Shared_memory_parent_child.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(){
	size_t size = 4096;
	char *shared_mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if(shared_mem == MAP_FAILED)
	{
		perror("mmap failed");
		exit(1);
	}
	
	pid_t pid = fork();
	if(pid == 0)
	{
		//Child process
		sprintf(shared_mem, "Hello from child!");
		printf("Child wrote: %s\n", shared_mem);
		exit(0);
	}
	else if(pid > 0)
	{
		//Parent process
		wait(NULL);    //wait foer child to0 finish
		printf("Parent read: %s\n", shared_mem);
		munmap(shared_mem, size);
	}
	else
	{
		perror("Fork failed");
		exit(1);
	}
	
	return 0;
}
[2021ict60@fedora ~]$ gcc Shared_memory_parent_child.c -o Shared_memory_parent_child
[2021ict60@fedora ~]$ ./Shared_memory_parent_child
Child wrote: Hello from child!
Parent read: Hello from child!