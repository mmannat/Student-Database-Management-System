#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    string major;
};

void addStudentRecord() {
    ofstream outFile("student_database.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    Student newStudent;
    cout << "Enter student name: ";
    getline(cin >> ws, newStudent.name);
    cout << "Enter student age: ";
    cin >> newStudent.age;
    cout << "Enter student major: ";
    getline(cin >> ws, newStudent.major);

    outFile << newStudent.name << "," << newStudent.age << "," << newStudent.major << endl;
    cout << "Student record added successfully." << endl;

    outFile.close();
}

void displayStudentRecords() {
    ifstream inFile("student_database.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    cout << "Student Records:" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

void searchStudentRecord() {
    ifstream inFile("student_database.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string searchName;
    cout << "Enter student name to search: ";
    getline(cin >> ws, searchName);

    string line;
    bool found = false;
    while (getline(inFile, line)) {
        if (line.find(searchName) != string::npos) {
            cout << "Student Record Found:" << endl;
            cout << line << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student record not found." << endl;
    }

    inFile.close();
}

int main() {
    int choice;
    do {
        cout << "\nStudent Database Management System" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. Display Student Records" << endl;
        cout << "3. Search Student Record" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentRecord();
                break;
            case 2:
                displayStudentRecords();
                break;
            case 3:
                searchStudentRecord();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
