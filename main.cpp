#include <iostream>
#include <string>
using namespace std;
/*Class Definitions*/
class System;
class Student;
class Seats;

class Student
{
private:
    int rank;
    bool isAssigned = false;
    string AssignedSeatCode = "0000";
    string *choiceList;

public:
    friend class System;
    Student(int rnk, string list[]);
    void display()
    {
        cout << "Student Rank: " << rank << endl;
        cout << "Student Assigned Seat: " << AssignedSeatCode << endl;
    }
};

Student::Student(int rnk, string list[])
{
    rank = rnk;
    choiceList = list;
}

class Seats
{
private:
    string seatCode;
    int availableSeats;

public:
    friend class System;
    Seats(string code, int count);
    void display()
    {
        cout << "Seat Code: " << seatCode << endl;
        cout << "Seats Available: " << availableSeats << endl;
    }
};

Seats::Seats(string code, int count)
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
            cout << "Seat Code: " << seatsList[i].seatCode << endl;
            cout << "Available Seats: " << seatsList[i].availableSeats << endl;
        }
    }
    void displayStudents()
    {
        for (int i = 0; i < studentsListSize; i++)
        {
            cout << "Student Rank: " << studentsList[i].rank << endl;
            cout << "Assigned Seat Code: " << studentsList[i].AssignedSeatCode << endl;
            cout<<"-----------------"<<endl;
        }
    }

    void AssignSeats()
    {
        for (int i = 0; i < 15; i++)
        {   
            //cout<<"Entered Student Loop"<<endl;
            for (int j = 0; j < 3; j++)
            {  
                //cout<<"Entered Choices Loop"<<endl;
                // if studentsList[i].choiceList[j] in seatsList and its count > 0, then assign.
                for (int k = 0; k < 3; k++)
                {   //cout<<"Entered Assignment Loop"<<endl;
                    if (studentsList[i].choiceList[j] == seatsList[k].seatCode && seatsList[k].availableSeats > 0)
                    {
                        studentsList[i].AssignedSeatCode = seatsList[k].seatCode;
                        studentsList[i].isAssigned = true;
                         seatsList[k].availableSeats = seatsList[k].availableSeats - 1;
                         //cout<<"Assigned Successfully"<<endl;
                        goto exit_choices;
                    }
                    else
                    {
                        //cout<<"Assignment Failed, iterating"<<endl;
                        continue;
                    }
                    
                }
                //cout<<"Exited Assignment Loop"<<endl;
            }
            exit_choices:
            //cout<<"Exited Choices Loop"<<endl;
        }
        //cout<<"Exited Student Lopp"<<endl;
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
    string c1[] = {"0101", "0102", "0103"};
    string c2[] = {"0102", "0101", "0103"};
    string c3[] = {"0101", "0103", "0102"};
    Student s1(1, c1);
    Student s2(2, c2);
    Student s3(3, c3);
    Student s4(4, c1);
    Student s5(5, c2);
    Student s6(6, c3);
    Student s7(7, c1);
    Student s8(8, c2);
    Student s9(9, c3);
    Student s10(10, c1);
    Student s11(11, c2);
    Student s12(12, c3);
    Student s13(13, c1);
    Student s14(14, c2);
    Student s15(15, c3);

    Seats seat1("0101", 5);
    Seats seat2("0102", 5);
    Seats seat3("0103", 5);

    Student array1[] = {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15};
    Seats array2[] = {seat1, seat2, seat3};

    System sys(array2, 3, array1, 15);
    sys.AssignSeats();
    sys.displayStudents();
    return 0;
}