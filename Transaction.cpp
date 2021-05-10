
#include "Account.h"
#include "Transaction.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

//Default construcor
Transaction::Transaction() {
	amount = 0;
	start = {};
	end = {};
}

//constructor with parameters
Transaction::Transaction(Account& bg,Account& fn, double x) {
	start = bg;
	end = fn;
	amount = x;
}

//Copy constructor
Transaction::Transaction(const Transaction& edg) {
	amount = edg.amount;
	start = edg.start;
	end = edg.end;
}

//Getters and setters:

double Transaction::getAmount() const{

	return amount;
}

void Transaction::setAmount(double x) {

	amount = x;
}

Account& Transaction::getStart(){
	return start;
}

void Transaction::setStart(Account a) {
	start = a;
}

Account& Transaction::getEnd(){
	return end;
}

void Transaction::setEnd(Account z) {
	end = z;
}

// Print the info about the transaction

void Transaction::printInfo() const{
	cout << "\nStart Account info:      ID: " << start.getId() << endl;
	cout << "End Account info:        ID: " << end.getId() << endl;
	cout << "Amount transfered:       " << setprecision(2) << amount <<" $"<< endl;
}

//Destructor
Transaction::~Transaction() {

}
