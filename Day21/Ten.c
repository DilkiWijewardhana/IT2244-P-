[2021ict60@fedora ~]$ vi pipe.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main()
{
	char inbuf[MSGSIZE];
	int p[2], i;
	
	if(pipe(p) < 0)
		exit (1);
	
	/* continued */
	/* wtrite pipe */
	
	write(p[1], msg1, MSGSIZE);
	write(p[1], msg2, MSGSIZE);
	write(p[1], msg3, MSGSIZE);

	for(i = 0; i < 3; i++)
	{
		/* read pipe */
		read(p[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc pipe.c -o pipe
[2021ict60@fedora ~]$ ./pipe
hello, world #1
hello, world #2
hello, world #3

//Another Way//

[2021ict60@fedora ~]$ vi pipe2.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MSGSIZE 16

char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main()
{
	char inbuf[MSGSIZE];
	int p[2], pid, nbytes;
	
	if(pipe(p) < 0)
		exit (1);
	
	/* continued */
	if((pid == fork()) > 0)
	{
	write(p[1], msg1, MSGSIZE);
	write(p[1], msg2, MSGSIZE);
	write(p[1], msg3, MSGSIZE);
	
	//Adding this line will
	//not hang the program
	//close(p[1]);
	wait(NULL);
	}
	
	else
	{
		//Adding this line will
		//not hang the program
		//close(p[1]);
		while((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)
			printf("%s\n",inbuf);
		
		if(nbytes != 0)
			exit(2);
		printf("Finished reading\n");
	}
    return 0;
}

[2021ict60@fedora ~]$ gcc pipe2.c -o pipe2
[2021ict60@fedora ~]$ ./pipe2
hello, world #1
hello, world #2
hello, world #3
---------------------------------------------------------------------

Exercise1:

1.Get two input from user(//parent process)
name:
reg no:
age:

2.Print the output from the child(//child process)
name:abc
reg no:2021/ict/01
age:25

[2021ict60@fedora ~]$ vi D5_Exercise1.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 

int main() {
    char name[50];
    char reg_no[50];
    int age;

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin); 

    printf("Enter reg number: ");
    fgets(reg_no, sizeof(reg_no), stdin); 

    printf("Enter age: ");
    scanf("%d", &age);
    getchar(); 

    pid_t pid = fork(); 

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) { 
        printf("\nChild Process Output:\n");
        printf("Name: %s", name);
        printf("Reg No: %s", reg_no);
        printf("Age: %d\n", age);
    }
    else {
        wait(NULL); 
        printf("\nParent Process: Child completed execution.\n");
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc  D5_Exercise1.c -o D5_Exercise1
[2021ict60@fedora ~]$ ./D5_Exercise1
Enter name: abc
Enter reg number: 2021/ict/01
Enter age: 25

Child Process Output:
Name: abc
Reg No: 2021/ict/01
Age: 25

Parent Process: Child completed execution.
------------------------------------------------------------------------

Exercise2:

Step 1--->Parent process:- Get input from user.
Step 2--->Sending those inputs to child process.
Step 3--->Child process getting those inputs from parent and doing calculations.
			Circle-r
			Triangle-h
			Rectangle-l
			
Step 4--->Send the calculated values to parent.
Step 5--->Parent prints the output.

[2021ict60@fedora ~]$ vi D5_Exercise2.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

void calculate_areas(float radius, float base, float height, float side, float *area_circle, float *area_triangle, float *area_square) {
*area_circle = M_PI * radius * radius;
*area_triangle = 0.5 * base * height;
*area_square = side * side;
}

	int main() {
	int pipe1[2]; // Parent to Child
	int pipe2[2]; // Child to Parent

	pipe(pipe1);
	pipe(pipe2);

	pid_t pid = fork();

	if (pid == 0) 
	{
		// Child process
		close(pipe1[1]); // Close write end of pipe1
		close(pipe2[0]); // Close read end of pipe2

		float data[4];  // radius, base, height, side
		read(pipe1[0], data, sizeof(data));

		float area_circle, area_triangle, area_square;
		calculate_areas(data[0], data[1], data[2], data[3], &area_circle, &area_triangle, &area_square);

		float result[3] = {area_circle, area_triangle, area_square};
		write(pipe2[1], result, sizeof(result));
	} 
	else 
	{
		// Parent process
		close(pipe1[0]); // Close read end of pipe1
		close(pipe2[1]); // Close write end of pipe2

		float radius, base, height, side;
		printf("Enter radius of circle: ");
		scanf("%f", &radius);

		printf("Enter base and height of triangle: ");
		scanf("%f %f", &base, &height);

		printf("Enter side of square: ");
		scanf("%f", &side);

		float inputs[4] = {radius, base, height, side};
		write(pipe1[1], inputs, sizeof(inputs));

		float results[3]; // To hold areas
		read(pipe2[0], results, sizeof(results));

		printf("\n--- Area Results from Child ---\n");
		printf("Circle: %.2f\n", results[0]);
		printf("Triangle: %.2f\n", results[1]);
		printf("Square: %.2f\n", results[2]);
	}

	return 0;
}
		
[2021ict60@fedora ~]$ vi D5_Exercise2.c
[2021ict60@fedora ~]$ gcc  D5_Exercise2.c -o D5_Exercise2
[2021ict60@fedora ~]$ ./D5_Exercise2
Enter radius of circle: 3
Enter base and height of triangle: 4 5
Enter side of square: 6

--- Area Results from Child ---
Circle: 28.27
Triangle: 10.00
Square: 36.00