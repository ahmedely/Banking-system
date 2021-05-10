
#include <string>
#include <iostream>
#include <array>
#include "Account.h"
#include "Transaction.h"
#include "Graph.h"
#include "DirectedGraph.h"


using namespace std;

//Default constructor
DirectedGraph::DirectedGraph():Graph() {

	accountSize = 0;
	transactionSize = 0;
	accounts = new Account[accountSize];
	transactions = new Transaction[transactionSize];
	maxA = 0;
	maxT = 0;

}

//Constructor with parameters
DirectedGraph::DirectedGraph(int x, int y):Graph(x,y) {
}

//Copy constructor
DirectedGraph::DirectedGraph(const DirectedGraph& x) {

	accountSize = x.accountSize;
	transactionSize = x.transactionSize;
	accounts = x.accounts;
	transactions = x.transactions;
	maxA = x.maxA;
	maxT = x.maxT;
}

//Get the Account's array
Account* DirectedGraph::getAccounts() const{
	return accounts;
}

//Get the Transaction's array
Transaction* DirectedGraph::getTransactions() const {
	return transactions;
}

//Adding an Account to the array
bool DirectedGraph::addAccount(Account& x) {

	//verifying if the max is reached
	if (maxA >= accountSize) {
		accounts[accountSize] = x;
		accountSize++;
		return true;
	}
	return false;
}

//Since it is a directed graph, the transaction will be a withdraw
//Fill the withdraw transcation
bool DirectedGraph::addTransaction(Transaction& edg) {
	//verifying if the max is reached
	if (maxT >= transactionSize) {
		try
		{
			//Withdraw cannot be executed if amount>balance
			if (edg.getStart().getBalance() <= edg.getAmount()) {
				throw "ERROR: Insufficient money in your account.\n";
			}
			edg.getStart().setBalance(edg.getStart().getBalance() - edg.getAmount());
			edg.getEnd().setBalance(edg.getEnd().getBalance() + edg.getAmount());
			transactions[transactionSize] = edg;
			transactionSize++;
			return true;
		}
		catch (const char* e)
		{
			cout << e;
		}
	}
}

//Remove an account from the array
bool DirectedGraph::removeAccount(Account& x) {

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
bool DirectedGraph::removeTransaction(Transaction& edg) {

	int t{ 0 };
	//returning the money to their owners
	edg.getStart().setBalance(edg.getStart().getBalance() + edg.getAmount());
	edg.getEnd().setBalance(edg.getEnd().getBalance() - edg.getAmount());

	//removing the transaction from the array
	for (size_t i = 0; i < transactionSize; i++) {

		if (transactions[i].getStart().getId() == edg.getStart().getId()
			&& transactions[i].getEnd().getId() == edg.getEnd().getId()) {
			t = i;
			break;
		}
	}
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
	return false;
}

//Search if a specific account exists
bool DirectedGraph::searchAccount(const Account& myV) {

	for (size_t i = 0; i < accountSize; i++) {

		if (accounts[i].getId() == myV.getId()) {
			return true;
		}
	}
	return false;
}

//Search if a specific transaction exists
bool DirectedGraph::searchTransaction(Transaction& myTransaction) {

	for (size_t i = 0; i < transactionSize; i++) {

		if (transactions[i].getStart().getId() == myTransaction.getStart().getId()
			&& transactions[i].getEnd().getId() == myTransaction.getEnd().getId()) {
			return true;
		}
	}

	return false;

}

//Search if a specific value exists
bool DirectedGraph::searchValue(const Account& V)
{
	for (size_t i = 0; i < accountSize; i++) {

		if (accounts[i].getBalance() == V.getBalance()) {
			return true;
		}
	}
	return false;

}

//Shows the path where an account leads to
void DirectedGraph::accountPath(const Account& x) {
	
	cout << "Path:\n";
	for (size_t i = 0; i < transactionSize; i++)
	{
		//checks when the account's ID is the same
		if (transactions[i].getStart().getId() == x.getId()) {

			cout << "Start Account's ID: (" << transactions[i].getStart().getId() << ") ------>";
			cout << "End Account's ID: (" << transactions[i].getEnd().getId()<<")\n"<<endl;
		}
	}
}

//Display the full graph

void DirectedGraph::display() const {
	// The ID starts can never be less than 100.
	if (transactions[0].getStart().getId() < 100) {
		cout << "\nThe array was cleaned!\n";
	}
	else {
		cout << "Diagram:";
		for (size_t i = 0; i < transactionSize; i++) {
			//number i transaction
			cout << "\nConnection " << i + 1 << ":\n";
			for (size_t j = 0; j < accountSize; j++) {

				if (transactions[i].getStart().getId() == accounts[j].getId()) {
					//starting account
					cout << "Start Account's ID: (" << accounts[j].getId() << ") ------>";
					break;
				}
			}
			for (size_t k = 0; k < accountSize; k++) {

				if (transactions[i].getEnd().getId() == accounts[k].getId()) {
					//Ending account
					cout << " End Account's ID: (" << accounts[k].getId() << ")\n\n";
					break;
				}
			}
		}
	}
}

//Clean the array
bool DirectedGraph::clean() {

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

//Desctructor
DirectedGraph::~DirectedGraph() {

	delete[] accounts;
	delete[] transactions;

}