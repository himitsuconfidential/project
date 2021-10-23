#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;



   

void buy_stock(int volumn, float &inventory, float &cash, float price){
    if (inventory + volumn <0)
        cout << "invalid trade: you dont have enough stock to sell" << endl;
    else if (cash - volumn*price <0)
        cout << "invalid trade: you dont have enough money to buy" << endl;
    else{
        cash -= volumn*price;
        inventory += volumn;
        cout << "trade successful";
    }
}


void show_stock(string stock, float price, int year){
    cout << "\n++++++Year" << year << "++++++" << endl;
    cout << "stock" << "\tcurrent price" << endl;
    cout << stock << "\t" << price << endl;
    cout << "=======================" << endl;
    cout << "q:leave, z:sleep, b: buy stock, s: sell stock" << endl;
}
void show_inventory(float cash, float inventory, float price){
    cout << "you have cash " << cash << endl;
    cout << "you have " << inventory << "unit of stock, each worth $" << price << endl;
}

void sleep(int &year, float &price,  float &profit, float &voltality){
    year++;
    price += (rand()%100-50)/100.0*voltality+profit;
}



int main(){
    string stock = "stockABC";
        float price = 50;
        float profit = 1;
        float voltality = 3;
        int year = 0;
        float cash = 1000;
        float inventory = 0;


    char command;
    while (command != 'q'){
        show_stock(stock, price, year);
        cout << "what do you want to do?";
        cin >> command;
        if (command == 'b'){
            int volumn;
            cout << "how many stock do you want to buy" << endl;
            cin >> volumn;

            buy_stock(volumn, inventory, cash, price);
            show_inventory(cash, inventory, price);

        }
        else if (command == 's'){
            int volumn;
            cout << "how many stock do you want to sell" << endl;
            cin >> volumn;
            buy_stock(-volumn,inventory, cash, price);
            show_inventory(cash, inventory, price);
        }
        else if (command == 'z'){
            sleep(year, price, profit, voltality);
        }
    }
    cout << "hello";
}


