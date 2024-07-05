#include <stdexcept>
#include "KiwerDriver.h"

void KiwerDriver::login(string ID, string password)
{
    _api.login(ID, password);
}

void KiwerDriver::buy(string stockCode, int count, int price)
{
    verify(price);
    _api.buy(stockCode, count, price);
}

void KiwerDriver::sell(string stockCode, int count, int price)
{
    verify(price);
    _api.sell(stockCode, count, price);
}

int KiwerDriver::getPrice(string stockCode, int minutes)
{
    return _api.currentPrice(stockCode);
}


void KiwerDriver::verify(int price)
{
    if (price == 0) throw std::exception{ "price is zero not allowed!" };
}