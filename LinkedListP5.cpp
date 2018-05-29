//Filename:LinkedListP5.cpp
//Programmer:  Juan Urzua                                                     CSCI 123, Spring 2017
//Project 5                                                                Instructor:  Timothy Mai
//Due Date: 05/20/17                                                          Date Submitted: 05/20/17
//Program Description: 
//This program copies the data found within the attached ".dat" files into an array of CCdAccounts and CCustomers classes.
//Once copied into the array, the user is able to request to see specific data dealing with the accounts.
//An example would be to look up specifc deposits, IDs, last names, all the accounts, etc.
//The user is also able to open up an account by inputting deposit, ID, yearterm, and agreeing to our offered rate.
//Once the user quits the program, all the date is then submitting back into the files.


#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<sstream>
#include<cstring>
#include"LinkedListCdAccount.h"
#include"LinkedListCustomer.h"
using namespace std;
using namespace linkedlistofclasses;

int menu();
void AddCDNode(CdPtr& c);
void AddCustNode(CustPtr& c);
void readCCdAccountInfo();
void readCCustomerInfo();
void writeCCdAccountInfo();
void writeCCustomerInfo();
void CDFrontToBack(CdPtr& c);
void CCustFrontToBack(CustPtr& c);
void setCDNode(CdPtr& c, CdPtr a);
void setCustNode(CustPtr& c, CustPtr a);
void ListAllCDAccounts();
void ListAllAccountsWithDepositAmountGreaterThanSpecificNumber();
void ListInformationOfASpecificAccountUsingTheCDAccountsID();
void ListAllAccountsOfACustomerBasedOnCustomerID();
void ListInformationOfAllCustomers();
void ListInformationOfAllCustomersWithASpecificStatus();
void ListInformationOfAllCustomersWithASpecificLastName();
void ListInformationOfASpecificCustomerUsingCustomerID();
float GetInitialDeposit();
int GetDuration(int min, int max);
double RandomPercentage();
CCustomer *AddNode(CCustomer *add, string id, string fname, string lname, float balance);
CCdAccount *AddCDNode(CCdAccount *next, string id, float deposit, float rate, int year);
bool NewID(string id);
string RandomIDNumber();
float CalculateBalance(float pDeposit, float pRate, int pYears);
void MakeADepositToABankAccount();
void ListAllAccountsWithRateGreaterThanASpecificRate();
void ListAllAccountsWithYearTermLongerThanASpecificTerm();
void ListInformationOfAllCustomersWithMultipleCDs();
void ListInformationOfAllCustomersWithTotalBalanceGreaterThanASpecificAmount();
void RemoveACustomer();
void RemoveCust(string ID);
bool CheckCDs(string ID);
float TotalBalance(CustPtr c);
CCustomer *locate(string ID);
void RemoveCD(string ID);
void OpenNewCdAccount();
void CreatNewCustomer();
void CloseACDAccount();
void Quit();

CustPtr cust = NULL;
CustPtr custback;
CdPtr Cd = NULL;
CdPtr CdBack;

