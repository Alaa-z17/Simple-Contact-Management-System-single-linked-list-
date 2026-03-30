#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsContact {
private:
    string _Name;
    string _Phone;

public:
    clsContact() : _Name(""), _Phone("") {}

    clsContact(string Name, string Phone) {
        _Name = Name;
        _Phone = Phone;
    }

    void setName(string Name) { _Name = Name; }
    string getName() { return _Name; }

    void setPhone(string Phone) { _Phone = Phone; }
    string getPhone() { return _Phone; }

    //operator overloading , when names are equal the contacts are equal
    bool operator==(const clsContact& other) const {
        return (_Name == other._Name);
    }

    //operator overloading , when printing a contact ,we print the name and the phone
    friend ostream& operator<<(ostream& os, const clsContact& contact) {
        os << "[Name: " << contact._Name << ", Phone: " << contact._Phone << "]";
        return os;
    }
};