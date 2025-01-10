#include <iostream>
#include <string>

using namespace std;

const int max_tasks = 100;

struct Task {
    string description;
    bool isDone;
};

int main() {
    Task tasks[max_tasks];
    int numTasks = 0;

    while (true) {
        cout << "To Do List Application" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Complete" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        if (choice == 1) {
            if (numTasks < max_tasks) {
                cout << "Enter task description: ";
                cin.ignore(); // Clear input buffer
                getline(cin, tasks[numTasks].description);
                tasks[numTasks].isDone = false;
                numTasks++;
                cout << "Task Added!" << endl;
            } else {
                cout << "Task list is full. Cannot add more tasks." << endl;
            }
        } else if (choice == 2) {
            cout << "Tasks:" << endl;
            for (int i = 0; i < numTasks; i++) {
                cout << (i + 1) << ". ";
                if (tasks[i].isDone) {
                    cout << "[x] ";
                } else {
                    cout << "[ ] ";
                }
                cout << tasks[i].description << endl;
            }
        } else if (choice == 3) {
            cout << "Enter the task number to mark as done: ";
            int taskNumber;
            cin >> taskNumber;
            if (taskNumber > 0 && taskNumber <= numTasks) {
                tasks[taskNumber - 1].isDone = true;
                cout << "Task Marked as Done!" << endl;
            } else {
                cout << "Invalid task number." << endl;
            }
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

