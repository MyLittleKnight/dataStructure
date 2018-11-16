#include<iostream>
#include <fstream>
#include <string.h>
#include<bits/stdc++.h> 
#iclude "main.h"
using namespace std;


void vocab_list::add_char(char *c){
	vocab_node *tail = new vocab_node;
	tail->next = NULL;
	tail->list=NULL;
	//check head
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
