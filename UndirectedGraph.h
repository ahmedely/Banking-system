
#ifndef UndirectedGraph_H
#define UndirectedGraph_H

#include <string>

using namespace std;

class UndirectedGraph : public Graph
{
public:

	UndirectedGraph();
	UndirectedGraph(int,int);
	UndirectedGraph(const UndirectedGraph&);
	
	virtual Account* getAccounts() const;
	virtual Transaction* getTransactions() const;

	virtual bool addAccount(Account&);
	virtual bool addTransaction(Transaction&);

	virtual bool removeAccount(Account&);
	virtual bool removeTransaction(Transaction&);
	
	virtual bool searchAccount(const Account&);
	virtual bool searchTransaction(Transaction&);

	virtual bool searchValue(const Account& V);
	virtual  void accountPath(const Account&);
	
	virtual void display()const;
	virtual bool clean();

	virtual ~UndirectedGraph();
};


#endif // !UndirectedGraph

