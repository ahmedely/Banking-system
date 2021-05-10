
#ifndef Graph_H
#define Graph_H

#include <string>

using namespace std;

class Graph
{
public:

	Graph();
	Graph(int,int);
	Graph(const Graph&);

	virtual ~Graph();

	//Abstact functions:
	virtual Account* getAccounts() const= 0;
	virtual Transaction* getTransactions() const= 0;

	virtual bool addAccount(Account&) = 0;
	virtual bool addTransaction(Transaction&) = 0;
	
	virtual bool removeAccount(Account&) = 0;
	virtual bool removeTransaction(Transaction&) = 0;
	
	virtual bool searchAccount(const Account&) = 0;
	virtual bool searchTransaction(Transaction&) = 0;

	virtual bool searchValue(const Account&) = 0;
	virtual void accountPath(const Account&) = 0;
	
	virtual void display()const= 0;
	virtual bool clean() = 0;


protected:
	//Account maximum size
	int maxA;
	//Transaction maximum size
	int maxT;

	int accountSize;
	int transactionSize;

	//Array of Accounts
	Account* accounts = 0;
	//Array of Transactions
	Transaction* transactions = 0;
};


#endif // !Graph

