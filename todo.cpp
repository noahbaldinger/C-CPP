#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>  // for system()
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

vector<string> Tasks;
const string FILENAME = "tasks.txt";

// --- load tasks ---
void loadTasks() {
    ifstream file(FILENAME);
    if (!file.is_open()) {
        cout << "No saved tasks found. Starting fresh.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            Tasks.push_back(line);
        }
    }

    file.close();
}

// --- save tasks ---
void saveTasks() {
    ofstream file(FILENAME);
    if (!file.is_open()) {
        cerr << "Error saving tasks!\n";
        return;
    }

    for (const string &task : Tasks) {
        file << task << "\n";
    }

    file.close();
}

// --- menu ---
int startMenu() {
    int choice;
    cout << "=== CLI ToDo App ===\n";
    cout << "1. Add a task\n";
    cout << "2. Remove a task\n";
    cout << "3. List all tasks\n";
    cout << "4. Exit\n";
    cout << "====================\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();
    return choice;
}

// --- add task ---
void addTask() {
    system(CLEAR);
    string addedTask;
    cout << "Enter task: ";
    getline(cin, addedTask);
    Tasks.push_back(addedTask);
    saveTasks();
    cout << "✅ Task added!\n";
    cout << "Press Enter to return to menu...";
    cin.get();
}

// --- remove task ---
void removeTask() {
    system(CLEAR);
    if (Tasks.empty()) {
        cout << "No tasks to remove.\n";
        cout << "Press Enter to return to menu...";
        cin.get();
        return;
    }

    cout << "Tasks:\n";
    for (int i = 0; i < Tasks.size(); i++) {
        cout << i + 1 << ". " << Tasks[i] << "\n";
    }

    cout << "Enter task number to remove: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > Tasks.size()) {
        cout << "Invalid index.\n";
    } else {
        Tasks.erase(Tasks.begin() + index - 1);
        saveTasks();
        cout << "✅ Task removed!\n";
    }

    cout << "Press Enter to return to menu...";
    cin.get();
}

// --- list tasks ---
void listTasks() {
    system(CLEAR);
    if (Tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        cout << "Your tasks:\n";
        for (int i = 0; i < Tasks.size(); i++) {
            cout << i + 1 << ". " << Tasks[i] << "\n";
        }
    }
    cout << "\nPress Enter to return to menu...";
    cin.get();
}

int main() {
    loadTasks();

    while (true) {
        system(CLEAR);
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
                system(CLEAR);
                cout << "Goodbye!\n";
                saveTasks();
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
}
