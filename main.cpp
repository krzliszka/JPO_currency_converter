#include <iostream>
#include <string>
#include <algorithm>    //biblioteka odpowiadaj¹ca za funkcjê transform()

#include "fType.h"
#include "converter.h"
#include "menu.h"

using std::cout; using std::cin; using std::endl; using std::cerr;
using std::string; 


int main() {

    int menu_control;

    do
    {
        menu();
        cin >> menu_control;
        switch (menu_control)
        {
        case 1:
     

            string currencyFrom, currencyTo;

            cout << "-Enter currency to convert from (symbol XXX):\n";
            cin >> currencyFrom;

            cout << "-Enter currency to convert to (symbol XXX):\n";
            cin >> currencyTo;

            transform(currencyFrom.begin(), currencyFrom.end(), currencyFrom.begin(), ::tolower);
            transform(currencyTo.begin(), currencyTo.end(), currencyTo.begin(), ::tolower);
            /*  zabezpieczenie programu, aby wykonywal sie przy wprowadzeniu zarowno wielkich
                jak i ma³ych liter przez uzytkownika przy wykorzystaniu funkcji transform()*/


            string currencyCheck[20] = { "usd","gbp","cad","eur","pln","aud","chf","rub","cny","aed",   // lista wszystkich walut 
                                         "USD","GBP","CAD","EUR","PLN","AUD","CHF","RUB","CNY","AED" };     // zabezpieczenie przed literami roznej wielkoœci
            bool allowFrom = 1, allowTo = 1;    //zmienne oznaczajace, czy waluta jest na liscie
            for (string x : currencyCheck) {    // iterowanie po kazdym elemencie tablicy
                if (x == currencyFrom) { allowFrom = 0; }   //znaleziono walute, z ktorej chcemy konwertowac
                if (x == currencyTo) { allowTo = 0; }   // znaleziono walute do ktorej chcemy konwertowac
            }

            if (allowFrom || allowTo) {     // wykona sie, jesli nie znajdzie obydwoch walut
                cout << "Wrong currency typed! Returning...\n";
                continue;   // powrot na poczatek petli do-while
            }

            fType amount;
            cout << "-Enter amount:\n";

            if (!(cin >> amount))  // instrukcja if, ktora zapobiega wpisaniu liter do zmiennej amount
            {
                cerr << "Error! You didn't enter an amount.";
                cin.clear(); //kasowanie flagi bledu strumienia
                cin.sync(); // kasowanie zbednych znakow z bufora
                exit(0);    // w przypadku wprowadzenia liter, program sie konczy
            }

            Converter convert;
            fType product = convert.convertCurrency(currencyFrom, currencyTo, amount.getLong());
         
            if (product.getLong() > 0) { // instrukcja if, ktora zapobiega podaniu przez klienta ujemnej kwoty do wymiany
              cout << "Amount after exchange: " << convert.getSymbol(currencyTo) << " " << product << endl;
            }
            else {
                cout << "Entered amount is lower than 0! Try again.\n";
            }
            break;
        }
    }
    while (menu_control != 0);
    return 0;
}