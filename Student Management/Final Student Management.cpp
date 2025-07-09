
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int roll;
    char name[50];
    float marks;
} Student;

Student students[MAX];
int count = 0;

// Function to add a new student
void addStudent() {
    if (count >= MAX) {
        printf("Student list is full!\n");
        return;
    }
    printf("Enter Roll Number: ");
    scanf("%d", &students[count].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (count == 0) {
        printf("No student records to display.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", students[i].roll, students[i].name, students[i].marks);
    }
}

// Function to search for a student by roll number
void searchStudent() {
    int roll, found = 0;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Record Found:\n");
            printf("Roll: %d | Name: %s | Marks: %.2f\n", students[i].roll, students[i].name, students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
}

// Function to update a student's record
void updateStudent() {
    int roll, found = 0;
    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new Marks: ");
            scanf("%f", &students[i].marks);
            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
}

// Function to delete a student's record
void deleteStudent() {
    int roll, found = 0;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Record deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
}

// Function to save records to a file
void saveToFile() {
    FILE *fp = fopen("students.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(students, sizeof(Student), count, fp);
    fclose(fp);
    printf("Records saved to file successfully.\n");
}

// Function to load records from a file
void loadFromFile() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No existing data file found. Starting fresh.\n");
        return;
    }
    fread(&count, sizeof(int), 1, fp);
    fread(students, sizeof(Student), count, fp);
    fclose(fp);
    printf("Records loaded from file successfully.\n");
}

int main() {
    int choice;
    loadFromFile();
    do {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Save Records to File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                saveToFile();
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}

