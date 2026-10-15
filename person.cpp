#include "person.h"
// Default constructor for Person class
Person::Person() {
    name_ = "";
    phone_ = "";
    person_address_ = address();
    person_credit_card_ = credit_card();
}
// Parameterized constructor for Person class
Person::Person(string name, string phone,
               address person_address,
               credit_card person_credit_card) {
    name_ = name;
    phone_ = phone;
    person_address_ = person_address;
    person_credit_card_ = person_credit_card;
}
// Setter methods for Person class
void Person::set_name(string name) {
    name_ = name;
}

void Person::set_phone(string phone) {
    phone_ = phone;
}

void Person::set_address(address person_address) {
    person_address_ = person_address;
}

void Person::set_credit_card(credit_card person_credit_card) {
    person_credit_card_ = person_credit_card;
}
// Getter methods for Person class
string Person::get_name() {
    return name_;
}

string Person::get_phone() {
    return phone_;
}

address Person::get_address() {
    return person_address_;
}

credit_card Person::get_credit_card() {
    return person_credit_card_;
}
// Method to return formatted information about the person
string Person::person_info() {
    return "Name: " + name_ +
           "\nPhone: " + phone_ +
           "\nAddress:\n" + person_address_.address_info() +
           "\nCredit Card:\n" + person_credit_card_.credit_card_info();
}
