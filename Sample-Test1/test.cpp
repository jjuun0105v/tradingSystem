//#include "pch.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../tradingSystem/App.cpp"
#include <string>

using namespace std;
using namespace testing;

// interface name needs to be changed if interface has changed
// + needs to be included
class MockStock : public StockBroker
{
public:
	MOCK_METHOD(void, login, (string ID, string password), (override));
	MOCK_METHOD(void, buy, (string stockCode, int count, int price), (override));
	MOCK_METHOD(void, sell, (string stockCode, int count, int price), (override));
	MOCK_METHOD(int, getPrice, (string stockCode, int minute), (override));
};

TEST(TestCaseName, KiwerCreated) {
	App app;
	EXPECT_THAT(app, NotNull());
	app.selectStockBrocker("kiwer");
	app.login("kim", "1234");
	app.buy("samsung", 8000, 5);
	app.sell("samsung", 9000, 5);
	app.getPrice("samsung");
}

TEST(TestCaseName, NemoCreated) {
	App app;
	EXPECT_THAT(app, NotNull());
	app.selectStockBrocker("nemo");
	app.login("kim", "1234");
	app.buy("hinix", 170000, 5);
	app.sell("hinix", 180000, 5);
	app.getPrice("hinix");
}

// buy zero stock is not allowed !
TEST(TestCaseName, BuyException) {
	App app;
	EXPECT_THAT(app, NotNull());
	app.selectStockBrocker("kiwer");
	app.login("kim", "1234");
	
	EXPECT_THROW(app.buy("hinix", 170000, 0), std::exception);
}

// sell zero stock is not allowed !
TEST(TestCaseName, SellException) {
	App app;
	EXPECT_THAT(app, NotNull());
	app.selectStockBrocker("kiwer");
	app.login("kim", "1234");

	EXPECT_THROW(app.sell("hinix", 170000, 0), std::exception);
}