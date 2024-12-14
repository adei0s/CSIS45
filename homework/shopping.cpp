#include<iostream>
#include<vector>
using namespace std;

class Item {
    private:
        string name;
        double price;

    public:
        Item(string input_name, double input_price){
            name = input_name;
            price = input_price;
        }
        string get_name () {
            return name;
        }
        double get_price () {
            return price;
        }    
};


class ShoppingCart {
    private:
        vector<Item> cart;
        double total = 0;
    
    public:
        void add(string item_name, double item_price) {
            Item new_item(item_name, item_price);
            cart.push_back(new_item);
            total += item_price;
        }

        void remove(string item_name) {
            for (int i=0; i<cart.size(); i++) {
                if (cart[i].get_name() == item_name) {
                    total -= cart[i].get_price();
                    cart.erase(cart.begin() + i);
                    break;
                }
            }
        }

        double checkout () {
            return total;
        }
};


int main() {
    ShoppingCart my_cart;
    my_cart.add("iphone", 700);
    my_cart.add("case", 30);

    my_cart.remove("case");
    my_cart.add("charger", 10);

    cout << my_cart.checkout() << endl; // total: 710

    return 0;
}