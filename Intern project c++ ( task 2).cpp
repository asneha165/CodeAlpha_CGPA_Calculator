#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <windows.h>

using namespace std;

/* =========================================================
                    COLOR FUNCTIONS
   ========================================================= */

void setColor(int color)
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        color
    );
}

void resetColor()
{
    setColor(7);
}

void showTitle()
{
    setColor(11);
}

void showSuccess()
{
    setColor(10);
}

void showError()
{
    setColor(12);
}

void showMenu()
{
    setColor(14);
}

void showInfo()
{
    setColor(11);
}

/* =========================================================
                       COURSE CLASS
   ========================================================= */

class Course
{
private:
    string courseName;
    string grade;
    double creditHours;
    double gradePoint;

public:

    Course(
        string name,
        string g,
        double credits,
        double points
    )
    {
        courseName = name;
        grade = g;
        creditHours = credits;
        gradePoint = points;
    }

    string getCourseName()
    {
        return courseName;
    }

    string getGrade()
    {
        return grade;
    }

    double getCreditHours()
    {
        return creditHours;
    }

    double getGradePoint()
    {
        return gradePoint;
    }

    double getTotalGradePoints()
    {
        return creditHours * gradePoint;
    }
};

/* =========================================================
                  GET NUMBER OF COURSES
   ========================================================= */

int getNumberOfCourses()
{
    int number;

    while (true)
    {
        showMenu();

        cout << "Enter Number of Courses (1-20): ";

        resetColor();

        if (cin >> number)
        {
            if (number >= 1 && number <= 20)
            {
                cin.ignore(10000, '\n');
                return number;
            }
        }

        showError();

        cout << "Error: Please enter a number between 1 and 20."
             << endl;

        resetColor();

        cin.clear();
        cin.ignore(10000, '\n');
    }
}

/* =========================================================
                    GET COURSE NAME
   ========================================================= */

string getCourseName()
{
    string name;

    while (true)
    {
        showMenu();

        cout << "Enter Course Name: ";

        resetColor();

        getline(cin, name);

        if (name.length() > 0)
        {
            return name;
        }

        showError();

        cout << "Error: Course name cannot be empty."
             << endl;

        resetColor();
    }
}

/* =========================================================
                    GET CREDIT HOURS
   ========================================================= */

double getCreditHours()
{
    double credits;

    while (true)
    {
        showMenu();

        cout << "Enter Credit Hours (1-6): ";

        resetColor();

        if (cin >> credits)
        {
            if (credits >= 1 && credits <= 6)
            {
                cin.ignore(10000, '\n');
                return credits;
            }
        }

        showError();

        cout << "Error: Credit hours must be between 1 and 6."
             << endl;

        resetColor();

        cin.clear();
        cin.ignore(10000, '\n');
    }
}

/* =========================================================
                      GET GRADE POINT
   ========================================================= */

double getGradePoint(string &grade)
{
    while (true)
    {
        showMenu();

        cout << "Enter Grade (A+, A, B+, B, C+, C, D, F): ";

        resetColor();

        cin >> grade;

        if (grade == "a+")
            grade = "A+";

        else if (grade == "a")
            grade = "A";

        else if (grade == "b+")
            grade = "B+";

        else if (grade == "b")
            grade = "B";

        else if (grade == "c+")
            grade = "C+";

        else if (grade == "c")
            grade = "C";

        else if (grade == "d")
            grade = "D";

        else if (grade == "f")
            grade = "F";


        if (grade == "A+" || grade == "A")
        {
            cin.ignore(10000, '\n');
            return 4.00;
        }

        if (grade == "B+")
        {
            cin.ignore(10000, '\n');
            return 3.50;
        }

        if (grade == "B")
        {
            cin.ignore(10000, '\n');
            return 3.00;
        }

        if (grade == "C+")
        {
            cin.ignore(10000, '\n');
            return 2.50;
        }

        if (grade == "C")
        {
            cin.ignore(10000, '\n');
            return 2.00;
        }

        if (grade == "D")
        {
            cin.ignore(10000, '\n');
            return 1.00;
        }

        if (grade == "F")
        {
            cin.ignore(10000, '\n');
            return 0.00;
        }

        showError();

        cout << "Error: Invalid grade. Please try again."
             << endl;

        resetColor();
    }
}

/* =========================================================
                     DISPLAY RESULT
   ========================================================= */

void displayResult(vector<Course> &courses)
{
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    int i;

    showTitle();

    cout << endl;
    cout << "============================================================"
         << endl;

    cout << "                    CGPA RESULT                             "
         << endl;

    cout << "============================================================"
         << endl;

    resetColor();

    showInfo();

    cout << left
         << setw(25) << "Course"
         << setw(12) << "Grade"
         << setw(15) << "Credit Hours"
         << setw(15) << "Grade Points"
         << endl;

    showTitle();

    cout << "------------------------------------------------------------"
         << endl;

    resetColor();

    /* C++98 compatible loop */
    for (i = 0; i < (int)courses.size(); i++)
    {
        cout << left
             << setw(25) << courses[i].getCourseName()
             << setw(12) << courses[i].getGrade()
             << setw(15) << fixed << setprecision(2)
             << courses[i].getCreditHours()
             << setw(15)
             << courses[i].getGradePoint()
             << endl;

        totalCredits =
            totalCredits + courses[i].getCreditHours();

        totalGradePoints =
            totalGradePoints + courses[i].getTotalGradePoints();
    }

    showTitle();

    cout << "------------------------------------------------------------"
         << endl;

    resetColor();

    showMenu();

    cout << "Total Credit Hours : ";

    resetColor();

    cout << fixed << setprecision(2)
         << totalCredits << endl;

    showMenu();

    cout << "Total Grade Points : ";

    resetColor();

    cout << fixed << setprecision(2)
         << totalGradePoints << endl;

    double cgpa = 0.0;

    if (totalCredits > 0)
    {
        cgpa = totalGradePoints / totalCredits;
    }

    showSuccess();

    cout << endl;
    cout << "FINAL CGPA         : "
         << fixed << setprecision(2)
         << cgpa << endl;

    showTitle();

    cout << "============================================================"
         << endl;

    resetColor();
}

/* =========================================================
                           MAIN
   ========================================================= */

int main()
{
    system("color 0B");

    showTitle();

    cout << endl;
    cout << "=================================================="
         << endl;

    cout << "                 CGPA CALCULATOR                  "
         << endl;

    cout << "=================================================="
         << endl;

    resetColor();

    int numberOfCourses =
        getNumberOfCourses();

    vector<Course> courses;

    int i;

    for (i = 0; i < numberOfCourses; i++)
    {
        showInfo();

        cout << endl;
        cout << "--------------- COURSE "
             << i + 1
             << " ----------------"
             << endl;

        resetColor();

        string courseName =
            getCourseName();

        double creditHours =
            getCreditHours();

        string grade;

        double gradePoint =
            getGradePoint(grade);

        Course course(
            courseName,
            grade,
            creditHours,
            gradePoint
        );

        courses.push_back(course);

        showSuccess();

        cout << "Course added successfully!"
             << endl;

        resetColor();
    }

    displayResult(courses);

    showSuccess();

    cout << endl;
    cout << "CGPA calculation completed successfully!"
         << endl;

    resetColor();

    return 0;
}
