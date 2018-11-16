#include<iostream>
#include<string.h>
#define NAME_LENGTH 30
#define PHONENUM_LENGTH 15
using namespace std;


struct Phone_node
{
	char name[NAME_LENGTH];
	char phonenum[PHONENUM_LENGTH];
	Phone_node *next;
};

struct List
{
	//node başlangıç tanımladım 
	Phone_node *head;
	int nodeCount;
	void create();
	void close();
	void print_list();
	void insert(Phone_node *);
	void remove(int order);
	void makeEmpty();
	int search(char *);
	void update(int record_Num,Phone_node *);
};

void List::create(){
	head = NULL;
	nodeCount=0;
}

// Operations :
void List::print_list(){
	Phone_node *headRef = head;
	while(headRef){
		cout<<headRef->name<<" " << headRef->phonenum<<endl;
		headRef = headRef->next;
	}
}

void List::insert(Phone_node * add){
	Phone_node* headRef = head;

	if(head == NULL)
	{	
		headRef->next = NULL;
		head = add;
		head->next = headRef;
		nodeCount++;
		return;
	}else{
		add->next = headRef;
		head = add;
		nodeCount++;
	}
}

void List::update(int record_Num,Phone_node *newNode){
	Phone_node * headRef;
	int counter = 1;
	headRef = head;
	while(headRef && counter < record_Num){
		counter++;
		headRef = headRef->next;
	}
	if(headRef){
		newNode->next = headRef->next;
		*headRef = *newNode;
	}else
		cout<<"Invalid number."<<endl;
}

void List::remove(int order){
	Phone_node *headRef, *temp;
	int counter =1;
	headRef = head;

	if(head==NULL)
	{
		cout<<"Empty list"<<endl;
		return;
	}

	//delete operation
	if(order == 1)
	{
			head = head->next;
			delete headRef;
			nodeCount--;
	
	}else{
		while(headRef->next != NULL && order == counter)
		{
			headRef = headRef->next; 
			counter++;
		}
		if(counter<order)
		{
			cout<<"I cant find it bro"<<endl;
		}else{
			temp = headRef;
			headRef = headRef->next;
			delete temp;
			nodeCount--;
		}
	}
}

void List::makeEmpty(){
	Phone_node *headRef = head;
	while(head){
		headRef = head;
		head = head->next;
		delete headRef;
	}
	nodeCount = 0;
}

int List :: search(char *target){
	Phone_node *traverse;
	int counter =0 ;
	int found = 0;
	traverse = head;
	bool all = false;

	if(strcmp(target,"*") == 0)
		all=true;

	while(traverse){
		counter++;
		if(all){
			cout<<counter<<"."<<traverse->phonenum<<endl;
			found ++;
		}else if(strncasecmp(traverse->name,target,strlen(target)) == 0){
			found++;
			cout << counter << "." << traverse->name << " " << traverse->phonenum <<endl;
		}
		traverse = traverse->next;
	}
	return found;
}

int main(int argc, char const *argv[])
{
	bool chouce = true;
	List list;
	list.create();
	while(chouce){
		cout<<"Do you wanna add (1-0)"<<endl;
		cin>>chouce;
		if(chouce){
			Phone_node* newOne;
			newOne->next = NULL;
			cout<<"name:";cin>>newOne->name;
			cout<<"no  :";cin>>newOne->phonenum;
			list.insert(newOne);
		}
	}
	list.print_list();

	return 0;
}
