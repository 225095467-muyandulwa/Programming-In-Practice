#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void employeeReport(void)
{
    printf("\n--- Employee Report ---\n");
    printf("Number of employees: %d\n", getEmployeeCount());
    printf("Total monthly payroll: N$ %.2f\n",
           calculatePayrollTotal());
}

void exportReport(void)
{
    FILE *fp = fopen("data/mfms_report.txt", "w");

    if (fp == NULL) {
        perror("Could not create data/mfms_report.txt");
        return;
    }

    if (fprintf(fp,
                "MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n"
                "=====================================\n"
                "Number of employees: %d\n"
                "Total monthly payroll: N$ %.2f\n"
                "Municipal budget: N$ %.2f\n"
                "Remaining balance: N$ %.2f\n",
                getEmployeeCount(),
                calculatePayrollTotal(),
                getBudget(),
                calculateBudgetBalance()) < 0) {
        perror("Error writing report");
        fclose(fp);
        return;
    }

    if (fclose(fp) == EOF) {
        perror("Error closing report");
        return;
    }

    printf("Report exported to data/mfms_report.txt\n");
}