#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[5];
    int id;
    int grade;
};

int main() {
    int choice, count = 0, i, capacity;
    struct Student *students = NULL;
    char temp[10];
    struct Student *p;

    do {
        // display menu
        printf("\nStudent Management System\n");
        printf("0. Main Menu\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Add Grade\n");
        printf("5. Change students capacity \n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear input buffer


        switch(choice) {
            case 0:
                break;
            case 1:
                // add student
                printf("\nEnter student name: ");
                scanf("%s", temp);
                if (count == 0) {
                    students = (struct Student*) malloc(sizeof(struct Student));
                } else {
                    students = (struct Student*) realloc(students, sizeof(struct Student) * (count + 1));
                }
                p = &students[count];
                strcpy(p->name, temp);

                // Input and validate student ID
                printf("Enter student ID (must be a positive integer): ");
                while (1) {
                    if (scanf("%d", &p->id) != 1 || p->id <= 0) {
                        printf("Invalid input. Enter a valid student ID: ");
                        while (getchar() != '\n'); // Clear input buffer
                    } else {
                        break;
                    }
                }

                // Input and validate student grade
                printf("Enter student grade (must be between 0 and 100): ");
                while (1) {
                    if (scanf("%d", &p->grade) != 1 || p->grade < 0 || p->grade > 100) {
                        printf("Invalid input. Enter a valid student grade: ");
                        while (getchar() != '\n'); // Clear input buffer
                    } else {
                        break;
                    }
                }

                count++;
                printf("Student added successfully.\n");
                choice = 0;
                break;

            case 2:
                // delete student
                printf("\nEnter student ID to delete: ");
                scanf("%d", &i);
                for (p = students; p < students+count; p++) {
                    if (p->id == i) {
                        *p = students[count-1];
                        students = (struct Student*) realloc(students, sizeof(struct Student) * (count - 1));
                        count--;
                        printf("Student deleted successfully.\n");
                        choice = 0;
                        break;
                    }
                }
                if (p == students+count) {
                    printf("Student not found.\n");
                    choice = 0;
                }
                break;
            case 3:
                // display all students
                printf("\nStudent List\n");
                printf("Name\tID\tGrade\n");
                for (p = students; p < students+count; p++) {
                    printf("%s\t%d\t%d\n", p->name, p->id, p->grade);
                }
                choice = 0;
                break;
            case 4:
                // add grade for student
                printf("\nEnter student ID to add grade: ");
                scanf("%d", &i);
                for (p = students; p < students+count; p++) {
                    if (p->id == i) {
                        printf("Enter grade for student %s: ", p->name);
                        scanf("%d", &p->grade);
                        printf("Grade added successfully.\n");
                        choice = 0;
                        break;
                    }
                }
                if (p == students+count) {
                    printf("Student not found.\n");
                    choice = 0;
                }
                break;
                
            case 5:
                // change student capacity
                printf("\nEnter new student capacity: ");
                int new_capacity;
                scanf("%d", &new_capacity);

                if (new_capacity < count) {
                    printf("New capacity is less than the current number of students. Please try again.\n");
                } else {
                    struct Student *new_students = (struct Student*)realloc(students, new_capacity * sizeof(struct Student));
                    if (new_students) {
                        students = new_students;
                        printf("Student capacity changed successfully.\n");
                        capacity = new_capacity;
                    } else {
                        printf("Failed to change student capacity.\n");
                    }
                }
                break;

            case 6:
                // exit program
                printf("\nGoodbye!\n");
                break;
            case 12:
                exit(0);
                break;
            case 13:
                free(students);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    free(students);

    return 0;
}