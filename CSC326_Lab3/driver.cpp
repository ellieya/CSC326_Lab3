#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int main() {
	
	LinkedList<AddressItem> main_list;
	ifstream file_input;
	AddressItem temp;

	file_input.open("FILENAME.txt");

	assert(!file_input.fail());

	while (!file_input.eof()) {
		if (MATCH_CONDITION) {
			GET_MATCHED_OBJECT.Tally();
		}
		else {
			file_input >> temp;
			main_list.push(temp);
		}
	}


}

// loop Get from file until eof


//search for match case. if match, go to & count +1
//else cin and push

