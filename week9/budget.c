#include <stdio.h>
#include "budget.h"
#include "employees.h"
#include "utilities.h"

static double municipalBudget = 0.0;

void setBudget(void)
{
    double amount = readDouble("Enter municipal budget: ");

    if (amount < 0) {
        printf("Budget cannot be negative.\n");
        return;
    }

    municipalBudget = amount;

    printf("Budget updated successfully.\n");
}

double getBudget(void)
{
    return municipalBudget;
}

double calculateBudgetBalance(void)
{
    return municipalBudget - calculatePayrollTotal();
}

void budgetReport(void)
{
    printf("\n--- Budget Report ---\n");
    printf("Total budget:       N$ %.2f\n", municipalBudget);
    printf("Employee payroll:   N$ %.2f\n",
           calculatePayrollTotal());
    printf("Remaining balance:  N$ %.2f\n",
           calculateBudgetBalance());
}