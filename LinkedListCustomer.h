//Juan Urzua
//LinkedListCustomer.h
//P5
#include<string>
#include<iostream>
using namespace std;

#ifndef _CCUSTOMER_H
#define _CCUSTOMER_H
enum CustomerStatus{INACTIVE, ACTIVE};
namespace linkedlistofclasses
{
	class CCustomer
	{
	public:
		CCustomer();
		CCustomer(string id, string fName, string lName, float b);
		CCustomer(const CCustomer *c);
		~CCustomer();
		friend istream& operator >>(istream& ins, CCustomer& c);
		friend ostream& operator <<(ostream& outs, const CCustomer *data);
		string ID;
		string FirstName;
		string LastName;
		string CdAccountIDs[3];
		CustomerStatus status;
		CCustomer *getLink();
		void setLink(CCustomer *next);
		CCustomer *addNode(CCustomer *add, CCustomer *list);
		void setBalance(float b);
		float getBalance();
	
	private:
		float Balance;
		CCustomer *link;
	};
	typedef CCustomer* CustPtr;
}
#endif