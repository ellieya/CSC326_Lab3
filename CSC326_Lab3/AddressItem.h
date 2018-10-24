/*
Jiali Chen
Lab 3 - Linked List
In Lab 3, we use a linked implementation stack to store distinct IP addresses that are read-in from file.
In the IP address holder class, AddressItem, we revisit CSC 211 concepts (friend function & overloaded operators).
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

class AddressItem {

public:

	AddressItem() {
		count = 0;
	}

	friend istream & operator>>(istream & in, AddressItem & a); //inputs one ip address into a
	friend ostream & operator<<(ostream & out, const AddressItem & a);// outputs ip and count

	void Tally(); // add one to address item’s count
	string getAddress()const;
	int getCount()const;
	bool operator==(const AddressItem & addr2)const; //compare address values only

private:

	string address;
	int count;

};


void AddressItem::Tally() {
	count++;
}
string AddressItem::getAddress() const {
	return address;
}
int AddressItem::getCount() const {
	return count;
}
bool AddressItem::operator== (const AddressItem & righthand) const {
	return address == righthand.address;
}
istream& operator >> (istream& in, AddressItem& a) {
	in >> a.address;

	return in;
}
ostream& operator<<(ostream& out, const AddressItem& a) {
	out << a.address << '(' << a.count << ')';

	return out;
}