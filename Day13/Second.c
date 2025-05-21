//If Else
if(condition){
	//body of the statement;
}
else{
	//body of the statement;
}

Example:Enter your age and verify your aligible or not for election voting using if else condition.

[2021ict60@fedora ~]$ vi If_Else.c

#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18) 
	{
        printf("You are eligible to vote.\n");
    } 
	else 
	{
        printf("You are not eligible to vote.\n");
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc If_Else.c -o If_Else
[2021ict60@fedora ~]$ ./If_Else
Enter your age: 22
You are eligible to vote.
[2021ict60@fedora ~]$ ./If_Else
Enter your age: 10
You are not eligible to vote.
---------------------------------------------------------

//Ternary Operator
test_condition? expression1 : expression2;

[2021ict60@fedora ~]$ vi If_Else.c
#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);
	
	(age>=18) ? printf("You are eligible to vote") : printf("You are not eligible to vote");
	
	return 0;
}

[2021ict60@fedora ~]$ gcc If_Else.c -o If_Else
[2021ict60@fedora ~]$ ./If_Else
Enter your age: 22
You are eligible to vote.
[2021ict60@fedora ~]$ ./If_Else
Enter your age: 10
You are not eligible to vote.
------------------------------------------------------------------------

//Switch Case
Example1: Enter the value between 1 to 7 and create a program for following output
Enter the number between 1 to 7: 1
Today is Sunday!

[2021ict60@fedora ~]$ vi Switch_Case.c
#include <stdio.h>

