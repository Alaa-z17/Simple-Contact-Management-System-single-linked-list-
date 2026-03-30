# Contact Management System

A robust C++ console application designed to manage personal contacts using a custom-built Singly Linked List. This project demonstrates advanced Object-Oriented Programming (OOP) concepts, including template classes, operator overloading, and manual memory management.

## Project Overview

Unlike standard applications that use built-in library containers, this system utilizes a custom data structure engine. Every contact entry is a node in a dynamic linked list, allowing the application to grow and shrink in memory as needed.

## Video Demonstration

Click the image below to watch the project walk-through and a full demonstration of the system in action!

[![Watch the Video](https://img.youtube.com/vi/kWoHAAvy2FI/hqdefault.jpg)](https://www.youtube.com/watch?v=kWoHAAvy2FI)

*(Note: Replace YOUR_VIDEO_ID in the link above with your actual YouTube video ID to make the thumbnail and link work perfectly!)*

## Key Features

* Custom Linked List Engine: A template-based SinglyLinkedList and Node structure built from the ground up.
* Data Integrity: Implemented a Unique ID system (Primary Key) to ensure no duplicate contacts can be added to the list.
* Advanced OOP: Includes deep implementation of Operator Overloading (the == and << operators) for precise object comparison and clean printing.
* Layered Architecture: Clear separation between Data Structures, Business Logic (ContactManager), and the UI (MainScreen).
* Crash-Proof UI: Built-in input validation to handle incorrect data types and prevent application crashes.

## Technical Skills Demonstrated

* C++ Templates: Creating reusable code that can work with any data type.
* Pointers and Memory: Managing the Heap using the new and delete keywords, alongside Destructors to ensure zero memory leaks.
* Static Methods and Enums: Organizing UI logic for professional code maintenance and readability.
* CRUD Operations: Full implementation of Create, Read, Update, and Delete logic within a linked environment.

## File Structure

* clsNode.h: The atomic building block of our list.
* clsSinglyLinkedList.h: The core data structure engine handling node logic.
* clsContact.h: The data entity representing a contact, featuring overloaded operators.
* clsContactManager.h: The controller responsible for managing the contact list and business logic.
* clsMainScreen.h: The interactive, menu-driven console interface.
* main.cpp: The entry point of the application.

## How to Run

1. Ensure you have a C++ compiler installed (such as GCC or MSVC).
2. Clone this repository to your local machine.
3. Compile all .cpp and .h files together.
4. Run the generated executable.

## License

This project is open-source and available under the MIT License. Feel free to use, modify, and distribute it as part of your learning journey or portfolio.