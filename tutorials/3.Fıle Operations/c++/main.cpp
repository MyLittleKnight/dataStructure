#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	char data[100];
	
	ofstream outfile;
	outfile.open("file.txt");
	
	cout << "Writing to the file." << endl;
	cout <<"Enter name: ";
	cin.getline(data,100);
	
	//we just using << for write on file.
	outfile << data << endl;
	
	//write with cin>>
	cout << "Enter your age: ";
    cin >> data;
    cin.ignore();
    outfile << data << endl;
	cout << "fin "<< endl;
	
	// again write inputted data into the file.
    outfile << data << endl;
    
   // close the opened file.
   outfile.close();

   // open a file in read mode.
   ifstream infile; 
   
   infile.open("file.txt");
   
   infile >> data;
   cout<<"result :" << data;
   infile.close();
   
   
   
   
	return 0;
}
