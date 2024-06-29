#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Login and Registration System
// a password [admin1] is required to display all users but also has error
// it only displays only first line of the file and not all content


// **delete function has some error which needs to be fixed

void registeruser()
{
    string username, password;
    // for storing new user and password
    cout << "!!Register User!!" << endl;
    cout << "Enter username->";
    cin >> username;
    cout << "Enter password [alphanumeric]->  ";
    cin >> password;

    ofstream file("user.txt", ios::app);
    if (file.is_open())
    {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration Successful" << endl;
    }
    else
    {
        cout << "File cannot be opened for writing!!" << endl;
    }
}

void displayuser()
{
    string fileusername, filepassword, admin = "admin1", admin_pass;
    string line;
    ifstream file("user.txt");
    if (file.is_open())
    {
        cout << "Administration Access, Password reuired!! -> ";
        cin >> admin_pass;
        if (admin_pass == admin)
        {
            while (file >> fileusername >> filepassword)
            {
                cout << "username: " << fileusername << ", password: " << filepassword << endl;
                file.close();
                return;
            }
        }
        else
        {
            cout << "Invalid password\nAccess not granted ";
        }
    }
    file.close();
}
void deleteuser()
{

    string username, password, fileusername, filepassword;
    cout << "Enter username-> ";
    cin >> username;
    cout << "Enter password-> ";
    cin >> password;

    ifstream file("user.txt");
    ofstream tempfile("temp.txt");
    bool userfound = false;
    if (file.is_open() && tempfile.is_open())
    {
        while (file >> fileusername >> filepassword)
        {
            if (fileusername == username && filepassword == password)
            {
                userfound = true;
            }
            else
            {
                tempfile << fileusername << " " << filepassword << endl;
            }
        }
        file.close();
        tempfile.close();

        remove("user.txt");
        rename("temp.txt", "user.txt");

        if (userfound)
        {
            cout << "User deleted successfully!" << endl;
        }
        else
        {
            cout << "User not found or incorrect password." << endl;
        }
    }
    else
    {
        cout << "Unable to open file for processing." << endl;
    }
}

bool userLogin()
{
    string username, password, fileusername, filepassword;
    cout << "Enter username -> ";
    cin >> username;
    cout << "Enter password -> ";
    cin >> password;

    // verifying that the user exists or not
    ifstream file("user.txt");
    if (file.is_open())
    {
        while (file >> fileusername >> filepassword)
        {
            if (fileusername == username && filepassword == password)
            {
                file.close();
                return true;
            }
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file for reading!!" << endl;
    }
    return false;
}

int main()
{
    int choice;
    cout << "1.Register user " << "2.Login user " << "3.Display all user " << "4.Delete user ->";
    cin >> choice;

    if (choice == 1)
    {
        registeruser();
    }
    else if (choice == 2)
    {
        if (userLogin())
        {
            cout << "Login Successful " << endl;
        }
        else
        {
            cout << "Invalid username or password." << endl;
        }
    }
    else if (choice == 3)
    {
        displayuser();
    }
    else if (choice == 4)
    {
        cout<<"Enter credentials: "<<endl;
        deleteuser();
    }
    else
    {
        cout << "Invalid option,try again!" << endl;
    }
    return 0;
}