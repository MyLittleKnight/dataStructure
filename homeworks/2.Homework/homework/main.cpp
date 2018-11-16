#include<iostream>
#include <fstream>
#include <string.h>
#include<bits/stdc++.h> 
#include "/home/limon/workPlace/ITU lessons/data Str/homeworks/2.Homework/codes/sorting.cpp"
#include<locale.h> 
using namespace std;

int main()
{
	
	setlocale(LC_ALL, "Turkish"); 
	string file = "turkish-input (1).txt";
	
	ifstream in(file);
	string contents((istreambuf_iterator<char>(in)),istreambuf_iterator<char>());
	int n = contents.length();
	char charContent[n+1];
	strcpy(charContent,contents.c_str());
	in.close();
	
	cout<<"text :\n"<<charContent<<endl;

	/*char order[50] = {};
	sorting(order,charContent);
	cout<<"text :\n"<<charContent<<endl;
	cout<<"\norder: "<<order<<"end."<<endl;
	*/
	
	return 0;
}
