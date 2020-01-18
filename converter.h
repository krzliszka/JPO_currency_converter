#ifndef CURRENCY_H
#define CURRENCY_H
#include <map>

class Converter {
private:
    std::map<std::string, double> currency;
    std::map<std::string, std::string> symbol;
public:
    Converter();
    std::string getSymbol(std::string currency);
    long convertCurrency(std::string c1, std::string c2, long amount);
};

#endif
