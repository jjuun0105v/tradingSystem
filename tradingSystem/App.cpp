#include <stdexcept>
#include <string>

#include "driverinterface.h"

using namespace std;

class BuyZeroFailException : public std::exception
{
public:
    char const* what() const override
    {
        return "buy zero not allowed !!!!";
    }
};

class SellZeroFailException : public std::exception
{
public:
    char const* what() const override
    {
        return "sell zero not allowed !!!!";
    }
};

class App {
public:
    void selectStockBrocker(DriverInterface* driver) {
        this->driver = driver;
    }

    void login(string id, string pw) {
        this->id = id;
        this->pw = pw;
        driver->login(id, pw);
    }

    string getID() {
        return this->id;
    }

    string getPW() {
        return this->pw;
    }

    void buy(string stockCode, int count, int price) {
        driver->buy(stockCode, count, price);
    }

    void sell(string stockCode, int count, int price) {
        driver->sell(stockCode, count, price);
    }

    int getPrice(string stockCode, int minutes) {
        return driver->getPrice(stockCode, minutes);
    }

    void buyNiceTiming(string stockCode, int price) {
        int p1 = getPrice(stockCode, 0);
        int p2 = getPrice(stockCode, 0);
        int p3 = getPrice(stockCode, 0);

        if ( p1 <= p2 && p2 <= p3 ) {
            buy(stockCode, price / p3, p3);
        }
    }

    void sellNiceTiming(string stockCode, int count) {
        int p1 = getPrice(stockCode, 0);
        int p2 = getPrice(stockCode, 0);
        int p3 = getPrice(stockCode, 0);

        if (p1 >= p2 && p2 >= p3) {
            sell(stockCode, count, p3);
        }
    }

private:
    DriverInterface* driver;
    string id;
    string pw;

};