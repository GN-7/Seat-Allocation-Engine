#include <iostream>
#include <string>

/*Class Definitions*/
class AllocationEngine;
class Student;
class Seats;

class Student
{
private:
    int rank;
    bool isAssigned = false;
    std::string AssignedSeatCode = "0000";
    std::string *choiceList;
    int choiceCount;
    

public:
    friend class AllocationEngine;
    Student(int rnk, std::string list[], int count);
    void display()
    {
        std::cout << "Student Rank: " << rank << std::endl;
        std::cout << "Student Assigned Seat: " << AssignedSeatCode << std::endl;
    }
};

Student::Student(int rnk, std::string list[], int count)
{
    rank = rnk;
    choiceList = list;
    choiceCount = count;
}

class Seats
{
private:
    std::string seatCode;
    int availableSeats;

public:
    friend class AllocationEngine;
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

class AllocationEngine
{
private:
    Seats *seatsList;
    Student *studentsList;
    int studentsListSize;
    int seatsListSize;

public:
    AllocationEngine(Seats array1[], int seatListSize, Student array2[], int studentListSize);
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
            for (int j = 0; j < studentsList[i].choiceCount; j++)
            { 
                for (int k = 0; k < seatsListSize; k++)
                {
                    if (studentsList[i].choiceList[j] == seatsList[k].seatCode && seatsList[k].availableSeats > 0)
                    {
                        studentsList[i].AssignedSeatCode = seatsList[k].seatCode;
                        studentsList[i].isAssigned = true;
                        if (seatsList[k].availableSeats == 1)
                        {
                            std::cout<<"The closing rank for seat with code "<<seatsList[k].seatCode<<" is "<<studentsList[i].rank<<std::endl;
                        }
                        
                        seatsList[k].availableSeats = seatsList[k].availableSeats - 1;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                if (studentsList[i].isAssigned){
                    break;
                }
            }

        }
    }

    void displayUnAssignedStudents(){
        for (int i = 0; i < studentsListSize; i++)
        {
            if (studentsList[i].isAssigned == false)
            {
                studentsList[i].display();
            }
            
        }
        
    }
};

AllocationEngine::AllocationEngine(Seats array1[], int seatListSize, Student array2[], int studentListSize)
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

    Student students[] = {Student(1, c1, 3),
                        Student(2, c2, 3),
                        Student(3, c3, 3),
                        Student(4, c1, 3),
                        Student(5, c2, 3),
                        Student(6, c3, 3),
                        Student(7, c1, 3),
                        Student(8, c2, 3),
                        Student(9, c3, 3),
                        Student(10, c1, 3),
                        Student(11, c2, 3),
                        Student(12, c3, 3),
                        Student(13, c1, 3),
                        Student(14, c2, 3),
                        Student(15, c3, 3),
                        Student(16, c1, 3),
                        Student(17, c2, 3),
                        Student(18, c3, 3)};

    Seats seats[] = {Seats("0101", 5),
                      Seats("0102", 5),
                      Seats("0103", 5)};

    AllocationEngine sys(seats, 3, students, 18);
    sys.AssignSeats();
    sys.displayUnAssignedStudents();
    return 0;
}