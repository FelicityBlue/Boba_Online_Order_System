
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <list>
#include "items.cpp"

Item item;
struct Drink {
    std::string category;
    std::string drink;
    int num_topping = 0;
    std::string topping[3]; // 3 topping is max
    std::string size; // 1 - medium, 2 - large/hot
    double cost = 0;
};

// check if a user's input is a number
int valid_num_input(int);
// check if input is in range
void in_range(int, int, int);
// display the drinks in user's choice of category
void display_drink(int);
// get a valid drink in range depends on the category
int get_drink_c(int);
// assign the drink to user's drink
void set_drink(Drink*, int,int);
// display order's attributes
void receipt(Drink*);

int main()
{
 
    Drink* order = new Drink;

    // Ask user's choice for drink category
    int category_i = -1;
    std::cout << "\n    Categories\n 1.Classic\n 2.Milk Tea\n 3.Punch\n 4.Yogurt\n 5.Slush\n 6.What's New\n Enter index of the category: ";
    while (category_i < 1 || category_i > 6 ) { 
        std::cin >> category_i;
        category_i = valid_num_input(category_i);
        in_range(category_i, 1, 6);

    }

    // Ask user's choice of drink
    display_drink(category_i);
    int drink_i = get_drink_c(category_i);

    // Ask user's drink's size
    int size_i = -1;
    std::cout << "\n    Drink size\n 1. Medium\n 2. Large\n Enter index of the category: ";
    while (size_i < 1 || size_i > 2) {
        std::cin >> size_i;
        size_i = valid_num_input(size_i);
        in_range(size_i, 1, 2);
    }

    // Ask user's choice of number of topping
    int n_topping =  -1;
    std::cout << "\nHow many topping do you want (max is 3): ";
    while (n_topping < 0 || n_topping > 3) {
        std::cin >> n_topping;
        n_topping = valid_num_input(n_topping);
        in_range(n_topping, 0, 3);
    }
    
    // Ask user's choice for toppings
    int topping_i = -1 ;
    for (int ii = 0; ii < n_topping; ii++) {
        topping_i = 0;
        std::cout << "\n 1.Bubbles\n 2.Pudding\n 3.Nata jellies\n 4.Mango popping bubbles\n 5.Lychee crystal bubbles\n Enter index of the topping " 
            << ii+1 << ": ";
        while (topping_i < 1 || topping_i > 6) {
            std::cin >>topping_i;
            topping_i = valid_num_input(topping_i);
            in_range(topping_i, 1, 6);
        }
        order->topping[ii] = item.get_topping(topping_i);
    }

    // Update values
    order->category = item.get_drink_category(category_i);
    set_drink(order, category_i, drink_i);
    order->num_topping = n_topping;

    // Calculate Total Cost
    order->cost = 4.50 + (n_topping * 0.50);
    if (size_i == 2) {
        order->cost += 0.50;
    }
     order->size = item.get_drink_size(size_i);
    
    // Display receipt
    // works on most unix machines
    std::cout << "\033[2J\033[1;1H"; // escape sequence to clear the console screen
    receipt(order);

    std::cout << "\n\n Thank you so much for choosing us!!\n\n";
    return 0;
}
void in_range(int i, int low, int high) {
    if (i < low || i > high) {
        std::cout << " Enter a valid choice: ";
    }
}

int valid_num_input(int input) {
    while (!std::cin) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "\n Enter a valid choice:: ";
        std::cin >> input;
    }
    return input;
}

void display_drink(int input) {
    switch (input) {
    case 1:
        std::cout << "\n    Classic\n"
            << " 1.Black Tea\n 2.Green Tea\n 3.Oolong Tea\n 4.Honey Tea\n Enter index of your drink choice: ";
        break;
    case 2:
        std::cout << "\n    Milk Tea\n"
            << " 1.Milk Green Tea\n 2.Rosehip Milk Tea\n 3.Coffee Milk Tea\n 4.Taro Milk Tea\n 5.Thai Milk Tea\n 6.Coconut Milk Tea\n Enter index of your drink choice: ";
        break;
    case 3:
        std::cout << "\n    Punch\n"
            << " 1.Strawberry Lemonade\n 2.Honey Lemonade\n 3.Peach Oolong Tea\n 4.Passion Fruit Green Tea\n 5.Strawberry Lemon Green Tea\n Enter index of your drink choice: ";
        break;
    case 4:
        std::cout << "\n    Yogurt\n"
            << " 1.Yogurt Orange\n 2.Yogurt Grapefruit\n 3.Yogurt Green Tea\n Enter index of your drink choice: ";
        break;
    case 5:
        std::cout << "\n    Slush\n"
            << " 1.Mango Snow\n 2.Taro\n 3.Matcha Red Bean\n 4.Strawberry Milk\n 5.Oreo\n 6.Pineapple\n Enter index of your drink choice: ";
        break;
    case 6:
        std::cout << "\n    What's New\n"
            << " 1.Sesame Slush\n 2.Coffee Wow Milk Cap\n 3.Black Tea Wow Milk Cap\n Enter index of your drink choice: ";
        break;
    default:
        break;
    }
    
}

int get_drink_c(int category) {

    int c = -1;
    bool validChoice = false;

    while (!validChoice){
        
        std::cin >> c;
        c = valid_num_input(c);

        if (category == 1) {
            if (c >= 1 && c <= 4) {
                validChoice = true;
            }
        }
        else if (category == 2) {
            if (c >= 1 && c <= 6) {
                validChoice = true;
            }
        }
        else if (category == 3) {
            if (c >= 1 && c <= 5) {
                validChoice = true;
            }
        }
        else if (category == 4) {
            if (c >= 1 && c <= 3) {
                validChoice = true;
            }
        }
        else if (category == 5) {
            if (c >= 1 && c <= 6) {
                validChoice = true;
            }
        }
        else if (category == 6) {
            if (c >= 1 && c <= 3) {
                validChoice = true;
            }
        }
        if (!validChoice) {
            std::cout << "\n Enter a valid choice: ";
        }
    }
    return c;
}

void set_drink(Drink* d, int category, int drink) {
    switch (category) {
    case 1:
        d->drink = item.get_classic_tea(drink);
        break;
    case 2:
        d->drink = item.get_milk_tea(drink);
        break;
    case 3:
        d->drink = item.get_punch(drink);
        break;
    case 4:
        d->drink = item.get_yogurt(drink);
        break;
    case 5:
        d->drink = item.get_slush(drink);
        break;
    case 6:
        d->drink = item.get_what_new(drink);
        break;
    }
}

void receipt(Drink* d) {
    std::cout << "\n    ~Drink: " << d->drink;
    std::cout << "\n    ~Size: " << d->size;
    std::cout << "\n    ~Number of toppings: " << d->num_topping;
    if (d->num_topping > 0) {
        std::cout << "\n    ~Topping(s) of your choice ~ ";
        for (int ii = 0; ii < d->num_topping; ii++) {
            printf("\n      %d. ", ii + 1);
            std::cout << d->topping[ii];
        }
    }
    printf("\n Total: $%.2f\n", d->cost);
}