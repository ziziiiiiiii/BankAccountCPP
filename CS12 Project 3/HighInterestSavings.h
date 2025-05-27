#ifndef HighInterestSavings_H
#define HighInterestSavings_H

#include <string>
#include "SavingsAccount.h"
using namespace std;

class HighInterestSavings: public SavingsAccount
{
private:
	const double MIN_BAL = 10000;
	const double RATE = 0.1;
	double minBal;
public:
	HighInterestSavings(string name, double bal, string type) : SavingsAccount(name, bal, type){
		setRate(RATE);
		minBal = MIN_BAL;
	};

	double getMinBal();

	void setMinBal(double minBal);
	void monthlyStatement();
};

#endif
