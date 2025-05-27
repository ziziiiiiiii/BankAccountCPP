#ifndef CheckingAccount_H
#define CheckingAccount_H

#include <string>
#include "BankAccount.h"
using namespace std;

class CheckingAccount: public BankAccount
{
public:
	CheckingAccount();

	virtual void balSub(double subAmount) = 0;
	virtual void monthlyStatement() = 0;
	virtual void checkWriter(string toName, double amount, string date) = 0;

};

#endif
