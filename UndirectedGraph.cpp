
#include <string>
#include <iostream>
#include <array>
#include "Account.h"
#include "Transaction.h"
#include "Graph.h"
#include "UndirectedGraph.h"


using namespace std;

//Default constructor
UndirectedGraph::UndirectedGraph():Graph() {

	accountSize = 0;
	transactionSize = 0;
	accounts = new Account[accountSize];
	transactions = new Transaction[transactionSize];
	maxA = 0;
	maxT = 0;

}

//Constructor with parameters
UndirectedGraph::UndirectedGraph(int x, int y):Graph(x,y) {
}

//Copy constructor
UndirectedGraph::UndirectedGraph(const UndirectedGraph& x) {

	accountSize = x.accountSize;
	transactionSize = x.transactionSize;
	accounts = x.accounts;
	transactions = x.transactions;
	maxA = x.maxA;
	maxT = x.maxT;
}

//Get the account's array
Account* UndirectedGraph::getAccounts() const {
	return accounts;
}

//Get the transaction's array
Transaction* UndirectedGraph::getTransactions() const {
	return transactions;
}

//Adding an Account to the array
bool UndirectedGraph::addAccount(Account& x) {
	//verifying if the max is reached
	if (maxA > accountSize) {
		accounts[accountSize] = x;
		accountSize++;
		return true;
	}
	return false;
}

//Since the graph is undirected, then the transaction will be just an exchange

// Adding the exchange-currency transaction
bool UndirectedGraph::addTransaction(Transaction& edg) {
	//balance should be higher than the amount wanted to exchange
	if (edg.getStart().getBalance() >= edg.getAmount() &&
		edg.getEnd().getBalance() >= edg.getAmount()) {

		if (maxT > transactionSize) {
			transactions[transactionSize] = edg;
			transactionSize++;
			return true;
		}
	}
	return false;
}

//Remove an account from the array
bool UndirectedGraph::removeAccount(Account& x) {

	int t{ 0 };
	for (size_t i = 0; i < accountSize; i++) {
		if (accounts[i].getId() == x.getId()) {
			t = i;
		}
	}
	for (size_t i = t; i < accountSize; i++)
	{

		if (i == accountSize - 1) {
			accounts[i] = {};
			return true;
		}
		else {
			accounts[i] = accounts[i + 1];
		}
	}
	return false;
}

//Remove/cancel the transaction
bool UndirectedGraph::removeTransaction(Transaction& edg) {

	int t{ 0 };

	for (size_t i = 0; i < transactionSize; i++) {

		if (transactions[i].getStart().getId() == edg.getStart().getId()
			&& transactions[i].getEnd().getId() == edg.getEnd().getId()) {
			t = i;

			for (size_t i = t; i < transactionSize; i++)
			{

				if (i == transactionSize - 1) {
					transactions[i] = {};
					return true;
				}
				else {
					transactions[i] = transactions[i + 1];
				}
			}
		}
	}
	return false;

}

//Search if a specific account exists
bool UndirectedGraph::searchAccount(const Account& myV) {

	for (size_t i = 0; i < accountSize; i++) {

		if (accounts[i].getId() == myV.getId()) {
			return true;
		}
	}
	return false;
}

//Search if a specific transaction exists
bool UndirectedGraph::searchTransaction(Transaction& myTransaction) {

	for (size_t i = 0; i < transactionSize; i++) {

		if (transactions[i].getStart().getId() == myTransaction.getStart().getId()
			&& transactions[i].getEnd().getId() == myTransaction.getEnd().getId()) {
			return true;
		}
	}

	return false;

}

//Search if a specific value exists
bool UndirectedGraph::searchValue(const Account& V)
{
	for (size_t i = 0; i < accountSize; i++) {

		if (accounts[i].getBalance() == V.getBalance()) {
			return true;
		}
	}
	return false;

}

//Gives the path where the given accounts leads to
void UndirectedGraph::accountPath(const Account& x) {
	cout << "Path:\n";
	for (size_t i = 0; i < transactionSize; i++)
	{
		//since it is an undirected graph, therefore, the account's position is useless
		// checks if the start ou end account have the same ID as the object in parameter
		if (transactions[i].getStart().getId() == x.getId() || transactions[i].getEnd().getId()==x.getId()) {

			cout << "Start account's ID: (" << transactions[i].getStart().getId() << ") <------>";
			cout << "End account's ID: (" << transactions[i].getEnd().getId() <<')'<< endl;
		}
	}
}

//Display the full graph

void UndirectedGraph::display()const{
	// The ID starts only with 100.
	if (transactions[0].getStart().getId() < 100) {
		cout << "\nThe array was cleaned!\n";
	}
	else {
		cout << "Diagram:";
		for (size_t i = 0; i < transactionSize; i++) {

			cout << "\nConnection " << i + 1 << ":\n";
			for (size_t j = 0; j < accountSize; j++) {

				if (transactions[i].getStart().getId() == accounts[j].getId()) {

					cout << "Start account's ID: (" << accounts[j].getId() << ") <------>";
					break;
				}
			}
			for (size_t k = 0; k < accountSize; k++) {

				if (transactions[i].getEnd().getId() == accounts[k].getId()) {

					cout << " End account's ID: (" << accounts[k].getId() << ")\n\n";
					break;
				}
			}
		}
	}
}

//clean both array
bool UndirectedGraph::clean() {

	for (size_t i = 0; i < accountSize; i++)
	{
		accounts[i] = {};
	}
	for (size_t i = 0; i < transactionSize; i++)
	{
		transactions[i] = {};
	}
	return true;
}

//destructor
UndirectedGraph::~UndirectedGraph() {

	delete[] accounts;
	delete[] transactions;

}