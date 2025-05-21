//Find PID
[2021ict60@fedora ~]$ vi found_pid.c

#include <stdio.h>
#include <unistd.h>
int main()
{
	int f=fork();
	printf("\nHello World!\n");
	if(f==0)
	{
		printf("I'm Parent\n");
	}
	else
	{
		printf("I'm Child\n");
	}
	
	return 0;
}

[2021ict60@fedora ~]$ gcc found_pid.c -o found_pid
[2021ict60@fedora ~]$ ./found_pid

Hello World!
I'm Child

Hello World!
I'm Parent
-----------------------------------------------------------------

[2021ict60]$ vi fork.c

#include <stdio.h>
#include <unistd.h>
int main()
{
	fork();
	fork();
	printf("\nHello World!");
	
	return 0;
}

[2021ict60@fedora ~]$ gcc fork.c -o fork
[2021ict60@fedora ~]$ ./fork

Hello World!
Hello World!
Hello World!
-----------------------------------------------------------------

Example1:

[2021ict60]$ vi Example1.c

#include <stdio.h>
#include <unistd.h>
int main()
{
	int p = getpid();
	int f=fork();
	if(f==0)
	{
		printf("I'm Child\n");
		printf("My parent ID %d\n",getppid());
	}
	else
	{
		int f1 = fork();
		if(f1 == 0)
		{
			printf("I'm Sibling\n");
			printf("My parent ID %d\n",getppid());
		}
		else
		{
			printf("I'm Parent\n");
			printf("My ID %d\n",getpid());
			printf("My parent ID %d\n",getppid());
		}
	}
	return 0;
}

[2021ict60@fedora ~]$ gcc Example1.c -o Example1
[2021ict60@fedora ~]$ ./Example1
I'm Parent
My ID 27224
My parent ID 2629
I'm Child
My parent ID 27224
I'm Sibling
My parent ID 27224
