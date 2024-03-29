/*
===============================================================================
Pattern Printing Program
===============================================================================

This C++ program implements a simple pattern. This was a semester project
given in 2024 for Section A, Group 3 Students. It allows you to print a certain
pattern based on the number you enter.

Features:
- Users can enter a number between 0 and 9.
- The program prints a pattern based on the number entered.


Usage:
1. Run the program.
2. Select the desired number between 0 - 9.


Note: The program uses loops to print the pattern.

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
#include <limits>
using namespace std;

int main()
{
  int n, upperSpacing;

  cout << "Enter a number between 1 and 9 : ";
invalid_input:
  cin >> n;
  if (cin.fail())
  {
    cout << "Invalid input. Please select a valid number." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    goto invalid_input;
  }
  if (n < 1 || n > 9)
  {
    cout << "Invalid input. Please enter a number between 0 and 10." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    goto invalid_input;
  }
  else
  {
    for (int i = 0; i <= n; i++)
    {
      if (i > 0)
      {
        for (int j = i; j >= 0; j--)
        {
          cout << j;
        }
      }
      // Only for the very first iteration(0                 0)
      else
      {
        cout << i;
        upperSpacing = 2 * n - 1;
      }

      if (upperSpacing > i)
      {
        for (int k = upperSpacing; k >= i; k--)
        {
          if (k != i)
          {
            cout << " ";
          }
          else
          {
            for (int m = 0; m <= i; m++)
            {
              cout << m;
            }
            upperSpacing -= 1;
          }
        }
      }

      // Only the most middle iteration 9876543210123456789
      else
      {
        for (int t = 1; t <= n; t++)
        {
          cout << t;
        }
      }
      cout << endl;
    }

    // For the lower part after the most middle

    int lowerSpacing = n - 2;
    for (int i = n - 1; i >= 0; i--)
    {
      if (i > 0)
      {
        for (int j = i; j >= 0; j--)
        {
          cout << j;
        }
      }

      // For the last iteration
      else
      {
        cout << i;
      }

      for (int k = lowerSpacing; k <= i; k++)
      {
        if (k != i)
        {
          cout << " ";
        }
        else
        {
          for (int m = 0; m <= i; m++)
          {
            cout << m;
          }
          lowerSpacing -= 3;
        }
      }

      cout << endl;
    }
  }

  return 0;
}