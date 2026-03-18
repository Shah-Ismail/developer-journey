#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

struct Student
{
    int id;
    string name;
    float gpa;
};

void add_student();
void view_all();
void search_student();
void delete_student();
void update_gpa();
string name_adder(string name);
string name_remover(string name);

int main()
{
	int choice;
	while (true)
	{
	    cout << "\n----------STUDENT MANAGEMENT SYSTEM----------\n\n";
	    cout << "Choose an operation : \n";
	    cout << "1.Add student.\n";
	    cout << "2.View all students.\n";
	    cout << "3.Search student.\n";
	    cout << "4.Delete student.\n";
	    cout << "5.Update GPA.\n";
	    cout << "6.Exit.\n";
	    
	    cout << "\nEnter your choice here : ";
	    cin >> choice;
	    
	    switch (choice)
	    {
	        case 1:
	            add_student();
	            break;
	        case 2:
	            view_all();
	            break;
	        case 3:
	            search_student();
	            break;
	        case 4:
	            delete_student();
	            break;
	        case 5:
	            update_gpa();
	            break;
	        case 6:
	            cout << "\nExiting...\n";
	            return 0; 
	        default:
	            cout << "\nInvalid Input\n";
	            break;
	    }
	}
}

void add_student()
{
    Student s;
    bool gpa_invalid = true;
    
    ofstream file("students.txt", ios::app);
    
    if (!file)
    {
        cout << "\nerror! file not opening.\n";
        return;
    }
    
    cout << "\nEnter student id : ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter student name : ";
    getline(cin, s.name);
    s.name = name_adder(s.name);
    
    while (gpa_invalid)
    {
        cout << "Enter new GPA : ";
        cin >> s.gpa;
        if (s.gpa < 0 || s.gpa > 4)
        {
            cout << "\nGPA must be in between 0-4.\n";
            gpa_invalid = true;
            continue ;
        }
        gpa_invalid = false;
    }
    
    file << s.id << " " << s.name << " " << s.gpa << endl;
    
    file.close();
    cout << "\nStudent added successfully!\n";
}

void view_all()
{
    Student s;
    ifstream file("students.txt");
    
    if (!file)
    {
        cout << "\nNo student record exist!\n";
        return ;
    }
    
    cout << "\n-----Record List------\n";
    
    while (file >> s.id >> s.name >> s.gpa)
    {
        s.name = name_remover(s.name);
        cout << "ID : " << s.id << " | Name : " << s.name << " | GPA : " << s.gpa << endl;
    }
    
    file.close();
}

void search_student()
{
    int targetID;
    bool found = false;
    Student s;
    
    cout << "\nEnter target ID for search : ";
    cin >> targetID; 
    ifstream file("students.txt");
    
    if (!file)
    {
        cout << "\nerror! file not opened!\n";
        return;
    }
    
    while (file >> s.id >> s.name >> s.gpa)
    {
        if (s.id == targetID)
        {
            s.name = name_remover(s.name);
            cout << "\nRecord found :\n\n";
            cout << "ID : " << s.id << " | Name : " << s.name << " | GPA : " << s.gpa << endl;
            found= true;
            break;
        }
    }
    
    if(!found)
    {
        cout << endl << targetID << " not found!\n";
    }
    file.close();
}

void delete_student()
{
    int targetID;
    bool found = false;
    Student s;
    cout << "\nEnter target ID to delete : ";
    cin >> targetID;
    
    ifstream file1("students.txt");
    
    if (!file1)
    {
        cout << "\nerror! file not opened!\n";
        return ;
    }
    ofstream file2("temp.txt");
    
    while (file1 >> s.id >> s.name >> s.gpa)
    {
        if (s.id == targetID)
        {
            found = true;
            continue;
        }
        file2 << s.id << " " << s.name << " " << s.gpa << endl;
    }
    
    file1.close();
    file2.close();
    
    if (found == true)
    {
        cout << "\nID(" << targetID << ") deleted successfully.\n";
        remove("students.txt");
        rename("temp.txt", "students.txt");
    }
    else 
    {
        cout << "\nID(" << targetID << ") not found in records.\n";
        remove("temp.txt");
    }
}

void update_gpa()
{
    int targetID;
    float new_gpa;
    bool found = false;
    Student s;
    cout << "\nEnter target ID to update GPA : ";
    cin >> targetID;
    
    ifstream file1("students.txt");
    
    if (!file1)
    {
        cout << "\nerror! file not opened!\n";
        return ;
    }
    ofstream file2("temp.txt");
    
    while (file1 >> s.id >> s.name >> s.gpa)
    {
        if (s.id == targetID)
        {
            found = true;
            bool gpa_invalid = true;
            cout << endl << targetID << " found.\n";
            while (gpa_invalid)
            {
                cout << "Enter new GPA : ";
                cin >> new_gpa;
                if (new_gpa < 0 || new_gpa > 4)
                {
                    cout << "\nGPA must be in between 0-4.\n";
                    gpa_invalid = true;
                    continue ;
                }
                gpa_invalid = false;
            }
            s.gpa = new_gpa;
        }
        file2 << s.id << " " << s.name << " " << s.gpa << endl;
    }
    
    file1.close();
    file2.close();
    
    if (found == true)
    {
        cout << "\nID(" << targetID << ")\'s GPA updated successfully.\n";
        remove("students.txt");
        rename("temp.txt", "students.txt");
    }
    else 
    {
        cout << "\nID(" << targetID << ") not found in records.\n";
        remove("temp.txt");
    }
}

string name_adder(string name)
{
    int n = name.length();
    string new_name = "";
    char c;
    for (int i = 0; i < n; i++)
    {
        c = name[i];
        if (c == ' ')
        {
            new_name += '_';
            continue;
        }
        new_name += c;
    }
    return new_name;
}

string name_remover(string name)
{
    int n = name.length();
    string new_name = "";
    char c;
    for (int i = 0; i < n; i++)
    {
        c = name[i];
        if (c == '_')
        {
            new_name += ' ';
            continue;
        }
        new_name += c;
    }
    return new_name;
}