#include <stdio.h>
int main()
{
 float basicSalary;
 float housing;
 float transport;
 float tax;
 float grossSalary;
 float netSalary;
 printf("Enter basic salary: ");
 scanf("%f", &basicSalary);
 printf("Enter housing allowance: ");
 scanf("%f", &housing);
 printf("Enter transport allowance: ");
 scanf("%f", &transport);
 printf("Enter tax: ");
 scanf("%f", &tax);
 grossSalary = basicSalary + housing + transport;
 netSalary = grossSalary - tax;
 printf("Gross Salary: %.2f\n", grossSalary);
 printf("Net Salary: %.2f\n", netSalary);

 if (netSalary >= 20000) {
     printf("High income\n");
 } else if (netSalary >= 5000) {
     printf("Standard income\n");
 } else {
     printf("Low income\n");
 }
 return 0;
}