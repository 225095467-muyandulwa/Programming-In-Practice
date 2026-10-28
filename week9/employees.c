#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

void addEmployee(void)
{
    Employee employee;

    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee storage is full.\n");
        return;
    }

    employee.id = readInt("Enter employee ID: ");

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == employee.id) {
            printf("That employee ID already exists.\n");
            return;
        }
    }

    readLine("Enter employee name: ",
             employee.name, sizeof employee.name);

    if (employee.name[0] == '\0') {
        printf("Name cannot be empty.\n");
        return;
    }

    employee.salary = readDouble("Enter monthly salary: ");

    if (employee.salary < 0) {
        printf("Salary cannot be negative.\n");
        return;
    }

    employees[employeeCount] = employee;
    employeeCount++;

    printf("Employee added successfully.\n");
}

void listEmployees(void)
{
    if (employeeCount == 0) {
        printf("No employees available.\n");
        return;
    }

    printf("\n%-10s %-25s %12s\n",
           "ID", "Name", "Salary");

    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-25s %12.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].salary);
    }
}

void searchEmployee(void)
{
    int id = readInt("Enter employee ID to search: ");

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee found\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Salary: %.2f\n", employees[i].salary);
            return;
        }
    }

    printf("Employee not found.\n");
}

int getEmployeeCount(void)
{
    return employeeCount;
}

double calculatePayrollTotal(void)
{
    double total = 0.0;

    for (int i = 0; i < employeeCount; i++) {
        total += employees[i].salary;
    }

    return total;
}

/* Save employee records in a readable text format. */
void saveEmployeesText(void)
{
    FILE *fp = fopen("data/employees.txt", "w");

    if (fp == NULL) {
        perror("Could not open data/employees.txt");
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        if (fprintf(fp, "%d|%s|%.2f\n",
                    employees[i].id,
                    employees[i].name,
                    employees[i].salary) < 0) {
            perror("Error writing employee data");
            fclose(fp);
            return;
        }
    }

    if (fclose(fp) == EOF) {
        perror("Error closing employee file");
        return;
    }

    printf("Employees saved to data/employees.txt\n");
}

/* Load employee records from the text file. */
void loadEmployeesText(void)
{
    FILE *fp = fopen("data/employees.txt", "r");
    Employee loaded[MAX_EMPLOYEES];
    int count = 0;
    int id;
    char name[50];
    double salary;
    char line[150];
    int valid = 1;

    if (fp == NULL) {
        perror("Could not open data/employees.txt");
        return;
    }

    while (fgets(line, sizeof line, fp) != NULL) {
        char extra;

        if (sscanf(line, "%d|%49[^|]|%lf %c",
                   &id, name, &salary, &extra) != 3 ||
            salary < 0 || count >= MAX_EMPLOYEES) {
            valid = 0;
            break;
        }

        loaded[count].id = id;
        strcpy(loaded[count].name, name);
        loaded[count].salary = salary;
        count++;
    }

    if (ferror(fp)) {
        perror("Error reading employee file");
        fclose(fp);
        return;
    }

    if (fclose(fp) == EOF) {
        perror("Error closing employee file");
        return;
    }

    if (!valid) {
        printf("Invalid file data. Existing employees unchanged.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (loaded[i].id == loaded[j].id) {
                printf("Duplicate IDs found in file. Load cancelled.\n");
                return;
            }
        }
    }

    memcpy(employees, loaded, count * sizeof(Employee));
    employeeCount = count;

    printf("%d employee record(s) loaded.\n", employeeCount);
}

/* Save employee records in binary format. */
void saveEmployeesBinary(void)
{
    FILE *fp = fopen("data/employees.dat", "wb");

    if (fp == NULL) {
        perror("Could not open data/employees.dat");
        return;
    }

    if (fwrite(&employeeCount, sizeof employeeCount, 1, fp) != 1) {
        perror("Error writing employee count");
        fclose(fp);
        return;
    }

    if (employeeCount > 0 &&
        fwrite(employees, sizeof(Employee), employeeCount, fp)
        != (size_t)employeeCount) {
        perror("Error writing employee records");
        fclose(fp);
        return;
    }

    if (fclose(fp) == EOF) {
        perror("Error closing binary file");
        return;
    }

    printf("Employees saved to data/employees.dat\n");
}

/* Load employee records from binary format. */
void loadEmployeesBinary(void)
{
    FILE *fp = fopen("data/employees.dat", "rb");
    Employee loaded[MAX_EMPLOYEES];
    int count;

    if (fp == NULL) {
        perror("Could not open data/employees.dat");
        return;
    }

    if (fread(&count, sizeof count, 1, fp) != 1 ||
        count < 0 || count > MAX_EMPLOYEES) {
        printf("Invalid binary employee file.\n");
        fclose(fp);
        return;
    }

    if (count > 0 &&
        fread(loaded, sizeof(Employee), count, fp) != (size_t)count) {
        printf("Incomplete binary employee file.\n");
        fclose(fp);
        return;
    }

    if (fclose(fp) == EOF) {
        perror("Error closing binary file");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (loaded[i].salary < 0 ||
            loaded[i].name[sizeof loaded[i].name - 1] != '\0') {
            printf("Invalid employee record in binary file.\n");
            return;
        }

        for (int j = i + 1; j < count; j++) {
            if (loaded[i].id == loaded[j].id) {
                printf("Duplicate IDs found. Load cancelled.\n");
                return;
            }
        }
    }

    memcpy(employees, loaded, count * sizeof(Employee));
    employeeCount = count;

    printf("%d binary employee record(s) loaded.\n", employeeCount);
}