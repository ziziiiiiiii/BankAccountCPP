#ifndef HighInterestChecking_H
#define HighInterestChecking_H

#include <string>
#include "NoServiceChargeChecking.h"
using namespace std;

class HighInterestChecking: public NoServiceChargeChecking
{
private:
	const double RATE = 0.1;
	const double MIN_BAL = 5000;
public:
	HighInterestChecking(string name, double bal, string type) : NoServiceChargeChecking(name, bal, type) {
		setRate(RATE);
		setMinBal(MIN_BAL);
	};
};

#endif
