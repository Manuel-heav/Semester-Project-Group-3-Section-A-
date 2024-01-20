/*
===============================================================================
Hotel Room Reservation System
===============================================================================

This C++ program implements a simple Hotel Room Reservation System. This was a semester project
given in 2024 for Section A, Group 3 Students. It allows
guests to book rooms in three categories: Ocean View Suite, Poolside Villa, and
Garden View Room. The program prevents assigning the same room to multiple
guests and prompts for alternative room choices if a category is fully booked.

Features:
- User-friendly interface for room selection and booking.
- Error handling for invalid inputs (non-numeric or out-of-range selections).
- Display of current reserved room status for hotel staff.
- Patron search based on names for future reservations.

Usage:
1. Run the program.
2. Select the desired room type (1, 2, or 3).
3. Choose a room number within the specified range.
4. Provide guest details (name, gender, age, and unique reservation code).
5. View the reservation confirmation and available rooms.
6. Optionally, search for patrons based on their names.

Note: The program uses arrays to manage room status, guest details, and reservation
codes. The main loop allows users to book multiple rooms.

Compilation:
- Ensure a C++ compiler is installed.
- Compile the program using: g++ -o hotel_reservation hotel_reservation.cpp
- Execute it as: ./hotel_reservation

Authors (Group 3):
- Abenezer Yirgalem [ETS0052/15]
- Abenezer Daniel [ETS0059/15]
- Abraham Sisay [ETS0070/15]
- Abraham Shimels [ETS0074/15]
- Aelaf Anteneh [ETS0102/15]
- Ahmed Yassin [ETS0108/15]
- Alan Sultan [ETS0115/15]
- Alazar Zemene [ETS0116/15]
- Amanuael Kebede [ETS0125/15]
- Amanuel Melkamu [ETS0129/15]
- Amanuel Wubishet [ETS0133/15]

Date: Sunday, January 20, 2024
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

const int rooms = 150;
const int roomCategory = 10;
const int oceanStart = 1;
const int poolStart = 61;
const int gardenStart = 111;

int main()
{
    int roomStatus[rooms] = {};
    string guestNames[rooms];
    string guestGender[rooms];
    int guestAge[rooms];
    string reservationCodes[rooms];
    cout << "===============================================================================" << endl;
    cout << "              Welcome to AASTU's Hotel Room Reservation System" << endl;
    cout << "===============================================================================" << endl;

    char answer;
    do
    {
        int roomType, roomNumber;
        cout << "Please select the room type you want to book" << endl;
        cout << "1. Ocean View Suite" << endl;
        cout << "2. Poolside Villa" << endl;
        cout << "3. Garden View Room" << endl;
        cin >> roomType;

        if (roomType < 1 || roomType > 3)
        {
            cout << "Invalid input. Please select a valid room type." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int roomCategoryStart = (roomType == 1) ? oceanStart : (roomType == 2) ? poolStart
                                                                               : gardenStart;

        cout << "You have selected ";
        switch (roomType)
        {
        case 1:
            cout << "Ocean View Suite";
            break;
        case 2:
            cout << "Poolside Villa";
            break;
        case 3:
            cout << "Garden View Room";
            break;
        }
        cout << endl;

        cout << "Please select the room number you want to book" << endl;
        for (int i = 0; i < roomCategory; ++i)
        {
            cout << i + 1 << ". " << roomCategoryStart + i << endl;
        }

        cin >> roomNumber;

        if (roomNumber < 1 || roomNumber > roomCategory)
        {
            cout << "Invalid input. Please select a valid room number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int roomIndex = roomCategoryStart + roomNumber - 1;

        if (roomStatus[roomIndex] == 0)
        {
            cout << "Please enter your name: ";
            cin >> guestNames[roomIndex];
            cout << "Please enter your gender: ";
            cin >> guestGender[roomIndex];
            cout << "Please enter your age: ";
            cin >> guestAge[roomIndex];
            cout << "Please enter a unique reservation code: ";
            cin >> reservationCodes[roomIndex];

            roomStatus[roomIndex] = 1;
            cout << "You have successfully booked room " << roomCategoryStart + roomNumber << endl;
        }
        else
        {
            cout << "Room " << roomCategoryStart + roomNumber << " is not available." << endl;
        }

        cout << "Do you want to book another room? (Y/N)" << endl;
        cin >> answer;

    } while (answer == 'Y' || answer == 'y');

    cout << "Current Reserved Room Status:" << endl;
    for (int i = 0; i < rooms; ++i)
    {
        if (roomStatus[i] == 1)
        {
            cout << "Room " << i + 1 << " is booked by " << guestNames[i] << endl;
        }
    }

    string searchName;
    cout << "Enter a name to search for patrons: ";
    cin >> searchName;

    bool found = false;
    for (int i = 0; i < rooms; ++i)
    {
        if (guestNames[i] == searchName)
        {
            cout << "Guest found in room " << i + 1 << ". Reservation code: " << reservationCodes[i] << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "No guest found with the given name." << endl;
    }

    return 0;
}
