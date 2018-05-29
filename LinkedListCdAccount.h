//Juan Urzua
//LinkedListCdAccount.h
//P5
#include<string>
#include<iostream>
using namespace std;
#ifndef _CCDACCOUNT_H
#define _CCDACCOUNT_H
namespace linkedlistofclasses
{
class CCdAccount
{
public:
	CCdAccount();
	CCdAccount(string id, float rate, int term, float d);
	CCdAccount(const CCdAccount *c);
	~CCdAccount();
	string ID;
	float Rate;
	int YearTerm;
	friend istream& operator >>(istream& ins, CCdAccount& c);
	friend ostream& operator <<(ostream& outs, const CCdAccount *c);
	CCdAccount *getLink();
	CCdAccount *addNode(CCdAccount *add, CCdAccount *list);
	void setLink(CCdAccount *next);
	void setNULL();
	void setDeposit(float deposit);
	float getDeposit();
	

private:
	float Deposit;
	CCdAccount* link;
};
typedef CCdAccount* CdPtr;
}
#endif