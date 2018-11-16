#include<iostream>
using namespace std;

//defining a single node for linkid list
struct node
{
	float data;
	//we define a pointer which hold the next sturuct place
	node *next;
};

void printList(struct node *n)
{
	while(n!=NULL)
	{
		cout<<n->data<<endl;
		n = n->next;
	}
}

//adding new variable front of list
void push(struct node **headRef,float data)
{
	//declare new node
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	//add data to new node
	newNode->data = data;

	//make next old head
	newNode->next = (*headRef);

	//make newNode head node
	*headRef = newNode;
}

void insertAfter(struct node* prev,float data)
{
	//check prev node last node or not
	if(prev == NULL)
	{
		cout<<"Please use append for this node."<<endl;
		return;
	}
	//declare new
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	//add data
	newNode->data = data;

	//point new node next to prev next
	newNode->next = prev->next;

	//point prev to new node
	prev->next = newNode;
}

void append(struct node **headRef,float data)
{
	//define new node and last node
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	struct node *last = *headRef;

	//add data and make pointer null
	newNode->data = data;
	newNode->next = NULL;

	//appand the node
	if (*headRef == NULL)
	{
		//if list is empty
		*headRef = newNode;
	}else{
		//if I do this last != NUll then I will get segment fault
		while(last->next != NULL)
			last = last->next;
		last->next = newNode;
	}
	

}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	//we define three node with 1 size
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	
	//they are struct so they are hold their places like array
	head->next = second;
	second->next = third;
	third->next = NULL;

	// assign value to nodes
	head->data = 11;
	second->data = 12;
	third->data = 13;
	
	cout<<"After declarations: "<<endl;
	printList(head);
	
	push(&head,10);
	cout<<"After Push function: "<<endl;
	printList(head);
	
	insertAfter(second,12.5);
	cout<<"After insertAfter function: "<<endl;
	printList(head);
	
	append(&head,14);
	cout<<"After append function: "<<endl;
	printList(head);

	return 0;
}
