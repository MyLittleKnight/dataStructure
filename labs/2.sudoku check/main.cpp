#include <iostream>
#include <fstream>

using namespace std;

struct matrix{
	int sudoku[9][9];
	bool numCheck[10];
	bool sudokuChecker();
	void reset();
};

bool matrix::sudokuChecker(){
	//checking boxes
	int total = 0;
	for(int j=0;j<3;j++){
		for(int l=0;l<3;l++){
			for(int i=0;i<3;i++){
				for(int k=0;k<3;k++){
					if(sudoku[i][j]<10){
						if(!numCheck[sudoku[i+j*3][k+l*3]]){
							numCheck[sudoku[i+j*3][k+l*3]] = true;
							total +=sudoku[i+j*3][k+l*3];
						}else
							return false;
					}else
							return false;
				}
			}
			if(total != 45)
				return false;
			total = 0;
			reset();
		}
	}
	//checking rows
	total = 0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(sudoku[i][j]<10){
				if(!numCheck[sudoku[i][j]]){
					numCheck[sudoku[i][j]] = true;
					total +=sudoku[i][j];
				}else
					return false;
			}else
					return false;
		}
		if(total != 45)
			return false;
		total = 0;
		reset();
	}
	//checking columns
	total = 0;
	for(int j=0;j<9;j++){
		for(int i=0;i<9;i++){
			if(sudoku[i][j]<10){
				if(!numCheck[sudoku[i][j]]){
					numCheck[sudoku[i][j]] = true;
					total +=sudoku[i][j];
				}else
					return false;
			}else
					return false;
		}
		if(total != 45)
			return false;
		total = 0;
		reset();
	}

	return true;
};

void matrix::reset(){
	for(int i=0;i<10;i++){
		numCheck[i] = false;
	}
}

int main(int argc, char * argv[]) 
{
	matrix m;
	ifstream in("sudoku2.txt");
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			in >> m.sudoku[i][j];
		}
	}
	cout << m.sudokuChecker();
	in.close();
	
	return 0;

}
