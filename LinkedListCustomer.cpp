//Juan Urzua
//LinkedListCustomer.cpp
//P5
#include "LinkedListCustomer.h"
#include<iostream>
#include<string>
using namespace std;


namespace linkedlistofclasses
{
CCustomer::CCustomer()
{  
	link = NULL;
}

CCustomer::CCustomer(string i, string fName, string lName, float b)
{
	ID = i;
	FirstName = fName;
	LastName = lName;
	Balance = b;
	status = INACTIVE;
	link = NULL;
	for(int counter = 0; counter < 3; counter++)
	{
		CdAccountIDs[counter] = "N/A";
	}
}
CCustomer::CCustomer(const CCustomer *c)
{
	ID = c->ID;
	FirstName = c->FirstName;
	LastName = c->LastName;
	Balance = c->Balance;
	status = c->status;
	

}
CCustomer::~CCustomer()
{}
istream& operator >>(istream& ins, CCustomer& c)
{
	cout<<"What is the desired ID: ";
	ins>>c.ID;
	cout<<"Enter your first and last name seperated by a space: ";
	ins>>c.FirstName>>c.LastName;
	cout<<"What is the desired balance: ";
	ins>>c.Balance;
	if(c.Balance > 0.00)
		c.status = ACTIVE;
	else
		c.status = INACTIVE;
	return ins;
}
ostream& operator <<(ostream& outs, const CCustomer *c)
{
	outs.precision(2);
	outs.setf(ios::fixed);
	outs.setf(ios::showpoint);
	string status = "";
	if(c->status == INACTIVE)
		status = "INACTIVE";
	if(c->status == ACTIVE)
		status = "ACTIVE";
	outs<<c->ID<<" "<<c->FirstName<<" "<<c->LastName<<" "<<c->Balance<<" "<<status<<" "<<c->CdAccountIDs[0]<<" "<<c->CdAccountIDs[1]<<" "<<c->CdAccountIDs[2]<<"\n";
	return outs;
}
CCustomer* CCustomer::addNode(CCustomer *add, CCustomer *list)
{
	CCustomer *temp;
	temp = list;
	list = add;
	temp->link = list;
	list = temp;
	return list;
}
CCustomer* CCustomer::getLink()
{
	return link;
}
void CCustomer::setLink(CCustomer *next)
{
	link = next;
}
void CCustomer::setBalance(float b)
{
	Balance = b;
}
float CCustomer::getBalance()
{
	return Balance;
}

}

