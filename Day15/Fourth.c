#include <stdio.h>
#include <unistd.h>  

int main(){
	//Fork
	fork();
	printf("Hello World!\n");
	
	return 0;
}

Day4_Example1:

Print numbers from 1 to 10 and
1 to 5 should be print by child process and
from 6 to should be parent process
calculate summation of those numbers

[2021ict60@fedora ~]$ vi Day4_Example1.c

#include <stdio.h>
#include <unistd.h>  

int main(){
	int f = fork();
	int parentSum = 0;
	int childSum = 0;
	if(f==0)
	{
		for(int i=1;i<=5;i++){
			printf("Child:%d\n",i);
			childSum = childSum +i;
		}
		printf("Child Process Sum: %d\n")
	}
	else
	{
		n=6;
	}
	for(int i=n;i<n+5;i++)
	{
		printf("%d",i);
	}
	printf("\n");
	
	return 0;
}

[2021ict60@fedora ~]$ gcc Day4_Example1.c -o Day4_Example1
[2021ict60@fedora ~]$ ./Day4_Example1

