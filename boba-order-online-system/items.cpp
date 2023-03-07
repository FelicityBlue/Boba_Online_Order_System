#include <iostream>
#include <string>
#include <map>

class Item{
public:
	typedef std::map<int, std::string> is_pair;

	std::string get_drink_size(int a){
		is_pair Drink_size;
		
		Drink_size[1] = "Medium";
		Drink_size[2] = "Large";
		
		return Drink_size[a];
	}

	std::string get_topping(int a) {
	is_pair Topping;

	Topping[1] = "Bubbles";
	Topping[2] = "Pudding";
	Topping[3] = "Nata jellies";
	Topping[4] = "Mango popping bubbles";
	Topping[5] = "Lychee crystal bubbles";

	return Topping[a];
}

std::string get_classic_tea(int a) {
	is_pair Classic;
	Classic[1] = "Black Tea";
	Classic[2] = "Green Tea";
	Classic[3] = "Oolong Tea";
	Classic[4] = "Honey Tea";

	return Classic.at(a);
}
std::string get_milk_tea(int a) {
	is_pair Milk_Tea;
	Milk_Tea[1] = "Milk Green Tea";
	Milk_Tea[2] = "Rosehip Milk Tea";
	Milk_Tea[3] = "Coffee Milk Tea";
	Milk_Tea[4] = "Taro Milk Tea";
	Milk_Tea[5] = "Thai Milk Tea";
	Milk_Tea[6] = "Coconut Milk Tea";

	return Milk_Tea[a];
}

std::string get_punch(int a) {
	is_pair Punch;
	Punch[1] = "Strawberry Lemonade";
	Punch[2] = "Honey Lemonade";
	Punch[3] = "Peach Oolong Tea";
	Punch[4] = "Passion Fruit Green Tea";
	Punch[5] = "Strawberry Lemon Green Tea";

	return Punch[a];
}

std::string get_yogurt(int a) {
	is_pair Yogurt;
	Yogurt[1] = "Yogurt Orange";
	Yogurt[2] = "Yogurt Grapefruit";
	Yogurt[3] = "Yogurt Green Tea";

	return Yogurt[a];
}

std::string get_slush(int a) {
	is_pair Slush;
	Slush[1] = "Mango Snow";
	Slush[2] = "Taro";
	Slush[3] = "Matcha Red Bean";
	Slush[4] = "Strawberry Milk";
	Slush[5] = "Oreo";
	Slush[6] = "Pineapple";

	return Slush[a];
}

std::string get_what_new(int a) {
	is_pair Whats_New;
	Whats_New[1] = "Sesame Slush";
	Whats_New[2] = "Coffee Wow Milk Cap";
	Whats_New[3] = "Black Tea Wow Milk Cap";

	return Whats_New[a];
}

std::string get_drink_category(int a) {
	is_pair Drink_Category;
	Drink_Category[1] = "Classic";
	Drink_Category[2] = "Milk_Tea";
	Drink_Category[3] = "Punch";
	Drink_Category[4] = "Yogurt";
	Drink_Category[5] = "Slush";
	Drink_Category[6] = "Whats_New";

	return Drink_Category[a];
}
};