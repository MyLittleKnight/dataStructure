#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
	char a[10]="naber";
	//int size=0;
	char *c = &a[2];
	cout<<*c;	
		
	return 0;
}

