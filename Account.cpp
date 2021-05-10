
#include <iostream>
#include <string>
#include <iomanip>
#include "Account.h"


//global variable will increment the ID each time a new object is created

int counter = 100;

//Default constructor
Account::Account() {
	id = 0;
	fullName = "";
	balance = 0.0;
}
//Constructor with parameters
Account::Account(string fullname, double y) {
	fullName = fullname;
	balance = y;
	id = counter++;
}

//Copy constructor
Account::Account(const Account& x) {
	id = counter++;
	fullName = x.fullName;
	balance = x.balance;
}

//Getters and setters:

int Account::getId() const {
	return id;
}

void Account::setId(int x) {
	id = x;
}

string Account::getFullName() const {
	return fullName;
}

void Account::setFullName(string x) {
	fullName = x;
}

double Account::getBalance() const {
	return balance;
}

void Account::setBalance(double x) {
	balance = x;
}

//Print info about the account
void Account::printInfo() const {
	cout << "Full name: " << fullName << endl;
	cout << "ID: " << id << endl;
	cout << "Balance: " <<fixed<< setprecision(2) << balance << " $" << endl;
}

//Destructor
Account::~Account() {

}
