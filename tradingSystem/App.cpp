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

private:
    DriverInterface* driver;
    string id;
    string pw;

};