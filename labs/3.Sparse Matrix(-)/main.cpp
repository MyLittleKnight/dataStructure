#include<iostream>

using namespace std;

struct node{
	int value,row,col;
	node *next;
};

struct LinkedList{
	int Mof_r,Mof_c;
	node *head;
	void create();
	void add(int,int,int);
	void print();
};

void LinkedList::create(){
	head = NULL;
	cout<<"Please enter row and column"<<endl;
	cin>>Mof_r>>Mof_c;
}

void LinkedList::add(int r,int c,int v){
	node *ptr = new node;
	node *temp = head;
	ptr->row = r;
	ptr->col = c;
	ptr->value = v;
	//3 option 1 head 2 before head 3 after head
	if(head == NULL){
		head=ptr;
		ptr->next =NULL;
		cout<<"ok";
	}else{//before head
		if(head->row >= ptr->row && ptr->col < head->col){
			if(ptr->col < head->col){
			ptr->next = head;
			head = ptr;}
		}else{
			while(temp->next && temp->row <= ptr->row){
				if(temp->col <ptr->col)
				temp=temp->next;
			}
			
			ptr->next = temp->next;
			temp->next = ptr;
		}
	}
	temp = head;
	while(temp){
	cout<<temp->row<<" "<<temp->col<<" "<<temp->value<<endl;
	temp = temp->next; 
	}
}

void LinkedList::print(){
	node *temp = head;
	cout<<"in print: "<<endl;
	int t = 0;
	int k = 0;
	do{
		for(int i=t;i<temp->row;i++){
			for(int j=k;k<temp->col;j++){
				if(temp->col > j && temp->row > i)
					cout<<"0 ";
				if(j>0 && j%Mof_c == 0)
					cout<<endl;
			}
		}
			cout<<temp->value<<" ";
			t = temp->row;
			k = temp->col;
			if(temp->col == Mof_r)
				cout<<endl;
			temp = temp->next;
	}while(temp->next);
	
	for(int i=t;i<temp->row;i++){
		for(int j=k;k<temp->col;j++){
			if(temp->col > j && temp->row > i)
				cout<<"0 ";
			if(j>0 && j==Mof_c)
				cout<<endl;
			}
		}
}


int main(){
	LinkedList list;
	list.create();
	bool flag=1;
	while(flag){
		int r,c,v;
		cout<<"r c v :";
		cin>>r>>c>>v;
		list.add(r,c,v);
		cout<<"do you want to give another input:";
		cin>>flag;
	}
	list.print();
	return 0;
}
