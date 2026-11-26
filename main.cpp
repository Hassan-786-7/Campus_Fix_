#include "CampusFix.h"
#include <iostream>
#include "Functions.cpp"
using namespace std;

int main()
{
    int choice;

    loadComplaints();

    do
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "                 CAMPUSFIX                  \n";
        cout << "       UNIVERSITY MAINTENANCE SYSTEM        \n";
        cout << "============================================\n";

        cout << "1. Submit New Complaint\n";
        cout << "2. View All Complaints\n";
        cout << "3. Track Complaint Status\n";
        cout << "4. Administrator Panel\n";
        cout << "5. Search Complaint\n";
        cout << "6. Filter Complaints\n";
        cout << "7. Generate Maintenance Report\n";
        cout << "8. Exit\n";

        cout << "============================================\n";

        choice = getNumber("Enter your choice: ", 1, 8);

        switch (choice)
        {
            case 1:
                submitComplaint();
                break;

            case 2:
                displayComplaints();
                break;

            case 3:
                trackComplaint();
                break;

            case 4:
                adminPanel();
                break;

            case 5:
                searchComplaint();
                break;

            case 6:
                filterComplaints();
                break;

            case 7:
                generateReport();
                break;

            case 8:
                cout << "\nThank you for using CampusFix!\n";
                cout << "Program terminated successfully.\n";
                break;
        }

    } while (choice != 8);

    return 0;
}
