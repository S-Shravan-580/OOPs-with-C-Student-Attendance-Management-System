#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string.h>
using namespace std;

struct Student
{
    std::string name;
    std::string subject1;
    int score1;
    std::string subject2;
    int score2;
};

namespace greetings
{
    void HomeDisplay()
    {
        cout << "--------WELCOME--------";
    }

}

struct User
{
    std::string username;
    std::string password;
    // Add more user-related fields as needed
};

bool userExists(const std::vector<User> &users, const std::string &username)
{
    for (const auto &user : users)
    {
        if (user.username == username)
        {
            return true;
        }
    }
    return false;
}

bool validatePassword(const std::vector<User> &users, const std::string &username, const std::string &password)
{
    for (const auto &user : users)
    {
        if (user.username == username && user.password == password)
        {
            return true;
        }
    }
    return false;
}

class user
{
public:
    string username;
    int Age;
    void virtual GenerateReport() = 0;
};

class Teacher : public user
{
    string Department;

public:
    int function_t();
    void incrementScore(std::vector<Student> &students, const std::string &subject);
    void GenerateReport();
};

void Teacher ::incrementScore(std::vector<Student> &students, const std::string &subject)
{

    char choice;
    for (auto &student : students)
    {
        std::cout << "Name: " << std::setw(10) << student.name
                  << ", Subject: " << std::setw(10) << subject
                  << ", Current Score: " << std::setw(5) << ((subject == student.subject1) ? student.score1 : student.score2)
                  << ", Increment the score? (Y/N): ";

        std::cin >> choice;
        if (std::toupper(choice) == 'Y')
        {
            if (subject == student.subject1)
            {
                ++student.score1;
            }
            else if (subject == student.subject2)
            {
                ++student.score2;
            }
            // Add more conditions for additional subjects if needed
        }
    }
}

int Teacher::function_t()
{
    // Create a vector to store structs
    std::vector<Student> studentsVector;

    // Open the input file in read mode
    ifstream inputFile("att.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Loop to read values from the file and store them in the vector
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        Student temp;
        if (!(iss >> temp.name >> temp.subject1 >> temp.score1 >> temp.subject2 >> temp.score2))
        {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }
        studentsVector.push_back(temp);
    }

    // Close the input file
    inputFile.close();

    // Take user input to determine which subject's scores to increment
    std::string subject;
    std::cout << "\nEnter the subject to update (subject1 or subject2): ";
    std::cin >> subject;

    // Increment the score in the vector based on user input
    incrementScore(studentsVector, subject);

    // Open the input file in write mode to overwrite it
    std::ofstream outputFile("att.txt");
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    // Overwrite the updated vector to the output file
    for (const auto &student : studentsVector)
    {
        outputFile << student.name << " " << student.subject1 << " " << student.score1
                   << " " << student.subject2 << " " << student.score2 << std::endl;
    }

    // Close the output file
    outputFile.close();

    return 0;
}

void Teacher::GenerateReport()
{
    std::vector<Student> studentsVector;
    std::ifstream inputFile("att.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
    }

    // Loop to read values from the file and store them in the vector
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        Student temp;
        if (!(iss >> temp.name >> temp.subject1 >> temp.score1 >> temp.subject2 >> temp.score2))
        {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }
        studentsVector.push_back(temp);
    }

    // Close the input file
    inputFile.close();

    cout << endl;
    std::cout << "Current data:" << std::endl;
    for (const auto &student : studentsVector)
    {
        std::cout << "Name: " << student.name
                  << ", Subject1: " << student.subject1 << ", Score1: " << student.score1
                  << ", Subject2: " << student.subject2 << ", Score2: " << student.score2 << std::endl;
    }
}

class Studentclass : public user
{
private:
    struct Student fin;

public:
    void GenerateReport(){

    };

    void inline view(string Username, Studentclass *obj);
};

void inline Studentclass::view(string Username, Studentclass *obj)
{
    std::vector<Student> studentsVector;
    std::ifstream inputFile("att.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
    }

    // Loop to read values from the file and store them in the vector
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        Student temp;
        if (!(iss >> temp.name >> temp.subject1 >> temp.score1 >> temp.subject2 >> temp.score2))
        {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }
        if (strcmp((temp.name).c_str(), Username.c_str()) == 0)
        {
            obj->fin=temp;
        }
    }

    // Close the input file
    inputFile.close();

    cout << endl;
    std::cout << "Current data:" << std::endl;
    for (const auto &student : studentsVector)
   /* {
        std::cout << "Name: " << student.name
                  << ", Subject1: " << student.subject1 << ", Score1: " << student.score1
                  << ", Subject2: " << student.subject2 << ", Score2: " << student.score2 << std::endl;
    }*/

    cout<<"ATTENDANCE REPORT";
    cout<<"-----------------";
    cout<<"\nSubject 1:"<<fin.subject1<<" No of classes attended:"<<fin.score1<<endl;
    cout<<"Subject 2:"<<fin.subject2<<"No of classes attended:"<<fin.score2<<endl;
}

