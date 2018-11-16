#include <string.h>
#include<iostream>

using namespace std;

//sorting elements corresponding to ascii table
void sorting(char *order,char *word)
{
	int sizeofword = strlen(word);
	//bool arr represent to ascii decimal numbers
	bool arr[128]={};
	for (int i=0;i<sizeofword;i++)
	{
		int decimal;
		if(word[i]<91 && word[i]>64)
		{
			decimal = word[i] + ('a' - 'A');
		}else if(word[i]>31){
			decimal = word[i];
		}
		if(!arr[decimal])
			arr[decimal]=true;
	}
	
	//converting bool array to char array
	int j=0;
	for(int i=65;i<128;i++)
	{
		if(arr[i])
		{
			order[j]=i;
			j++;
		}
	}
	for(int i=33;i<65;i++)
	{
		if(arr[i])
		{
			order[j]=i;
			j++;
		}
	}
	if(arr[32])
		order[j] = 32;
}
