#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Tasks;
const string FILENAME = "tasks.txt";

// load tasks from file
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
  cout << "Loaded " << Tasks.size() << " tasks.\n";
}

// save tasks to file
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
  system("clear");
  cout << "Saved " << Tasks.size() << " tasks.\n";
}

// Start menu
int startMenu() {
  int choice;
  cout << "\n=== CLI ToDo App ===\n";
  cout << "1. Add a task\n";
  cout << "2. Remove a task\n";
  cout << "3. List all tasks\n";
  cout << "4. Exit\n";
  cout << "Choose an option: ";
  cin >> choice;
  cin.ignore();
  return choice;
}

// add task
void addTask() {
  string addedTask;
  system("clear");
  cout << "Enter task: ";
  getline(cin, addedTask);
  Tasks.push_back(addedTask);
  saveTasks();
  system("clear");
  cout << "Task added!\n";
}

// remove task
void removeTask() {
  system("clear");
  if (Tasks.empty()) {
    cout << "No tasks to remove.\n";
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
    return;
  }

  Tasks.erase(Tasks.begin() + index - 1);
  saveTasks();
  system("clear");
  cout << "Task removed!\n";
}

// list tasks
void listTasks() {
  if (Tasks.empty()) {
    system("clear");
    cout << "No tasks available.\n";
    return;
  }
  system("clear");
  cout << "Your tasks:\n";
  for (int i = 0; i < Tasks.size(); i++) {
    cout << i + 1 << ". " << Tasks[i] << "\n";
  }
  string a;
  getline(cin, a);
  system("clear");
}

int main() {
  loadTasks();

  while (true) {
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
      cout << "Invalid choice.\n";
      break;
    }
  }
}
