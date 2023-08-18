#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[50]; // Increased size for student names
    int id;
    int grade;
};

int main() {
    int choice, count = 0, capacity = 0; // Initialize capacity
    struct Student *students = NULL;
    char temp[50]; // Increased size for temporary input
    int i; // Initialize i
    struct Student *p;

    do {
        // Display menu
        printf("\nStudent Management System\n");
        printf("0. Main Menu\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Add Grade\n");
        printf("5. Change students capacity \n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 0:
                break;
            case 1:
                // Add student
                printf("\nEnter student name: ");
                if (scanf("%s", temp) != 1) {
                    printf("Invalid input. Exiting.\n");
                    break;
                }
                if (count == capacity) {
                    capacity += 5; // Increase capacity in blocks
                    students = (struct Student *)realloc(students, sizeof(struct Student) * capacity);
                }
                p = &students[count];
                strcpy(p->name, temp);
                printf("Enter student ID: ");
                if (scanf("%d", &p->id) != 1) {
                    printf("Invalid input. Exiting.\n");
                    break;
                }
                printf("Enter student grade: ");
                if (scanf("%d", &p->grade) != 1) {
                    printf("Invalid input. Exiting.\n");
                    break;
                }
                count++;
                printf("Student added successfully.\n");
                break;
            case 2:
                // Delete student
                printf("\nEnter student ID to delete: ");
                if (scanf("%d", &i) != 1) {
                    printf("Invalid input. Exiting.\n");
                    break;
                }
                int found = 0;
                for (int j = 0; j < count; j++) {
                    if (students[j].id == i) {
                        students[j] = students[count - 1];
                        count--;
                        found = 1;
                        printf("Student deleted successfully.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Student not found.\n");
                }
                break;
            case 3:
                // Display all students
                printf("\nStudent List\n");
                printf("Name\tID\tGrade\n");
                for (int j = 0; j < count; j++) {
                    printf("%s\t%d\t%d\n", students[j].name, students[j].id, students[j].grade);
                }
                break;
            case 4:
                // Add grade for student
                printf("\nEnter student ID to add grade: ");
                if (scanf("%d", &i) != 1) {
                    printf("Invalid input. Exiting.\n");
                    break;
                }
                found = 0;
                for (int j = 0; j < count; j++) {
                    if (students[j].id == i) {
                        printf("Enter grade for student %s: ", students[j].name);
                        if (scanf("%d", &students[j].grade) != 1) {
                            printf("Invalid input. Exiting.\n");
                            break;
                        }
                        found = 1;
                        printf("Grade added successfully.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                // Change student capacity
                printf("\nEnter new student capacity: ");
                int new_capacity;
                if (scanf("%d", &new_capacity) != 1) {
                    printf("Invalid input. Exiting.\n");
                    break;
                }
                if (new_capacity < count) {
                    printf("New capacity is less than current number of students. Please try again.\n");
                } else {
                    students = (struct Student *)realloc(students, new_capacity * sizeof(struct Student));
                    if (students == NULL) {
                        printf("Memory reallocation failed. Exiting.\n");
                        return 1;
                    }
                    printf("Student capacity changed successfully.\n");
                    capacity = new_capacity;
                }
                break;
            case 6:
                // Exit program
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    free(students); // Free allocated memory

    return 0;
}
