#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include "employee.h"
using namespace std;
char ch,ch1;
string s2;
struct emp
{
	string name;
	int empNo;
	int salary;
	int hireStatus;
	int fireStatus;
};
class Database:public Employee
{
public:
	
};
int main()
{
	cout << "Welcome to the Employee Database Management System!\n";
	do
	{
	cout << "Press e to enter the details of employees..\n";
	cin >> ch;
		if (ch == 101)
		{
			emp *empl = new emp;
			cout << "Enter details of the employee to be hired..\n";
			cout << "Enter employee name :\n";
			cin.ignore();
			getline(cin, s2);
			empl->name = s2;
			cout << "Assign EmployeeNo. :\n";
			cin >> empl->empNo;
			Database db;
			db.hire();
			empl->salary = db.salary;
			empl->hireStatus = db.hireStatus;
			empl->fireStatus = db.fireStatus;
		}
		else
			cout << "Please press e..\n";
		cout << "Would you like to enter another employee's details?\n";
		cin >> ch1;
		cout << endl;
	} while (ch1==121);
	return 0;
}
