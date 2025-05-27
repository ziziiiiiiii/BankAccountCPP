#include <string>
#include <iostream>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CertificateOfDeposit.h"
#include "ServiceChargeChecking.h"
#include "NoServiceChargeChecking.h"
#include "HighInterestChecking.h"
#include "HighInterestSavings.h"
using namespace std;

int BankAccount::ID = 0;

BankAccount::BankAccount()
{
    name = "N/A";
    balance = 0.0;
    type = "N/A";
}

int BankAccount::getID()
{
    return myID;
}

string BankAccount::getName()
{
    return name;
}

double BankAccount::getBal()
{
    return balance;
}

string BankAccount::getType()
{
    return type;
}

int BankAccount::setID()
{
    BankAccount::ID++;
    return ID;
}

void BankAccount::setName(string inputName)
{
    name = inputName;
}

void BankAccount::setBal(double inputBal)
{
    balance = inputBal;
}

void BankAccount::balAdd(double addAmount)
{
    balance += addAmount;
    cout << "The new balance amount is: $" << balance << endl;
}

void BankAccount::balSub(double subAmount)
{
    balance -= subAmount;
    cout << "The new balance amount is: $" << balance << endl;
}

void BankAccount::setType(string inputType)
{
    type = inputType;
}

void BankAccount::setBankAccount(string inputName, double inputBal, string inputType)
{
    name = inputName;
    balance = inputBal;
    type = inputType;
    myID = setID();
}


//------


CheckingAccount::CheckingAccount()
{
}


//------


ServiceChargeChecking::ServiceChargeChecking(string name, double bal, string type)
{
	setBankAccount(name, bal, type);
	checkLimit = CHECK_LIMIT;
	currentChecks = CHECK_LIMIT;
	serviceCharge = SERVICE_CHARGE;
}

int ServiceChargeChecking::getLimit()
{
	return checkLimit;
}

double ServiceChargeChecking::getCharge()
{
	return serviceCharge;
}

void ServiceChargeChecking::setLimit(int limit)
{
	checkLimit = limit;
}

void ServiceChargeChecking::setCharge(double charge)
{
	serviceCharge = charge;
}

void ServiceChargeChecking::postCharge()
{
	setBal(getBal() - serviceCharge);
	cout << "The interest gained is: $" << serviceCharge << endl;
	cout << "The new balance is: $" << getBal() << endl;
}

void ServiceChargeChecking::balSub(double subAmount)
{
	setBal(getBal() - subAmount);
	cout << "The new balance is: $" << getBal() << endl;
}

void ServiceChargeChecking::monthlyStatement()
{
	cout << getName() << "\'s account information:" << endl;
    cout << "Account ID: " << getID() << endl;
    cout << "Account type: service charge checking account"<< endl;
    cout << "$" << getBal() << endl;
    cout << "The current service charge is fee is: $" << getCharge() << endl;
    cout << "The maximum number of checks is: " << checkLimit << endl;
    cout << "The number of checks left this month is: " << currentChecks << endl;
}

void ServiceChargeChecking::checkWriter(string toName, double amount, string date)
{
	setBal(getBal() - amount);
	currentChecks -= 1;

	cout << getName() << "'s check dated " << date << ":" << endl;
	cout << "To: " << toName << endl;
	cout << "Amount: $" << amount << endl;
}


//------

NoServiceChargeChecking::NoServiceChargeChecking(string name, double bal, string type)
{
	setBankAccount(name, bal, type);
	rate = RATE;
	minBal = MIN_BAL;
	interest = 0;
}

double NoServiceChargeChecking::getRate()
{
    return rate;
}

double NoServiceChargeChecking::getMinBal()
{
	return minBal;
}

void NoServiceChargeChecking::getInterest()
{
	interest =  balance * getRate();
}

void NoServiceChargeChecking::postInterest()
{
	setBal(getBal() + interest);
	cout << "The interest gained is: $" << interest << endl;
	cout << "The new balance is: $" << getBal() << endl;
}

void NoServiceChargeChecking::setRate(double inputRate)
{
    rate = inputRate;
}

void NoServiceChargeChecking::setMinBal(double inputMin)
{
	minBal = inputMin;
}

