#include "CampusFix.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <cstdlib>
using namespace std;

// Global complaint records and counters
Complaint complaints[MAX];
int totalComplaints = 0;
int nextID = 1001;


// Function to save all complaints to file
void saveComplaints()
{
    ofstream file(DATA_FILE.c_str());

    if (!file)
    {
        cout << "Warning: Could not save complaints to file!" << endl;
        return;
    }

    for (int i = 0; i < totalComplaints; i++)
    {
        file << complaints[i].id << endl;
        file << complaints[i].studentName << endl;
        file << complaints[i].category << endl;
        file << complaints[i].location << endl;
        file << complaints[i].description << endl;
        file << complaints[i].status << endl;
    }

    file.close();
}


// Function to load complaints from file when program starts
void loadComplaints()
{
    ifstream file(DATA_FILE.c_str());

    if (!file)
    {
        return;   // No saved file yet, start fresh
    }

    string idText;

    while (totalComplaints < MAX && getline(file, idText))
    {
        complaints[totalComplaints].id = atoi(idText.c_str());
        getline(file, complaints[totalComplaints].studentName);
        getline(file, complaints[totalComplaints].category);
        getline(file, complaints[totalComplaints].location);
        getline(file, complaints[totalComplaints].description);
        getline(file, complaints[totalComplaints].status);

        if (complaints[totalComplaints].id >= nextID)
        {
            nextID = complaints[totalComplaints].id + 1;
        }

        totalComplaints++;
    }

    file.close();
}


