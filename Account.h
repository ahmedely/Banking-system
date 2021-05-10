
#ifndef Account_H
#define Account_H

#include <string>

using namespace std;

//The class Account acts like a Vertex object

class Account
{
public:
	Account();
	Account(string fullname, double y);
	Account(const Account&);
	int getId() const;
	void setId(int x);
	void printInfo() const;
	void setFullName(string x);
	string getFullName() const;
	double getBalance() const;
	void setBalance(double x);
	~Account();


protected:
	int id;

private:
	// each bank account contains the costumer's fullname
	string fullName;

	// the balance will be the value stored in the account
	double balance;

};

#endif // !Account


