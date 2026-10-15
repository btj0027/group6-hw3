#include "store.h"
#include <string>
#include <sstream>
// Default constructor for the Store class
Store::Store() {
    num_customers_ = 0;
    num_products_ = 0;
    num_transactions_ = 0;
}
// Parameterized constructor for the Store class
void Store::num_customers(int customer_count) {
    if (customer_count >= 0 && customer_count <= 100) {
        num_customers_ = customer_count;
    }
}
// Store class methods
int Store::num_customers() {
    return num_customers_;
}

void Store::num_products(int product_count) {
    if (product_count >= 0 && product_count <= 100) {
        num_products_ = product_count;
    }
}

int Store::num_products() {
    return num_products_;
}

void Store::num_transactions(int transaction_count) {
    if (transaction_count >= 0 && transaction_count <= 100) {
        num_transactions_ = transaction_count;
    }
}

int Store::num_transactions() {
    return num_transactions_;
}

bool Store::add_customer(Person customer) {
    if (num_customers_ >= 100) {
        return false;
    }

    customers_[num_customers_++] = customer;
    return true;
}

bool Store::update_customer(int index, Person customer) {
    if (index < 0 || index >= num_customers_) {
        return false;
    }

    customers_[index] = customer;
    return true;
}

Person Store::get_customer(int index) {
    if (index >= 0 && index < num_customers_) {
        return customers_[index];
    }

    return Person();
}

bool Store::add_product(product item) {
    if (num_products_ >= 100) {
        return false;
    }

    products_[num_products_++] = item;
    return true;
}

product Store::get_product(int index) {
    if (index >= 0 && index < num_products_) {
        return products_[index];
    }

    return product();
}

bool Store::add_transaction(transaction ntransaction) {
    if (num_transactions_ >= 100) {
        return false;
    }

    transactions_[num_transactions_++] = ntransaction;
    return true;
}

transaction Store::get_transaction(int index) {
    if (index >= 0 && index < num_transactions_) {
        return transactions_[index];
    }

    return transaction();
}

bool Store::make_purchase(Person customer, product item, int quantity) {
    int customer_index = find_customer(customer);

    if (customer_index < 0 || quantity <= 0 ||
        num_transactions_ >= 100) {
        return false;
    }

    double total = item.price * quantity;

    credit_card card = customers_[customer_index].person_credit_card();

    if (card.current_balance + total > card.limit) {
        return false;
    }

    card.current_balance += total;
    customers_[customer_index].person_credit_card(card);

    transaction new_transaction(
        num_transactions_ + 1,
        customers_[customer_index],
        item,
        quantity
    );

    return add_transaction(new_transaction);
}

string Store::customer_info() {
    string info;

    for (int i = 0; i < num_customers_; i++) {
        info += customers_[i].person_info() + "\n";
    }

    return info;
}

string Store::product_info() {
    string info;

    for (int i = 0; i < num_products_; i++) {
        info += products_[i].product_info() + "\n";
    }

    return info;
}

string Store::transaction_info() {
    string info;

    for (int i = 0; i < num_transactions_; i++) {
        info += transactions_[i].transaction_info() + "\n";
    }

    return info;
}

string Store::store_info() {
    return "Customers:\n" + customer_info() +
           "\nProducts:\n" + product_info() +
           "\nAll Transactions:\n" + transaction_info();
}

string Store::purchase_history(Person customer) {
    string info;

    for (int i = 0; i < num_transactions_; i++) {
        if (transactions_[i].customer.name() == customer.name()) {
            info += transactions_[i].transaction_info() + "\n";
        }
    }

    return info;
}

int Store::find_customer(Person customer) {
    for (int i = 0; i < num_customers_; i++) {
        if (customers_[i].name() == customer.name()) {
            return i;
        }
    }

    return -1;
}
