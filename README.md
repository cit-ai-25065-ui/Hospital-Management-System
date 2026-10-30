Hospital Management System

1. Project Overview

The Hospital Management System is a simple C++ console application designed to manage basic hospital information, including patients, doctors, and appointments.

2. Project Objectives

 ● Add and display patient information.
 ● Add and display doctor information.
 ● Search for a patient by ID or name.
 ● Book an appointment between a patient and a doctor.
 ● Display registered appointments.
 ● Demonstrate Object-Oriented Programming (OOP) concepts.

3. Project Files

 ● main.cpp — The main C++ source code.
 ● README.md — This file, which explains the project and how to run it.
 ● مناقشة_كود_إدارة_المستشفى.pdf — The code explanation and discussion questions, if included in the project folder.

4. Requirements

You need:

 ● A C++ compiler such as g++, or an IDE such as Code::Blocks or Visual Studio.
 ● Support for C++11 or a newer standard.

5. How to Compile and Run

Using g++ on Linux or macOS

 1. Open a terminal in the project directory.
 2. Compile the program:

g++ -std=c++11 main.cpp -o hospital

 3. Run the program:

./hospital

Using g++ on Windows

Compile the program:

g++ -std=c++11 main.cpp -o hospital.exe

Then run it:

hospital.exe

You can also open the project in an IDE such as Code::Blocks and build/run main.cpp.

6. How to Use the Program

When the program starts, a menu appears. Select the number corresponding to the operation you want to perform, such as:

 ● Add a patient.
 ● Display patients.
 ● Add a doctor.
 ● Display doctors.
 ● Search for a patient.
 ● Book an appointment.
 ● Display appointments.
 ● Exit the program.

Follow the on-screen prompts and enter the requested information.

7. Object-Oriented Programming Concepts

 ● Class: Defines a type that groups data and functions.
 ● Inheritance: The Patient and Doctor classes inherit from the base class Person.
 ● Encapsulation: Related data and functions are organized within classes.
 ● Polymorphism: The virtual showInfo() function allows different types of people to display their information in their own way.
 ● Function Overloading: The searchPatient() function can search by patient ID or by patient name using different parameter types.

8. Important Notes

 ● The program stores information in memory only. The data will be lost when the application is closed.
 ● This is a simplified educational project, not a production-ready hospital system.
 ● Enter the correct patient and doctor IDs when booking an appointment.

9. Preparing for the Project Discussion

Review the accompanying PDF, if available, to study the classes, functions, OOP concepts, and possible discussion questions before presenting the project.



Project Name: Hospital Management System
Programming Language: C++
Language Standard: C++11
