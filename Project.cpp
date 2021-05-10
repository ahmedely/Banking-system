
#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include "Account.h"
#include "Transaction.h"
#include "Graph.h"
#include "DirectedGraph.h"
#include "UndirectedGraph.h"

using namespace std;

int main()
{
	//Accounts

	Account myV1("Holei Sm1th", 243.00);
	Account myV2("Michi Monc", 2273.12);
	Account myV3("Sizi Pentchi", 12313.01);
	Account myV4("Ween Dragon", 33.97);
	Account myV5("Mantera Sei", 2100002.04);
	Account myV6("Danzu Itch", 20.00);

	//Testing Account functions
	cout << "ACCOUNTS:\n\n";

	cout << myV1.getId() << endl;
	cout <<fixed<<setprecision(2)<< myV3.getBalance() << endl;
	cout << myV4.getId() << endl;
	cout << myV4.getFullName() << endl;
	myV2.printInfo();
	cout << "\n***************************\n";

	//Transactions

	Transaction transaction1(myV1, myV2, 12.55);
	Transaction transaction2(myV1, myV3, 3.14);
	Transaction transaction3(myV4, myV1, 13.666);
	Transaction transaction4(myV3, myV2, 22.21);
	Transaction transaction5(myV2, myV4, 5.43);
	Transaction transaction6(myV5, myV3, 0.001);
	Transaction transaction7(myV4, myV6, 4.321);

	//Testing Transaction functions

	cout << "\nTRANSACTIONS:\n\n";
	cout << transaction7.getEnd().getId() << endl;
	cout <<fixed<<setprecision(2)<< transaction2.getAmount() << endl;
	cout << transaction3.getStart().getBalance()<<endl;
	transaction4.printInfo();
	cout << "\n***************************\n";

	//Directed graph

	DirectedGraph myGraph1(20,20);

	cout << "Directed Graph:\n";
	myGraph1.addAccount(myV1);
	myGraph1.addAccount(myV2);
	myGraph1.addAccount(myV3);
	myGraph1.addAccount(myV4);
	myGraph1.addAccount(myV5);

	myGraph1.addTransaction(transaction1);
	myGraph1.addTransaction(transaction2);
	myGraph1.addTransaction(transaction3);
	myGraph1.addTransaction(transaction4);
	myGraph1.addTransaction(transaction5);
	myGraph1.addTransaction(transaction6);

	
	//Testing Directed_Graph functions
	cout << "\n";

	cout << myGraph1.searchAccount(myV5)<<'\n'<<endl;
	myGraph1.accountPath(myV3);
	myGraph1.display();

	myGraph1.clean();

	myGraph1.display();


	cout << "\n***************************\n";

	//Undirected graph

	UndirectedGraph myGraph2(20,10);

	myGraph2.addAccount(myV1);
	myGraph2.addAccount(myV6);
	myGraph2.addAccount(myV2);
	myGraph2.addAccount(myV3);
	myGraph2.addAccount(myV4);
	myGraph2.addAccount(myV5);
	myGraph2.addAccount(myV6);

	myGraph2.addTransaction(transaction1);
	myGraph2.addTransaction(transaction2);
	myGraph2.addTransaction(transaction3);
	myGraph2.addTransaction(transaction4);
	myGraph2.addTransaction(transaction5);
	myGraph2.addTransaction(transaction6);
	myGraph2.addTransaction(transaction7);

	//Testing Undirected_Graph functions


	cout << myGraph2.searchTransaction(transaction1)<<endl;
	cout << myGraph2.searchAccount(myV6)<<'\n'<<endl;
	myGraph2.accountPath(myV3);
	cout << endl;
	myGraph2.display();

	return 0;
}