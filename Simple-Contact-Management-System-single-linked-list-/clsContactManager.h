#pragma once
#include <iostream>
#include <string>
#include "clsSinglyLinkedList.h" // Ensure this matches your file name
#include "clsContact.h"

using namespace std;

class clsContactManager {
private:
    // LinkedList to store Contact objects
    SinglyLinkedList<clsContact> _ContactList;

public:
    // Adds a new contact to the end of the list
    void AddNewContact(int ID, string Name, string Phone) {
        clsContact Contact(ID, Name, Phone);
        _ContactList.addBack(Contact);
    }

    // Deletes a contact using its Unique ID
    bool DeleteContact(int ID) {
        // Create a temporary object with the target ID for comparison
        clsContact TempContact(ID, "", "");
        return _ContactList.deleteByValue(TempContact);
    }

    // Searches for a contact by ID
    bool SearchContact(int ID) {
        clsContact TempContact(ID, "", "");
        return _ContactList.find(TempContact);
    }

    // Updates a contact's phone number based on ID
    // Note: In SinglyLinkedList, update requires (OldObject, NewObject)
    bool UpdateContact(int ID, string NewName, string NewPhone) {
        clsContact OldContact(ID, "", "");
        clsContact NewContact(ID, NewName, NewPhone);
        return _ContactList.update(OldContact, NewContact);
    }

    // Prints all contacts in the list
    void PrintAllContacts() {
        if (_ContactList.isEmpty()) {
            cout << "\n\t\t\t--- No Contacts Available ---\n";
        }
        else {
            _ContactList.display();
        }
    }

    // Returns the total number of contacts
    int TotalContacts() {
        return _ContactList.size();
    }
};