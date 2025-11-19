#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "tasks.txt"
#define MAX_TASK_LEN 256

char **Tasks = NULL;
int taskCount = 0;

// Add task to dynamic array
void pushTask(const char *task) {
    Tasks = realloc(Tasks, (taskCount + 1) * sizeof(char*));
    Tasks[taskCount] = malloc(strlen(task) + 1);
    strcpy(Tasks[taskCount], task);
    taskCount++;
}

// Load tasks from file
void loadTasks() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No saved tasks found. Starting fresh.\n");
        return;
    }

    char line[MAX_TASK_LEN];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;  // remove newline
        if (strlen(line) > 0) {
            pushTask(line);
        }
    }

    fclose(file);
    printf("Loaded %d tasks.\n", taskCount);
}

// Save tasks to file
void saveTasks() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error saving tasks!\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%s\n", Tasks[i]);
    }

    fclose(file);

    system("clear");
    printf("Saved %d tasks.\n", taskCount);
}

// Start menu
int startMenu() {
    int choice;
    printf("\n=== CLI ToDo App ===\n");
    printf("1. Add a task\n");
    printf("2. Remove a task\n");
    printf("3. List all tasks\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    getchar(); // consume newline
    return choice;
}

// Add task
void addTask() {
    char buffer[MAX_TASK_LEN];

    system("clear");
    printf("Enter task: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    pushTask(buffer);
    saveTasks();

    system("clear");
    printf("Task added!\n");
}

// Remove task
void removeTask() {
    system("clear");

    if (taskCount == 0) {
        printf("No tasks to remove.\n");
        return;
    }

    printf("Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, Tasks[i]);
    }

    printf("Enter task number to remove: ");
    int index;
    scanf("%d", &index);
    getchar(); // flush newline

    if (index < 1 || index > taskCount) {
        printf("Invalid index.\n");
        return;
    }

    free(Tasks[index - 1]);

    for (int i = index - 1; i < taskCount - 1; i++) {
        Tasks[i] = Tasks[i + 1];
    }

    taskCount--;
    Tasks = realloc(Tasks, taskCount * sizeof(char*));

    saveTasks();
    system("clear");
    printf("Task removed!\n");
}

// List tasks
void listTasks() {
    system("clear");

    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("Your tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, Tasks[i]);
    }

    printf("\nPress Enter to continue...");
    getchar();
    system("clear");
}

int main() {
    loadTasks();

    while (1) {
        int choice = startMenu();

        switch (choice) {
            case 1: 
                addTask(); 
                break;
            case 2:    
                removeTask(); 
                break;
            case 3: 
                listTasks(); 
                break;
            case 4:
                saveTasks();
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}
