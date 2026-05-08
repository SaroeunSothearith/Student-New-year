#include <iostream>
using namespace std;

struct Student {
    string name;
    int age{};
    float score{};
};

Student s[100];
int countStudents = 0;

// Add Student
void addStudent() {
    cout << "\nEnter name: ";
    cin >> s[countStudents].name;

    cout << "Enter age: ";
    cin >> s[countStudents].age;

    cout << "Enter score: ";
    cin >> s[countStudents].score;

    countStudents++;
    cout << "Student added successfully!\n";
}

// Show Students
void showStudents() {
    cout << "\n===== Student List =====\n";

    if (countStudents == 0) {
        cout << "No students found!\n";
        return;
    }

    for (int i = 0; i < countStudents; i++) {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Age: " << s[i].age << endl;
        cout << "Score: " << s[i].score << endl;
        cout << "----------------------\n";
    }
}

// Search Student
void searchStudent() {
    string name;
    cout << "\nEnter name to search: ";
    cin >> name;

    for (int i = 0; i < countStudents; i++) {
        if (s[i].name == name) {
            cout << "Found Student!\n";
            cout << "Name: " << s[i].name << endl;
            cout << "Age: " << s[i].age << endl;
            cout << "Score: " << s[i].score << endl;
            return;
        }
    }

    cout << "Student not found!\n";
}

// Delete Student
void deleteStudent() {
    string name;
    cout << "\nEnter name to delete: ";
    cin >> name;

    for (int i = 0; i < countStudents; i++) {
        if (s[i].name == name) {
            for (int j = i; j < countStudents - 1; j++) {
                s[j] = s[j + 1];
            }

            countStudents--;
            cout << "Student deleted successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Show Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Goodbye 👋\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}