#include<iostream>
#include<string>
using namespace std;

class student {
    public:
        int pay_tuition(int payment) {
            balance -= payment;
        }

        void setBalance(int amount) {
            balance = amount;
        }

        int getBalance() {
            return balance;
        }

        int getID() {
            return id;
        }

        void setID(int set_id) {
            id = set_id;
        }

    private:
        string name;
        int age;
        int id;
        int balance;
};


class car {
    public:

        void travel (int distance) {
            tank = tank - distance/50;
        }

        //setters
        void set_tank (int tank_init) {
            tank = tank_init;
        }

        double fill_tank (double fuel) {
            tank += fuel;
        }

        void set_make (string make_init) {
            make = make_init;
        }

        void set_model (string model_init) {
            model = model_init;
        }

        void set_year (int input_year) {
            year = input_year;
        }


        //getters

        double get_tank () {
            return tank;
        }

        string get_make () {
            return make;
        }

        string get_model () {
            return model;
        }

        int get_year () {
            return year;
        }    


    private:
        double tank;
        string make;
        string model;
        int year;
        int travel;

};

int main () {
    // student a;
    // a.name = "paaras";
    // a.age = 30;
    // cout << a.name << ": " << a.age << endl;
    // cout << a.getID() << endl;
    // a.setID(123);
    // a.setBalance(1000);

    // cout << a.getBalance() << endl;

    car my_car;
    my_car.set_year(2010);
    my_car.set_make("Toyota");
    my_car.set_model("Corolla");
    my_car.set_tank(20);

    cout << my_car.get_year() << endl;
    cout << my_car.get_make() << endl;
    cout << my_car.get_model() << endl;
    cout << my_car.get_tank() << endl;

    my_car.travel(20);
    cout << my_car.get_year() << endl;
    cout << my_car.get_make() << endl;
    cout << my_car.get_model() << endl;
    cout << my_car.get_tank() << endl;

    return 0;
}