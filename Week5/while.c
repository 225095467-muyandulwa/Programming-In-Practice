#include <stdio.h>
int main() {
 float salaries[5];
 for (int i = 0; i < 5; i++) {
 printf("Enter salary %d: ", i + 1);
 scanf("%f", &salaries[i]);
 }
 printf("\nEmployee Salaries\n");
 for (int i = 0; i < 5; i++) {
 printf("%.2f\n", salaries[i]);
 }
 return 0;
}

