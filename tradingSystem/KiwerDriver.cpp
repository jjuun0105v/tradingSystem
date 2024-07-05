#include "KiwerDriver.h"

void KiwerDriver::login(string ID, string password)
{
    _api.login(ID, password);
}

void KiwerDriver::buy(string stockCode, int count, int price)
{
    _api.buy(stockCode, count, price);
}

void KiwerDriver::sell(string stockCode, int count, int price)
{
    _api.sell(stockCode, count, price);
}

int KiwerDriver::getPrice(string stockCode, int minutes)
{
    return _api.currentPrice(stockCode);
}
