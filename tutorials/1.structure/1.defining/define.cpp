#include <iostream>
using namespace std;

struct Person
{
    string name;
    int age;
    float salary;
};

int main()
{
    Person one;
	
	//give some variables
	one.name = "emn";
	one.age = 22;
	one.salary = 23423;
	
	cout<< one.name << " is " << one.age << " years old" << endl;
	
	return 0;
}
