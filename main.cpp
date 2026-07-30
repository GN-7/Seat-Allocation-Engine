#include <iostream>
#include <string>

/*Class Definitions*/
class System;
class Student;
class Seats;

class Student
{
private:
    int rank;
    bool isAssigned = false;
    std::string AssignedSeatCode = "0000";
    std::string *choiceList;

public:
    friend class System;
    Student(int rnk, std::string list[]);
    void display()
    {
        std::cout << "Student Rank: " << rank << std::endl;
        std::cout << "Student Assigned Seat: " << AssignedSeatCode << std::endl;
    }
};

Student::Student(int rnk, std::string list[])
{
    rank = rnk;
    choiceList = list;
}

class Seats
{
private:
    std::string seatCode;
    int availableSeats;

public:
    friend class System;
    Seats(std::string code, int count);
    void display()
    {
        std::cout << "Seat Code: " << seatCode << std::endl;
        std::cout << "Seats Available: " << availableSeats << std::endl;
    }
};

Seats::Seats(std::string code, int count)
{
    seatCode = code;
    availableSeats = count;
}

class System
{
private:
    Seats *seatsList;
    Student *studentsList;
    int studentsListSize;
    int seatsListSize;

public:
    System(Seats array1[], int seatListSize, Student array2[], int studentListSize);
    void displaySeats()
    {
        for (int i = 0; i < seatsListSize; i++)
        {
            std::cout << "Seat Code: " << seatsList[i].seatCode << std::endl;
            std::cout << "Available Seats: " << seatsList[i].availableSeats << std::endl;
        }
    }
    void displayStudents()
    {
        for (int i = 0; i < studentsListSize; i++)
        {
            std::cout << "Student Rank: " << studentsList[i].rank << std::endl;
            std::cout << "Assigned Seat Code: " << studentsList[i].AssignedSeatCode << std::endl;
            std::cout << "-----------------" << std::endl;
        }
    }

    void AssignSeats()
    {
        for (int i = 0; i < studentsListSize; i++)
        {
            // cout<<"Entered Student Loop"<<endl;
            for (int j = 0; j < seatsListSize; j++)
            {
                // cout<<"Entered Choices Loop"<<endl;
                //  if studentsList[i].choiceList[j] in seatsList and its count > 0, then assign.
                for (int k = 0; k < seatsListSize; k++)
                { // cout<<"Entered Assignment Loop"<<endl;
                    if (studentsList[i].choiceList[j] == seatsList[k].seatCode && seatsList[k].availableSeats > 0)
                    {
                        studentsList[i].AssignedSeatCode = seatsList[k].seatCode;
                        studentsList[i].isAssigned = true;
                        seatsList[k].availableSeats = seatsList[k].availableSeats - 1;
                        // cout<<"Assigned Successfully"<<endl;
                        goto exit_choices;
                    }
                    else
                    {
                        // cout<<"Assignment Failed, iterating"<<endl;
                        continue;
                    }
                }
                // cout<<"Exited Assignment Loop"<<endl;
            }
        exit_choices:
            std::cout << "Exited Choices Loop" << std::endl;
        }
        // cout<<"Exited Student Lopp"<<endl;
    }
};

System::System(Seats array1[], int seatListSize, Student array2[], int studentListSize)
{
    seatsList = array1;
    seatsListSize = seatListSize;
    studentsList = array2;
    studentsListSize = studentListSize;
}

int main()
{
    std::string c1[] = {"0101", "0102", "0103"};
    std::string c2[] = {"0102", "0101", "0103"};
    std::string c3[] = {"0101", "0103", "0102"};

    Student array1[] = {Student(1, c1),
                        Student(2, c2),
                        Student(3, c3),
                        Student(4, c1),
                        Student(5, c2),
                        Student(6, c3),
                        Student(7, c1),
                        Student(8, c2),
                        Student(9, c3),
                        Student(10, c1),
                        Student(11, c2),
                        Student(12, c3),
                        Student(13, c1),
                        Student(14, c2),
                        Student(15, c3)};

    Seats array2[] = {Seats("0101", 5),
                      Seats("0102", 5),
                      Seats("0103", 5)};

    System sys(array2, 3, array1, 15);
    sys.AssignSeats();
    sys.displayStudents();
    return 0;
}