#ifndef BankAccount_H
#define BankAccount_H

#include <string>
using namespace std;

class BankAccount
{
private:
        static int ID;
        int myID;
protected:
        double balance;
        string name;
        string type;
public:
        BankAccount();
        BankAccount(int ID, string name, double balance, string type);
        int getID();
        string getName();
        double getBal();
        string getType();

        static int setID();
        void setName(string inputName);
        void setBal(double inputBalance);
        void balAdd(double addAmount);
        void setType(string inputType);

        virtual void balSub(double subAmount) = 0;
        virtual void monthlyStatement() = 0;

        void setBankAccount(string inputName, double inputBal, string inputType);

};

#endif
