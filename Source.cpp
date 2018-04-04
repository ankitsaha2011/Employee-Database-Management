//dynamic array used
#include<iostream>
#include<string>
#include<cstdlib>
#include "employee.h"
using namespace std;
char ch,ch1;
string s2;
int i = 0, max = 5, check = 0,mask=0;
struct emp
{
	string name;
	int empNo;
	int salary;
	int hireStatus;
	int fireStatus;
};
emp *empl = new emp[max];
class Database:public Employee
{
public:
	void newemployeehire();
	void employeefire( int check);
	void promotion(int check);
	void demotion(int check);
};
void Database::newemployeehire()
{
	cout << "Enter details of the employee :\n";
	cout << "Enter employee name :\n";
	cin.ignore();
	getline(cin, s2);
	empl[i].name = s2;
	cout << "Assign EmployeeNo. :\n";
	cin >> empl[i].empNo;
	Database db;
	db.hire();
	empl[i].salary = db.salary;
	empl[i].hireStatus = db.hireStatus;
	empl[i].fireStatus = db.fireStatus;
	mask++;
	if (i >= max)
	{
		max *= 2;
		emp *temp = new emp[max];
		for (int j = 0; j < i; j++)
			temp[j] = empl[j];
		delete[]empl;
		empl = temp;
	}
	i++;
	cout << i << endl;
}
void Database::employeefire( int check)
{
	for (int j = 0; j < i; j++)
	{
		if (empl[j].empNo == check)
		{
			Database db2;
			db2.fire();
			empl[j].salary = db2.salary;
			empl[j].hireStatus = db2.hireStatus;
			empl[j].fireStatus = db2.fireStatus;
			mask--;
			break;
		}
	}
}
void Database::promotion(int check)
{
	Database db2;
	db2.promote();
	for (int j = 0; j < i; j++)
	{
		if (empl[j].empNo == check)
		{
			db2.promote();
			empl[j].salary = db2.salary;
		}
	}
}
void Database::demotion(int check)
{
	Database db2;
	db2.demote();
	for (int j = 0; j < i; j++)
	{
		if (empl[j].empNo == check)
		{
			db2.demote();
			empl[j].salary = db2.salary;
		}
	}
}
int main()
{
	Database db;
	cout << "Welcome to the Employee Database Management System!\n"<<endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -\n" << endl;
	do
	{
		cout << "Press h to hire , f to fire , p to promote , d to demote , c to view current employees , v to view fired employees :\n";
		cin >> ch;
		if (ch == 'h' || ch == 'f' || ch=='p' || ch=='d' || ch=='c' || ch=='v')
			switch (ch)
			{
			case (char)'h':
				db.newemployeehire();
				break;
			case (char)'f':
				if (mask != 0)
				{
					cout << "Enter Employee Number of employee to be fired :\n";
					cin >> check;
					db.employeefire(check);
				}
				else if(mask==0)
					cout << "No employess to be fired \n";
				break;
			case (char)'p':
				if (mask != 0)
				{
					cout << "Enter Employee Number of employee to be promoted :\n";
					cin >> check;
					db.promotion(check);
				}
				else
					cout << "No employee to be promoted \n";
				break;
			case (char)'d':
				if (mask != 0)
				{
					cout << "Enter Employee Number of employee to be demoted :\n";
					cin >> check;
					db.demotion(check);
				}
				else
					cout << "No employee to be demoted \n";
				break;
			case (char)'c':
				if (mask != 0)
				{
					cout << "Details of current employees :\n";
					cout << "No. of current employees :" << i<<endl;
					for (int j = 0; j < i; j++)
					{
						if (empl[j].hireStatus == 1)
						{
							cout << "Name :\t" << empl[j].name << endl;
							cout << "Employee Number :\t" << empl[j].empNo << endl;
							cout << "Salary :\t" << empl[j].salary << endl;
						}
					}
				}
				else
					cout << "No current employees \n";
				break;
			case (char)'v':
				if (mask != 0)
				{
					cout << "Details of current employees :\n";
					for (int j = 0; j < i; j++)
					{
						if (empl[j].fireStatus == 1)
						{
							cout << "Name :\t" << empl[j].name << endl;
							cout << "Employee Number :\t" << empl[j].empNo << endl;
							cout << "Salary :\t" << empl[j].salary << endl;
						}
					}
				}
				else
					cout << "No fired employees \n";
				break;
			}
		else
			cout << "Press h or f \n";
		cout << "Press y if you want to repeat the process :\n";
		cin >> ch1;
	} while (ch1 == 121);
	return 0;
}
