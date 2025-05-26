Example1: 

[2021ict60@fedora ~]$ vi Day6_Example1.c

#include <stdio.h>
#include <stdlib.h> //for exait()
#include <unistd.h>  //for sleep()

int main(){
	printf("Program started.\n");
	
	printf("Sleepingfor 3seconds...\n");
	sleep(3); //pause for 3seconds
	
	printf("Exiting the program.\n");
	exit(0); // clean exit
}

[2021ict60@fedora ~]$ gcc Day6_Example1.c -o Day6_Example1
[2021ict60@fedora ~]$ ./Day6_Example1
Program started.
Sleepingfor 3seconds...
Exiting the program.


Example2:

[2021ict60@fedora ~]$ vi Day6_Example2.c

#include <stdio.h>
#include <stdlib.h> //for exait()
#include <unistd.h>  //for fork(), sleep()
#include <sys/wait.h> //for wait(

int main(){
	pid_t pid;
	
	printf("Parent process started.PID: %d\n", getpid());
	
	pid = fork(); // create a new child process
	if(pid<0)
	{
		perror("Fork faild!");
		exit(1);
	}
	
	if(pid==0)
	{
		//child process
		printf("Child Process.PID: %d, sleeping for 2seconds..\n");
		sleep(2);
		printf("Child process exiting.\n");
		exit(0); // child exit with status 0 
	}
	else
	{
		//parent process
		int status;
		printf("Parent waiting for child to finish..\n");
		wait(&status);
		if(WIFEXITED(status)){
			printf("Child exited with status: %d\n",(WEXITSTATUS(status)));
		}
		else
		{
			printf("Child did not exit normally./n");
		}
		printf("Parent process ending!");
	}
	return 0;
}

[2021ict60@fedora ~]$ gcc Day6_Example2.c -o Day6_Example2
[2021ict60@fedora ~]$ ./Day6_Example2
Parent process started.PID: 11993
Parent waiting for child to finish..
Child Process.PID: 0, sleeping for 2seconds..
Child process exiting.
Child exited with status: 0
Parent process ending!

Example3:

First child: Slept for 1second
Second child:  Slept for 3second
Parent: Both chldren have finished

[2021ict60@fedora ~]$ vi Day6_Example3.c

#include <stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h>  // for fork(), sleep()
#include <sys/wait.h> // for wait()

