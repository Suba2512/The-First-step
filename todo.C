#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

int main() {
    char tasks[MAX_TASKS][MAX_LENGTH];
    int taskCount = 0;
    int choice;

    while (1) {
        printf("\n--- To-Do List Menu ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        if (choice == 1) {
            if (taskCount < MAX_TASKS) {
                printf("Enter task: ");
                fgets(tasks[taskCount], MAX_LENGTH, stdin);
                tasks[taskCount][strcspn(tasks[taskCount], "\n")] = '\0'; // remove newline
                taskCount++;
                printf("Task added!\n");
            } else {
                printf("Task list full!\n");
            }
        } else if (choice == 2) {
            printf("\n--- Your Tasks ---\n");
            for (int i = 0; i < taskCount; i++) {
                printf("%d. %s\n", i + 1, tasks[i]);
            }
        } else if (choice == 3) {
            printf("Goodbye! exit\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}