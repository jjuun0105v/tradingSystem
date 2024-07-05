#include <stdexcept>
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

class App
{


};