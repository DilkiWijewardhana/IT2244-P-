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
-----------------------------------------------------------------------------------------

[dilki@DESKTOP-JDQG16N ~]$ vi switchCase_pipe.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main() {
    int pipe1[2]; // Parent to Child
    int pipe2[2]; // Child to Parent
    pipe(pipe1);
    pipe(pipe2);

    pid_t pid = fork();

    if (pid == 0) {
        // ---------------- CHILD PROCESS ----------------
        close(pipe1[1]); // close write end
        close(pipe2[0]); // close read end

        int choice;
        float input1, input2;
        read(pipe1[0], &choice, sizeof(int));        // read choice first
        read(pipe1[0], &input1, sizeof(float));      // read input1
        read(pipe1[0], &input2, sizeof(float));      // read input2 (if needed)

        float result = 0;

        switch (choice) {
            case 1: // Circle
                result = M_PI * input1 * input1;
                break;
            case 2: // Triangle
                result = 0.5 * input1 * input2;
                break;
            case 3: // Square
                result = input1 * input1;
                break;
            default:
                result = -1; // Invalid choice
        }

        write(pipe2[1], &result, sizeof(float)); // send result back

    } else {
        // ---------------- PARENT PROCESS ----------------
        close(pipe1[0]); // close read end
        close(pipe2[1]); // close write end

        int choice;
        float input1 = 0, input2 = 0;

        printf("----- AREA CALCULATOR MENU -----\n");
        printf("1. Area of Circle\n");
        printf("2. Area of Triangle\n");
        printf("3. Area of Square\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter radius of circle: ");
                scanf("%f", &input1);
                input2 = 0; // not used
                break;
            case 2:
                printf("Enter base and height of triangle: ");
                scanf("%f %f", &input1, &input2);
                break;
            case 3:
                printf("Enter side of square: ");
                scanf("%f", &input1);
                input2 = 0; // not used
                break;
            default:
                printf("Invalid choice. Exiting.\n");
                exit(1);
        }

        // Send choice and inputs to child
        write(pipe1[1], &choice, sizeof(int));
        write(pipe1[1], &input1, sizeof(float));
        write(pipe1[1], &input2, sizeof(float));

        // Receive result
        float result;
        read(pipe2[0], &result, sizeof(float));

        // Display result
        printf("\n--- AREA RESULT ---\n");
        if (result == -1)
            printf("Error: Invalid choice in child process.\n");
        else {
            switch (choice) {
                case 1: printf("Circle Area: %.2f\n", result); break;
                case 2: printf("Triangle Area: %.2f\n", result); break;
                case 3: printf("Square Area: %.2f\n", result); break;
            }
        }
    }

    return 0;
}

[dilki@DESKTOP-JDQG16N ~]$ gcc switchCase_pipe.c -o switchCase_pipe
[dilki@DESKTOP-JDQG16N ~]$ ./switchCase_pipe
----- AREA CALCULATOR MENU -----
1. Area of Circle
2. Area of Triangle
3. Area of Square
Enter your choice (1-3): 1
Enter radius of circle: 20.9

--- AREA RESULT ---
Circle Area: 1372.28
[dilki@DESKTOP-JDQG16N ~]$ ./switchCase_pipe
----- AREA CALCULATOR MENU -----
1. Area of Circle
2. Area of Triangle
3. Area of Square
Enter your choice (1-3): 2
Enter base and height of triangle: 10 6

--- AREA RESULT ---
Triangle Area: 30.00
[dilki@DESKTOP-JDQG16N ~]$ ./switchCase_pipe
----- AREA CALCULATOR MENU -----
1. Area of Circle
2. Area of Triangle
3. Area of Square
Enter your choice (1-3): 3
Enter side of square: 6

--- AREA RESULT ---
Square Area: 36.00
[dilki@DESKTOP-JDQG16N ~]$ ./switchCase_pipe
----- AREA CALCULATOR MENU -----
1. Area of Circle
2. Area of Triangle
3. Area of Square
Enter your choice (1-3): 4
Invalid choice. Exiting.