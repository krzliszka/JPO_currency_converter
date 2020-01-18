#ifndef MENU_H
#define MENU_H

using std::cout;

void menu() {
    cout << "----------------------------\n";
    cout << "-----Currency Converter-----\n";
    cout << "----------------------------\n";
    cout << "01.2020 (C) Krzysztof Liszka \n";
    cout << "----------------------------\n";
    cout << "1. USD - US dollar, \n";
    cout << "2. GBP - British pound, \n";
    cout << "3. CAD - Canadian dollar, \n";
    cout << "4. EUR - Euro, \n";
    cout << "5. PLN - Polish zloty, \n";
    cout << "6. AUD - Australian dollar, \n";
    cout << "7. CHF - Swiss franc, \n";
    cout << "8. RUB - Russian ruble, \n";
    cout << "9. CNY - Chinese youan renminbi, \n";
    cout << "10. AED - Emirati dirham. \n";
    cout << "----------------------------\n";
    cout << "----------------------------\n";
	cout << "Press 1 to start currency converter\n";
    cout << "Press 0 to exit\n";
}

#endif 
