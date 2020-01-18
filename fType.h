#ifndef MONEY_H
#define MONEY_H
#include <iostream>
#include <iomanip>

class fType {
private:
    long outputfType;
    double inputfType;
public:
     fType(long nfType = 0) {
        outputfType = nfType;
    }

    long getLong() const { return outputfType; }

    friend std::ostream& operator<< (std::ostream& out, fType& cfType) {
        out << std::fixed << std::setprecision(2) << (double)cfType.outputfType / 100;
        return out;
    }

    friend std::istream& operator>> (std::istream& in, fType& cfType) {
        in >> cfType.inputfType;
        cfType.inputfType *= 100;
        cfType.inputfType += 0.5;
        cfType.outputfType = cfType.inputfType;
        std::cin.ignore(3, '\n');
        return in;
    }
};

#endif
