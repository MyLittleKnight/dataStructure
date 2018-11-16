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
		head->next = NULL;
		count++;
		return;
	}

	//before head
	if(head->value > v){
		
		newNode->next = head;
		head = newNode;
		count++;
		return;
	}
	
	
	//after head
	node *tail;
	while(headRef->next && headRef->value < newNode->value){
		if(headRef->value > newNode->value)
			break;
		tail = headRef;	
		headRef = headRef->next;
		cout<<"in while: "<<headRef->value<<endl;
	}
	if(headRef -> next == NULL && headRef->valus < newNode->value){
		headRef->next = newNode;
		newNode->next = NULL;
		count++;
	}else{
		tail->next=newNode;
		newNode->next=headRef;
		count++;
	}
	
	
}

void list::print(){
	node *headRef = head;
	while(headRef->next){
		cout<<headRef->value<<" ";
		headRef = headRef->next;
	}cout<<headRef->value;
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