// Function to take and validate numeric input
int getNumber(string message, int min, int max)
{
    int number;

    while (true)
    {
        cout << message;

        if (cin >> number)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (number >= min && number <= max)
            {
                return number;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Invalid input! Please enter a number between "
             << min << " and " << max << "." << endl;
    }
}


// Function to take non-empty text input
string getText(string message)
{
    string text;

    while (true)
    {
        cout << message;
        getline(cin, text);

        if (text.find_first_not_of(" \t") != string::npos)
        {
            return text;
        }

        cout << "Input cannot be empty! Try again." << endl;
    }
}


// Function to select complaint category
string chooseCategory()
{
    cout << "\nSelect Complaint Category:\n";
    cout << "1. Electricity\n";
    cout << "2. Furniture\n";
    cout << "3. Air Conditioner / Fan\n";
    cout << "4. Projector / Computer\n";
    cout << "5. Water Supply\n";
    cout << "6. Other\n";

    int choice = getNumber("Enter your choice: ", 1, 6);

    switch (choice)
    {
        case 1: return "Electricity";
        case 2: return "Furniture";
        case 3: return "AC / Fan";
        case 4: return "Projector / Computer";
        case 5: return "Water Supply";
        case 6: return "Other";
    }

    return "Other";
}


// Function to select complaint status
string chooseStatus()
{
    cout << "\nSelect New Status:\n";
    cout << "1. Pending\n";
    cout << "2. In Progress\n";
    cout << "3. Resolved\n";

    int choice = getNumber("Enter your choice: ", 1, 3);

    switch (choice)
    {
        case 1: return "Pending";
        case 2: return "In Progress";
        case 3: return "Resolved";
    }

    return "Pending";
}


// Function to submit a new complaint
void submitComplaint()
{
    if (totalComplaints >= MAX)
    {
        cout << "\nComplaint storage is full!" << endl;
        return;
    }

    cout << "\n========== SUBMIT NEW COMPLAINT ==========\n";

    complaints[totalComplaints].id = nextID++;

    complaints[totalComplaints].studentName =
        getText("Enter Student Name: ");

    complaints[totalComplaints].category = chooseCategory();

    complaints[totalComplaints].location =
        getText("Enter Building / Room Number: ");

    complaints[totalComplaints].description =
        getText("Describe the Problem: ");

    complaints[totalComplaints].status = "Pending";

    cout << "\nComplaint submitted successfully!" << endl;
    cout << "Your Complaint ID is: "
         << complaints[totalComplaints].id << endl;
    cout << "Current Status: Pending" << endl;

    totalComplaints++;
    saveComplaints();
}


// Function to display one complaint
void displayOneComplaint(int index)
{
    cout << "\n----------------------------------------\n";
    cout << "Complaint ID: " << complaints[index].id << endl;
    cout << "Student Name: " << complaints[index].studentName << endl;
    cout << "Category: " << complaints[index].category << endl;
    cout << "Location: " << complaints[index].location << endl;
    cout << "Description: " << complaints[index].description << endl;
    cout << "Status: " << complaints[index].status << endl;
    cout << "----------------------------------------\n";
}


// Function to display all complaints
void displayComplaints()
{
    cout << "\n========== ALL COMPLAINTS ==========\n";

    if (totalComplaints == 0)
    {
        cout << "No complaints have been submitted yet.\n";
        return;
    }

    for (int i = 0; i < totalComplaints; i++)
    {
        displayOneComplaint(i);
    }
}


// Function to search complaint using ID
int searchByID(int id)
{
    for (int i = 0; i < totalComplaints; i++)
    {
        if (complaints[i].id == id)
        {
            return i;
        }
    }

    return -1;
}


// Function to track complaint status
void trackComplaint()
{
    cout << "\n========== TRACK COMPLAINT ==========\n";

    if (totalComplaints == 0)
    {
        cout << "No complaints available.\n";
        return;
    }

    int id = getNumber("Enter Complaint ID: ", 1001, nextID - 1);
    int index = searchByID(id);

    if (index != -1)
    {
        cout << "\nComplaint Found!\n";
        displayOneComplaint(index);
    }
    else
    {
        cout << "\nComplaint ID not found!\n";
    }
}


// Function to update complaint status
void updateStatus()
{
    cout << "\n========== UPDATE COMPLAINT STATUS ==========\n";

    if (totalComplaints == 0)
    {
        cout << "No complaints available.\n";
        return;
    }

    int id = getNumber("Enter Complaint ID: ", 1001, nextID - 1);
    int index = searchByID(id);

    if (index != -1)
    {
        cout << "\nComplaint Found!\n";
        displayOneComplaint(index);

        complaints[index].status = chooseStatus();

        cout << "\nComplaint status updated successfully!\n";
        saveComplaints();

        cout << "New Status: " << complaints[index].status << endl;
    }
    else
    {
        cout << "\nComplaint ID not found!\n";
    }
}


// Function to search complaint by ID or location
void searchComplaint()
{
    cout << "\n========== SEARCH COMPLAINT ==========\n";

    if (totalComplaints == 0)
    {
        cout << "No complaints available.\n";
        return;
    }

    cout << "1. Search by Complaint ID\n";
    cout << "2. Search by Location\n";

    int choice = getNumber("Enter your choice: ", 1, 2);

    if (choice == 1)
    {
        int id = getNumber("Enter Complaint ID: ", 1001, nextID - 1);
        int index = searchByID(id);

        if (index != -1)
        {
            displayOneComplaint(index);
        }
        else
        {
            cout << "Complaint not found!\n";
        }
    }
    else
    {
        string location = getText("Enter Building or Room Name: ");
        bool found = false;

        for (int i = 0; i < totalComplaints; i++)
        {
            if (complaints[i].location.find(location) != string::npos)
            {
                displayOneComplaint(i);
                found = true;
            }
        }

        if (!found)
        {
            cout << "No complaints found at this location.\n";
        }
    }
}


// Function to filter complaints by status
void filterComplaints()
{
    cout << "\n========== FILTER COMPLAINTS ==========\n";

    if (totalComplaints == 0)
    {
        cout << "No complaints available.\n";
        return;
    }

    cout << "1. Pending Complaints\n";
    cout << "2. In Progress Complaints\n";
    cout << "3. Resolved Complaints\n";

    int choice = getNumber("Enter your choice: ", 1, 3);

    string selectedStatus;

    if (choice == 1)
        selectedStatus = "Pending";
    else if (choice == 2)
        selectedStatus = "In Progress";
    else
        selectedStatus = "Resolved";

    bool found = false;

    for (int i = 0; i < totalComplaints; i++)
    {
        if (complaints[i].status == selectedStatus)
        {
            displayOneComplaint(i);
            found = true;
        }
    }

    if (!found)
    {
        cout << "No " << selectedStatus << " complaints found.\n";
    }
}


// Function to generate maintenance report
void generateReport()
{
    cout << "\n========== MAINTENANCE REPORT ==========\n";

    int pending = 0;
    int inProgress = 0;
    int resolved = 0;

    for (int i = 0; i < totalComplaints; i++)
    {
        if (complaints[i].status == "Pending")
            pending++;
        else if (complaints[i].status == "In Progress")
            inProgress++;
        else if (complaints[i].status == "Resolved")
            resolved++;
    }

    cout << "\nTotal Complaints: " << totalComplaints << endl;
    cout << "Pending Complaints: " << pending << endl;
    cout << "In Progress Complaints: " << inProgress << endl;
    cout << "Resolved Complaints: " << resolved << endl;

    if (totalComplaints == 0)
    {
        cout << "\nNo category statistics available yet.\n";
        return;
    }

    string categories[6] =
    {
        "Electricity",
        "Furniture",
        "AC / Fan",
        "Projector / Computer",
        "Water Supply",
        "Other"
    };

    int maxCount = 0;
    string mostCommonCategory;

    cout << "\n========== CATEGORY REPORT ==========\n";

    for (int i = 0; i < 6; i++)
    {
        int count = 0;

        for (int j = 0; j < totalComplaints; j++)
        {
            if (complaints[j].category == categories[i])
            {
                count++;
            }
        }

        cout << categories[i] << ": " << count << endl;

        if (count > maxCount)
        {
            maxCount = count;
            mostCommonCategory = categories[i];
        }
    }

    if (maxCount > 0)
    {
        cout << "\nMost Reported Category: "
             << mostCommonCategory << endl;
    }
    else
    {
        cout << "\nNo reported category yet.\n";
    }
}


// Function to check the administrator PIN (3 attempts)
bool verifyAdminPin()
{
    const int MAX_ATTEMPTS = 3;

    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++)
    {
        string pin;

        cout << "\nEnter Administrator PIN: ";
        getline(cin, pin);

        if (pin == ADMIN_PIN)
        {
            cout << "Access granted.\n";
            return true;
        }

        cout << "Incorrect PIN! Attempts left: "
             << MAX_ATTEMPTS - attempt << endl;
    }

    cout << "Too many wrong attempts. Returning to Main Menu...\n";
    return false;
}


