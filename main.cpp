#include <iostream>
#include <string>
using namespace std;
/*Class Definitions*/
//class System;
class Student;
class Seats;

class Student
{
private:
    int rank;
    bool isAssigned = false;
    std::string AssignedSeatCode = "0000";
    int* choiceList;
public:
    //friend System;
    Student(int rnk, int list[]);
    void display(){
        cout<<"Student Rank: "<<rank<<endl;
        cout<<"Student Assigned Seat: "<<AssignedSeatCode<<endl;

    }
};

Student::Student(int rnk, int list[])
{
    rank = rnk;
    choiceList = list;
}

class Seats
{
private:
    int seatCode;
    int availableSeats;
public:
    Seats(int code, int count);
    void display(){
        cout<<"Seat Code: "<<seatCode<<endl;
        cout<<"Seats Available: "<<availableSeats<<endl;

    }
};

Seats::Seats(int code, int count){
    seatCode = code;
    availableSeats = count;
}


int main(){
    int c1[] = {0101, 0202};
    Student s1(1, c1);
    s1.display();

    Seats seat1(0101, 10);
    seat1.display();
    return 0;
}