#pragma once
#include "driverinterface.h"
#include "KiwerAPI.cpp"

class KiwerDriver : public DriverInterface {
public:
	void login(string ID, string password) override;
	void buy(string stockCode, int count, int price) override;
	void sell(string stockCode, int count, int price) override;
	int getPrice(string stockCode, int minutes) override;

private:
	KiwerAPI _api;
};