void main()
{
	readCCdAccountInfo();
	readCCustomerInfo();
	int choice;
	do{
		system("CLS");
	
		choice = menu();
		switch (choice)
		{
		case 1:
			ListInformationOfAllCustomers();
			break;
		case 2:
			CreatNewCustomer();
			break;
		case 3:
			RemoveACustomer();
			break;
		case 4:
			MakeADepositToABankAccount();
			break;
		case 5:
			ListInformationOfAllCustomersWithASpecificStatus();
			break;
		case 6:
			ListInformationOfAllCustomersWithMultipleCDs();
			break;
		case 7:
			ListInformationOfAllCustomersWithTotalBalanceGreaterThanASpecificAmount();
			break;
		case 8:
			ListInformationOfAllCustomersWithASpecificLastName();
			break;
		case 9:
			ListInformationOfASpecificCustomerUsingCustomerID();
			break;
		case 10:
			ListAllCDAccounts();
			break;
		case 11:
			ListAllAccountsWithRateGreaterThanASpecificRate();
			break;
		case 12: 
			ListAllAccountsWithYearTermLongerThanASpecificTerm();
			break;
		case 13:
			ListAllAccountsWithDepositAmountGreaterThanSpecificNumber();
			break;
		case 14:
			ListInformationOfASpecificAccountUsingTheCDAccountsID();
			break;
		case 15:
			ListAllAccountsOfACustomerBasedOnCustomerID();
			break;
		case 16:
			OpenNewCdAccount();
			break;
		case 17:
			CloseACDAccount();
			break;
		case 18:
			Quit();
			break;
		default:
			cout<<"That was an invalid choice, please try again!!\n";

		}
		system("PAUSE");
	}while(!(choice == 18));
}
int menu()
{
	int option;
	cout<<"				BANK ACCOUNT SYSTEM \n\n";
	cout<<"1. List Information Of All Bank Customers.\n";
	cout<<"2. Add A Customer.\n";
	cout<<"3. Remove A Customer.\n";
	cout<<"4. Make Deposit To A Bank Account.\n";
	cout<<"5. List Information Of All Customers With A Specific Status.\n";
	cout<<"6. List Information Of All Customers Having Multiple CDs.\n";
	cout<<"7. List Information Of All Customers With Total Balance More Than A Specific Amount\n";
	cout<<"8. List Information Of Customers With A Specific Last Name. \n";
	cout<<"9. List Information Of A Specific Customer Using Customer ID. \n";
	cout<<"10.List All CD Accounts.\n";
	cout<<"11.List All Accounts With Rate Greater Than A Specific Rate.\n";
	cout<<"12.List All Accounts With Year Term Longer Than A Specific Term.\n";
	cout<<"13.List All Accounts With Deposit More Than A Specific Amount.\n";
	cout<<"14.List Information Of A Specific Account Using The Account ID.\n";
	cout<<"15.List All Accounts Of A Customer Based On Customer ID.\n";
	cout<<"16.Open A New CD Account.\n";
	cout<<"17.Close A CD Account.\n";
	cout<<"18.Quit.\n\n";

	cout<<"Please select your option: ";
	cin>>option;
	while(option < 1 || option >18)
	{
		cout<<"Invalid Option!! Please select a valid option.";
		cin>>option;
	}
	return option;
}
void CDFrontToBack(CdPtr& c)
{
	CdPtr temp1, temp2;
	temp1 = Cd;
	while(temp1->getLink() != NULL)
	{
		temp2 = new CCdAccount();
		setCDNode(temp2, temp1);
		if(c->ID == "CD00")
			c = temp2;
		else
		{
			CdPtr temp3;
			temp3 = c;
			c = temp2;
			c->setLink(temp3);
		}
		temp1 = temp1->getLink();
		if(temp1->getLink() == NULL)
		{
			temp2 = new CCdAccount();
			setCDNode(temp2, temp1);
			CdPtr temp4;
			temp4 = c;
			c = temp2;
			c->setLink(temp4);
		}
	}


}
void CCustFrontToBack(CustPtr& c)
{
	CustPtr temp1, temp2;
	temp1 = cust;
	while(temp1->getLink() != NULL)
	{
		temp2 = new CCustomer();
		setCustNode(temp2, temp1);
		if(c->ID == "Z000")
			c = temp2;
		else
		{
			CustPtr temp3;
			temp3 = c;
			c = temp2;
			c->setLink(temp3);
		}
		temp1 = temp1->getLink();
		if(temp1->getLink() == NULL)
		{
			temp2 = new CCustomer();
			setCustNode(temp2, temp1);
			CustPtr temp4;
			temp4 = c;
			c = temp2;
			c->setLink(temp4);

		}
	}

}
void setCustNode(CustPtr& c, CustPtr a)
{
	c->ID = a->ID;
	c->FirstName = a->FirstName;
	c->LastName = a->LastName;
	c->status = a->status;
	c->CdAccountIDs[0] = a->CdAccountIDs[0];
	c->CdAccountIDs[1] = a->CdAccountIDs[1];
	c->CdAccountIDs[2] = a->CdAccountIDs[2];
	float balance = a->getBalance();
	c->setBalance(balance);

}
void setCDNode(CdPtr& c, CdPtr a)
{
	c->ID = a->ID;
	c->Rate = a->Rate;
	float deposit = a->getDeposit();
	c->setDeposit(deposit);
	c->YearTerm = a->YearTerm;
}
void readCCdAccountInfo()
{
	float deposit;
	ifstream input;
	CdPtr temp;
	
	input.open("LinkedListCdAccounts.dat");
	if(input.fail())
	{
		cout<<"Unable to read file\n";
		exit(1);
	}
	while(!input.eof())
	{
		temp = new CCdAccount();
		input>>temp->ID;
		if(temp->ID.length() != 7)
			break;
		input>>deposit;
		temp->setDeposit(deposit);
		input>>temp->Rate;
		input>>temp->YearTerm;
		AddCDNode(temp);
		
	}
	input.close();
}
void AddCDNode(CdPtr& c)
{
	CdPtr temp;
	if(Cd == NULL)
	{
		c->setLink(Cd);
		Cd = c;
	}
	else
	{
		temp = Cd;
		Cd = c;
		Cd->setLink(temp);
	}
}
void AddCustNode(CustPtr& c)
{
	CustPtr temp;
	if(cust == NULL)
	{
		c->setLink(cust);
		cust = c;
	}
	else
	{
		temp = c;
		temp->setLink(cust);
		cust = temp;
		
	}
}
void readCCustomerInfo()
{
	float balance;
	string status;
	CustPtr temp;
	
	
	ifstream input;
	input.open("LinkedListCustomers.dat");
	if(input.fail())
	{
		cout<<"Unable to open file\n";
		exit(1);
	}
	while(!input.eof())
	{
		temp = new CCustomer;
		input>>temp->ID;
		if(temp->ID.length() != 4)
			break;
		input>>temp->FirstName;
		input>>temp->LastName;
		input>>balance;
		temp->setBalance(balance);
		input>>status;
		if(status == "INACTIVE")
			temp->status = INACTIVE;
		else
			temp->status = ACTIVE;
		input>>temp->CdAccountIDs[0];
		input>>temp->CdAccountIDs[1];
		input>>temp->CdAccountIDs[2];
		
		AddCustNode(temp);
	}
	input.close();
}
void writeCCustomerInfo()
{
	
	ofstream outstream;
	outstream.open("LinkedListCustomers.dat");
	if(outstream.fail())
	{
		cout<<"Unable to open file\n";
		exit(1);
	}
	CustPtr temp = new CCustomer();
	CCustFrontToBack(temp);
	while(temp->getLink() != NULL)
	{
		outstream<<temp->ID<<" ";
		outstream<<temp->FirstName<<" ";
		outstream<<temp->LastName<<" ";
		outstream.precision(2);
		outstream.setf(ios::fixed);
		outstream.setf(ios::showpoint);
		outstream<<temp->getBalance()<<" ";
		if(temp->status == INACTIVE)
			outstream<<"INACTIVE"<<" ";
		if(temp->status == ACTIVE)
			outstream<<"ACTIVE"<<" ";
		for(int counter = 0; counter<3; counter++)
		{
			outstream<<temp->CdAccountIDs[counter]<<" ";
		}
		outstream<<"\n";
		temp = temp->getLink();
	}
	outstream.close();
}
void writeCCdAccountInfo()
{
	ofstream outstream;
	outstream.open("LinkedListCdAccounts.dat");
	if(outstream.fail())
	{
		cout<<"Unable to open file\n";
		exit(1);
	}
	CdPtr temp = new CCdAccount();
	CDFrontToBack(temp);
	while(temp->getLink() != NULL)
	{
		outstream<<temp->ID<<" ";
		outstream.precision(2);
		outstream.setf(ios::fixed);
		outstream.setf(ios::showpoint);
		outstream<<temp->getDeposit()<<" ";
		outstream.precision(1);
		outstream.setf(ios::fixed);
		outstream.setf(ios::showpoint);
		outstream<<temp->Rate<<" ";
		outstream<<temp->YearTerm<<" ";
		outstream<<"\n";
		temp = temp->getLink();

	}
	outstream.close();
}
void ListAllCDAccounts()
{
	CdBack = new CCdAccount;
	CDFrontToBack(CdBack);
	cout<<"\n";
	cout<<"ID"<<"      RATE "<<"TERM"<<" DEPOSIT\n";
	while(true)
	{
		cout<<CdBack;
		CdBack = CdBack->getLink();
		if(CdBack->getLink() == NULL)
			break;
	}

}
void ListAllAccountsWithDepositAmountGreaterThanSpecificNumber()
{
	float deposit;
	bool presentvalue = false;
	cout<<"What is the deposit amount?";
	cin>>deposit;
	CdPtr temp = new CCdAccount();
	CDFrontToBack(temp);
	cout<<"\n";
	while(temp->getLink() != NULL)
	{
		if(temp->getDeposit() > deposit)
		{
			cout<<temp;
			if(presentvalue == false)
				presentvalue = true;
		}
		temp = temp->getLink();
		if(temp->getLink() == NULL)
		{
			if(temp->getDeposit()>deposit)
			{
				cout<<temp;
				if(presentvalue == false)
					presentvalue = true;
			}
		}

	}
	if(presentvalue == false)
	{
		cout<<"There was no such account with greater than that specifc deposit";
		cout<<"\n";
	}
}
void ListInformationOfASpecificAccountUsingTheCDAccountsID()
{
	string ID;
	bool presentvalue = false;
	cout<<"What is the desired ID?";
	cin>>ID;
	CdPtr temp = new CCdAccount();
	CDFrontToBack(temp);
	cout<<"\n";
	
	while(temp->getLink() != NULL)
	{
		if(temp->ID == ID)
		{

			cout<<temp;
			if(presentvalue == false)
				presentvalue = true;
		}
		temp = temp->getLink();
		if(temp->getLink() == NULL)
		{
			if(temp->ID == ID)
			{
				cout<<temp;
				if(presentvalue == false)
					presentvalue = true;
			}
		}

	}
	if(presentvalue == false)
	{
		cout<<"There was no such account with that ID";
		cout<<"\n";
	}
}
void ListAllAccountsOfACustomerBasedOnCustomerID()
{
	string ID;
	bool presentvalue = false;
	cout<<"What is the desired 4 digit ID?";
	cin>>ID;
	while(ID.length() != 4)
	{
		cout<<"Please enter a 4 digit ID: ";
		cin>>ID;
	}
	CdPtr temp = new CCdAccount();
	CDFrontToBack(temp);
	while(temp->getLink() != NULL)
	{
		if(temp->ID.find(ID) != string::npos)
		{
			cout<<temp;
			if(presentvalue == false)
				presentvalue = true;
		}
		temp = temp->getLink();
		if(temp->getLink() == NULL)
		{
			if(temp->ID.find(ID) != string::npos)
			{
				cout<<temp;
				if(presentvalue == false)
					presentvalue = true;
			}
		}

	}
	if(presentvalue == false)
	{
		cout<<"There were no such accounts with that ID";
		cout<<"\n";
	}
}
void ListInformationOfAllCustomers()
{
	custback = new CCustomer;
	CCustFrontToBack(custback);
	cout<<"\n";
	while(true)
	{
		
		cout<<custback;
		custback = custback->getLink();
		if(custback->getLink() == NULL)
		{
			break;
		}
	}
}
void ListInformationOfAllCustomersWithASpecificStatus()
{
	int response;
	
	cout<<"To view accounts with status INACTIVE enter 0 and enter 1 to view accounts with status ACTIVE: ";
	cin>>response;
	while(response != 1 && response != 0)
	{
		cout<<"Invalid input, please enter a 1 or 0";
		cin>>response;
	}
	cout<<"\n";
	CustPtr temp = new CCustomer();
	CCustFrontToBack(temp);
	while(temp->getLink() != NULL)
	{
		if(response == 0)
		{
			if(temp->status == INACTIVE)
				cout<<temp;
			
		}
		if(response == 1)
		{
			if(temp->status == ACTIVE)
				cout<<temp;
		}
		temp = temp->getLink();
		if(temp->getLink() == NULL)
		{
			if(response == 0)
			{
				if(temp->status == INACTIVE)
					cout<<temp;
				
			}
			if(response == 1)
			{
				if(temp->status == ACTIVE)
					cout<<temp;
			}
		}
	}
	
}
void ListInformationOfAllCustomersWithASpecificLastName()
{
	string lastname;
	bool presentvalue = false;
	cout<<"What is the last name of the account(s)? ";
	cin>>lastname;
	CustPtr temp = new CCustomer();
	CCustFrontToBack(temp);
	cout<<"\n";
	while(temp->getLink() != NULL)
	{
		if(temp->LastName == lastname)
		{
			cout<<temp;
			if(presentvalue == false)
				presentvalue = true;
		}
		temp = temp->getLink();
		if(temp->getLink() == NULL)
		{
			if(temp->LastName == lastname)
			{
				cout<<temp;
				if(presentvalue == false)
					presentvalue = true;
			}
		}

	}
	if(presentvalue == false)
	{
		cout<<"There isnt an account with that last name.";
		cout<<"\n";
	}
}
void ListInformationOfASpecificCustomerUsingCustomerID()
{
	string ID;
	bool presentvalue = false;
	cout<<"What is the ID?";
	cin>>ID;
	CustPtr temp = new CCustomer();
	temp = cust;
	cout<<"\n";
	
	while(true)
	{
		if(temp->ID == ID)
		{
			cout<<temp;
			if(presentvalue == false)
				presentvalue = true;
			break;
		}
		temp = temp->getLink();
		if(temp->getLink() == NULL)
		{
			if(temp->ID == ID)
			{
				cout<<temp;
				if(presentvalue == false)
					presentvalue = true;
				
			}
			break;
		}

	}
	if(presentvalue == false)
	{
		cout<<"There isnt an account with that ID.";
		cout<<"\n";
	}
}
float GetInitialDeposit()
{
	bool reinput = false;
	float deposit;
	cout<<"Enter your initial deposit: ";
	cin>>deposit;
	if(deposit > 100000 || deposit <= 0)
		reinput = true;
	while(reinput)
	{
		cout<<"Deposit is out of desired range, enter deposit between 0 and 100000:";
		cin>>deposit;
		if(deposit<=100000 && deposit > 0)
			reinput = false;
	}
	return deposit;
}
int GetDuration(int min, int max)
{
	bool reinput = false;
	int years;
	cout<<"Enter how many years the money will be certified: ";
	cin>>years;
	if(years<1 || years>10)
		reinput = true;
	while(reinput)
	{
		cout<<"Years certified is out of range, enter rate between "<<min<<" and "<<max<<":";
		cin>>years;
		if(years>=1 && years<=10)
			reinput = false;
	}
	return years;
}
double RandomPercentage()
{
	srand ((unsigned)time (NULL));
	int randomNum = rand();
	randomNum %= 450;
	double percentage = randomNum/100.00 + 0.5;
	return percentage;
}