int main() {
    int day;

    printf("Enter the number between 1 and 7: ");
    scanf("%d", &day);

    if (day == 1) {
        printf("Today is Sunday!\n");
    } else if (day == 2) {
        printf("Today is Monday!\n");
    } else if (day == 3) {
        printf("Today is Tuesday!\n");
    } else if (day == 4) {
        printf("Today is Wednesday!\n");
    } else if (day == 5) {
        printf("Today is Thursday!\n");
    } else if (day == 6) {
        printf("Today is Friday!\n");
    } else if (day == 7) {
        printf("Today is Saturday!\n");
    } else {
        printf("Invalid input! Please enter a number between 1 and 7.\n");
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc Switch_Case.c -o Switch_Case
[2021ict60@fedora ~]$ ./Switch_Case
Enter the number between 1 and 7: 4
Today is Wednesday!
[2021ict60@fedora ~]$ ./Switch_Case
Enter the number between 1 and 7: 8
Invalid input! Please enter a number between 1 and 7.


Example2:
Write a code for small astrology based on your life path number for that get date of from user then calculate life path number.(Use switch case)
	Example:
		Date: 23
		
		calculation for life path number:
			a=date%10	3
			b=date/10	2
			c=a+b 		5
		
		 if life path number :
		   1.Lucky 
		   2.Carefuly do your work
		   3.Storger
		   4.Happy
		   5.Can get help
		   6.Doubt
		   7.sad
		   8.Like
		   9.Courage
		   
[2021ict60@fedora ~]$ vi Life_path_number.c
#include <stdio.h>

int main() {
    int date, a, b, lifePathNumber;

    printf("Enter your birth date (1 to 31): ");
    scanf("%d", &date);

    a = date % 10;        
    b = date / 10;       
    lifePathNumber = a + b; 

    if (lifePathNumber > 9) {
        a = lifePathNumber % 10;
        b = lifePathNumber / 10;
        lifePathNumber = a + b;
    }

    printf("Your Life Path Number is: %d\n", lifePathNumber);

    switch (lifePathNumber) {
        case 1:
            printf("Lucky\n");
            break;
        case 2:
            printf("Carefully do your work\n");
            break;
        case 3:
            printf("Stronger\n");
            break;
        case 4:
            printf("Happy\n");
            break;
        case 5:
            printf("Can get help\n");
            break;
        case 6:
            printf("Doubt\n");
            break;
        case 7:
            printf("Sad\n");
            break;
        case 8:
            printf("Like\n");
            break;
        case 9:
            printf("Courage\n");
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc Life_path_number.c -o Life_path_number
[2021ict60@fedora ~]$ ./Life_path_number
Enter your birth date (1 to 31): 15
Your Life Path Number is: 6
Doubt
		   
Example3:
Give list of numbers then calculate the summation and multiplication using for loop.
	Example:
		1 2 3 4 5
		summation = 15
		multiplication = 120
	
[2021ict60@fedora ~]$ vi Calculator.c	
#include <stdio.h>

int main() {
    int n, i;
    int sum = 0, multiplication = 1;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

for (i = 0; i < n; i++) {
        sum += numbers[i];           
        multiplication *= numbers[i]; 
    }

    printf("Summation = %d\n", sum);
    printf("Multiplication = %d\n", multiplication);

    return 0;
}

[2021ict60@fedora ~]$ gcc Calculator.c -o Calculator
[2021ict60@fedora ~]$ ./Calculator
Enter the number of elements: 2
Enter 2 numbers: 20
10
Summation = 30
Multiplication = 200

		
Example4:
Print the intergers from 1 to 10 using while loop
	
[2021ict60@fedora ~]$ vi intergers_whliLoop.c
#include <stdio.h>

int main() {
    int i = 1; 
    
   while (i <= 10) {
        printf("%d ", i);
        i++; 
    }

    printf("\n"); 
    return 0;
}

[2021ict60@fedora ~]$gcc intergers_whliLoop.c -o intergers_whliLoop
[2021ict60@fedora ~]$./intergers_whliLoop
1 2 3 4 5 6 7 8 9 10

Example5:
Write a C program to generate and print the Fibonacci series up to a specified number of terms.The program should take the number of terms as input from the user and then display the corresponding Fibonacci sequence.

[2021ict60@fedora ~]$ Fibonacci.c
#include <stdio.h>

int main() {
    int n, i;
    long long int first = 0, second = 1, next;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series up to %d terms: \n", n);

    for (i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%lld ", first);
        } else if (i == 2) {
            printf("%lld ", second);
        } else {
            next = first + second;
            first = second;
            second = next;
            printf("%lld ", next);
        }
    }

    printf("\n");

    return 0;
}

[2021ict60@fedora ~]$ gcc Fibonacci.c -o Fibonacci
[2021ict60@fedora ~]$ ./Fibonacci
Enter the number of terms: 10
Fibonacci Series up to 10 terms:
0 1 1 2 3 5 8 13 21 34

Example6:
Write a C program to calculate the factorial of a given non-negetive interger

[2021ict60@fedora ~]$ vi Factorial.c
#include <stdio.h>

long long int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number;

    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %lld\n", number, factorial(number));
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc Factorial.c -o Factorial
[2021ict60@fedora ~]$ ./Factorial
Enter a non-negative integer: 5
Factorial of 5 is 120
[2021ict60@fedora ~]$ ./Factorial
Enter a non-negative integer: -5
Factorial is not defined for negative numbers.

Example7:
Write a C program that:
Accept two string as input from the user.
Concatenates the two string displays the concatenated result

[2021ict60@fedora ~]$ vi Example7.c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    
	str2[strcspn(str2, "\n")] = '\0';

    strcat(str1, str2);

    printf("Concatenated string: %s\n", str1);

    return 0;
}

[2021ict60@fedora ~]$ gcc Example7.c -o Example7
[2021ict60@fedora ~]$ ./Example7

Example 8:
Write a C program that takes a binary number (as an integer) as input and 
converts it to its decimal equivalent.

[2021ict60@fedora ~]$ Binary_number.c
#include <stdio.h>

int main() {
    long long binary;
    int decimal = 0, base = 1, remainder;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while (binary > 0) {
        remainder = binary % 10;
        if (remainder != 0 && remainder != 1) {
            printf("Invalid binary number.\n");
            return 1; 
        }

        decimal += remainder * base;
        binary /= 10;
        base *= 2;
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}

[2021ict60@fedora ~]$ gcc Binary_number.c -o Binary_number
[2021ict60@fedora ~]$ ./Binary_number

Example 9:
Write a C program that:
Accepts an array of integers from the user.
Finds and displays the maximum and minimum values in the array.

[2021ict60@fedora ~]$ Example9.c
#include <stdio.h>

int main() {
    int n, i;
    int arr[100]; 
    int max, min;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}

[2021ict60@fedora ~]$ gcc Example9.c -o Example9
[2021ict60@fedora ~]$ ./Example9


Example 10:
C program to generate Pascal's Triangle.

Output:
no of rows =5
          1
        1   1
      1   2   1
    1   3   3   1
  1   4   6   4   1

[2021ict60@fedora ~]$ Example10.c  
#include <stdio.h>

int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int binomialCoeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int rows, i, j, space;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("\n");

    for(i = 0; i < rows; i++) {
        for(space = 0; space < rows - i - 1; space++) {
            printf("  ");
        }

        for(j = 0; j <= i; j++) {
            printf("%4d", binomialCoeff(i, j));
        }

        printf("\n");
    }

    return 0;
}

[2021ict60@fedora ~]$ gcc Example10.c -o Example10
[2021ict60@fedora ~]$ ./Example10
  
  
Enter a binary number: 1011
Decimal equivalent: 11

Enter the number of elements in the array: 5
Enter 5 integers:
8 3 15 1 9
Maximum value: 15
Minimum value: 1