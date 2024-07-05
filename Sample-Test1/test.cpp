//#include "pch.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../tradingSystem/App.cpp"
#include "../tradingSystem/driverinterface.h"
#include <string>

using namespace std;
using namespace testing;

// interface name needs to be changed if interface has changed
// + needs to be included
class MockStock : public DriverInterface
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

// buy nice timing !
// if the price has been increased for three times,
// then it goes to buy
TEST(TestCaseName, BuyNiceTiming) {
	App app;
	app.selectStockBrocker("kiwer");
	app.login("kim", "1234");
	EXPECT_CALL(app, getPrice).Times(3);
	app.buyNiceTiming("hinix", 180000);
}

// sell nice timing !
// if the price has been decreased for three times,
// then it goes to buy
TEST(TestCaseName, SellNiceTiming) {
	App app;
	app.selectStockBrocker("kiwer");
	app.login("kim", "1234");
	EXPECT_CALL(app, getPrice).Times(3);
	app.sellNiceTiming("hinix", 180000);
}

// TODO
// use mock
TEST(TestCaseName, BasicFeatureUsingMock) {
	App app;
	MockStock mk;
	app.selectStockBroker(&mk);

	app.login("kim", "1234");
	app.buy("samsung", 8000, 5);
	app.sell("samsung", 9000, 5);

	EXPECT_CALL(app, getPrice("samsung")).WillRepeatedly(Return(9000));
	EXPECT_EQ(app.getPrice("samsung"), 9000);
}
