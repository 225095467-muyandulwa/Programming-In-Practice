#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

void addEmployee(void);
void listEmployees(void);
void searchEmployee(void);
int getEmployeeCount(void);
double calculatePayrollTotal(void);
void saveEmployeesText(void);
void loadEmployeesText(void);
void saveEmployeesBinary(void);
void loadEmployeesBinary(void);

#endif