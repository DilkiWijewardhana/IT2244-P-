Example 01:Create a file using .c extention 

Simple example for the C language code:
input output functinality => #include<stdio.h>

Putty code:
login as: 2021ict60
2021ict60@172.16.140.150's password:
Last login: Thu May 15 16:27:49 2025 from 172.16.140.84
[2021ict60@fedora ~]$ touch Firstpro.c
[2021ict60@fedora ~]$ vi Firstpro.c

#include<stdio.h>

int main()
{
   printf("Hello world!");
return 0;
}

//gcc [foldername with extention] -o [folder name without extention]
[2021ict60@fedora ~]$ gcc Firstpro.c -o Firstpro 
[2021ict60@fedora ~]$ ./Firstpro
Hello world!

Example 02: Display integer values

[2021ict60@fedora ~]$ vi Second.c

#include<stdio.h>
int main() 
{
  int age=25;
  printf(age);
  //printf("%d", age);
  
  return 0;
 }
 
[2021ict60@fedora ~]$ gcc Second.c -o Second
[2021ict60@fedora ~]$ ./Second
25

####variables######
 %d / %i - integers
 %f / %F - float 
 %lf -double
 %e - char
 %s - strings
 
Example 03:assign new value for same variables

[2021ict60@fedora ~]$ vi third.c

#include<stdio.h>
int main()
{
 
 int age=25;
 printf("%d", age);
 printf("C programming ");
 
 age=31;
 printf("\nNew age: %d",age);
 
 return 0;
}

[2021ict60@fedora ~]$ gcc third.c -o third
[2021ict60@fedora ~]$ ./third
25C programming
New age: 31

 
Example 04:

[2021ict60@fedora ~]$ vi fourth.c

#include<stdio.h>
int main()
{
	int firstNumber=25;
	printf("first number :%d",firstNumber);
	printf("\n");
	int secondNumber=firstNumber;
	printf("second number %d",secondNumber);
	
	return 0;
}
[2021ict60@fedora ~]$ gcc fourth.c -o fourth
[2021ict60@fedora ~]$ ./fourth
first number :25
second number 25


Example05:declare multiple variables in single line

[2021ict60@fedora ~]$ vi five.c

#include<stdio.h>
int main()
{
	int firstNumber,secondNumber=25;
	printf("First number %d:",firstNumber);
	printf("Second number %d:",secondNumber);
	printf("\n");
	
}

[2021ict60@fedora ~]$ gcc five.c -o five
[2021ict60@fedora ~]$ ./five
First number 1:Second number 25:



Example 06:data types 

[2021ict60@fedora ~]$ touch six.c
[2021ict60@fedora ~]$ vi six.c
#include<stdio.h>
int main()
{
	int age=10;
	printf("%d",age);
    printf("\n");
	printf("size: %zu",sizeof(age));
	printf("\n");
	
	return 0;
}

[2021ict60@fedora ~]$ gcc six.c -o six
[2021ict60@fedora ~]$ ./six
10
size: 4


Example 07:
//variable naming convention
//can't create variable names with space
//can't start variable names with numbers




Example 08:

[2021ict60@fedora ~]$ touch eight.c
[2021ict60@fedora ~]$ vi eight.c

#include<stdio.h>
int main()
{
	double number=12.45;
	printf("%lf",number);
	printf("\n");
	printf("\n");
	
	return 0;
}
[2021ict60@fedora ~]$ gcc eight.c -o eight
[2021ict60@fedora ~]$ ./eight
12.450000

 
Example 09:
[2021ict60@fedora ~]$ touch nine.c
[2021ict60@fedora ~]$ vi nine.c

#include<stdio.h>
int main()
{
	float number1=10.9f;
	printf("%f",number1);
	printf(".1%f",number1);
	printf("\n");
	printf("\n");
	
	return 0;
}

[2021ict60@fedora ~]$ gcc nine.c -o nine
[2021ict60@fedora ~]$ ./nine
10.900000
10.9

//using f we indicate the output number
// %f -10.900000
// .1%f -10.9 


Example 10:
[2021ict60@fedora ~]$ touch ten.c
[2021ict60@fedora ~]$ vi ten.c
#include<stdio.h>
int main()
{
	char gender='m';
	printf("gender: %c",gender);
	printf("\n%d",gender);
	printf("\n");
	printf("\n");
	
	return 0;
}

[2021ict60@fedora ~]$ gcc ten.c -o ten
[2021ict60@fedora ~]$ ./ten
gender: m
109


Example 11:

[2021ict60@fedora ~]$ touch eleven.c
[2021ict60@fedora ~]$ vi eleven.c
#include<stdio.h>
int main()
{
	int age;
	printf("Enter your age:");
	printf("%d",age);
	scanf("%d", &age);
	
	printf("Age=%d",age);
	printf("\n");
	printf("\n");
	
	return 0;
}

[2021ict60@fedora ~]$ gcc eleven.c -o eleven
[2021ict60@fedora ~]$ ./eleven
Enter your age:025
Age=25


Example 12:
[2021ict60@fedora ~]$ touch twelve.c
[2021ict60@fedora ~]$ vi twelve.c
#include<stdio.h>
int main()
{
	double number;
	char alpha;
	printf("Enter double input:");
	scanf("%lf", &number);
	printf("\nYour double input is:%lf",number);
	
    printf("Enter Char  input:");
	scanf("%c", &alpha);
	printf("\nYour char input is:%c",alpha);
	
     printf("\n");
	printf("\n");
	
	return 0;
}

[2021ict60@fedora ~]$ gcc twelve.c -o twelve
[2021ict60@fedora ~]$ ./twelve
Enter double input:25.10

Your double input is:25.100000Enter Char  input:
Your char input is:


Example 13:

//Take multiple inputs together

[2021ict60@fedora ~]$ vi 13.c
#include<stdio.h>
int main()
{
	double number;
	char alpha;
	printf("Enter input:");
	scanf("%lf %c", &number,&alpha);
	printf("%lf",number);
	printf("%c",alpha);
	
	
    printf("\n");
	printf("\n");
	
	return 0;
	
}
[2021ict60@fedora ~]$ gcc 13.c -o 13
[2021ict60@fedora ~]$ ./13
Enter input:12.52
A
12.520000
A


Example 14:

//Comments:

// -single live comments ctrl+/
// /* */ -multiple comments ctrl+shift+/


Example 15:

[2021ict60@fedora ~]$ vi 15.c
#include<stdio.h>
int main()
{
	int  number1;
	int number2;
  printf("Enter First number:");
  scanf("%d", &number1);
  
  printf("Enter Second number:");
  scanf("%d", &number2);
  
   printf("Summation is : %d",number1+number2);
   printf("\n");
   printf("Substraction is :%d ",number1-number2);
   printf("\n");
   printf("Multiplication is : %d",number1*number2);
   printf("\n");
   printf("Divition is : %d",number1/number2);
   printf("\n");
   printf("Module is : %d",number1%number2);
  
  printf("\n");
  printf("\n");
  
  return 0;./
}
[2021ict60@fedora ~]$ gcc 15.c  -o 15
[2021ict60@fedora ~]$ ./15
Enter First number:20
Enter Second number:5
Summation is : 25
Substraction is :15
Multiplication is : 100
Divition is : 4
Module is : 0

#### C operations #######
//arithmatic operators
+
-
*
/
%- remainder