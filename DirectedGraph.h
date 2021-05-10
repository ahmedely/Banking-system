
#ifndef DirectedGraph_H
#define DirectedGraph_H

#include <string>

using namespace std;

class DirectedGraph: public Graph
{
public:

	DirectedGraph();
	DirectedGraph(int, int);
	DirectedGraph(const DirectedGraph&);

	virtual Account* getAccounts() const;
	virtual Transaction* getTransactions() const;

	virtual bool addAccount(Account&);
	virtual bool addTransaction(Transaction&);

	virtual bool removeAccount(Account&);
	virtual bool removeTransaction(Transaction&);

	virtual bool searchAccount(const Account&);
	virtual bool searchTransaction(Transaction&);

	virtual bool searchValue(const Account&);
	virtual void accountPath(const Account&);

	virtual void display()const;
	virtual bool clean();
	
	virtual ~DirectedGraph();
};


#endif // !DirectedGraph

