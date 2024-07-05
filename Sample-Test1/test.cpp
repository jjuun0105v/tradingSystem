//#include "pch.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../tradingSystem/App.cpp"

using namespace std;
using namespace testing;

TEST(TestCaseName, TestName) {
	App app;
	EXPECT_THAT(app, NotNull());
	app.selectStockBrocker("kiwer");
	app.login("kim", "1234");
	app.buy("samsung", 8000, 5);
	app.sell("samsung", 9000, 5);
	app.getPrice("samsung");
}

TEST(TestCaseName, TestName) {
	App app;
	EXPECT_THAT(app, NotNull());
	app.selectStockBrocker("nemo");
	app.login("kim", "1234");
	app.buy("hinix", 170000, 5);
	app.sell("hinix", 180000, 5);
	app.getPrice("hinix");
}