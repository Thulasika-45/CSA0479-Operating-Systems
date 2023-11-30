//13. Develop a C program for implementing random access file for processing the employee details.
#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int empId;
    char empName[50];
    float empSalary;
};

void addEmployee(FILE *file) {
    struct Employee emp;

    printf("Enter employee ID: ");
    scanf("%d", &emp.empId);
    fflush(stdin);

    printf("Enter employee name: ");
    fgets(emp.empName, sizeof(emp.empName), stdin);

    printf("Enter employee salary: ");
    scanf("%f", &emp.empSalary);

    fseek(file, 0, SEEK_END);

    fwrite(&emp, sizeof(struct Employee), 1, file);

    printf("Employee added successfully.\n");
}

void displayEmployee(FILE *file, int empId) {
    struct Employee emp;

    long offset = (empId - 1) * sizeof(struct Employee);

    fseek(file, offset, SEEK_SET);

    fread(&emp, sizeof(struct Employee), 1, file);

    printf("\nEmployee ID: %d\n", emp.empId);
    printf("Employee Name: %s", emp.empName);
    printf("Employee Salary: %.2f\n", emp.empSalary

