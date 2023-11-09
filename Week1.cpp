#include <iostream>
#include <string>
using namespace std;

int main() {
    const int NUM_CATEGORIES = 7;
    const int NUM_ITEMS_PER_CATEGORY = 7;


    // Arrays to store item code, description, and price for each category
    string itemcode[NUM_CATEGORIES][NUM_ITEMS_PER_CATEGORY] =
    {
      {"A1", "A2"},
      {"B1", "B2", "B3"},
      {"C1", "C2", "C3"},
      {"D1", "D2"},
      {"E1", "E2", "E3"},
      {"F1", "F2"},
      {"G1", "G2"}
    };

    string description[NUM_CATEGORIES][NUM_ITEMS_PER_CATEGORY] =
    {
      {"Case A1 (Compact)", "Case A2 (Tower)"},
      {"RAM B1 (8GB)", "RAM B2 (16GB)", "RAM B3 (32GB)"},
      {"Hard Drive C1 (1TB)", "Hard Drive C2 (2TB)", "Hard Drive C3(4TB)"},
      {"SSD D1(240GB)", "SSD D2(480GB)"},
      {"Second HDD E1(1TB)", "Second HDD E2(2TB)", "Second HDD E3(4TB)"},
      {"Optical Drive F1(DVD1)", "Optical Drive F2(DVD2)"},
      {"OS G1(Standard)", "OS G2(Professional)"}
    };

    double price[NUM_CATEGORIES][NUM_ITEMS_PER_CATEGORY] = {
      {75.00, 150.00},
      {79.99, 149.99, 299.99},
      {49.99, 89.99, 129.99},
      {59.99, 119.00},
      {49.99, 89.99, 129.99},
      {50.00, 100.00},
      {100.00, 175.00}
    };

    // Prompt user to choose one item from each category
    int choices[NUM_CATEGORIES];
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        cout << "Choose one " << description[i][0] << " - $" << price[i][0] << ", " << description[i][1] << " - $" << price[i][1] << ", " << description[i][2] << " - $" << price[i][2] << ":" << endl;
        cout << "Enter your choice (1-" << NUM_ITEMS_PER_CATEGORY << "): ";
        cin >> choices[i];
        choices[i]--; // Adjust for 0-based indexing
    }

    // Calculate total price
    double total_price = 0.0;
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        total_price += price[i][choices[i]];
    }

    // Output chosen items and total price
    cout << "\nChosen items:" << endl;
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        cout << description[i][choices[i]] << " - $" << price[i][choices[i]] << endl;
    }
    cout << "Total price: $" << total_price << endl;

    // Allow customer to choose additional items
    char additional_choice;
    do {
        int category, item;
        cout << "Do you want to purchase any item from the other categories? (y/n): ";
        cin >> additional_choice;
        if (additional_choice == 'y') {
            cout << "Enter the category (1-" << NUM_CATEGORIES << "): ";
            cin >> category;
            category--; // Adjust for 0-based indexing
            cout << "Choose one additional item from " << description[category][0] << ", " << description[category][1] << ", " << description[category][2] << ": ";
            cin >> item;
            item--; // Adjust for 0-based indexing
            total_price += price[category][item];
            cout << "You added " << description[category][item] << " - $" << price[category][item] << " to your order." << endl;
        }
    } while (additional_choice == 'y');

    // Output updated total price
    cout << "Updated total price: $" << total_price << endl;

    // Apply discounts based on the number of additional items
    double discount_amount = 0.0;
    if (additional_choice == 'n') {
        // Customer didn't buy additional items
        discount_amount = total_price * 0.05;
    }
    else {
        // Customer bought one or more additional items
        discount_amount = total_price * 0.10;
    }

    // Calculate final price after discount
    double final_price = total_price - discount_amount;

    // Output discount amount and final price
    cout << "Discount applied: $" << discount_amount << endl;
    cout << "Final price after discount: $" << final_price << endl;

    return 0;
}
