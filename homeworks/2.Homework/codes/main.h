#include<iostream>
#include <fstream>
#include <string.h>
#include<bits/stdc++.h> 
#include "sorting.cpp"
using namespace std;

//defining structures
struct occur_node {
	char character;
	occur_node *next;
	int occurence;
};

struct vocab_node {
	char character;
	vocab_node *next;
	occur_node *list;
};

struct vocab_list{
	vocab_node *head;
	int x = 2;
	void create();
	void print();
	void add_char(char *);
	void add_occurence(char *, char *);
	int get_occurence(char);
	int get_union_occurence (char , char );
};

struct language_model {
	vocab_list *vocabularylist;
	void readData (const char *);
	double calculateProbability (char, char);
};

void vocab_list::create(){
	head = NULL;
}

void vocab_list::add_char(char *c){
	vocab_node *tail = new vocab_node;
	tail->next = NULL;
	tail->list=NULL;
	//check head and if empty fill it
	if(head==NULL){
		head = new vocab_node;
		head->character = *c;
		head->next = NULL;
		head->list = NULL;
	}
	else{
		vocab_node *headRef = head;
		while(headRef->next)
			headRef = headRef->next;
		headRef->next = tail;
		tail->character = *c;
	}
	
}

void vocab_list::add_occurence(char *before,char *after){
	vocab_node *headRef = new vocab_node;
	headRef = head;
	occur_node *refNode = new occur_node;

	do
	{
		if(headRef->character == *before)
			break;
		headRef = headRef->next;
	}while (headRef->next != NULL); 
	
	//checking and adding
	if(headRef->list == NULL){
		refNode->character  = *after;
		refNode->next = NULL;
		refNode->occurence = 1;
		headRef->list = refNode;
	}else{
		refNode = headRef->list;
		while(refNode->character != *after && refNode->next != NULL){
		refNode = refNode->next;
		}

		if (refNode->character == *after)
			refNode->occurence++;
		else{
			occur_node *newNode = new occur_node;
			refNode->next = newNode;
			newNode->character = *after;
			newNode ->occurence =1;
			newNode->next = NULL;
		}
	}
}

int vocab_list::get_occurence(char x){
	vocab_node *headRef = new vocab_node;
	headRef = head;
	do
	{
		if(headRef->character == x)
			break;
			
		headRef = headRef->next;
	}while (headRef->next != NULL);
	
	occur_node *refNode = new occur_node;
	refNode = headRef->list;
	int total = 0;
	while(refNode->next !=NULL)
	{
		total += refNode->occurence;
		refNode = refNode->next;
	}
	total += refNode -> occurence; 
	return total;
}

int vocab_list::get_union_occurence (char x, char y){
	vocab_node *headRef = new vocab_node;
	headRef = head;
	do
	{
		if(headRef->character == x)
			break;
			
		headRef = headRef->next;
	}while (headRef->next != NULL);
	
	occur_node *refNode = new occur_node;
	refNode = headRef->list;
	
	int occur = 0;
	while(refNode->next !=NULL)
	{
		if(refNode->character == y)
			{occur=refNode->occurence;break;}
		refNode = refNode->next;
	}
	
	return occur;
}

double language_model::calculateProbability(char x,char y){
	return vocabularylist->get_union_occurence(x,y)*1.0/vocabularylist->get_occurence(y);
}

void vocab_list::print(){
	vocab_node *headRef = head;
	occur_node *refNode;
	//checking space and print it as requested
	while(headRef){
		if(headRef->character != ' ')
			cout<<headRef->character<<":"<<endl;
		else
			cout<<"<SP>"<<":"<<endl;
		refNode = headRef->list;
		while(refNode){
			if(refNode->character != ' ')
				cout<<"\t<"<<refNode->character<<","<<refNode->occurence<<">"<<endl;
			else
				cout<<"\t<"<<"<SP>"<<","<<refNode->occurence<<">"<<endl;
				
			refNode = refNode->next;
		}
		headRef=headRef->next;
	}
}

void language_model::readData(const char *file){
	//read data
	ifstream in(file);
	string contents((istreambuf_iterator<char>(in)),istreambuf_iterator<char>());
	int n = contents.length();
	char charContent[n+1];
	strcpy(charContent,contents.c_str());
	in.close();

	//sort them by order
	char order[50] = {};
	sorting(order,charContent);
	vocabularylist = new vocab_list;
	
	//convert ordered list linklid list;
	vocabularylist->create();
	int sizeof_ord = strlen(order);
	for(int i=0;i<sizeof_ord;i++){
		vocabularylist->add_char(&order[i]);
	}
	
	int sizeOfContent = strlen(charContent)-1;
	for(int i=0;i<sizeOfContent;i++)
		{
			if((charContent[i+1] >31 && charContent[i+1] <127) && (charContent[i] >31 && charContent[i] <127))
				vocabularylist->add_occurence(&charContent[i],&charContent[i+1]);
		}	
}
