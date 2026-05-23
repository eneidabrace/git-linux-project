#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    double grade;
};

void addStudent(Student students[], int &count) {
    cout << "\nEnter student name: ";
    cin >> students[count].name;

    cout << "Enter age: ";
    cin >> students[count].age;

    cout << "Enter grade: ";
    cin >> students[count].grade;

    count++;

    cout << "\nStudent added successfully!\n";
}

void displayStudents(Student students[], int count) {

    if(count == 0) {
        cout << "\nNo students found.\n";
        return;
    }

    cout << "\n------ Student List ------\n";

    for(int i = 0; i < count; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Grade: " << students[i].grade << endl;
    }
}

double calculateAverage(Student students[], int count) {

    if(count == 0)
        return 0;

    double sum = 0;

    for(int i = 0; i < count; i++) {
        sum += students[i].grade;
    }

    return sum / count;
}

void searchStudent(Student students[], int count) {

    string searchName;
    bool found = false;

    cout << "\nEnter student name to search: ";
    cin >> searchName;

    for(int i = 0; i < count; i++) {

        if(students[i].name == searchName) {

            cout << "\nStudent found!\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Grade: " << students[i].grade << endl;

            found = true;
        }
    }

    if(!found)
        cout << "\nStudent not found.\n";
}

// ✅ EDIT STUDENT (NEW IN V3)
void editStudent(Student students[], int count) {

    string name;
    bool found = false;

    cout << "\nEnter student name to edit: ";
    cin >> name;

    for(int i = 0; i < count; i++) {

        if(students[i].name == name) {

            cout << "\nEnter new age: ";
            cin >> students[i].age;

            cout << "Enter new grade: ";
            cin >> students[i].grade;

            cout << "\nStudent updated successfully!\n";

            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nStudent not found.\n";
}

// ✅ DELETE STUDENT (NEW IN V3)
void deleteStudent(Student students[], int &count) {

    string name;
    bool found = false;

    cout << "\nEnter student name to delete: ";
    cin >> name;

    for(int i = 0; i < count; i++) {

        if(students[i].name == name) {

            for(int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;

            cout << "\nStudent deleted successfully!\n";

            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nStudent not found.\n";
}

int main() {

    Student students[100];
    int count = 0;
    int choice;

    do {

        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Search Student\n";
        cout << "5. Edit Student\n";
        cout << "6. Delete Student\n";
        cout << "7. Exit\n";

        cout << "\nChoose option: ";
        cin >> choice;

        switch(choice) {

            case 1:
                addStudent(students, count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                cout << "\nAverage grade: "
                     << calculateAverage(students, count)
                     << endl;
                break;

            case 4:
                searchStudent(students, count);
                break;

            case 5:
                editStudent(students, count);
                break;

            case 6:
                deleteStudent(students, count);
                break;

            case 7:
                cout << "\nProgram closed.\n";
                break;

            default:
                cout << "\nInvalid option!\n";
        }

    } while(choice != 7);

    return 0;
}
