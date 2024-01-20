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
using namespace std;

int main()
{
  int n, y;
  cout << "Enter a number between 0 and 9 : ";
  cin >> n;
  if (n < 1 || n > 9)
  {
    cout << "Invalid input. Please enter a number between 0 and 9." << endl;
    return 0;
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
      else
      {
        cout << i;
        y = 2 * n - 1;
      }
      if (y > i)
      {
        for (int k = y; k >= i; k--)
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
            y -= 1;
          }
        }
      }
      else
      {
        for (int t = 1; t <= n; t++)
        {
          cout << t;
        }
      }
      cout << endl;
    }

    int x = n - 2;
    for (int i = n - 1; i >= 0; i--)
    {
      if (i > 0)
      {
        for (int j = i; j >= 0; j--)
        {
          cout << j;
        }
      }
      else
      {
        cout << i;
      }
      for (int k = x; k <= i; k++)
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
          x -= 3;
        }
      }

      cout << endl;
    }
  }

  return 0;
}