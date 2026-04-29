#include <iostream>
using namespace std;

class Student {
private:
    string name;
    string course;
    string regNo;
    int semesters;
    float cgpa;

public:
    // Function to get student details
    void getStudentDetails() {
        cout << "Enter Student Name: ";
        
        getline(cin, name);

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Registration Number: ";
        getline(cin, regNo);
    }

    int getGradePoint(float marks) {
        if (marks >= 90) return 10;
        else if (marks >= 80) return 9;
        else if (marks >= 70) return 8;
        else if (marks >= 60) return 7;
        else if (marks >= 50) return 6;
        else return 0;
    }

    void calculateCGPA() {
        cout << "Enter number of semesters: ";
        cin >> semesters;

        float totalWeightedGPA = 0;
        int totalCreditsAll = 0;

        for (int s = 1; s <= semesters; s++) {
            int subjects;
            cout << "\nSemester " << s << endl;
            cout << "Enter number of subjects: ";
            cin >> subjects;

            float semTotal = 0;
            int semCredits = 0;

            for (int i = 0; i < subjects; i++) {
                float marks;
                int credit;

                cout << "Enter marks for subject " << i + 1 << ": ";
                cin >> marks;

                cout << "Enter credit for subject " << i + 1 << ": ";
                cin >> credit;

                int gp = getGradePoint(marks);

                semTotal += gp * credit;
                semCredits += credit;
            }

            float gpa = semTotal / semCredits;
            cout << "Semester " << s << " GPA = " << gpa << endl;

            totalWeightedGPA += gpa * semCredits;
            totalCreditsAll += semCredits;
        }

        cgpa = totalWeightedGPA / totalCreditsAll;
    }

    // Display function
    void displayDetails() {
        cout << "\n===== Student Details =====" << endl;
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Registration No: " << regNo << endl;
        cout << "Final CGPA: " << cgpa << endl;
    }
};

int main() {
    Student s;
    
    s.getStudentDetails();   // Input details
    s.calculateCGPA();       // Calculate CGPA
    s.displayDetails();      // Show output
    

    return 0;
}