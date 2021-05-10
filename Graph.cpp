
#include <iostream>
#include <string>
#include <array>
#include "Account.h"
#include "Transaction.h"
#include "Graph.h"

using namespace std;

//Default constructor
Graph::Graph() {
	accountSize = 0;
	transactionSize = 0;
	accounts = new Account[accountSize];
	transactions = new Transaction[transactionSize];
	maxA = 0;
	maxT = 0;

}

//Constructor with parameters
Graph::Graph(int x,int y) {
	try
	{
		maxA = x;
		maxT = 0;
		accountSize = 0;
		transactionSize = 0;
		accounts = new Account[maxA];
		//Limitate the number of transactions(edges) that can be executed between available costumers
		if (y > ((x * (x - 3) / 2) + x)) {
			throw 102;
		}
		maxT = y;
		transactions = new Transaction[maxT];
	}
	catch (int x)
	{
		cout << "ERROR " << x << ": Impossible number of transaction";
	}
}

//Copy constructor
Graph::Graph(const Graph& x) {

	accountSize = x.accountSize;
	transactionSize = x.transactionSize;
	accounts = x.accounts;
	transactions = x.transactions;
	maxA = x.maxA;
	maxT = x.maxT;
}

//Destructor
Graph::~Graph() {

	delete[] accounts;
	delete[] transactions;

}