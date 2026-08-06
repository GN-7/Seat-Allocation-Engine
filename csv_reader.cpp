#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::fstream file("file.csv");
    std::string line;

    std::getline(file, line);
    while (std::getline(file, line))
    {

        std::string name = line.substr(0, line.find(','));
        std::string rank = line.substr(line.find(',') + 1, line.length());

        // std:: string rank = line.substr(0, line.find(','));
        // std:: string line = line.substr(line.find(',') + 1, line.length());

        std::cout << name << std::endl;
        std::cout << rank << std::endl;
    }
    return 0;
}