int main() {
    pid_t pid1, pid2;

    printf("Parent process started. PID: %d\n", getpid());

    pid1 = fork(); 
    if (pid1 < 0) {
        perror("Fork for first child failed!");
        exit(1);
    }

    if (pid1 == 0) {
        printf("First child. PID: %d, sleeping for 1 second..\n", getpid());
        sleep(1); 
        printf("First child process exiting.\n");
        exit(0); 
    } else {
        pid2 = fork(); 
        if (pid2 < 0) {
            perror("Fork for second child failed!");
            exit(1);
        }

        if (pid2 == 0) {
            printf("Second child. PID: %d, sleeping for 3 seconds..\n", getpid());
            sleep(3); 
            printf("Second child process exiting.\n");
            exit(0); 
        } else {
            int status1, status2;
            printf("Parent waiting for both children to finish..\n");

            waitpid(pid1, &status1, 0);
            if (WIFEXITED(status1)) {
                printf("First child exited with status: %d\n", WEXITSTATUS(status1));
            } else {
                printf("First child did not exit normally.\n");
            }

            waitpid(pid2, &status2, 0);
            if (WIFEXITED(status2)) {
                printf("Second child exited with status: %d\n", WEXITSTATUS(status2));
            } else {
                printf("Second child did not exit normally.\n");
            }

            printf("Parent: Both children have finished.\n");
        }
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc Day6_Example3.c -o Day6_Example3
[2021ict60@fedora ~]$ ./Day6_Example3
Parent process started. PID: 14533
Parent waiting for both children to finish..
First child. PID: 14534, sleeping for 1 second..
Second child. PID: 14535, sleeping for 3 seconds..
First child process exiting.
First child exited with status: 0
Second child process exiting.
Second child exited with status: 0
Parent: Both children have finished.

Example4:

First child: Sleeps for 2seconds, exit with status 2.
Second child:  Sleeps for 1seconds, exit with status 1.
Parent: Waits twice, and prints wicth child(by PID or exit code) finished firts and second

[2021ict60@fedora ~]$ vi Day6_Example4.c

#include <stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h>  // for fork(), sleep()
#include <sys/wait.h> // for wait()

int main() {
    pid_t pid1, pid2;

    printf("Parent process started. PID: %d\n", getpid());

    pid1 = fork(); 
    if (pid1 < 0) {
        perror("First child failed!");
        exit(1);
    }

    if (pid1 == 0) {
        printf("First child. PID: %d, sleeping for 2 seconds..\n", getpid());
        sleep(2); 
        printf("First child process exiting with status 2.\n");
        exit(2); 
    } else {
        pid2 = fork(); 
        if (pid2 < 0) {
            perror("Second child failed!");
            exit(1);
        }

        if (pid2 == 0) {
            printf("Second child. PID: %d, sleeping for 1 second..\n", getpid());
            sleep(1); 
            printf("Second child process exiting with status 1.\n");
            exit(1); 
        } else {
            int status1, status2;
            printf("Parent waiting for both children to finish..\n");

            waitpid(pid1, &status1, 0);
            if (WIFEXITED(status1)) {
                printf("First child (PID: %d) exited with status: %d\n", pid1, WEXITSTATUS(status1));
            } else {
                printf("First child did not exit normally.\n");
            }

            waitpid(pid2, &status2, 0);
            if (WIFEXITED(status2)) {
                printf("Second child (PID: %d) exited with status: %d\n", pid2, WEXITSTATUS(status2));
            } else {
                printf("Second child did not exit normally.\n");
            }

            if (WEXITSTATUS(status1) == 2 && WEXITSTATUS(status2) == 1) {
                printf("Parent: Second child finished first (PID: %d).\n", pid2);
                printf("Parent: First child finished second (PID: %d).\n", pid1);
            } else if (WEXITSTATUS(status1) == 1 && WEXITSTATUS(status2) == 2) {
                printf("Parent: First child finished first (PID: %d).\n", pid1);
                printf("Parent: Second child finished second (PID: %d).\n", pid2);
            }
            printf("Parent: Both children have finished.\n");
        }
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc Day6_Example4.c -o Day6_Example4
[2021ict60@fedora ~]$ ./Day6_Example4
Parent process started. PID: 15134
Parent waiting for both children to finish..
First child. PID: 15135, sleeping for 2 seconds..
Second child. PID: 15136, sleeping for 1 second..
Second child process exiting with status 1.
First child process exiting with status 2.
First child (PID: 15135) exited with status: 2
Second child (PID: 15136) exited with status: 1
Parent: Second child finished first (PID: 15136).
Parent: First child finished second (PID: 15135).
Parent: Both children have finished.

Example5:

The parent creates a child process
The child creates a grandchild process
The grandchild sleep 2 seconds and exit with status 2.
The child waits for the grandchild, prints its exit status,then exits with status 55.

[2021ict60@fedora ~]$ vi Day6_Example5.c

#include <stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h>  // for fork(), sleep()
#include <sys/wait.h> // for wait()

int main() {
    pid_t pid_child, pid_grandchild;

    printf("Parent process started. PID: %d\n", getpid());

    pid_child = fork(); 
    if (pid_child < 0) {
        perror("Fork for child failed!");
        exit(1);
    }

    if (pid_child == 0) {
        printf("Child process. PID: %d, creating a grandchild.\n", getpid());

        pid_grandchild = fork(); 
        if (pid_grandchild < 0) {
            perror("Fork for grandchild failed!");
            exit(1);
        }

        if (pid_grandchild == 0) {
            printf("Grandchild process. PID: %d, sleeping for 2 seconds..\n", getpid());
            sleep(2); 
            printf("Grandchild process exiting with status 2.\n");
            exit(2); 
        } else {
            int status_grandchild;
            waitpid(pid_grandchild, &status_grandchild, 0);
            if (WIFEXITED(status_grandchild)) {
                printf("Child process: Grandchild exited with status: %d\n", WEXITSTATUS(status_grandchild));
            } else {
                printf("Child process: Grandchild did not exit normally.\n");
            }

            printf("Child process exiting with status 55.\n");
            exit(55);
        }
    } else {
        int status_child;
        waitpid(pid_child, &status_child, 0);
        if (WIFEXITED(status_child)) {
            printf("Parent process: Child exited with status: %d\n", WEXITSTATUS(status_child));
        } else {
            printf("Parent process: Child did not exit normally.\n");
        }

        printf("Parent process ending.\n");
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc Day6_Example5.c -o Day6_Example5
[2021ict60@fedora ~]$ ./Day6_Example5
Parent process started. PID: 15407
Child process. PID: 15408, creating a grandchild.
Grandchild process. PID: 15409, sleeping for 2 seconds..
Grandchild process exiting with status 2.
Child process: Grandchild exited with status: 2
Child process exiting with status 55.
Parent process: Child exited with status: 55
Parent process ending.