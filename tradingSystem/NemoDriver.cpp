#include <stdexcept>
#include "driverinterface.h"
#include "NemoAPI.cpp"

class NemoDriver :public DriverInterface {
public:
	// DriverInterface을(를) 통해 상속됨
	void login(string ID, string password) override
	{
		nemoAPI.certification(ID, password);
	}
	void buy(string stockCode, int count, int price) override
	{
		if (price == 0 || count == 0) {
			throw std::exception();
		}
		nemoAPI.purchasingStock(stockCode, price, count);
	}
	void sell(string stockCode, int count, int price) override
	{
		if (price == 0 || count == 0) {
			throw std::exception();
		}
		nemoAPI.sellingStock(stockCode, price, count);
	}
	int getPrice(string stockCode, int minutes) override
	{
		return nemoAPI.getMarketPrice(stockCode,minutes);
	}
private:
	NemoAPI nemoAPI;
};