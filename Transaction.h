
#ifndef Transaction_H
#define Transaction_H

#include<string>

using namespace std;

//The class Transaction acts like an Edge object

class Transaction
{
public:

	Transaction();
	Transaction(Account&,Account&, double);
	Transaction(const Transaction&);
	Account& getStart();
	void setStart(Account a);
	Account& getEnd() ;
	void setEnd(Account z);
	double getAmount()const;
	void setAmount(double x);
	void printInfo() const;
	~Transaction();

protected:

	double amount;
	Account start;
	Account end;
};

#endif // !Transaction
