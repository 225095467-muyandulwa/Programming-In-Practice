#include <stdio.h>

int main(void)
{
    struct name {
        char Municipal[20];
    } municipal;
    int choice;

    (void)municipal;

    printf("============================================================\n");
    printf("        MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid choice.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            printf("Employee Management selected.\n");
            break;
        case 2:
            printf("Budget Management selected.\n");
            break;
        case 3:
            printf("Supplier Management selected.\n");
            break;
        case 4:
            printf("Asset Management selected.\n");
            break;
        case 5:
            printf("Reports selected.\n");
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
