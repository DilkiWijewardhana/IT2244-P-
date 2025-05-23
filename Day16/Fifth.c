Example1:

[2021ict60@fedora ~]$ vi D5_Example1.c

#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("\n---A Process---\n");
	printf("\nI'm A.My ID %d\n",getpid());


	int n1;
	printf("Enter first number: ");
	scanf("%d", &n1);
	int n2;
	printf("Enter second number: ");
	scanf("%d", &n2);
	int n3;
	printf("Enter third number: ");
	scanf("%d", &n3);
			
	int p=getpid();
    int f=fork();
			
	if(f>0)
		{
			printf("\n---B Process---\n");
			printf("\nI'm B.My ID %d\n",getpid());
				
			int number = n1;
			int factorial = 1;

				if (number < 0) {
					printf("It is a negative number\n");
				} 
				else 
				{
					for (int i = 1; i <= number; i++) {
						factorial *= i;
					}
					printf("Factorial of %d is: %d\n", number, factorial);
				}
		}
		else if(f==0)
		{
			printf("\n---C Process---\n");
			printf("\nI'm C.My ID %d\n",getpid());
				
			int i, first = 0, second = 1, next;

			if (n2 <= 0)
			{
				printf("Please enter a positive number.\n");
				return 1;
			}

			printf("Fibonacci series: ");

			for (i = 1; i <= n2; i++) 
			{
				if (i == 1) 
				{
					printf("%d ", first);
					continue;
				}
				if (i == 2) 
				{
					printf("%d ", second);
					continue;
				}
				next = first + second;
				first = second;
				second = next;
				printf("%d ", next);
			}
			printf("\n");

			int f1=fork();
			if(f1==0)
			{
				printf("\n---D Process---\n");
				printf("\nI'm C.My ID %d\n",getpid());
					
				int i, isPrime = 1;

				if (n1 <= 1) 
					isPrime = 0;

				for (i = 2; i * i <= n1; i++) 
				{
					if (n1 % i == 0) 
					{
						isPrime = 0;
						break;
					}
				}

				if (isPrime)
				{
					printf("%d is prime\n", n1);
				}
				else
				{
					printf("%d is NOT prime\n", n1);
				}
			}	
		}
	return 0;
}

[2021ict60@fedora ~]$ gcc D5_Example1.c -o D5_Example1.c
[2021ict60@fedora ~]$ ./D5_Example1.c


Example2:

[2021ict60@fedora ~]$ vi D5_Example2.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);  // Use &n to store the value at the address of n

    int child1 = fork();  // First fork

    if (child1 == 0) {
        // Child1 process
        printf("Child1 -> PID: %d \t PPID: %d\n", getpid(), getppid());

        // Factorial calculation
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Factorial of %d is %d\n", n, fact);

        // Child of child1 - for Fibonacci
        int child5 = fork();
        if (child5 == 0) {
            printf("Child5 -> PID: %d \t PPID: %d\n", getpid(), getppid());

            int a = 0, b = 1, fib = 0;
            for (int j = 1; j < n; j++) {
                fib = a + b;
                a = b;
                b = fib;
            }
            printf("Fibonacci term at position %d is %d\n", n, (n == 0) ? 0 : (n == 1) ? 1 : fib);
        } else {
            wait(NULL);  // Wait for child5
        }

    } else {
        // Parent process

        int child2 = fork();  // Second fork
        if (child2 == 0) {
            printf("Child2 -> PID: %d \t PPID: %d\n", getpid(), getppid());

            int s = 1;
            for (int k = 0; k < n; k++) {
                s *= 2;
            }
            printf("2 to the power of %d is %d\n", n, s);

        } else {
            int child3 = fork();  // Third fork
            if (child3 == 0) {
                printf("Child3 -> PID: %d \t PPID: %d\n", getpid(), getppid());
                int square = n * n;
                printf("Square of %d is %d\n", n, square);
            } else {
                // Parent waits for all its children
                wait(NULL);
                wait(NULL);
            }
        }
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc D5_Example2.c -o D5_Example2.c
[2021ict60@fedora ~]$ ./D5_Example2.c
