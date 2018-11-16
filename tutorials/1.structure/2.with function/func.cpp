#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//this part for C
struct Person
{
    string name;
    int age;
    float salary;
};


void print1(string name,int age, float sal);
// struct as a argumant
void print2(struct Person a);

//struct as a pointer
void print3(struct Person *);

// above defination fuc. change orginal structure but if we do not want to change
void print4(const struct Person *);

/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Now we will use c++
struct Employee{
	string name;
	int age;
	float salary;
	void printPlus();	
};

void Employee::printPlus() 
{
	cout << name << age << salary;
}
//////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Person one;
	Employee Eone = {"ali",34,3444};
	//give some variables
	one.name = "emn";
	one.age = 22;
	one.salary = 23423;

	//cout<< one.name << " is " << one.age << " years old" << endl;
	print1(one.name, one.age,one.salary);

	// variables can also define as
	Person two = {"mrt", 19,23.500};
	print2(two);
	
	//to make program more efficient we should use pointers 
	print3(&two);
	
	//for not permisson changes 
	print4(&one);
	
	//c++
	Eone.printPlus();
		
	return 0;
}

void print1(string name,int age, float sal)
{
	cout<< "print 1 "<< name << " is " << age << " years old" << endl;
}

void print2(struct Person a)
{
	cout<< "print 2 " << a.name << " is " << a.age << " years old" << endl;
}

void print3(struct Person *a)
{
	cout<< "print 2 " << a->name << " is " << a->age << " years old" << endl;
}

void print4(const struct Person *a)
{
	cout<< "print 2 " << a->name << " is " << a->age << " years old" << endl;
}

