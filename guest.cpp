/*************************************************************
Simple example to demonstarte dynamic memory allocation.
If running using inbuilt sololearn compiler, enter the
input as given below,
NUMBER_OF_GUESTS - Integer value, number of guests in the list
GUEST_1_NAME     - Name of the first guest
GUEST_2_NAME     - Name of the second guest
.
.
GUEST_N_NAME     - Name of the Nth guest
Y or N           - Y to save to the file.
***************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

// Now Madhura is editing this same line!

int main() {
  int numGuests;

  string *pGuests;    // Pointer for holding address of our 
                      // dynamically allocated memory
  
  char saveResponse;
  
  ofstream F;         // Output filesteam object.

  // Get the number of guests
  cout << "Enter the number of guests: ";
  cin >> numGuests;

  // Allocate memory to accomodate previously entered
  // number of guests
  pGuests = new string[numGuests];

  // Enter the name of the guests.
  cout << "Enter the name of the guests, one per line." << endl;
  for(int i=0;i<numGuests;i++) {
   cin >> pGuests[i];
  }

  // Optionally, save the guest list to a file.
  cout << "Do you wish to save the list?[Y]es or [N]o: ";
  cin >> saveResponse;
  
  if(saveResponse == 'Y' || saveResponse == 'y') {
    F.open("guest_list.txt");
    for(int i=0;i<numGuests;i++){
     F << pGuests[i] << endl;
    }
    cout << "File saved successfully" << endl;
  }

  // Delete the previously allocated memory.
  delete [] pGuests;

  return 0;
}
