#include <string>
using namespace std;

class DriverInterface {
public:
	virtual void login(string ID, string password) = 0;
	virtual void buy(string stockCode, int count, int price) = 0;
	virtual void sell(string stockCode, int count, int price) = 0;
	virtual int getPrice(string stockCode, int minutes = 0) = 0;
};