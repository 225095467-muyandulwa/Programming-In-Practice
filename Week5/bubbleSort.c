#include <stdio.h>
int main() {
    
   float numbers[5] = {2500000, 1800000, 4500000, 3200000,2100000};
   int temp;
   float total = numbers[0] + numbers[1] + numbers[2] + numbers[3] + numbers[4];
 float average = total / 5;
 for (int i = 0; i < 5 - 1; i++) {
 for (int j = 0; j < 5 - i - 1; j++) {
 if (numbers[j] > numbers[j + 1]) {
 temp = numbers[j];
 numbers[j] = numbers[j + 1];
 numbers[j + 1] = temp;
 }
 }
 }
 printf("Sorted values:\n");
 for (int i = 0; i < 5; i++) {
 printf("%.2f\n", numbers[i]);
 total += numbers[i];
 }
 printf("Total: %.2f\n", total);
 printf("Average: %.2f\n", average);
 return 0;
}