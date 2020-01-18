#include <iostream>
#include <iomanip>

#include "converter.h"

Converter::Converter() {

    currency["usd-gbp"] = 0.7667;
    currency["usd-cad"] = 1.3044;
    currency["usd-eur"] = 0.8965;
    currency["usd-pln"] = 3.7938;
    currency["usd-aud"] = 1.4475;
    currency["usd-chf"] = 0.9642;
    currency["usd-rub"] = 61.5789;
    currency["usd-cny"] = 6,8597;
    currency["usd-aed"] = 3.6725;
    currency["usd-usd"] = 1.0000;
    symbol["usd"] = "USD";

    currency["gbp-usd"] = 1.3042;
    currency["gbp-cad"] = 1.7012;
    currency["gbp-eur"] = 1.1693;
    currency["gbp-pln"] = 4.9479;
    currency["gbp-aud"] = 1.8878;
    currency["gbp-chf"] = 1.2575;
    currency["gbp-rub"] = 80.1505;
    currency["gbp-cny"] = 8.9285;
    currency["gbp-aed"] = 4.7801;
    currency["gbp-gbp"] = 1.0000;
    symbol["gbp"] = "GBP";

    currency["aud-usd"] = 0.6908;
    currency["aud-gbp"] = 0.5297;
    currency["aud-cad"] = 0.9011;
    currency["aud-eur"] = 0.6193;
    currency["aud-pln"] = 2.6209;
    currency["aud-chf"] = 0.6661;
    currency["aud-rub"] = 42.3326;
    currency["aud-cny"] = 4.7157;
    currency["aud-aed"] = 2.5246;
    currency["aud-aud"] = 1.0000;
    symbol["aud"] = "AUD";


    currency["cad-usd"] = 0.7666;
    currency["cad-gbp"] = 0.5877;
    currency["cad-aud"] = 1.1095;
    currency["cad-eur"] = 0.6873;
    currency["cad-pln"] = 2.9086;
    currency["cad-chf"] = 0.7393;
    currency["cad-rub"] = 47.1376;
    currency["cad-cny"] = 5.2510;
    currency["cad-aed"] = 2.8112;
    currency["cad-cad"] = 1.0000;
    symbol["cad"] = "CAD";

    currency["eur-usd"] = 1.1153;
    currency["eur-gbp"] = 0.8550;
    currency["eur-aud"] = 1.6141;
    currency["eur-cad"] = 1.4548;
    currency["eur-pln"] = 4.2301;
    currency["eur-chf"] = 1.0756;
    currency["eur-rub"] = 68.2609;
    currency["eur-cny"] = 7.6041;
    currency["eur-aed"] = 4.0710;
    currency["eur-eur"] = 1.0000;
    symbol["eur"] = "EUR";

    currency["pln-usd"] = 0.2637;
    currency["pln-gbp"] = 0.2021;
    currency["pln-aud"] = 0.3816;
    currency["pln-cad"] = 0.3439;
    currency["pln-eur"] = 0.2364;
    currency["pln-chf"] = 0.2543;
    currency["pln-rub"] = 16.1059;
    currency["pln-cny"] = 1.7941;
    currency["pln-aed"] = 0.9605;
    currency["pln-pln"] = 1.0000;
    symbol["pln"] = "PLN";

    currency["chf-usd"] = 1.0368;
    currency["chf-gbp"] = 0.7948;
    currency["chf-aud"] = 1.5003;
    currency["chf-cad"] = 1.3524;
    currency["chf-eur"] = 0.9296;
    currency["chf-pln"] = 3.9314;
    currency["chf-rub"] = 63.6492;
    currency["chf-cny"] = 7.0899;
    currency["chf-aed"] = 3.7956;
    currency["chf-chf"] = 1.0000;
    symbol["chf"] = "CHF ";

    currency["rub-usd"] = 0.0162;
    currency["rub-gbp"] = 0.0124;
    currency["rub-aud"] = 0.0236;
    currency["rub-cad"] = 0.0212;
    currency["rub-eur"] = 0.0146;
    currency["rub-pln"] = 0.0620;
    currency["rub-chf"] = 0.0157;
    currency["rub-cny"] = 0.1113;
    currency["rub-aed"] = 0.0596;
    currency["rub-rub"] = 1.0000;
    symbol["rub"] = "RUB";

    currency["cny-usd"] = 0.1457;
    currency["cny-gbp"] = 0.1120;
    currency["cny-aud"] = 0.2120;
    currency["cny-cad"] = 0.1904;
    currency["cny-eur"] = 0.1315;
    currency["cny-chf"] = 0.1410;
    currency["cny-pln"] = 0.5573;
    currency["cny-rub"] = 8.9772;
    currency["cny-aed"] = 0.5353;
    currency["cny-cny"] = 1.0000;
    symbol["cny"] = "CNY";

    currency["aed-usd"] = 0.2722;
    currency["aed-gbp"] = 0.2092;
    currency["aed-aud"] = 0.3961;
    currency["aed-cad"] = 0.3557;
    currency["aed-eur"] = 0.2456;
    currency["aed-pln"] = 1.0410;
    currency["aed-chf"] = 0.2634;
    currency["aed-rub"] = 16.7681;
    currency["aed-cny"] = 1.8678;
    currency["aed-aed"] = 1.0000;
    symbol["aed"] = "AED";
}

std::string Converter::getSymbol(std::string currency) {
    return symbol[currency];
}

long Converter::convertCurrency(std::string c1, std::string c2, long amount) {
    std::string key = c1 + "-" + c2;
        if (currency.find(key) != currency.end()) {
            double conversion = currency[key];
            conversion *= static_cast<double>(amount);
            return (long)conversion;
        }
}