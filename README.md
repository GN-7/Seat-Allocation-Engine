# Seat Allocation Engine

A basic implementation of college seat allocation system in C++ inspired by JoSAA.
It does not currently attempt to reproduce the complete rules of real counselling systems.

## Concepts Explored

 - ### Object Oriented Programming
 - ### File Handling
 - ### Algorithmic Thinking

## How the Program Works
 - There are three fundamental entities in this program. The Student, Course and the Allocation Engine itself.
 - Each Student has a Rank and a list of choices.
 - Each Course has a course code (0101, 0102, 0103) and a seat capacity.
 - The Engine itself has no attributes, it has only methods.

   ### Step 1
    - The Engine reads the student data from the CSV file and creates corresponding Student objects.
    - All objects are stored in a vector for further manipulation.
  
   ### Step 2
    - The data is sorted by rank using a simple lambda with a std::sort method.
    - A new, sorted vector is returned.

   ### Step 3
    - The Engine reads the course data from the CSV file and creates corresponding Course objects.
  
   ### Step 4
    - The Engine then assigns the seats using the logic specified below.
  
   ### Step 5
    - The assigned seat data is written to a new CSV file.

## The Core Logic

![](/Seat_Allocation_Project.svg)

Students with better ranks are processed first.
For each student, the engine checks their course preferences in order.
The first preferred course with an available seat is allocated to the student, and the remaining seat count for that course is reduced.

## Building and Running

A C++ compiler such as `g++` can be used.

Clone the repository:

```bash
git clone https://github.com/GN-7/Seat-Allocation-Engine.git
cd Seat-Allocation-Engine
```

Compile:

```bash
g++ main.cpp -o allocation
```

Run:

### Linux / macOS

```bash
./allocation
```

### Windows

```bash
allocation.exe
```

The program expects `studentData.csv` and `courseData.csv` to be present in the working directory.

After execution, the allocation results will be available as a CSV file in the same directory.


## Future Improvements
This is an early version of the project and is intended primarily as a learning and experimentation project.
Possible extensions include:

* Support for any number of student preferences
* Better CSV parsing
* Error handling
* Advanced Data Structures
* Multiple allocation rounds
* Simulation using larger datasets
