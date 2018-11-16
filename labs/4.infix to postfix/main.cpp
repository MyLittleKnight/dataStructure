#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

#define SIZE 10

struct Stack{
	char arr[SIZE];
	int top;
	void create();
	void push(char);
	char pop();
	bool prvt(char,char);
};

void Stack::create(){
	top =0;
};

void Stack::push(char c){
	if(top == SIZE){
		cout<<"TOP FULL";
		return;
	}
	arr[top++] = c;
	cout<<"top:"<<top<<endl;
};

char Stack::pop(){
	cout<<"befr pop: "<<top<<"in arr"<<arr[top-1]<<endl;
	return arr[--top];
};

bool Stack::prvt(char in,char out){
	cout<<"\nprvt: in: "<<in<<"out: "<<out<<endl;
	if(in == '*' || in == '/'){
		if(out == '-' || out == '+')
			return true;
	}
	return false;
};

bool isOperator(char c){
	if(c == '*' || c == '+' || c == '/' || c == '-')
		return true;
	else
		return false;
}

int main(){
	Stack stack;
	stack.create();
	string a;
	ifstream myfile("equation.txt");
	
	string charcontent((istreambuf_iterator<char>(myfile)),istreambuf_iterator<char>());
	int n = charcontent.length();
	char *content = new char[n+1];
	strcpy(content,charcontent.c_str());
	myfile.close();

	
	char *postfix = new char[n+1];
	cout<<"cont: "<<content<<endl;
	int num =0;
	int i=0;
	while(content[i]!='\0'){
		if(isOperator(content[i]) ){
			cout<<"operand";
			if(stack.top){//check empty
				cout<<"not empty top"<<stack.top-1<<"arr:"<<stack.arr[0]<<endl;
				if(stack.prvt(stack.arr[stack.top-1],content[i])){
					//if true fill postfix
					while(stack.top>0){
						postfix[num++] = stack.pop();
					}stack.push(content[i]);
				}else //fill add to stack
					{stack.push(content[i]);cout<<"elel"<<stack.arr<<endl;}
			}else//fill add to stack
					{stack.push(content[i]);cout<<"empty:"<<stack.arr<<endl;}
		
		}else{
			postfix[num++]=content[i];cout<<num<<"if"<<postfix[num-1]<<endl;
		}
		cout<<"num: "<<num<<"n+1"<<n+1<<"i: "<<i<<endl;
		i++;
	}
	num--;
	if(strlen(postfix) < strlen(content)){
		while(stack.top>0){
			postfix[num++] = stack.pop();
			cout<<"after: "<<postfix[num]<<"num"<<num;
		}
	}
	
	cout<<"\nresult: "<<postfix<<endl;
	
	return 0;
}
