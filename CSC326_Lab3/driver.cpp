#include "AddressItem.h"
#include "LinkedList.h"

int search(LinkedList<AddressItem> main_list, AddressItem input);
//POST: Returns index if found, -1 if not found

void print(LinkedList<AddressItem> main_list);
//POST: Goes through entire LinkedList and prints all existing nodes.

void process_data(LinkedList<AddressItem>& main_list, AddressItem temp);
//POST: Processes data and applies changes to LinkedList

int main() {
	
	LinkedList<AddressItem> main_list;
	ifstream file_input;
	AddressItem data_holder;								//The count of data_holder will always be 0, only data changes

	file_input.open("file_input.txt");

	assert(!file_input.fail());								//Force program to stop if file_input cannot be opened

	//Go through file to retrieve data
	while (!file_input.eof()) {
		file_input >> data_holder;
		process_data(main_list, data_holder);
	}

	print(main_list);

	file_input.close();
}

int search(LinkedList<AddressItem> main_list, AddressItem input) {
	bool match_found = false;
	bool sentinel = true;									//Becomes false when appropriate conditions for while loop to stop are met
	int i = 1;												//Has to start at 1 and not 0 because we are working with linked implementation

	//Searching for match case...
	if (!main_list.isEmpty()) {								//Completely skip search if the list is empty
		
		//Search starts here
		while (sentinel) {
			if (main_list.getEntry(i) == input) {
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
		return i;
	}
	else {
		return -1;
	}
}
void process_data(LinkedList<AddressItem>& main_list, AddressItem temp) {
	int index;

	index = search(main_list, temp);
	if (index != -1) {									//If match found
		temp = main_list.getEntry(index);					//Store previously entered data into temp
		temp.Tally();										//Increment temp's count
		main_list.replace(index, temp);						//Replace previously entered data with updated data
		cout << "Match found. Address " << main_list.getEntry(index) << "'s value has been increased." << endl;
	}
	else {
		temp.Tally();										//Need to increment temp's count so that it will not display 0 if it only shows up once
		main_list.insert(main_list.getLength() + 1, temp);
		cout << "Match not found. Creating new entry for address " << temp << "." << endl;
	}
}
void print(LinkedList<AddressItem> main_list) {
	int i;

	cout << "\nPrinting final results..." << endl;
	for (i = 1; i <= main_list.getLength(); i++) {			//For loop condition must be <= because we aren't working with array
		cout << main_list.getEntry(i) << endl;
	}
}

