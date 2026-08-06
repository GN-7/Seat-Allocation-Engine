#include <iostream>
#include <fstream>
#include <string>

class AllocationEngine;

class Student{
    friend class AllocationEngine;
    int rank;
    std::string allotedSeat;
    std::string *choiceList;

    Student::Student(int r, std::string list[3]);
};
Student::Student(int r, std::string list[3]){
    rank = r;
    choiceList = list;
}


class AllocationEngine
{
private:

public:
    void createStudentObjects()
    {

        std::fstream file("file.csv");
        std::string line;
        std::getline(file, line);

        while (std::getline(file, line))
        {

            std::string name = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            std::string rank = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            std::string allotedSeat = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            std::string choice1 = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            std::string choice2 = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            std::string choice3 = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            std :: string choiceList[] = {choice1, choice2, choice3};
        };
    }
};

int main()
{
    AllocationEngine sys;
    sys.createStudentObjects();
    return 0;
}