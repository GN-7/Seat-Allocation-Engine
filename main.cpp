#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class AllocationEngine;
class Course;

class Student
{
    friend class AllocationEngine;
    int rank;
    std::string allotedSeat = "0000";
    std::string Choice1;
    std::string Choice2;
    std::string Choice3;
    std::vector<std::string> ChoiceList;
    std::string name;

    Student(std::string n, int r, std::string aS, std::string c1, std::string c2, std::string c3);
};

Student::Student(std::string n, int r, std::string aS, std::string c1, std::string c2, std::string c3)
{
    name = n;
    rank = r;
    Choice1 = c1;
    Choice2 = c2;
    Choice3 = c3;
    ChoiceList = {c1, c2, c3};
    allotedSeat = aS;
}

class Course
{
    friend class AllocationEngine;
    std::string courseCode;
    int seatCount;
    Course(std::string s, int r);
};
Course::Course(std::string s, int r)
{
    courseCode = s;
    seatCount = r;
}

class AllocationEngine
{
private:
public:
    std::vector<Student> readStudentData()
    {
        std::vector<Student> studentsList;

        std::fstream file("studentData.csv");
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

            studentsList.push_back(Student(name, rank, allotedSeat, choice1, choice2, choice3));
        };

        return studentsList;
    }

    std::vector<Course> readCourseData()
    {
        std::vector<Course> courseList;

        std::fstream file("courseData.csv");
        std::string line;
        std::getline(file, line);

        while (std::getline(file, line))
        {

            std::string seatcode = line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1, line.length());

            std::string count_s = line.substr(0, line.find(','));
            int count = std::stoi(count_s);

            courseList.push_back(Course(seatcode, count));
        };

        return courseList;
    }

    std::vector<Student> AssignSeats(std::vector<Student> s, std::vector<Course> c)
    {
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s[i].ChoiceList.size(); j++)
            {
                for (int k = 0; k < c.size(); k++)
                {
                    if (s[i].ChoiceList[j] == c[k].courseCode && c[k].seatCount > 0)
                    {
                        s[i].allotedSeat = c[k].courseCode;
                        c[k].seatCount = c[k].seatCount - 1;
                        break;
                    }
                }
                if (s[i].allotedSeat != "0000")
                {
                    break;
                }
            }
        }
        return s;
    }

    void writeStudentData(std::vector<Student> s)
    {
        std::ofstream out_file;
        out_file.open("outputData.csv");
        out_file << "Name" << "," << "Rank" << "," << "Alloted Seat Code" << "\n";
        for (int i = 0; i < s.size(); i++)
        {
            out_file << s[i].name << "," << s[i].rank << "," << s[i].allotedSeat << "\n";
        }

        out_file.close();
    }
};

int main()
{
    AllocationEngine sys;
    std::vector<Student> a = sys.readStudentData();
    std::vector<Course> b = sys.readCourseData();
    std::vector<Student> c = sys.AssignSeats(a, b);
    sys.writeStudentData(c);
    return 0;
}