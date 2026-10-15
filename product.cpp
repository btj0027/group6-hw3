#include "product.h"
#include <iomanip>
#include <sstream>

// Default constructor
product::product() {
    name = "";
    description = "";
    price = 0.0;
}

// Parameterized constructor
product::product(std::string name, std::string description, double price) {
    this->name = name;
    this->description = description;
    this->price = price;
}

// product_info method to return product details as a formatted string
std::string product::product_info() {
    std::ostringstream output;

    output << std::fixed << std::setprecision(2);
    output << "Name: " << name << "\n";
    output << "Description: " << description << "\n";
    output << "Price: $" << price;

    return output.str();
}
