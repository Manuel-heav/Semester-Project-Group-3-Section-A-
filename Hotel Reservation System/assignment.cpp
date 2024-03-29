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

Date: Tuesday, January 23, 2024
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

const int rooms = 150;
const int oceanStart = 1;
const int poolStart = 61;
const int gardenStart = 111;
const int oceanEnd = 60;
const int poolEnd = 110;
const int gardenEnd = 150;
const string username = "admin";
const string passcode = "admin321";

int main()
{
    int roomStatus[rooms] = {};
    string guestNames[rooms];
    string guestGender[rooms];
    int guestAge[rooms];
    string reservationCodes[rooms];
    string staffUsername, staffPasscode;
    cout << "===============================================================================" << endl;
    cout << "              Welcome to AASTU's Hotel Room Reservation System" << endl;
    cout << "===============================================================================" << endl;

    char answer, genderChar;

    int roomType, roomNumber, optionType;
homepage:
    cout << "Please select what you want " << endl;
    cout << "1. To choose room type " << endl;
    cout << "2. To search for patrons " << endl;
    cout << "3. Exit " << endl;
INVALID_OPTIONTYPE:
    cin >> optionType;

    if (optionType < 1 || optionType > 3)
    {
        cout << "Invalid input. Please select a valid choice." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        goto INVALID_OPTIONTYPE;
    }

    cout << "You have selected ";
    switch (optionType)
    {
    case 1:
        cout << "to choose room type";

        break;
    case 2:
        cout << "to search for patrons" << endl;
        goto searchType;
        break;
    case 3:
        cout << "Exit " << endl
             << "-------- THANK YOU ---------";
        return 0;
        break;
    }
    cout << endl;
    do
    {
        cout << "Please select the room type you want to book" << endl;
        cout << "1. Ocean View Suite" << endl;
        cout << "2. Poolside Villa" << endl;
        cout << "3. Garden View Room" << endl;

    invalid_room_type:
        cin >> roomType;

        if (roomType < 1 || roomType > 3)
        {
            cout << "Invalid input. Please select a valid room type." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            goto invalid_room_type;
        }

        int roomCategoryStart = (roomType == 1) ? oceanStart : (roomType == 2) ? poolStart
                                                                               : gardenStart;
        int roomCategoryEnd = (roomType == 1) ? oceanEnd : (roomType == 2) ? poolEnd
                                                                           : gardenEnd;

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

        cout << "Please select the room number you want to book from room " << roomCategoryStart << " - " << roomCategoryEnd << endl;
    invalid_room_number:
        cin >> roomNumber;

        if (roomNumber < roomCategoryStart || roomNumber > roomCategoryEnd)
        {
            cout << "Invalid input. Please select a valid room number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            goto invalid_room_number;
        }

        int roomIndex = roomNumber - 1;

        if (roomStatus[roomIndex] == 0)
        {
            cout << "Please enter your name: ";
            cin >> guestNames[roomIndex];
            cout << "Please enter your gender (M/F): ";
        invalid_gender:
            cin >> guestGender[roomIndex];

            genderChar = toupper(guestGender[roomIndex][0]);

            if (genderChar != 'M' && genderChar != 'F')
            {
                cout << "Invalid input. Please enter 'M' for Male or 'F' for Female : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                goto invalid_gender;
            }

            cout << "Please enter your age: ";
        invalidAge:
            cin >> guestAge[roomIndex];
            if (guestAge[roomIndex] < 1 || guestAge[roomIndex] > 150)
            {
                cout << "Invalid input. Please put a valid AGE: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                goto invalidAge;
            }

            cout << "Please enter a unique reservation code: ";
            cin >> reservationCodes[roomIndex];

            roomStatus[roomIndex] = 1;
            cout << "You have successfully booked room " << roomNumber << endl;
        }
        else
        {
            cout << "Sorry, room " << roomIndex + 1 << " is not available." << endl;
            cout << endl;
            cout << "Please choose another room: ";
            goto invalid_room_number;
        }

        cout << "Do you want to book another room? (Y for yes or other key to see current reserved room and to see homepage): ";
        cin >> answer;

    } while (answer == 'Y' || answer == 'y');

    cout << "Current Reserved Room Status:" << endl;
    for (int i = 0; i < rooms; ++i)
    {
        if (roomStatus[i] == 1)
        {
            cout << "   => Room " << i + 1 << " is booked by " << guestNames[i] << endl;
            cout << endl;
        }
    }

    goto homepage;
    // if (optionType==2){
    do
    {
    searchType:
        cout << "please enter the username and the password :  " << endl;
    invalidUser:
        cin >> staffUsername;
        cin >> staffPasscode;

        if (staffUsername != username || staffPasscode != passcode)
        {
            cout << "Invalid input. Please put a valid username or password : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto invalidUser;
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
            }
        }

        if (!found)
        {
            cout << "No guest found with the given name." << endl;
        }
        cout << "would you like to search again ? (Y for yes or other key to back to home page): ";
        cin >> answer;
    } while (answer == 'Y' || answer == 'y');

    goto homepage;
    return 0;
}