int main()

{

    using namespace greetings;
    cout << endl;
    greetings::HomeDisplay();
    cout << endl;
    cout << endl;
    cout << "ATTENDANCE MANAGMENT DATABASE" << endl;

   
        try
        {

            cout << "\nPlease choose mode: " << endl;
            cout << "Teacher [1] | Student [2] | Exit [0]" << endl;
            int st;
            cout << "Enter an integer: ";
            cin >> st;

            if (!cin.good())
            {

                throw invalid_argument("Invalid input");
            }

            if (st == 1)
            {
                Teacher ob;
                std::vector<User> users;
                std::ifstream inputFile("Teacher.txt");
                if (!inputFile.is_open())
                {
                    std::cerr << "Error opening file." << std::endl;
                    return 1;
                }
                std::string line;
                while (std::getline(inputFile, line))
                {
                    std::istringstream is1(line);
                    User temp;
                    if (!(is1 >> temp.username >> temp.password))
                    {
                        std::cerr << "Error reading line: " << line << std::endl;
                        continue;
                    }
                    users.push_back(temp);
                }
                std::string enteredUsername;
                std::cout << "Enter your username: ";
                std::cin >> enteredUsername;

                // Check if the entered username exists
                if (userExists(users, enteredUsername))
                {
                    // If the username exists, ask for the password
                    std::string enteredPassword;
                    std::cout << "Enter your password: ";
                    std::cin >> enteredPassword;

                    if (validatePassword(users, enteredUsername, enteredPassword))
                    {
                        std::cout << "Access granted. You can now proceed with other functions." << std::endl;
                        int choice = 0;
                        do
                        {
                            cout << endl;
                            cout << "------------Menu-----------";
                            cout << endl;

                            cout << "Enter ( 1 ) to take attendance." << endl;
                            cout << "Enter ( 2 ) to generate a report" << endl;
                            cout << "Enter ( 3 ) to exit." << endl;
                            cout << endl;
                            cout << "Option:";
                            cin >> choice;
                            if (choice == 3)
                            {
                                cout << endl
                                     << "Thank You";
                            }
                            switch (choice)
                            {

                            case 1:
                                ob.function_t();
                                break;

                            case 2:
                                ob.GenerateReport();
                                break;

                            case 3:
                                cout << "Exiting out of process.";
                                break;
                            }

                        } while (choice != 3);
                    }
                    else
                    {
                        std::cout << "Incorrect password. Access denied." << std::endl;
                    }
                }
                else
                {
                    std::cout << "User not found. Access denied." << std::endl;
                }

                return 0;
            }
            else if (st == 2)

            {

                Studentclass obj;
                std::vector<User> users;
                std::ifstream inputFile("Student.txt");
                if (!inputFile.is_open())
                {
                    std::cerr << "Error opening file." << std::endl;
                    return 1;
                }
                std::string line;
                while (std::getline(inputFile, line))
                {
                    std::istringstream is1(line);
                    User temp;
                    if (!(is1 >> temp.username >> temp.password))
                    {
                        std::cerr << "Error reading line: " << line << std::endl;
                        continue;
                    }
                    users.push_back(temp);
                }

                cout << "Placeholder:Student " << endl;
                std::string enteredUsername;
                std::cout << "Enter your username: ";
                std::cin >> enteredUsername;

                if (userExists(users, enteredUsername))
                {
                    // If the username exists, ask for the password
                    std::string enteredPassword;
                    std::cout << "Enter your password: ";
                    std::cin >> enteredPassword;

                    if (validatePassword(users, enteredUsername, enteredPassword))
                    {
                        std::cout << "Access granted. You can now proceed with other functions." << std::endl;
                        cout << endl;
                        cout << "------------Menu-----------";
                        cout << endl;

                        cout << "Enter ( 1 ) to view Attendance." << endl;
                        cout << "Enter ( 2 ) to exit." << endl;
                        cout << endl;

                        int choice = -1;

                        do
                        {
                            cout << "\nOption:";
                            cin >> choice;
                            switch (choice)
                            {
                            case 1:
                             obj.view(enteredUsername,&obj);

                                
                                break;

                            case 2:
                            cout<<endl<<"Thank you";
                            break;

                            default:
                            cout<<"enter a valid option";
                            break;
                            }

                        } while (choice != 2);
                    }
                    else
                    {
                        cout<<"\n Invalid Username/Password";
                    }
                }
            }
            else if(st==0)
            {
                exit(0);
            }
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    
    

    /*  else
      {
       cout<<"Placeholder:invalid";
      }*/
}