#include "AddressItem.h"
#include "LinkedList.h"

int main() {
	
	LinkedList<AddressItem> main_list;
	ifstream file_input;
	AddressItem temp;

	//Variables for search loop
	bool match_found = false;
	bool sentinel = true; //Becomes false when appropriate conditions for while loop to stop are met
	int i = 1; //Has to start at 1 and not 0 because we are working with linked implementation

	file_input.open("file_input.txt");

	//Force program to stop if file_input cannot be opened
	assert(!file_input.fail());

	//Go through file to retrieve data
	while (!file_input.eof()) {

		file_input >> temp;
		
		//Searching for match case...
		//Completely skip search if the list is empty
		if (!main_list.isEmpty()) {
			while (sentinel) {
				if (main_list.getEntry(i) == temp) {
					match_found = true;
				}
				if (match_found || i == main_list.getLength()) {
					sentinel = false;
				}
				else {
					i++;
				}
			}
		}

		if (match_found) {
			//Store previously entered data into temp
			temp = main_list.getEntry(i);
			//Increment temp's count
			temp.Tally();
			//Replace previously entered data with updated data
			main_list.replace(i, temp);
			cout << "Match found. Address " << main_list.getEntry(i) << "'s value has been increased." << endl;
		}
		else {
			//Need to increment temp's count so that it will not display 0 if it only shows up once
			temp.Tally();
			main_list.insert(main_list.getLength() + 1, temp);
			cout << "Match not found. Creating new entry for address " << temp << "." << endl;
			
		}

		//Reset sentinel, match_found, i, and temp
		sentinel = true; match_found = false; i = 1;
		temp = AddressItem(); //This should not cause memory leak as data will be stored in same address
	}

	cout << "\nPrinting final results..." << endl;

	for (i = 1; i <= main_list.getLength(); i++) { //For loop condition must be <= because we aren't working with array
		cout << main_list.getEntry(i) << endl;
	}

	file_input.close();
}

/*

/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
	OUTPUT
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

Match not found. Creating new entry for address 88.201.42.196(1).
Match not found. Creating new entry for address 114.23.89.150(1).
Match not found. Creating new entry for address 44.67.175.57(1).
Match found. Address 88.201.42.196(2)'s value has been increased.
Match found. Address 88.201.42.196(3)'s value has been increased.
Match found. Address 114.23.89.150(2)'s value has been increased.

Printing final results...
88.201.42.196(3)
114.23.89.150(2)
44.67.175.57(1)

*/