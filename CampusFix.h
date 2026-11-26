#ifndef CAMPUSFIX_H
#define CAMPUSFIX_H

#include <string>
using namespace std;

// Maximum number of complaints
const int MAX = 100;

// PIN required to open the Administrator Panel
const string ADMIN_PIN = "1234";

// File used to store complaints permanently
const string DATA_FILE = "complaints.txt";

// Structure to store complaint information
struct Complaint
{
    int id;
    string studentName;
    string category;
    string location;
    string description;
    string status;
};

// Shared complaint records and counters
extern Complaint complaints[MAX];
extern int totalComplaints;
extern int nextID;

// Function prototypes
int getNumber(string message, int min, int max);
string getText(string message);
string chooseCategory();
string chooseStatus();
void submitComplaint();
void displayComplaints();
void displayOneComplaint(int index);
int searchByID(int id);
void trackComplaint();
void updateStatus();
void searchComplaint();
void filterComplaints();
void generateReport();
bool verifyAdminPin();
void adminPanel();
void saveComplaints();
void loadComplaints();

#endif
