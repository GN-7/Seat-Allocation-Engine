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
    string* choiceList;
public:
    friend class System;
    Student(int rnk, string list[]);
    void display(){
        cout<<"Student Rank: "<<rank<<endl;
        cout<<"Student Assigned Seat: "<<AssignedSeatCode<<endl;

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
    void display(){
        cout<<"Seat Code: "<<seatCode<<endl;
        cout<<"Seats Available: "<<availableSeats<<endl;

    }
};

Seats::Seats(string code, int count){
    seatCode = code;
    availableSeats = count;
}

class System
{
private:
    Seats* seatsList;
    Student* studentsList;
    int studentsListSize;
    int seatsListSize;
public:
    System(Seats array1[],int seatListSize, Student array2[], int studentListSize);
    void displaySeats(){
        for (int i = 0; i < seatsListSize; i++)
        {
            cout<<"Seat Code: "<<seatsList[i].seatCode<<endl;
            cout<<"Available Seats: "<<seatsList[i].availableSeats<<endl;
        }
        
    }
    void displayStudents(){
        for (int i = 0; i < studentsListSize; i++)
        {
            cout<<"Student Rank: "<<studentsList[i].rank<<endl;
            cout<<"Assigned Seat Code: "<<studentsList[i].AssignedSeatCode<<endl;
        }
        
    }
};

System::System(Seats array1[],int seatListSize, Student array2[], int studentListSize)
{
    seatsList=array1;
    seatsListSize=seatListSize;
    studentsList=array2;
    studentsListSize=studentListSize;
}



int main(){
    string c1[] = {"0101", "0202"};
    string c2[] = {"0101", "0102"};
    Student s1(1, c1);
    Student s2(2, c2);

    Seats seat1("0101", 10);
    Seats seat2("0102", 10);

    Student array1[] = {s1, s2};
    Seats array2[] = {seat1, seat2};
    System sys(array2, 2, array1, 2);
    sys.displaySeats();
    sys.displayStudents();
    return 0;
}