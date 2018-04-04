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
};
void Employee::promote()
{
	salary  += 10000;
}
void Employee::demote()
{
	salary -= 10000;
}
Employee::Employee()
{
	name="";
	empNo = -1;
	salary = -1;
	hireStatus = 0;
	fireStatus = 0;
}
void Employee::hire()
{
	//setter
	hireStatus = 1;
	salary = 20000;
	fireStatus = -1;
}
void Employee::fire()
{
	//setter
	fireStatus = 1;
	salary = 0;
	hireStatus = -1;
}
