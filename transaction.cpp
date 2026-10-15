#include "transaction.h"
// Default constructor
transaction::transaction() {
    transaction_number = 0;
    customer = Person();
    purchased_item = product();
    quantity = 0;
}
// Parameterized constructor
transaction::transaction(int t_number, Person customer,
                         product purchased_item, int quantity) {
    this->transaction_number = t_number;
    this->customer = customer;
    this->purchased_item = purchased_item;
    this->quantity = quantity;
}
// Function to display transaction information
std::string transaction::transaction_info() {
    return "Transaction #: " + std::to_string(transaction_number) +
           "\nCustomer:\n" + customer.person_info() +
           "\nProduct:\n" + purchased_item.product_info() +
           "\nQuantity: " + std::to_string(quantity);
}


