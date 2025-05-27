#ifndef CertificateOfDeposit_H
#define CertificateOfDeposit_H

#include <string>
#include "BankAccount.h"
using namespace std;

class CertificateOfDeposit: public BankAccount
{
private:
	const double RATE = 0.05;
	const int CD_MATURITY = 40;
	double rate;
	int cdMaturity;
	int cdMonth;
	double interest;
public:
	CertificateOfDeposit();
	CertificateOfDeposit(string name, double bal, string type);

	int getMaturity();
	int getMonth();
	double getRate();

	void setRate(double inputRate);
	void setMaturity(int maturity);
	void setMonth(int month);

	void balSub(double subAmount);
	void monthlyStatement();
};

#endif
