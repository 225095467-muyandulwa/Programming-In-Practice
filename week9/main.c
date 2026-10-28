#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

int main(void)
{
    int choice;

    do {
        printf("\n====================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add employee\n");
        printf("2. List employees\n");
        printf("3. Search employee\n");
        printf("4. Set municipal budget\n");
        printf("5. Employee report\n");
        printf("6. Budget report\n");
        printf("7. Export report to text file\n");
        printf("8. Save employees to text file\n");
        printf("9. Load employees from text file\n");
        printf("10. Save employees to binary file\n");
        printf("11. Load employees from binary file\n");
        printf("0. Exit\n");

        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addEmployee();
                break;

            case 2:
                listEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                setBudget();
                break;

            case 5:
                employeeReport();
                break;

            case 6:
                budgetReport();
                break;

            case 7:
                exportReport();
                break;

            case 8:
                saveEmployeesText();
                break;

            case 9:
                loadEmployeesText();
                break;

            case 10:
                saveEmployeesBinary();
                break;

            case 11:
                loadEmployeesBinary();
                break;

            case 0:
                printf("Exiting MFMS. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (choice != 0) {
            pauseScreen();
        }

    } while (choice != 0);

    return 0;
}