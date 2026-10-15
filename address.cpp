#include "address.h"
// Default constructor
address::address() {
    address_line1 = "";
    address_line2 = "";
    city = "";
    state = "";
    zip = "";
}
// Parameterized constructor
address::address(string street, string address_line2, string city, string state, string zip) {
    address_line1 = street;
    this->address_line2 = address_line2; // This line seems to be missing a parameter for address_line2. You might want to add it to the constructor parameters.
    this->city = city;
    this->state = state;
    this->zip = zip;
}
// address_info function returns a string with the address information formatted nicely
string address::address_info() {
    string info = address_line1 + "\n";
    info += address_line2 + "\n";
    info += city + "\n";
    info += state + "\n";
    info += zip;

    return info;
}



