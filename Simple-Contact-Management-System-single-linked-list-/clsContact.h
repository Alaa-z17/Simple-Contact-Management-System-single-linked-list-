#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsContact {
private:
    int _ID;         // Unique Identifier (Primary Key)
    string _Name;
    string _Phone;

public:
    // Default Constructor
    clsContact() : _ID(-1), _Name(""), _Phone("") {}

    // Parameterized Constructor
    clsContact(int ID, string Name, string Phone) {
        _ID = ID;
        _Name = Name;
        _Phone = Phone;
    }

    // Setters
    void setID(int ID) { _ID = ID; }
    void setName(string Name) { _Name = Name; }
    void setPhone(string Phone) { _Phone = Phone; }

    // Getters
    int getID() const { return _ID; }
    string getName() const { return _Name; }
    string getPhone() const { return _Phone; }

    // --- Operator Overloading ---

    // Equality operator based on ID only for precision
    bool operator==(const clsContact& other) const {
        return (_ID == other._ID);
    }

	// Output stream operator for easy printing via clsLinkedList::display(),friend for accessing private members from outside the class
    friend ostream& operator<<(ostream& os, const clsContact& contact) {
        os << "[ID: " << contact._ID << " | Name: " << contact._Name << " | Phone: " << contact._Phone << "]";
        return os;
    }
};