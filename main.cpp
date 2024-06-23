#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Student {
private:
    string lastName;
    double averageGrade;
    bool scholarship;

public:
    Student(string lname, double avg) {
        lastName = lname;
        averageGrade = avg;
        scholarship = (avg >= 4.5);
    }

    void printInfo() const {
        cout << "�������: " << lastName << endl;
        cout << "������� ���: " << fixed << averageGrade << endl;
        cout << "������ ��������: " << (scholarship ? "true" : "false") << endl;
        cout << "--------------------------" << endl;
    }

    string getLastName() const {
        return lastName;
    }

    double getAverageGrade() const {
        return averageGrade;
    }

    bool isScholarship() const {
        return scholarship;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int maxSize = 100;
    Student* students[maxSize];
    int n = 0;

    cout << "������ ��� ��� ��������:" << endl;
    cout << "(������� �������_���)" << endl;
    cout << "������ 'end' ��� ���������� �����." << endl;

    string lname;
    double avg;

    while (cin >> lname >> avg) {
        if (lname == "end") {
            break;
        }
        students[n] = new Student(lname, avg); 
        n++;
        if (n >= maxSize) {
            cerr << "���������� ������������ ����� ������ ��������." << endl;
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        students[i]->printInfo();
    }
    for (int i = 0; i < n; ++i) {
        delete students[i];
    }

    return 0;
}
