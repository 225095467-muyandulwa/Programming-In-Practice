#include <stdio.h>

int main() {
    // 1. Variables
    char studentName[50];
    float test1, test2, assignment, total;

    // Input data
    printf("Enter Student Name: ");
    // Reads a full line of text including spaces
    scanf(" %[^\n]", studentName); 

    printf("Enter Test 1 Mark: ");
    scanf("%f", &test1);

    printf("Enter Test 2 Mark: ");
    scanf("%f", &test2);

    printf("Enter Assignment Mark: ");
    scanf("%f", &assignment);

    // 2. Arithmetic operators and Assignment
    total = test1 + test2 + assignment;

    // 3. Formatted output (Header)
    printf("\n=============================\n");
    printf("       STUDENT REPORT        \n");
    printf("=============================\n");
    printf("Student Name: %s\n", studentName);
    printf("Total Mark:   %.2f\n", total);

    // 4. Relational operators and if...else if...else structure
    printf("Result:       ");
    if (total >= 75.0 && total <= 100.0) {
        printf("Distinction\n");
    } else if (total >= 60.0 && total < 75.0) {
        printf("Credit\n");
    } else if (total >= 50.0 && total < 60.0) {
        printf("Pass\n");
    } else {
        printf("Fail\n");
    }
    printf("=============================\n");

    return 0;
}

