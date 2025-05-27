#ifndef SavingsAccount_H
#define SavingsAccount_H

#include <string>
#include "BankAccount.h"
using namespace std;

class SavingsAccount: public BankAccount
{
private:
	const double RATE = 0.05;
protected:
	double rate;
	double interest;
public:
	SavingsAccount();
	SavingsAccount(string name, double bal, string type);

	double getRate();
	void getInterest();
	void postInterest();

	void setRate(double rate);

	void balSub(double subAmount);
	void monthlyStatement();

	void show();

};

#endif
