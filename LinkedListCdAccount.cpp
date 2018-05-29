//Juan Urzua
//LinkedListCdAccount.cpp
//P5

#include "LinkedListCdAccount.h"
#include<iostream>
#include<string>
using namespace std;
namespace linkedlistofclasses
{
CCdAccount::CCdAccount()
{
	
	link = NULL;

}
CCdAccount::CCdAccount(string id, float rate, int term, float d)
{
	ID = id;
	Rate = rate;
	YearTerm = term;
	Deposit = d;

}
void CCdAccount::setNULL()
{
	link = NULL;
}

CCdAccount::CCdAccount(const CCdAccount *c)
{
	ID = c->ID;
	Rate = c->Rate;
	YearTerm = c->YearTerm;
	Deposit = c->Deposit;
}
CCdAccount::~CCdAccount()
{
}
CCdAccount* CCdAccount::getLink()
{
	return link;
}
CCdAccount* CCdAccount::addNode(CCdAccount *next, CCdAccount *list)
{
	CCdAccount *temp;
	temp = list;
	list = next;
	temp->link = list;
	list = temp;
	return temp;

}
void CCdAccount::setLink(CCdAccount *next)
{
	link = next;
}
istream& operator>>(istream& ins, CCdAccount& c)
{
	cout<<"Enter desired ID: ";
	ins>>c.ID;
	cout<<"Enter desired rate: ";
	ins>>c.Rate;
	cout<<"Enter desired year term: ";
	ins>>c.YearTerm;
	cout<<"Enter desired deposit: ";
	ins>>c.Deposit;
	return ins;
}
ostream& operator<<(ostream& outs, const CCdAccount *c)
{
	outs<<c->ID<<" ";
	outs.precision(1);
	outs.setf(ios::fixed);
	outs.setf(ios::showpoint);
	outs<<c->Rate<<"   ";
	outs<<c->YearTerm<<"   ";
	outs.precision(1);
	outs.setf(ios::fixed);
	outs.setf(ios::showpoint);
	outs<<c->Deposit<<endl;
	return outs;
	
}

float CCdAccount::getDeposit()
{
	return Deposit;

}
void CCdAccount::setDeposit(float deposit)
{
	Deposit = deposit;
}

}
