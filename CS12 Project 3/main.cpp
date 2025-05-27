#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <typeinfo>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CertificateOfDeposit.h"
#include "ServiceChargeChecking.h"
#include "NoServiceChargeChecking.h"
#include "HighInterestChecking.h"
#include "HighInterestSavings.h"
using namespace std;

int result();

int main()
{
    BankAccount *accountArray[10];
    string accountNames[6];

    accountNames[0] = "Service charge checking account";
    accountNames[1] = "No service charge checking account";
    accountNames[2] = "High interest checking account";
    accountNames[3] = "Savings account";
    accountNames[4] = "High interest savings account";
    accountNames[5] = "Certificate of deposit account";

    string name;
    double balance;
    double rate;
    double minBal;
    double serviceCharge;
    string date;
    int mature;
	int month;
    int userInput;
    int loopVar = 1;
    int accountLoop = 0;
    string inputName;
    bool accountExists = false;
    int changeAmount;
    int accountNumber;

    cout << fixed << setprecision(2);
    cout << "Please specify what kind of account you want to make:" << endl;
    cout << "1: Service charge checking account." << endl;
    cout << "2: No service charge checking account." << endl;
    cout << "3: High interest checking account." << endl;
    cout << "4: Savings account." << endl;
    cout << "5: High interest savings account." << endl;
    cout << "6: Certificate of deposit account." << endl;
    cin >> userInput;

    while(userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4 && userInput != 5 && userInput != 6)
    {
    	cout << "Invalid input. Please enter one of the following options:" << endl;
    	cout << "1: Service charge checking account." << endl;
		cout << "2: No service charge checking account." << endl;
		cout << "3: High interest checking account." << endl;
		cout << "4: Savings account." << endl;
		cout << "5: High interest savings account." << endl;
		cout << "6: Certificate of deposit account." << endl;
    	cin >> userInput;
    }

	cout << "Please enter the account's name and balance:" << endl;
	cin >> name;
	cin >> balance;

	if(userInput == 1)
	{
		accountArray[0] = new ServiceChargeChecking(name, balance, accountNames[userInput - 1]);
	}
	if(userInput == 2)
	{
		accountArray[0] = new NoServiceChargeChecking(name, balance, accountNames[userInput - 1]);
	}
	if(userInput == 3)
	{
		accountArray[0] = new HighInterestChecking(name, balance, accountNames[userInput - 1]);
	}
	if(userInput == 4)
	{
		accountArray[0] = new SavingsAccount(name, balance, accountNames[userInput - 1]);
	}
	if(userInput == 5)
	{
		accountArray[0] = new HighInterestSavings(name, balance, accountNames[userInput - 1]);
	}
	if(userInput == 6)
	{
		accountArray[0] = new CertificateOfDeposit(name, balance, accountNames[userInput - 1]);
	}

    do {
        cout << "Please enter one of the following options:" << endl;
        cout << "1: Enter a new account." << endl;
        cout << "2: Get an account's monthly statement." << endl;
        cout << "3: Change an account's information and access account features." << endl;
        cout << "0: Exit." << endl;
        cin >> userInput;

        if(userInput == 1)
        {
        	cout << fixed << setprecision(2);
        	    cout << "Please specify what kind of account you want to make:" << endl;
        	    cout << "1: Service charge checking account." << endl;
				cout << "2: No service charge checking account." << endl;
				cout << "3: High interest checking account." << endl;
				cout << "4: Savings account." << endl;
				cout << "5: High interest savings account." << endl;
				cout << "6: Certificate of deposit account." << endl;
        	    cin >> userInput;

        	    while(userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4 && userInput != 5 && userInput != 6)
				{
					cout << "Invalid input. Please enter one of the following options:" << endl;
					cout << "1: Service charge checking account." << endl;
					cout << "2: No service charge checking account." << endl;
					cout << "3: High interest checking account." << endl;
					cout << "4: Savings account." << endl;
					cout << "5: High interest savings account." << endl;
					cout << "6: Certificate of deposit account." << endl;
					cin >> userInput;
				}

        	    cout << "Please enter the account's name and balance:" << endl;
				cin >> name;
				cin >> balance;

				if(userInput == 1)
				{
					accountArray[loopVar] = new ServiceChargeChecking(name, balance, accountNames[userInput - 1]);
				}
				if(userInput == 2)
				{
					accountArray[loopVar] = new NoServiceChargeChecking(name, balance, accountNames[userInput - 1]);
				}
				if(userInput == 3)
				{
					accountArray[loopVar] = new HighInterestChecking(name, balance, accountNames[userInput - 1]);
				}
				if(userInput == 4)
				{
					accountArray[loopVar] = new SavingsAccount(name, balance, accountNames[userInput - 1]);
				}
				if(userInput == 5)
				{
					accountArray[loopVar] = new HighInterestSavings(name, balance, accountNames[userInput - 1]);
				}
				if(userInput == 6)
				{
					accountArray[loopVar] = new CertificateOfDeposit(name, balance, accountNames[userInput - 1]);
				}

            loopVar++;
        }
        else if(userInput == 2)
        {
            cout << "Please enter the account holder's name:" << endl;
            cin >> inputName;
            cout << endl;

            for(auto accountVar : accountArray)
            {
                if(accountVar->getName() == inputName)
                {
                	accountVar->monthlyStatement();
                    accountExists = true;
                    break;
                }
            }

			if(!accountExists)
			{
				cout << "Invalid account." << endl;
			}

            accountExists = false;
            inputName = "";
        }
        else if(userInput == 3)
        {
        	cout << "Please enter the account holder's name:" << endl;
			cin >> inputName;
			cout << endl;

			for(auto accountVar : accountArray)
            {
                if(accountVar->getName() == inputName)
                {
                    accountNumber = accountLoop;
                    accountExists = true;
                    break;
                }
                accountLoop++;
            }
            accountLoop = 0;

            if(accountExists)
            {
            	if(ServiceChargeChecking *check = dynamic_cast<ServiceChargeChecking*>(accountArray[accountNumber]))
            	{
            		cout << "What would you like to do? Please enter one of the following:" << endl;
					cout << "1: Change the account name." << endl;
					cout << "2: Deposit money." << endl;
					cout << "3: Withdraw money." << endl;
					cout << "4: Change the service fee." << endl;
					cout << "5: Write a check." << endl;
					cout << "0: Return to the main menu.";
					cin >> userInput;

					ServiceChargeChecking *scc = static_cast<ServiceChargeChecking*>(accountArray[accountNumber]);

					if(userInput == 1)
					{
						cout << "Please enter the new name:" << endl;
						cin >> name;

						scc->setName(name);
					}
					else if (userInput == 2)
					{
						cout << "How much would you like to deposit?" << endl;
						cin >> changeAmount;
						cout << endl;
						scc->balAdd(changeAmount);
					}
					else if(userInput == 3)
					{
						cout << "How much would you like to withdraw?" << endl;
						cin >> changeAmount;
						cout << endl;
						scc->balSub(changeAmount);
					}
					else if (userInput == 4)
					{
						cout << "Please enter the new service fee:" << endl;
						cin >> serviceCharge;

						scc->setCharge(serviceCharge);
					}
					else if (userInput == 5)
					{
						cout << "Please enter the recipient's name, the amount to be sent and today's date:" << endl;
						cin >> name;
						cin >> balance;
						cin >> date;

						scc->checkWriter(name, balance, date);
					}
					else if (userInput == 0)
					{
					}

            	}
            	else if(NoServiceChargeChecking *check = dynamic_cast<NoServiceChargeChecking*>(accountArray[accountNumber]))
				{
            		cout << "What would you like to do? Please enter one of the following:" << endl;
					cout << "1: Change the account name." << endl;
					cout << "2: Change the interest rate." << endl;
					cout << "3: Deposit money." << endl;
					cout << "4: Withdraw money." << endl;
					cout << "5: Change the minimum balance." << endl;
					cout << "6: Write a check." << endl;
					cout << "0: Return to the main menu.";
					cin >> userInput;

					NoServiceChargeChecking *ncc = static_cast<NoServiceChargeChecking*>(accountArray[accountNumber]);

					if(typeid(accountArray[accountNumber]) == typeid(NoServiceChargeChecking))
					{
						ncc = static_cast<NoServiceChargeChecking*>(accountArray[accountNumber]);
					}
					else
					{
						ncc = static_cast<HighInterestChecking*>(accountArray[accountNumber]);
					}

					if(userInput == 1)
					{
						cout << "Please enter the new name:" << endl;
						cin >> name;

						ncc->setName(name);
					}
					else if (userInput == 2)
					{
						cout << "Please enter the new interest rate:" << endl;
						cin >> rate;

						ncc->setRate(rate);
					}
					else if (userInput == 3)
					{
						cout << "How much would you like to deposit?" << endl;
						cin >> changeAmount;
						cout << endl;
						ncc->balAdd(changeAmount);
					}
					else if(userInput == 4)
					{
						cout << "How much would you like to withdraw?" << endl;
						cin >> changeAmount;
						cout << endl;
						ncc->balSub(changeAmount);
					}
					else if (userInput == 5)
					{
						cout << "Please enter the new minimum balance:" << endl;
						cin >> minBal;

						ncc->setMinBal(minBal);
					}
					else if (userInput == 6)
					{
						cout << "Please enter the recipient's name, the amount to be sent and today's date:" << endl;
						cin >> name;
						cin >> balance;
						cin >> date;

						ncc->checkWriter(name, balance, date);
					}
					else if (userInput == 0)
					{
					}

				}
            	else if(HighInterestChecking *check = dynamic_cast<HighInterestChecking*>(accountArray[accountNumber]))
            	{
            		cout << "What would you like to do? Please enter one of the following:" << endl;
					cout << "1: Change the account name." << endl;
					cout << "2: Change the interest rate." << endl;
					cout << "3: Deposit money." << endl;
					cout << "4: Withdraw money." << endl;
					cout << "5: Change the minimum balance." << endl;
					cout << "6: Write a check." << endl;
					cout << "0: Return to the main menu.";
					cin >> userInput;

					HighInterestChecking *hic = static_cast<HighInterestChecking*>(accountArray[accountNumber]);

					if(userInput == 1)
					{
						cout << "Please enter the new name:" << endl;
						cin >> name;

						hic->setName(name);
					}
					else if (userInput == 2)
					{
						cout << "Please enter the new interest rate:" << endl;
						cin >> rate;

						hic->setRate(rate);
					}
					else if (userInput == 3)
					{
						cout << "How much would you like to deposit?" << endl;
						cin >> changeAmount;
						cout << endl;
						hic->balAdd(changeAmount);
					}
					else if(userInput == 4)
					{
						cout << "How much would you like to withdraw?" << endl;
						cin >> changeAmount;
						cout << endl;
						hic->balSub(changeAmount);
					}
					else if (userInput == 5)
					{
						cout << "Please enter the new minimum balance:" << endl;
						cin >> minBal;

						hic->setMinBal(minBal);
					}
					else if (userInput == 6)
					{
						cout << "Please enter the recipient's name, the amount to be sent and today's date:" << endl;
						cin >> name;
						cin >> balance;
						cin >> date;

						hic->checkWriter(name, balance, date);
					}
					else if (userInput == 0)
					{
					}
            	}
            	else if(SavingsAccount *check = dynamic_cast<SavingsAccount*>(accountArray[accountNumber]))
				{
            		cout << "What would you like to do? Please enter one of the following:" << endl;
					cout << "1: Change the account name." << endl;
					cout << "2: Change the interest rate." << endl;
					cout << "3: Deposit money." << endl;
					cout << "4: Withdraw money." << endl;
					cout << "0: Return to the main menu.";
					cin >> userInput;

					SavingsAccount *sa = static_cast<SavingsAccount*>(accountArray[accountNumber]);

					if(userInput == 1)
					{
						cout << "Please enter the new name:" << endl;
						cin >> name;

						sa->setName(name);
					}
					else if (userInput == 2)
					{
						cout << "Please enter the new interest rate:" << endl;
						cin >> rate;

						sa->setRate(rate);
					}
					else if (userInput == 3)
					{
						cout << "How much would you like to deposit?" << endl;
						cin >> changeAmount;
						cout << endl;
						sa->balAdd(changeAmount);
					}
					else if(userInput == 4)
					{
						cout << "How much would you like to withdraw?" << endl;
						cin >> changeAmount;
						cout << endl;
						sa->balSub(changeAmount);
					}
					else if (userInput == 0)
					{
					}

				}
            	else if(HighInterestSavings *check = dynamic_cast<HighInterestSavings*>(accountArray[accountNumber]))
				{
					cout << "What would you like to do? Please enter one of the following:" << endl;
					cout << "1: Change the account name." << endl;
					cout << "2: Change the interest rate." << endl;
					cout << "3: Deposit money." << endl;
					cout << "4: Withdraw money." << endl;
					cout << "5: Change minimum balance." << endl;
					cout << "0: Return to the main menu.";
					cin >> userInput;

					HighInterestSavings *his = static_cast<HighInterestSavings*>(accountArray[accountNumber]);

					if(userInput == 1)
					{
						cout << "Please enter the new name:" << endl;
						cin >> name;

						his->setName(name);
					}
					else if (userInput == 2)
					{
						cout << "Please enter the new interest rate:" << endl;
						cin >> rate;

						his->setRate(rate);
					}
					else if (userInput == 3)
					{
						cout << "How much would you like to deposit?" << endl;
						cin >> changeAmount;
						cout << endl;
						his->balAdd(changeAmount);
					}
					else if(userInput == 4)
					{
						cout << "How much would you like to withdraw?" << endl;
						cin >> changeAmount;
						cout << endl;
						his->balSub(changeAmount);
					}
					else if (userInput == 5)
					{
						cout << "Please enter the new minimum balance:" << endl;
						cin >> minBal;

						his->setMinBal(minBal);
					}
					else if (userInput == 0)
					{
					}
				}
            	else if(CertificateOfDeposit *check = dynamic_cast<CertificateOfDeposit*>(accountArray[accountNumber]))
				{
            		cout << "What would you like to do? Please enter one of the following:" << endl;
					cout << "1: Change the account name." << endl;
					cout << "2: Change the interest rate." << endl;
					cout << "3: Deposit money." << endl;
					cout << "4: Withdraw money." << endl;
					cout << "5: Change CD maturity months." << endl;
					cout << "6: Change current CD month." << endl;
					cout << "0: Return to the main menu.";
					cin >> userInput;

					CertificateOfDeposit *cod = static_cast<CertificateOfDeposit*>(accountArray[accountNumber]);

					if(userInput == 1)
					{
						cout << "Please enter the new name:" << endl;
						cin >> name;

						cod->setName(name);
					}
					else if (userInput == 2)
					{
						cout << "Please enter the new interest rate:" << endl;
						cin >> rate;

						cod->setRate(rate);
					}
					else if (userInput == 3)
					{
						cout << "How much would you like to deposit?" << endl;
						cin >> changeAmount;
						cout << endl;
						cod->balAdd(changeAmount);
					}
					else if(userInput == 4)
					{
						cout << "How much would you like to withdraw?" << endl;
						cin >> changeAmount;
						cout << endl;
						cod->balSub(changeAmount);
					}
					else if (userInput == 5)
					{
						cout << "Please enter the new number of maturity months:" << endl;
						cin >> mature;

						cod->setMaturity(mature);
					}
					else if (userInput == 6)
					{
						cout << "Please enter the current CD month:" << endl;
						cin >> month;

						cod->setMonth(month);
					}
					else if (userInput == 0)
					{
					}
				}
            	accountExists = false;
				inputName = "";
            }
        }
        else if(userInput == 0)
        {
            break;
        }
    }
    while(userInput != 0);

    return 0;
}
