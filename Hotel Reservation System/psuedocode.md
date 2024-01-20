# Hotel Room Reservation System Pseudocode

## Initialization

Initialize constants:

- `rooms = 150`
- `roomCategory = 10`
- `oceanStart = 1`
- `poolStart = 61`
- `gardenStart = 111`

Initialize arrays:

- `roomStatus[rooms]`
- `guestNames[rooms]`
- `guestGender[rooms]`
- `guestAge[rooms]`
- `reservationCodes[rooms]`

## Main Program

Display welcome message

Repeat until the user decides not to book another room:

- Prompt the user to select a room type (1, 2, or 3)

  - If the input is invalid, display an error message and continue to the next iteration

- Determine roomCategoryStart based on the selected room type

- Display the selected room type

- Prompt the user to select a room number within the specified range

  - If the input is invalid, display an error message and continue to the next iteration

- Calculate the room index based on room type and number

- If the selected room is available:
  - Prompt the user for guest details (name, gender, age, reservation code)
  - Update roomStatus, guestNames, guestGender, guestAge, and reservationCodes arrays
  - Display a success message with the booked room number
- Else:

  - Display a message indicating that the room is not available

- Prompt the user if they want to book another room (Y/N)

Display the current reserved room status:

- Iterate through the roomStatus array:
  - If the room is booked, display the room number and guest name

Prompt the user to enter a name to search for patrons

Search for patrons based on the entered name:

- If a match is found, display the room number and reservation code
- If no match is found, display a message indicating that no guest was found

Exit the program