bool NewID(string id)
{
	bool newID = true;
	CustPtr temp;
	temp = cust;
	while(temp->getLink() != NULL)
	{
		if(temp->ID == id)
		{
			newID = false;
			break;
		}
		else
		{
			temp = temp->getLink();
			if(temp->getLink() == NULL)
			{
				if(temp->ID == id)
					newID = false;
			}
		}
	}
	return newID;
}
string RandomIDNumber()
{
	string zeros;
	string IDdigits;
	string digits;
	srand ((unsigned)time (NULL));
	int randomNum = rand();
	randomNum %= 1000;
	if(randomNum < 10)
	{
		zeros = "00";
		stringstream convert;
		convert<<randomNum;
		digits = convert.str();
		IDdigits += zeros;
		IDdigits += digits;
		return IDdigits;

	}
	else if (randomNum > 10 && randomNum < 100)
	{	
		zeros = "0";
		stringstream convert;
		convert<<randomNum;
		digits = convert.str();
		IDdigits += zeros;
		IDdigits += digits;
		return IDdigits;
	}
	else
	{
		stringstream convert;
		convert<<randomNum;
		digits = convert.str();
		IDdigits += digits;
		return IDdigits;
	}

	
	

}
float CalculateBalance(float pDeposit, float pRate, int pYears)
{
	float balance;
	int compounding = 12;
	float rate = pRate/100;
	balance = pDeposit * pow((1 + rate/compounding), compounding * pYears);
	return balance;
}
void MakeADepositToABankAccount()
{
	string ID;
	cout<<"Enter your Customer ID: ";
	cin>>ID;
	bool validID = NewID(ID);
	if(validID == true)
	{
		cout<<"There was no Customer account with that ID.\n";
	}
	else
	{
		float deposit = GetInitialDeposit();
		CustPtr temp;
		temp = cust;
		while(temp->ID != ID)
			temp = temp->getLink();
		deposit = temp->getBalance() + deposit;
		temp->setBalance(deposit);
		cout<<"Congratulations! Your deposit has been made!\n\n";
	}


}
void ListAllAccountsWithRateGreaterThanASpecificRate()
{
	float rate;
	bool exists = false;
	cout<<"What is the rate? ";
	cin>>rate;
	CdPtr temp;
	temp = Cd;
	cout<<"\n";
	while(temp->getLink() != NULL)
	{
		if(temp->Rate >= rate)
		{
			cout<<temp;
			if(exists == false)
				exists = true;
		}
		temp = temp->getLink();
		if(temp->getLink() == NULL)
		{
			if(temp->Rate >= rate)
			{
				cout<<temp;
				if(exists == false)
					exists = true;
			}
		}
	}
	if(exists == false)
		cout<<"Sorry, there were no accounts with Rate greater than Rate specified.\n\n";
}
void ListAllAccountsWithYearTermLongerThanASpecificTerm()
{
	int yearterm;
	bool exists = false;
	cout<<"What is the term? ";
	cin>>yearterm;
	CdPtr temp;
	temp = Cd;
	while(temp->getLink() != NULL)
	{
		if(temp->YearTerm >= yearterm)
		{
			cout<<"\n"<<temp<<"\n";
			if(exists == false)
				exists = true;
		}
		temp = temp->getLink();
		if(temp->getLink() == NULL)
		{
			if(temp->YearTerm >= yearterm)
			{
				cout<<"\n"<<temp<<"\n";
				if(exists == false)
					exists = true;
			}
		}
	}
	if(exists == false)
		cout<<"Sorry, there were no accounts with term greater than term specified.\n\n";

}
void ListInformationOfAllCustomersWithMultipleCDs()
{
	bool exists = false;
	int total;
	cout<<"How many CD accounts? ";
	cin>>total;
	while(total>3 || total<1)
	{
		cout<<"Amount is out of bounds. Enter amount that is equal to or less than 3 and greater than 0: ";
		cin>>total;
	}
	CustPtr temp;
	temp = cust;
	cout<<"\n";
	while(temp->getLink() != NULL)
	{
		

		if(total == 1)
		{
			if((temp->CdAccountIDs[0] != "N/A"&& temp->CdAccountIDs[1] == "N/A" 
				&& temp->CdAccountIDs[2] == "N/A") || (temp->CdAccountIDs[0] == "N/A"&& temp->CdAccountIDs[1] != "N/A" 
				&& temp->CdAccountIDs[2] == "N/A") || (temp->CdAccountIDs[0] == "N/A"&& temp->CdAccountIDs[1] == "N/A" 
				&& temp->CdAccountIDs[2] != "N/A"))
			{
				cout<<temp;
				if(exists == false)
					exists = true;
			}
		}
		if(total == 2)
		{
			if((temp->CdAccountIDs[0] != "N/A"&& temp->CdAccountIDs[1] != "N/A" 
				&& temp->CdAccountIDs[2] == "N/A") || (temp->CdAccountIDs[0] == "N/A"&& temp->CdAccountIDs[1] != "N/A" 
				&& temp->CdAccountIDs[2] != "N/A") || (temp->CdAccountIDs[0] != "N/A"&& temp->CdAccountIDs[1] == "N/A" 
				&& temp->CdAccountIDs[2] != "N/A"))
			{
				cout<<temp;
				if(exists == false)
					exists = true;
			}
		}
		if(total == 3)
		{
			if((temp->CdAccountIDs[0] != "N/A"&& temp->CdAccountIDs[1] != "N/A" 
				&& temp->CdAccountIDs[2] != "N/A"))
			{
				cout<<temp;
				if(exists == false)
					exists = true;
			}
		}
		temp = temp->getLink();
		if(temp->getLink() == NULL)
		{
			
			if(total == 1)
			{
				if((temp->CdAccountIDs[0] != "N/A"&& temp->CdAccountIDs[1] == "N/A" 
					&& temp->CdAccountIDs[2] == "N/A") || (temp->CdAccountIDs[0] == "N/A"&& temp->CdAccountIDs[1] != "N/A" 
					&& temp->CdAccountIDs[2] == "N/A") || (temp->CdAccountIDs[0] == "N/A"&& temp->CdAccountIDs[1] == "N/A" 
					&& temp->CdAccountIDs[2] != "N/A"))
				{
					cout<<temp;
					if(exists == false)
						exists = true;
				}
			}
			if(total == 2)
			{
				if((temp->CdAccountIDs[0] != "N/A"&& temp->CdAccountIDs[1] != "N/A" 
					&& temp->CdAccountIDs[2] == "N/A") || (temp->CdAccountIDs[0] == "N/A"&& temp->CdAccountIDs[1] != "N/A" 
					&& temp->CdAccountIDs[2] != "N/A") || (temp->CdAccountIDs[0] != "N/A"&& temp->CdAccountIDs[1] == "N/A" 
					&& temp->CdAccountIDs[2] != "N/A"))
				{
					cout<<temp;
					if(exists == false)
						exists = true;
				}
			}
			if(total == 3)
			{
				if((temp->CdAccountIDs[0] != "N/A"&& temp->CdAccountIDs[1] != "N/A" 
					&& temp->CdAccountIDs[2] != "N/A"))
				{
					cout<<temp;
					if(exists == false)
						exists = true;
				}
			}
		}
		
	}
	if(exists == false)
		cout<<"Sorry, there were no customer accounts with that many CD accounts.\n\n";
}
void RemoveACustomer()
{
	string ID;
	bool validID;
	cout<<"What is the ID? ";
	cin>>ID;
	validID = NewID(ID);
	if(validID == true)
	{
		cout<<"Sorry, there was no customer account with that ID.";
	}
	else
	{
		bool exists = CheckCDs(ID);
		if(exists == false)
		{
			CustPtr temp = locate(ID);
			cout.precision(2);
			cout.setf(ios::showbase);
			cout.setf(ios::fixed);
			cout<<"Your final balance is: "<<temp->getBalance()<<". Have a Nice Day!!\n\n";
			
			RemoveCust(ID);

		}
		else
		{
			string response;
			cout<<"This Customer account contains CDs. They will be removed too if you remove your Customer account. Are you sure you want to do this? (Y/N)";
			cin>>response;
			while(response != "Y" && response != "y" && response != "N" && response != "n")
			{
				cout<<"Invalid input. Enter (Y/N): ";
				cin>>response;
			}
			if(response == "N" || response == "n")
			{
				cout<<"Your account was not removed. Have a nice Day!!\n\n";

			}
			else
			{
				CustPtr temp = locate(ID);
				float total = TotalBalance(temp);
				cout.precision(2);
				cout.setf(ios::showbase);
				cout.setf(ios::fixed);
				cout<<"This is your final balance: "<<total<<"\n";
				RemoveCust(ID);
				string CD1 = ID + "CD1";
				string CD2 = ID + "CD2";
				string CD3 = ID + "CD3";
				RemoveCD(CD1);
				RemoveCD(CD2);
				RemoveCD(CD3);

				cout<<"Your account has been removed. Have a Nice Day!!\n\n";

			}
		}
	}
}
void RemoveCust(string ID)
{
	CustPtr temp, temp2;
	temp = cust;
	if(temp->ID == ID)
	{
		cust = cust->getLink();
		delete temp;
	}
	else
	{
		
		while(true)
		{
			temp2 = temp;
			temp = temp->getLink();
			if(temp->ID == ID)
			{
				temp2->setLink(temp->getLink());
				delete temp;
				break;
			}

		}
	}
}
void RemoveCD(string ID)
{
		int iteration = 0;
		CdPtr temp3, temp4, temp5;
		temp3 = Cd;
		while(true)
		{
			if(iteration == 0)
			{
				if(temp3->ID == ID)
				{
						Cd = Cd->getLink();
						delete temp3;
						break;
				}
				else
				{
					temp4 = temp3;
					temp3 = temp3->getLink();
					iteration += 1;
				}
			}
			else
			{
				if(temp3->ID == ID)
				{
					if(temp3->getLink() != NULL)
					{
						temp5 = temp3->getLink();
						temp4->setLink(temp5);
						delete temp3;
						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					if(temp3->getLink() == NULL)
						break;
					else
					{
					temp4 = temp3;
					temp3 = temp3->getLink();
					}
				}
			}

	}

}
bool CheckCDs(string ID)
{
	CustPtr temp;
	bool CD = false;
	temp = cust;
	while(true)
	{
		if(temp->ID == ID)
		{
			if(temp->CdAccountIDs[0] != "N/A" ||temp->CdAccountIDs[1] != "N/A" || temp->CdAccountIDs[2] != "N/A")
				CD = true;
			break;
		}
		if(temp->getLink() == NULL)
			break;
		else
			temp = temp->getLink();
	}
	return CD;
}
CCustomer *locate(string ID)
{
	CustPtr temp = cust;
	if(temp->ID == ID)
		return temp;
	else
	{
		while(true)
		{
			temp = temp->getLink();
			if(temp->ID == ID)
				return temp;
			if(temp->getLink() == NULL)
				break;
		}
	}
}

void OpenNewCdAccount()
{
	string ID;
	cout<<"Enter your 4 digit ID: ";
	cin>>ID;
	bool validID = false;
	stringstream convert;
	bool balance = false;
	float total;
	int numberofaccounts = 0;
	bool CD1 = true;
	bool CD2 = true;
	bool CD3 = true;
	CustPtr temp;
	temp = cust;
	while(true)
	{
		if(temp->ID == ID)
		{
			validID = true;
			if(temp->CdAccountIDs[0] == "N/A")
				CD1 = false;
			if(temp->CdAccountIDs[1] == "N/A")
				CD2 = false;
			if(temp->CdAccountIDs[2] == "N/A")
				CD3 = false;
			if(temp->getBalance()>0.0)
			{
				balance = true;
				total = temp->getBalance();
				break;
			}

			break;
		}
		if(temp->getLink() != NULL)
			temp = temp->getLink();
		else
			break;

	}
	
	if(validID == false)
	{
		cout<<"No such ID was found.\n";
		
	}
	else if(balance == false)
	{
		cout<<"Sorry, you do not have any remaining balance in your Customer Account to open a CD account. Please make a deposit to your account to create a CD account.\n\n";
		
	}
	else
	{
		CdPtr temp2;
		temp2 = Cd;
		while(true)
		{
			if(temp2->ID.find(ID) != string::npos)
			{
				numberofaccounts = numberofaccounts + 1;
			}
			if(temp2->getLink() != NULL)
			{
				temp2 = temp2->getLink();
			}
			else
				break;
		}
	
	if(numberofaccounts == 3)
	{
		cout<<"I am sorry, but you have reached the limit of open CD accounts.\n";
		
	}
	else
	{
		if(CD1 == false && CD2 == true && CD3 == true)
			numberofaccounts = 0;
		if(CD1 == true && CD2 == false && CD3 == true)
			numberofaccounts = 1;
		numberofaccounts = numberofaccounts + 1;
		convert<<numberofaccounts;
		string accounts = convert.str();
		string dummyID = ID;
		ID += "CD";
		ID += accounts;
		float deposit = GetInitialDeposit();
		if(deposit>total)
		{
			cout<<"You do not have enough in your balance to make such a deposit. Add more money to your balance if you would like to make such a deposit.\n";
			
		}
		else
		{

			int year = GetDuration(1,10);
			double rate = RandomPercentage();
			string agree;
			cout.precision(1);
			cout.setf(ios::showpoint);
			cout.setf(ios::fixed);
			cout<<"This is the rate we can offer you on your new account: "<<rate<<endl;
			cout<<"Do you agree to this rate? if yes, your new account will be open. If no, then no new account is created.\n";
			cin>>agree;
			while(agree != "yes" && agree != "Yes" && agree != "No" && agree != "no")
			{
				cout<<"Invalid input, enter a yes or no: ";
				cin>>agree;
			}
			if(agree == "no" || agree == "No")
			{
				cout<<"Account was not created. Have a nice day !!\n\n";
		
			}
			else
			{
				CustPtr temp3;
				temp3 = cust;
				while(true)
				{
					if(temp3->ID == dummyID)
					{
						for(int counter = 0; counter<3;counter++)
						{
							if(temp3->CdAccountIDs[counter] == "N/A")
							{
								temp3->CdAccountIDs[counter] = ID;
								break;
							}
						}
						if(temp3->status == INACTIVE)
							temp3->status = ACTIVE;
						total = total - deposit;
						temp3->setBalance(total);

						break;
					}
					if(temp3->getLink() != NULL)
						temp3 = temp3->getLink();
					else
						break;

				}
				CdPtr temp4 = new CCdAccount;
				
				Cd = AddCDNode(temp4, ID, deposit, (float)rate, year);
				cout<<"Your Account has been created!!\n\n";
				
				
			}
		}
	}
	}
}
void CloseACDAccount()
{
	string ID;
	bool validID = false;
	bool CDexists = false;
	float adjustedbalance;
	cout<<"What is your customer ID? ";
	cin>>ID;
	CustPtr temp;
	temp = cust;
	while(true)
	{
		if(temp->ID == ID)
		{
			adjustedbalance = temp->getBalance();
			validID = true;
			break;
		}
		if(temp->getLink() != NULL)
			temp = temp->getLink();
		else
			break;

	}
	if(validID == false)
		cout<<"Sorry, there isnt a customer account with that ID\n\n";
	else
	{
		CdPtr temp1;
		temp1 = Cd;
		while(true)
		{
			if(temp1->ID.find(ID) != string::npos)
			{
				if(CDexists == false)
					CDexists = true;
				cout<<"\n"<<temp1<<"\n";
			}
			if(temp1->getLink() != NULL)
				temp1 = temp1->getLink();
			else
				break;
		}
		if(CDexists == false)
			cout<<"Sorry, your customer account does not have any open CD accounts.\n";
		else
		{
			string CDid;
			CCdAccount temp;
			string answer;
			cout<<"Which CD account would you like to close?";
			cin>>CDid;
			bool invalid = false;
			CdPtr temp2;
			temp2 = Cd;
			while(true)
			{
				if(temp2->ID == CDid)
				{
					invalid = true;
					break;
				}
				if(temp2->getLink() != NULL)
					temp2 = temp2->getLink();
				else
					break;
			}
			while(invalid == false)
			{
				temp2 = Cd;
				cout<<"Invalid input, please enter the ID of the CD account you wish to close: ";
				cin>>CDid;
				while(true)
				{
					if(temp2->ID == CDid)
					{
						invalid = true;
						break;
					}
					if(temp2->getLink() != NULL)
						temp2 = temp2->getLink();
					else
						break;
				}
			}
			
					adjustedbalance = adjustedbalance + temp2->getDeposit();
					float pdeposit = temp2->getDeposit();
					float prate = temp2->Rate;
					int pyear = temp2->YearTerm;
					cout.precision(2);
					cout.setf(ios::showpoint);
					cout.setf(ios::fixed);
					cout<<"This would have been the ending balance on the account "<<CalculateBalance(pdeposit, prate, pyear)<<". Are you sure you want to delete it? (Y/N)";
					cin>>answer;
					while(answer != "Y" && answer != "N" && answer != "y" && answer != "n")
					{
						cout<<"Invalid input, enter (Y/N): ";
						cin>>answer;
					}
					if(answer == "Y" || answer == "y")
					{
						int iteration = 0;
						CdPtr temp3, temp4, temp5;
						temp3 = Cd;
						while(true)
						{
							if(iteration == 0)
							{
								if(temp3->ID == CDid)
								{
									Cd = Cd->getLink();
									delete temp3;
									break;
								}
								else
								{
									temp4 = temp3;
									temp3 = temp3->getLink();
									iteration += 1;
								}
							}
							else
							{
								if(temp3->ID == CDid)
								{
									if(temp3->getLink() != NULL)
									{
										temp5 = temp3->getLink();
										temp4->setLink(temp5);
										delete temp3;
										break;
									}
									else
									{
										temp4->setNULL();
										delete temp3;
										break;
									}
								}
								else
								{
									temp4 = temp3;
									temp3 = temp3->getLink();
								}
							}
						}
						CustPtr temp6;
						temp6 = cust;

						while(true)
						{
							if(temp6->ID == ID)
							{
								temp6->setBalance(adjustedbalance);
								for(int counter= 0; counter<3; counter++)
								{
									if(temp6->CdAccountIDs[counter] == CDid)
									{
										temp6->CdAccountIDs[counter] = "N/A";
										break;
									}
								}
								if(temp6->CdAccountIDs[0] == "N/A" && temp6->CdAccountIDs[1] == "N/A" && temp6->CdAccountIDs[2] == "N/A")
									temp6->status = INACTIVE;
								break;
							}
							if(temp6->getLink() != NULL)
								temp6 = temp6->getLink();
							else
								break;
						}
					
						cout<<"Your CD account has been removed.\n";
						
					}
					else
					{
						cout<<"Your CD account was not removed.\n";
						
					}
				}
			}
		}
void Quit()
{
	writeCCustomerInfo();
	writeCCdAccountInfo();
	cout<<"\nHave A Nice Day!!!\n\n";
	exit(0);
}
void ListInformationOfAllCustomersWithTotalBalanceGreaterThanASpecificAmount()
{
	float balance;
	bool exists = false;
	cout<<"What is the balance? ";
	cin>>balance;
	CustPtr temp;
	temp = cust;
	cout<<"\n";
	while(true)
	{
		float total = TotalBalance(temp);
		if(total > balance)
		{
			cout.precision(2);
			cout.setf(ios::showpoint);
			cout.setf(ios::fixed);
			cout<<temp<<"Total Balance with CD accounts(s) factored in: "<<total<<endl<<endl;
			if(exists == false)
				exists = true;
		}
		if(temp->getLink() != NULL)
			temp= temp->getLink();
		else
			break;
	}
	if(exists == false)
		cout<<"Sorry, there were no accounts with Balance greater than Balance specified.\n\n";
}
float TotalBalance(CustPtr c)
{
	float total = 0;
	string ID = c->ID;
	CdPtr temp;
	temp = Cd;
	while(true)
	{
		if(temp->ID.find(ID)!= string::npos)
		{
			total += temp->getDeposit();
		}
		if(temp->getLink() != NULL)
			temp = temp->getLink();
		else
			break;
	}
	total = total + c->getBalance();
	return total;

}
void CreatNewCustomer()
{

	bool accountlimit = true;
	string firstname;
	string lastname;
	string ID;
	stringstream convert;
	bool newID;
	float deposit;
	CustPtr temp;
	
	cout<<"Please enter your first and last name seperated by a space: ";
	cin>>firstname>>lastname;
	do
	{
		
		char letter = lastname[0];
		convert<<letter;
		ID = convert.str();
		ID += RandomIDNumber();
		newID = NewID(ID);

	}while(newID == false);
		
		
		deposit = GetInitialDeposit();
		temp = new CCustomer;
		cust = AddNode(temp, ID, firstname, lastname, deposit);
		
		
		cout<<"Congratulations!! Your customer account has been created! This is the information on your Customer Account: \n\n";
		cout<<cust<<"\n\nHave a nice Day!!\n";
		
}
CCustomer *AddNode(CCustomer *next, string id, string fname, string lname, float balance)
{
	next->ID = id;
	next->FirstName = fname;
	next->LastName = lname;
	next->setBalance(balance);
	next->status = INACTIVE;
	for(int counter= 0; counter<3; counter++)
		next->CdAccountIDs[counter] = "N/A";

	next->setLink(cust);
	return next;
}
CCdAccount *AddCDNode(CCdAccount *next, string id, float deposit, float rate, int year)
{
	next->ID = id;
	next->setDeposit(deposit);
	next->Rate = rate;
	next->YearTerm = year;
	next->setLink(Cd);
	return next;
}