// Administrator panel
void adminPanel()
{
    if (!verifyAdminPin())
    {
        return;
    }

    int choice;

    do
    {
        cout << "\n========== ADMINISTRATOR PANEL ==========\n";
        cout << "1. View All Complaints\n";
        cout << "2. Update Complaint Status\n";
        cout << "3. View Pending Complaints\n";
        cout << "4. View Resolved Complaints\n";
        cout << "5. Generate Maintenance Report\n";
        cout << "6. Back to Main Menu\n";

        choice = getNumber("Enter your choice: ", 1, 6);

        switch (choice)
        {
            case 1:
                displayComplaints();
                break;

            case 2:
                updateStatus();
                break;

            case 3:
            {
                bool found = false;

                for (int i = 0; i < totalComplaints; i++)
                {
                    if (complaints[i].status == "Pending")
                    {
                        displayOneComplaint(i);
                        found = true;
                    }
                }

                if (!found)
                    cout << "No pending complaints found.\n";

                break;
            }

            case 4:
            {
                bool found = false;

                for (int i = 0; i < totalComplaints; i++)
                {
                    if (complaints[i].status == "Resolved")
                    {
                        displayOneComplaint(i);
                        found = true;
                    }
                }

                if (!found)
                    cout << "No resolved complaints found.\n";

                break;
            }

            case 5:
                generateReport();
                break;

            case 6:
                cout << "Returning to Main Menu...\n";
                break;
        }

    } while (choice != 6);
}


