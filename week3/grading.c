#include <stdio.h>
int main()
{
   int marks; 
   int grade;
   char studentName[50];
   printf("Enter name of student: ");
scanf("%49s", studentName);
   printf("Enter marks of student: ");
   scanf("%d", &marks);
   if (marks >= 80) {
       grade = 'A';
       printf("You got A, Excellent!\n");
   } else if (marks >= 70) {
       grade = 'B';
       printf("You got B, Good!\n");
   } else if (marks >= 60) {
       grade = 'C';
       printf("You got C, Satisfactory!\n");
   } else if (marks >= 50) {
       grade = 'D';
       printf("You got D, Pass!\n");
   } else {
       grade = 'F';
       printf("You got F, Fail!\n");
   }
   return 0;
}   