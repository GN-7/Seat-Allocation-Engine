#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class AllocationEngine;

class Student
{
    friend class AllocationEngine;
    int rank;
    std::string allotedSeat;
    std::string Choice1;
    std::string Choice2;
    std::string Choice3;

    Student(int r, std::string aS, std::string c1, std::string c2, std::string c3);
};

Student::Student(int r, std::string aS, std::string c1, std::string c2, std::string c3)
{
    rank = r;
    Choice1 = c1;
    Choice2 = c2;
    Choice1 = c3;
    allotedSeat = aS;
}

class AllocationEngine
{
private:
public:
    std::vector<Student> readStudentData()
    {
        std::vector<Student> studentsList;
        std::fstream file("file.csv");
        std::string line;
        std::getline(file, line);

        while (std::getline(file, line))
        {

            std::string name = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            std::string rank_s = line.substr(0, line.find(','));
            int rank = std::stoi(rank_s);
            line = line.substr(line.find(',') + 1, line.length());

            std::string allotedSeat = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            std::string choice1 = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            std::string choice2 = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            std::string choice3 = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            studentsList.push_back(Student(rank, allotedSeat, choice1, choice2, choice3));
            std::cout << "Done!" << std::endl;
        };

        return studentsList;
    }
};

int main()
{
    AllocationEngine sys;
    sys.readStudentData();
    return 0;
}