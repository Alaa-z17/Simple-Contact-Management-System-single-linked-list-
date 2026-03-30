#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsContactManager.h"

using namespace std;

class clsMainScreen {
private:
    // Enum to replace magic numbers with descriptive names
    enum enMainMenuOptions {
        eAdd = 1, eDelete = 2, eSearch = 3,
        eUpdate = 4, ePrint = 5, eExit = 6
    };

    // Helper: Screen Pausing
    static void _GoBackToMainMenu() {
        cout << "\n\nPress any key to go back to Main Menu...";
        system("pause>0");
    }

    // Helper: Safe Integer Input
    static int _ReadInt() {
        int Number;
        while (!(cin >> Number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        return Number;
    }

    // Sub-Screen: Add
    static void _ShowAddContactScreen(clsContactManager<clsContact>& Manager) {
        cout << "\n--- Add New Contact ---\n";
        int ID;
        string Name, Phone;

        cout << "Enter ID: ";
        ID = _ReadInt();
        
        //ID must be unique
        while (Manager.SearchContact(ID)) {
            cout << "Error: ID [" << ID << "] is already taken. Enter a different ID: ";
            ID = _ReadInt();
        }

        cout << "Enter Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, Name);

        cout << "Enter Phone: ";
        getline(cin, Phone);

        Manager.AddNewContact(ID, Name, Phone);
        cout << "\nContact Added Successfully!";
    }

    // Sub-Screen: Delete
    static void _ShowDeleteContactScreen(clsContactManager<clsContact>& Manager) {
        cout << "\n--- Delete Contact ---\n";
        cout << "Enter ID to Delete: ";
        int ID = _ReadInt();

        if (Manager.DeleteContact(ID))
            cout << "\nContact Deleted Successfully.";
        else
            cout << "\nError: Contact ID not found.";
    }

    // Sub-Screen: Search
    static void _ShowSearchContactScreen(clsContactManager<clsContact>& Manager) {
        cout << "\n--- Search Contact ---\n";
        cout << "Enter ID to Search: ";
        int ID = _ReadInt();

        if (Manager.FindContact(ID)) {
            cout << "\nContact details: " << Manager.FindContact(ID)->data << endl;
        }
        else
            cout << "\nContact not found.";
    }

    // Sub-Screen: Update
    static void _ShowUpdateContactScreen(clsContactManager<clsContact>& Manager) {
        cout << "\n--- Update Contact ---\n";
        cout << "Enter ID to Update: ";
        int ID = _ReadInt();

        string NewName, NewPhone;
        cout << "Enter New Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, NewName);

        cout << "Enter New Phone: ";
        getline(cin, NewPhone);

        if (Manager.UpdateContact(ID, NewName, NewPhone))
            cout << "\nContact Updated Successfully.";
        else
            cout << "\nUpdate Failed: ID not found.";
    }

    // Sub-Screen: List All
    static void _ShowAllContactsScreen(clsContactManager<clsContact>& Manager) {
        cout << "\n--- Contact List (Singly Linked List) ---\n";
        Manager.PrintAllContacts();
        cout << "\nTotal Contacts: " << Manager.TotalContacts();
    }

public:
    // Main Entry Point for the UI
    static void ShowMainLayout(clsContactManager<clsContact>& Manager) {
        int Choice = 0;
        while (Choice != enMainMenuOptions::eExit) {
            system("cls");
            cout << "========================================\n";
            cout << "    CONTACT MANAGEMENT SYSTEM (LL)\n";
            cout << "========================================\n";
            cout << "  [1] Add New Contact\n";
            cout << "  [2] Delete Contact (by ID)\n";
            cout << "  [3] Search Contact (by ID)\n";
            cout << "  [4] Update Contact\n";
            cout << "  [5] Print All Contacts\n";
            cout << "  [6] Exit\n";
            cout << "========================================\n";
            cout << "Choose an option [1-6]: ";

            Choice = _ReadInt();

            // Using Enum in Switch for better readability
            switch ((enMainMenuOptions)Choice) {
            case enMainMenuOptions::eAdd:
                _ShowAddContactScreen(Manager);
                _GoBackToMainMenu();
                break;
            case enMainMenuOptions::eDelete:
                _ShowDeleteContactScreen(Manager);
                _GoBackToMainMenu();
                break;
            case enMainMenuOptions::eSearch:
                _ShowSearchContactScreen(Manager);
                _GoBackToMainMenu();
                break;
            case enMainMenuOptions::eUpdate:
                _ShowUpdateContactScreen(Manager);
                _GoBackToMainMenu();
                break;
            case enMainMenuOptions::ePrint:
                _ShowAllContactsScreen(Manager);
                _GoBackToMainMenu();
                break;
            case enMainMenuOptions::eExit:
                cout << "\nExiting... Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice!";
                _GoBackToMainMenu();
                break;
            }
        }
    }
};