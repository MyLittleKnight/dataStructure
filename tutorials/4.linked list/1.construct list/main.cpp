#include<iostream>
using namespace std;

//defining a single node for linkid list
struct node
{
	int data;
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
	
	printList(head);
	
	return 0;
}
