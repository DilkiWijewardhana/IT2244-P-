Exersice1:
Area calculation program

Circle => C
Triangle => T
Square => S
Rectangle => Rectangle

Enter Your choice: C

Circle area calculation

Enter the radius: 20.9
Area is: 1371.58

[2021ict60@fedora ~]$ vi D22_Exercise1.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <sys/wait.h>  // For wait()

int main() {
    int pipefd1[2], pipefd2[2];
    pid_t pid;
    char shape;
    double radius, area;

    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    printf("Area calculation program\n");
    printf("\n\tCircle => C\n\tTriangle => T\n\tSquare => S\n\tRectangle => R\n");
    printf("\nEnter Your Choice : ");
    scanf(" %c", &shape);

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process
        close(pipefd1[0]);
        close(pipefd2[1]);

        if (shape == 'C' || shape == 'c') {
            printf("\nCircle area calculation\nEnter the radius : ");
            scanf("%lf", &radius);

            write(pipefd1[1], &radius, sizeof(radius));
            close(pipefd1[1]);

            read(pipefd2[0], &area, sizeof(area));
            close(pipefd2[0]);

            printf("Area is : %.2lf\n", area);
        } else {
            printf("Only Circle calculation is implemented in this example.\n");
            close(pipefd1[1]);
            close(pipefd2[0]);
        }

        wait(NULL);
    } else {
        // Child process
        close(pipefd1[1]);
        close(pipefd2[0]);

        if (shape == 'C' || shape == 'c') {
            read(pipefd1[0], &radius, sizeof(radius));
            close(pipefd1[0]);

            area = M_PI * radius * radius;

            write(pipefd2[1], &area, sizeof(area));
            close(pipefd2[1]);
        } else {
            close(pipefd1[0]);
            close(pipefd2[1]);
            exit(EXIT_SUCCESS);
        }

        exit(EXIT_SUCCESS);
    }

    return 0;
}

[2021ict60@fedora ~]$ vi D22_Exercise1.c
[2021ict60@fedora ~]$ gcc  D22_Exercise1.c -o D22_Exercise1
[2021ict60@fedora ~]$ ./D22_Exercise1
Area calculation program

Circle => C
Triangle => T
Square => S
Rectangle => R

Enter Your choice: C

Circle area calculation

Enter the radius: 20.9
Area is: 1372.28
[2021ict60@fedora ~]$ ./D22_Exercise1
Area calculation program

Circle => C
Triangle => T
Square => S
Rectangle => R

Enter Your choice: T

Triangle area calculation

Enter base and height: 10 6
Area is: 30.00
[2021ict60@fedora ~]$ ./D22_Exercise1
Area calculation program

Circle => C
Triangle => T
Square => S
Rectangle => R

Enter Your choice: S

Square area calculation

Enter the side length: 6
Area is: 36.00
[2021ict60@fedora ~]$ ./D22_Exercise1
Area calculation program

Circle => C
Triangle => T
Square => S
Rectangle => R

Enter Your choice: R

Rectangle area calculation

Enter length and width: 12.5 4
Area is: 50.00
[2021ict60@fedora ~]$ ./D22_Exercise1
Area calculation program

Circle => C
Triangle => T
Square => S
Rectangle => R

Enter Your choice: A
Invalid choice!