#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::getline;
using std::string;

int main() {
	// Open input files.
    ifstream credit_card_file("credit_card.txt");
    ifstream people_file("people.txt");
    ifstream product_file("products.txt");
	// Check if files opened successfully.
    if (!credit_card_file || !people_file || !product_file) {
        cout << "Error opening input files." << endl;
        return 1;
    }
	// Create a Store object.
    Store store1;

    // Read credit cards.
    int num_cards;
    credit_card_file >> num_cards;
    credit_card_file.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n'
    );
	// Create an array to hold credit card objects.
    credit_card cards[100];
    string card_name;
	// Read each credit card's details and create credit_card objects.
    for (int i = 0; i < num_cards; i++) {
        int number;
        double limit, balance;

        getline(credit_card_file, card_name);
        credit_card_file >> number >> limit >> balance;
        credit_card_file.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );

        cards[i] = credit_card(number, card_name, limit, balance);
    }

    // Read people and associate them with credit cards by name.
    int num_people;
    people_file >> num_people;
    people_file.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n'
    );

    for (int i = 0; i < num_people; i++) {
        string name, phone, street, city, state, zip;

        getline(people_file, name);
        getline(people_file, phone);
        getline(people_file, street);

        // Skip the blank address_line2 in people.txt.
        string address_line2;
        getline(people_file, address_line2);
        getline(people_file, city);
        getline(people_file, state);
        getline(people_file, zip);

        credit_card card;

        for (int j = 0; j < num_cards; j++) {

    		if (cards[j].name == name) {
        		card = cards[j];
        		break;
    		}
	}

        address person_address(street,address_line2, city, state, zip);

        Person customer(name, phone, person_address, card);

        store1.add_customer(customer);
    }

    // Read products.
    int num_products;
    product_file >> num_products;
    product_file.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n'
    );

    for (int i = 0; i < num_products; i++) {
        string name, description;
        double price;

        getline(product_file, name);
        getline(product_file, description);
        product_file >> price;
        product_file.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );

        product item(name, description, price);
        store1.add_product(item);
    }

    credit_card_file.close();
    people_file.close();
    product_file.close();

    // Random transactions between customers and products. (10-100)

	// Seed the random number generator once.
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// Generate between 10 and 100 transactions.
	int num_transactions = 10 + std::rand() % 91;

	for (int i = 0; i < num_transactions; i++) {
    	// Choose a random customer.
    	int customer_index = std::rand() % store1.num_customers();

    	// Choose a random product.
    	int product_index = std::rand() % store1.num_products();

    	// Choose a quantity between 1 and 10.
    	int quantity = 1 + std::rand() % 10;

    	// Attempt the purchase.
    	store1.make_purchase(
        store1.get_customer(customer_index),
        store1.get_product(product_index),
        quantity);
	}

    cout << "Store info:" << endl << endl;
    cout << store1.store_info() << endl << endl;

    return 0;
}