void NoServiceChargeChecking::balSub(double subAmount)
{
	setBal(getBal() - subAmount);
	cout << "The new balance is: $" << getBal() << endl;
}

void NoServiceChargeChecking::monthlyStatement()
{
	getInterest();
	cout << getName() << "\'s monthly statement:" << endl;
	cout << "Account ID: " << getID() << endl;
	cout << "Account type: no service charge checking account"<< endl;
	cout << "$" << getBal() << endl;
	cout << "Interest rate: " << rate << endl << endl;
	cout << "The current minimum balance is: $" << minBal << endl;
	cout << "The current interest payment is: $" << interest << endl;
}

void NoServiceChargeChecking::checkWriter(string toName, double amount, string date)
{
	setBal(getBal() - amount);

	cout << getName() << "'s check dated " << date << ":" << endl;
	cout << "To: " << toName << endl;
	cout << "Amount: $" << amount << endl;
}


//------

//------


SavingsAccount::SavingsAccount(string name, double bal, string type)
{
	setBankAccount(name, bal, type);
	rate = RATE;
}

double SavingsAccount::getRate()
{
    return rate;
}

void SavingsAccount::getInterest()
{
	interest =  getBal() * getRate();
}

void SavingsAccount::postInterest()
{
	setBal(getBal() + interest);
	cout << "The interest gained is: $" << interest << endl;
	cout << "The new balance is: $" << getBal() << endl;
}

void SavingsAccount::setRate(double inputRate)
{
    rate = inputRate;
}

void SavingsAccount::balSub(double subAmount)
{
	setBal(getBal() - subAmount);
	cout << "The new balance is: $" << getBal() << endl;
}

void SavingsAccount::monthlyStatement()
{
	getInterest();
	cout << getName() << "\'s monthly statement:" << endl;
	cout << "Account ID: " << getID() << endl;
	cout << "Account type: savings account"<< endl;
	cout << "$" << getBal() << endl;
	cout << "Interest rate: " << rate << endl << endl;
	cout << "The current interest payment is: $" << interest << endl;
}


//------


double HighInterestSavings::getMinBal()
{
	return minBal;
}

void HighInterestSavings::setMinBal(double inputMin)
{
	minBal = inputMin;
}

void HighInterestSavings::monthlyStatement()
{
	getInterest();
	cout << getName() << "\'s monthly statement:" << endl;
	cout << "Account ID: " << getID() << endl;
	cout << "Account type: high interest savings account"<< endl;
	cout << "$" << getBal() << endl;
	cout << "Interest rate: " << rate << endl << endl;
	cout << "The current minimum balance is: $" << minBal << endl;
	cout << "The current interest payment is: $" << interest << endl;
}


//------


CertificateOfDeposit::CertificateOfDeposit(string name, double bal, string type)
{
	setBankAccount(name, bal, type);
	rate = RATE;
	cdMaturity = CD_MATURITY;
	cdMonth = 0;
	interest = 0;
}

int CertificateOfDeposit::getMaturity()
{
	return cdMaturity;
}

int CertificateOfDeposit::getMonth()
{
	return cdMonth;
}

double CertificateOfDeposit::getRate()
{
	return rate;
}

void CertificateOfDeposit::setRate(double inputRate)
{
	rate = inputRate;
}

void CertificateOfDeposit::setMaturity(int maturity)
{
	cdMaturity = maturity;
}

void CertificateOfDeposit::setMonth(int month)
{
	cdMonth = month;
}

void CertificateOfDeposit::balSub(double subAmount)
{
	setBal(getBal() - subAmount);
	cout << "The new balance is: $" << getBal() << endl;
}

void CertificateOfDeposit::monthlyStatement()
{
	cout << getName() << "\'s monthly statement:" << endl;
	cout << "Account ID: " << getID() << endl;
	cout << "Account type: certificate of deposit account"<< endl;
	cout << "$" << getBal() << endl;
	cout << "Interest rate: " << rate << endl << endl;
	cout << "The number of CD maturity months is: " << cdMaturity << endl;
	cout << "The current CD month is: " << cdMonth << endl;
}
