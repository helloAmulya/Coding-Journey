#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// student database management system

// one of the best and proficiently designed programs

class Student
{
public:
    int id;
    int age;
    string name;
    string department;
    Student(){};

    // Student(int id,int age,string name, string department)
    // above is defined how the values goes but due to misplace of age with name it was showing error
    Student(int id, string name, int age, string department)
    {
        this->id = id;
        this->age = age;
        this->name = name;
        this->department = department;
    }
    void display() const
    {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << ", Department: " << department << endl;
    }
};

vector<Student> readDatabase(const string &filename)
{
    vector<Student> students;
    ifstream file(filename);
    if (file.is_open())
    {
        int id, age;
        string name, department;
        while (file >> id >> name >> age >> department)
        {
            students.push_back(Student(id, name, age, department));
            /* a very silly error which took too much time
            while overloading the Student function of the class, i swapped position of age and name
            so it was taking name in age (integer) and age in place of name (string).
            try to initalize as the function says as it can cause huge error sometimes
            */
        }
        file.close();
    }
    else
    {
        cerr << " Unable to open file: " << filename << endl;
    }
    return students;
}

void writeDatabase(const string &filename, const vector<Student> &students)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (const Student &student : students)
        {
            file << student.id << " " << student.name << " " << student.age << " " << student.department << endl;
        }
        file.close();
    }
}

void addStudent(const string &filename)
{
    int id, age;
    string name, department;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name [first name only]: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Department: ";
    cin >> department;

    Student newStudent(id, name, age, department);
    vector<Student> students = readDatabase(filename);
    students.push_back(newStudent);
    writeDatabase(filename, students);
}

void displayStudents(const string &filename)
{
    vector<Student> students = readDatabase(filename);

    sort(students.begin(), students.end(), [](const Student &s1, const Student &s2)
         { return s1.id < s2.id; }); // using stl
    for (const Student &student : students)
    {

        student.display();
    }

    // to display all students sorted by ID , use sort
}

void searchStudent(const string &filename, int searchID)
{
    vector<Student> students = readDatabase(filename);
    for (const Student &student : students)
    {
        
        if (student.id == searchID)
        {
            student.display();
            return;
        }
    }
    cout << "Student with ID [" << searchID << "] not found." << endl;
}

void deleteStudent(const string &filename, int deleteID)
{
    vector<Student> students = readDatabase(filename);
    auto it = remove_if(students.begin(), students.end(), [&](const Student &student)
    { return student.id == deleteID; });
    if(it!= students.end()){
        students.erase(it,students.end());
        cout<<"Student with ID "<<deleteID<<" deleted Successfully!!"<<endl;
    }
    else{
        cout<<"Student with ID "<<deleteID<<"not found!!"<<endl;
    }

    writeDatabase(filename, students);
}

int main()
{
    string filename = "students.txt";
    int choice, searchID, deleteID;
    string admin = "admin1";
    string admin_pass;

    while (true)
    {
        cout << "\n\t\tStudent Database Management System\n";
        cout << "1. Add Student" << endl;
        cout << "2. Display All" << endl;
        cout << "3. Search Student by ID" << endl;
        cout << "4. Delete Student data [Admin only]" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice -> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent(filename);
            break;
        case 2:
            displayStudents(filename);
            break;
        case 3:
            cout << "Enter ID to search: ";
            cin >> searchID;
            searchStudent(filename, searchID);
            break;
        case 4:
            cout << "Administration Access!! Please enter password: ";
            cin >> admin_pass;
            if (admin_pass == admin)
            {
                cout << "Enter Student ID to delete -> ";
                cin >> deleteID;
                deleteStudent(filename, deleteID);
            }
            else
            {
                cout << "Incorrect password!!" << endl;
            }
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice. Please try again. \n";
        }
    }

    return 0;
}