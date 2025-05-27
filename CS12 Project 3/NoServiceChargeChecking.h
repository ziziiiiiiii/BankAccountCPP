#ifndef NoServiceChargeChecking_H
#define NoServiceChargeChecking_H

#include <string>
#include "CheckingAccount.h"
using namespace std;

class NoServiceChargeChecking: public CheckingAccount
{
private:
	const double RATE = 0.05;
	const double MIN_BAL = 1000;
	double rate;
	double minBal;
	double interest;
public:
	NoServiceChargeChecking(string name, double bal, string type);

	double getRate();
	double getMinBal();
	void getInterest();
	void postInterest();

	void setRate(double rate);
	void setMinBal(double minBal);

	void balSub(double subAmount);
	void monthlyStatement();
	void checkWriter(string toName, double amount, string date);
};

#endif
