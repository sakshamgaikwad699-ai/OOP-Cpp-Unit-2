#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int totalDays;
    int presentDays;

public:
    Student(int r, string n)
        : rollNo(r), name(n), totalDays(0), presentDays(0) {}

    void markAttendance(bool isPresent) {
        totalDays++;
        if (isPresent) {
            presentDays++;
        }
    }

    double getAttendancePercentage() const {
        if (totalDays == 0) return 0.0;
        return (presentDays * 100.0) / totalDays;
    }

    void display() const {
        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Attendance: " << getAttendancePercentage() << "%" << endl;
    }

    bool isEligible() const {
        return getAttendancePercentage() >= 75.0;
    }
};

int main() {
    vector<Student> students;
    students.emplace_back(101, "Rahul");
    students.emplace_back(102, "Priya");
    students.emplace_back(103, "Aditya");

    students[0].markAttendance(true);
    students[0].markAttendance(true);
    students[0].markAttendance(false);

    students[1].markAttendance(true);
    students[1].markAttendance(true);
    students[1].markAttendance(true);

    students[2].markAttendance(true);
    students[2].markAttendance(false);
    students[2].markAttendance(false);

    cout << "== Attendance Report ==" << endl;
    for (const auto& s : students) {
        s.display();
    }

    cout << "\n== Defaulter Report (Below 75%) ==" << endl;
    for (const auto& s : students) {
        if (!s.isEligible()) {
            s.display();
        }
    }

    return 0;
}
