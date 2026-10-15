#include "credit_card.h"

#include <iomanip>
#include <sstream>
// Constructor definitions
credit_card::credit_card() {
    cc_number = 0;
    limit = 0.0;
    current_balance = 0.0;
}

credit_card::credit_card(int number, double credit_limit, double balance) {
    cc_number = number;
    limit = credit_limit;
    current_balance = balance;
}
// Member function definitions
bool credit_card::make_purchase(double purchase_amount) {
    if (purchase_amount <= 0 ||
        current_balance + purchase_amount > limit) {
        return false;
    }

    current_balance += purchase_amount;
    return true;
}

bool credit_card::make_payment(double payment_amount) {
    if (payment_amount <= 0 || payment_amount > current_balance) {
        return false;
    }

    current_balance -= payment_amount;
    return true;
}
// Function to return credit card information as a string
std::string credit_card::credit_card_info() {
    std::ostringstream output;

    output << std::fixed << std::setprecision(2);
    output << "Credit card number: " << cc_number << "\n";
    output << "Credit Card Limit: $" << limit << "\n";
    output << "Current Balance: $" << current_balance;

    return output.str();
}