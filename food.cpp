#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


struct Food {
    int code;
    string name;
    double price;
};


void printMenu(const vector<Food>& menu) {
    cout << "Menu:" << endl;
    for (const auto& food : menu) {
        cout << food.code << ". " << food.name << " - " << food.price << " Rials" << endl;
    }
}

int main() {
    int numberOfFoods;
    cout << "Enter the number of foods in the menu: ";
    cin >> numberOfFoods;

    vector<Food> menu;
    for (int i = 0; i < numberOfFoods; ++i) {
        Food food;
        food.code = i + 1;
        cout << "Enter the name of food " << food.code << ": ";
        cin >> food.name;
        cout << "Enter the price of " << food.name << ": ";
        cin >> food.price;
        menu.push_back(food);
    }

    double taxRate;
    cout << "Enter the tax rate (e.g., enter 9 for 9%): ";
    cin >> taxRate;
    taxRate /= 100; 

    printMenu(menu);

    int foodCode;
    cout << "Enter the food code you want to order: ";
    cin >> foodCode;

    double foodPrice = 0;
    for (const auto& food : menu) {
        if (food.code == foodCode) {
            foodPrice = food.price;
            break;
        }
    }

    if (foodPrice == 0) {
        cout << "Invalid food code." << endl;
        return 1;
    }

    
    double taxAmount = foodPrice * taxRate;
    double finalPrice = foodPrice + taxAmount;

    
    cout << fixed << setprecision(2);  
    cout << "Food Price: " << foodPrice << " Rials" << endl;
    cout << "Tax Amount (" << taxRate * 100 << "%): " << taxAmount << " Rials" << endl;
    cout << "Final Price: " << finalPrice << " Rials" << endl;

    return 0;
}
