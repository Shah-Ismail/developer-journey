#include <iostream>
#include <fstream>
using namespace std;

struct student
{
    int id;
    string name;
    float gpa;
};

void add_student();
void view_student();
void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice;
    do
    {
        cout << "\n-----------STUDENT_MANAGER----------" << endl
             << "\nChoose one option 1 - 3:" << endl
             << "1. Add Student." << endl
             << "2. View Student." << endl
             << "3. Exit." << endl
             << "\nEnter Choice: ";
        cin >> choice;
    
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            view_student();
            break;
        case 3:
            cout<<"Exiting Program...";
            break;
        default:
            break;
        }
    } while (choice != 3);
    
    return;
}

void add_student()
{
    student s;
    ofstream file("students.txt", ios::app);

    cout << "Enter ID : ";
    cin >> s.id;
    cout << "Enter Name : ";
    cin >> s.name;
    cout << "Enter GPA : ";
    cin >> s.gpa;

    file << s.id << " " << s.name << " " << s.gpa << endl;
    file.close();

    cout << "Student Added Sucessfully!\n";
}

void view_student()
{
    student s;
    ifstream file("students.txt");

    while (file >> s.id >> s.name >> s.gpa)
    {
        cout << "\nID : " << s.id;
        cout << "\nName : " << s.name;
        cout << "\nGPA : " << s.gpa;
    }

    file.close();    
}