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

TEST(ApplicationTest, AppNullCheck) {
	App app;
	EXPECT_THAT(&app, NotNull());
}

TEST(ApplicationTest, AppLogin) {
	App app;
	app.login("kim", "1234");

	EXPECT_EQ(app.getID(), "kim");
	EXPECT_EQ(app.getPW(), "1234");
}

TEST(TestCaseName, KiwerCreated) {
	App app;
	MockStock mock;
	EXPECT_THAT(app, NotNull());
	app.selectStockBrocker(&mock);
	app.login("kim", "1234");
	app.buy("samsung", 5, 8000);
	app.sell("samsung", 5, 9000);
	app.getPrice("samsung", 0);
}

TEST(TestCaseName, NemoCreated) {
	App app;
	MockStock mock;
	EXPECT_THAT(app, NotNull());
	app.selectStockBrocker(&mock);
	app.login("kim", "1234");
  app.buy("hinix", 5, 170000);
	app.sell("hinix", 5, 180000);
	app.getPrice("hinix", 0);
}

// buy zero stock is not allowed ! there_is_no_price
TEST(TestCaseName, BuyException_there_is_no_price) {
	App app;
	MockStock mock;
	EXPECT_THAT(app, NotNull());
	app.selectStockBrocker(&mock);
	app.login("kim", "1234");
	
	EXPECT_THROW(app.buy("hinix", 0, 170000), std::exception);
}

// sell zero stock is not allowed ! there_is_no_price
TEST(TestCaseName, SellException_there_is_no_price) {
	App app;
	MockStock mock;
	EXPECT_THAT(app, NotNull());
	app.selectStockBrocker(&mock);
	app.login("kim", "1234");

	EXPECT_THROW(app.sell("hinix", 0, 170000), std::exception);
}

// buy zero stock is not allowed ! there_is_no_count
TEST(TestCaseName, BuyException_there_is_no_count) {
	App app;
	app.selectStockBrocker("kiwer");
	app.login("kim", "1234");

	EXPECT_THROW(app.buy("hinix", 5, 0), std::exception);
}

// sell zero stock is not allowed ! there_is_no_count
TEST(TestCaseName, SellException_there_is_no_count) {
	App app;
	app.selectStockBrocker("kiwer");
	app.login("kim", "1234");

	EXPECT_THROW(app.sell("hinix", 5, 0), std::exception);
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
