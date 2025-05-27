#ifndef ServiceChargeChecking_H
#define ServiceChargeChecking_H

#include <string>
#include "CheckingAccount.h"
using namespace std;

class ServiceChargeChecking: public CheckingAccount
{
private:
	const int CHECK_LIMIT = 10;
	const double SERVICE_CHARGE = 30;
	int checkLimit;
	int currentChecks;
	double serviceCharge;
public:
	ServiceChargeChecking();
	ServiceChargeChecking(string name, double bal, string type);

	int getLimit();
	double getCharge();

	void setLimit(int limit);
	void setCharge(double charge);
	void postCharge();

	void balSub(double subAmount);
	void monthlyStatement();
	void checkWriter(string toName, double amount, string date);
};

#endif
