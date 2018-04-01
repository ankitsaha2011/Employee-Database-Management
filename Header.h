#pragma once
#include<iostream>
using namespace std;
class Employee
{
public:
	string name;
	int empNo;
	int salary;
	int hireStatus;
	int fireStatus;
	Employee();
	void hire();
	void fire();
	void promote();
	void demote();
	void viewcurremp();
	void viewforemp();
};
void Employee::promote()
{
	int raiseAmount = 10000;
}
void Employee::demote()
{
	int demeritAmount = 10000;
}
Employee::Employee()
{
	name="";
	empNo = -1;
	salary = -1;
	hireStatus = -1;
	fireStatus = -1;
}
void Employee::hire()
{
	//setter
	hireStatus = 0;
	salary = 20000;
	fireStatus = -1;
}
void Employee::fire()
{
	//setter
	fireStatus = 0;
	salary = 0;
	hireStatus = -1;
}
void Employee::viewcurremp()
{}
void Employee::viewforemp()
{}
