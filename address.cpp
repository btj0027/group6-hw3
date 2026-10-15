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
address::address(string street, string city, string state, string zip) {
    address_line1 = street;
    address_line2 = "";
    this->city = city;
    this->state = state;
    this->zip = zip;
}
// address_info function returns a string with the address information formatted nicely
string address::address_info() {
    string info = address_line1 + "\n";

    if (address_line2 != "") {
        info += address_line2 + "\n";
    }

    info += city + "\n";
    info += state + "\n";
    info += zip;

    return info;
}



