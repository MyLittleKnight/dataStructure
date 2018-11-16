/* @Dilara TORUNOĞLU SELAMET
* Student Name: Muhammed Emin Topuz
* Student ID : 150150122
* Date: 8.11.2018 */

#include<iostream>
#include "main.h"
using namespace std;

int main(int argc, char* argv[]){
	language_model language; //define a struct language

	if (argc == 2){
		language.readData(argv[1]); // reading data
		language.vocabularylist->print(); // print
	}else{
		//printing probability
		language.readData(argv[1]); // reading data
		cout <<"Occurance of C(" <<argv[2][0]<<") : "<<language.vocabularylist->get_occurence(argv[2][0])<<endl;
		cout <<"Uninon Occurance C(" <<argv[2][0]<< "," <<argv[3][0] <<") : " 
			 <<language.vocabularylist->get_union_occurence(argv[2][0],argv[3][0])<< endl;
		cout <<"The probability is P(" <<argv[3][0]<< "|" <<argv[2][0] <<") : "
			 <<language.calculateProbability(argv[2][0], argv[3][0])<<endl; 
	}
	return 0;
}
