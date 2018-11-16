#include <iostream>
using namespace std;

struct node{
	int value;
	node *next;
};

struct list{
	node *head;
	int count;
	void create();
	void insert(int);
	void print();
};

void list::create(){
	head = NULL;
	count=0;
}

void list::insert(int v){
	node *newNode = new node;
	node *headRef = head;
	newNode->value = v;
	//without head
	if(head == NULL){
		head = newNode;
		head->next = head;
		count++;
		return;
	}
	
	//before head
	if(newNode->value < head->value)
	{
		while(headRef->next != head){
			headRef = headRef->next;
		}
		newNode->next = head;
		headRef->next = newNode;
		head = newNode;
		return;
	}
	
	//after head
	node *tail;
	while(headRef->next != head && headRef->value < newNode->value){
		tail = headRef;
		headRef = headRef->next;
		cout<<"in while: "<<headRef->value<<endl;
	}if(headRef->next == head && headRef->value < newNode->value){
		headRef->next = newNode;
		newNode->next = head;
		count++;
	}else{
		tail->next = newNode;
		newNode->next = headRef;
	}
	
}

void list::print(){
	node *headRef = head;
	do{
		cout<<headRef->value<<" ";
		headRef = headRef->next;
	}while(head != headRef);
}


int main(){
	int flag=1;
	int val;
	list l;
	l.create();
	cout<<"Give some values"<<endl;
	while(flag){
		cin>>val;
		l.insert(val);
		l.print();
		cout<<"\nadd one more time? ";
		cin>>flag;
	}
	return 0;
}
