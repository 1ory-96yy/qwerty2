#include <iostream>
#include <fstream>

using namespace std;

class Student {
private:
    string surname;
    double average_grade;
    bool scholarship;

public:
    Student(string s, double avg) {
        surname = s;
        average_grade = avg;
        scholarship = (average_grade >= 4.5);
    }
    Student() {
        surname = "";
        average_grade = 0.0;
        scholarship = false;
    }
    void display() {
        cout << "Surname: " << surname << endl;
        cout << "Average Grade: " << average_grade << endl;
        cout << "Scholarship: " << (scholarship ? "true" : "false") << endl;
        cout << endl;
    }
};

int main() {
    const int MAX_STUDENTS = 5;
    Student students[MAX_STUDENTS];
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        string surname;
        double average_grade;

        cout << "Enter student's surname: ";
        cin >> surname;
        cout << "Enter student's average grade: ";
        cin >> average_grade;

        students[i] = Student(surname, average_grade);
    }
    cout << "List of students:" << endl;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        students[i].display();
    }

    return 0;
}
