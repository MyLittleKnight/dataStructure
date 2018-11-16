#include <iostream>
#include <fstream>
using namespace std;

struct Action{
	char type;
	bool grid;
	bool Error = true;
	int loc[2];
	int size;
};

struct Move{
	string name;
	int center[2];
	int loc[2];
	int dist;
};

bool inBorder(int Px,int Py,int rows,int cols)
{
	if(Px  <rows && Py  < cols && Px  >= 0 && Py  >= 0)
		return true;
	else
		return false;
}

bool conf(int Px,int Py,char **arr)
{
	if(arr[Px][Py]!='*')
		return false;
	else 
		return true;
}

int littleChecking(int Px,int Py,char **arr,int rows,int cols,int lastError)
{
	int errorType;
	if(inBorder(Px,Py,rows,cols))
	{	
		if(conf(Px,Py,arr) && lastError == 0)
			{errorType= 0;}
		else if(!conf(Px,Py,arr))
			{errorType=1;}
	}else 
		errorType = 2;
	
	if(lastError == 1 && errorType == 2)
		errorType = 3;
	else if(lastError == 2 && errorType == 1)
		errorType = 3;
	
	return errorType;
}

int checking(Action *act,int rows,int cols,char **arr,bool grid)
{
	int Maxsize = act->size;
	int errorType=0;
	int centerR = act->loc[0]-1;
	int centerC = act->loc[1]-1;
	char type = act->type;
	
	
	if(type=='+')
		{
			//checking center pointx 6 6 1
			errorType = littleChecking(centerR,centerC,arr,rows,cols,errorType);
				
				int size = 1;
				while(size<=Maxsize && errorType!=3)
				{
					errorType=littleChecking(centerR + size,centerC,arr,rows,cols,errorType);
					if(errorType==3)
						break;
					errorType=littleChecking(centerR - size,centerC,arr,rows,cols,errorType);
					if(errorType==3)
						break;				
					errorType=littleChecking(centerR,centerC+size,arr,rows,cols,errorType);
					if(errorType==3)
						break;					
					errorType=littleChecking(centerR,centerC-size,arr,rows,cols,errorType);
					if(errorType==3)
						break;					
					size++;
				}
		}
		else if(type=='-')
		{
				errorType = littleChecking(centerR,centerC,arr,rows,cols,errorType);
				
				int size = 1;
				while(size<=Maxsize && errorType!=3)
				{
					errorType=littleChecking(centerR,centerC+size,arr,rows,cols,errorType);
					if(errorType==3)
						break;
					errorType=littleChecking(centerR ,centerC-size,arr,rows,cols,errorType);
					if(errorType==3)
						break;								
					size++;
				}
		}
		else if(type=='x')
		{
				errorType = littleChecking(centerR,centerC,arr,rows,cols,errorType);
				
				int size = 1;
				while(size<=Maxsize && errorType!=3)
				{
					errorType=littleChecking(centerR + size,centerC + size,arr,rows,cols,errorType);
					if(errorType==3)
						break;
					errorType=littleChecking(centerR - size,centerC + size,arr,rows,cols,errorType);
					if(errorType==3)
						break;				
					errorType=littleChecking(centerR + size,centerC-size,arr,rows,cols,errorType);
					if(errorType==3)
						break;					
					errorType=littleChecking(centerR - size,centerC-size,arr,rows,cols,errorType);
					if(errorType==3)
						break;					
					size++;
				}
		}
		else
		{
				errorType = littleChecking(centerR,centerC,arr,rows,cols,errorType);
				int size = 1;
				while(size<=Maxsize && errorType!=3)
				{
					errorType=littleChecking(centerR + size,centerC-size,arr,rows,cols,errorType);
					if(errorType==3)
						break;					
					errorType=littleChecking(centerR - size,centerC+size,arr,rows,cols,errorType);
					if(errorType==3)
						break;		
					size++;
				}
		}
	
	return errorType;
}

void putting(int centerR,int centerC,char **arr,char type,int Maxsize)
{
	
	if(type=='+')
		{

				arr[centerR][centerC]='+';
				int size = 1;
				while(size<=Maxsize)
				{
					arr[centerR+size][centerC] = '+';
					arr[centerR-size][centerC] = '+';
					arr[centerR][centerC+size] = '+';
					arr[centerR][centerC-size] = '+';
					size++;
				}
		}
		else if(type=='-')
		{
				arr[centerR][centerC]='-';
				int size = 1;
				while(size<=Maxsize)
				{
					arr[centerR][centerC+size] = '-';
					arr[centerR][centerC-size] = '-';
					size++;
				}
		}
		else if(type=='x')
		{
				arr[centerR][centerC]='x';
				int size = 1;
				while(size<=Maxsize)
				{
					arr[centerR+size][centerC+size] = 'x';
					arr[centerR-size][centerC+size] = 'x';
					arr[centerR+size][centerC-size] = 'x';
					arr[centerR-size][centerC-size] = 'x';
					size++;
				}
		}
		else
		{
				arr[centerR][centerC]='/';
				int size = 1;
				while(size<=Maxsize)
				{
					arr[centerR+size][centerC-size] = '/';
					arr[centerR-size][centerC+size] = '/';
					size++;
				}
		}
		
}

void del(int centerR,int centerC,char **arr,char type,int Maxsize)
{
	if(type=='+')
		{

				arr[centerR][centerC]='*';
				int size = 1;
				while(size<=Maxsize)
				{
					arr[centerR+size][centerC] = '*';
					arr[centerR-size][centerC] = '*';
					arr[centerR][centerC+size] = '*';
					arr[centerR][centerC-size] = '*';
					size++;
				}
		}
		else if(type=='-')
		{
				arr[centerR][centerC]='*';
				int size = 1;
				while(size<=Maxsize)
				{
					arr[centerR][centerC+size] = '*';
					arr[centerR][centerC-size] = '*';
					size++;
				}
		}
		else if(type=='x')
		{
				arr[centerR][centerC]='*';
				int size = 1;
				while(size<=Maxsize)
				{
					arr[centerR+size][centerC+size] = '*';
					arr[centerR-size][centerC+size] = '*';
					arr[centerR+size][centerC-size] = '*';
					arr[centerR-size][centerC-size] = '*';
					size++;
				}
		}
		else
		{
				arr[centerR][centerC]='*';
				int size = 1;
				while(size<=Maxsize)
				{
					arr[centerR+size][centerC-size] = '*';
					arr[centerR-size][centerC+size] = '*';
					size++;
				}
		}
		
}


void move(Action *act,Move *move,int row,int column,char **arr)
{
	int dist = move->dist;
	int check =0;
	int wantedPoints[2];
	int oldPoints[2];
	oldPoints[0] = act->loc[0];
	oldPoints[1] = act->loc[1];	
	wantedPoints[0] = move->center[0];
	wantedPoints[1] = move->center[1];

	if(move->name == "MVD")
	{
		del(act->loc[0]-1,act->loc[1]-1,arr,act->type,act->size);
		act->loc[0]+=dist;
		wantedPoints[0] +=dist;
		check = checking(act,row,column,arr,false);
		if(check==0)
			putting(act->loc[0]-1,act->loc[1]-1,arr,act->type,act->size);
		else
			putting(oldPoints[0]-1,oldPoints[1]-1,arr,act->type,act->size);
		
	}else if(move->name == "MVU"){
		del(act->loc[0]-1,act->loc[1]-1,arr,act->type,act->size);
		act->loc[0]-=dist;
		wantedPoints[0] -=dist;
		check = checking(act,row,column,arr,false);
		if(check==0)
			putting(act->loc[0]-1,act->loc[1]-1,arr,act->type,act->size);
		else
			putting(oldPoints[0]-1,oldPoints[1]-1,arr,act->type,act->size);
			
	}else if(move->name == "MVR"){
		del(act->loc[0]-1,act->loc[1]-1,arr,act->type,act->size);
		act->loc[1]+=dist;
		wantedPoints[1] +=dist;
		check = checking(act,row,column,arr,false);
		if(check==0)
			putting(act->loc[0]-1,act->loc[1]-1,arr,act->type,act->size);
		else
			putting(oldPoints[0]-1,oldPoints[1]-1,arr,act->type,act->size);
			
	}else if(move->name == "MVL"){
		del(act->loc[0]-1,act->loc[1]-1,arr,act->type,act->size);
		act->loc[1]-=dist;
		wantedPoints[1] -=dist;
		check = checking(act,row,column,arr,false);
		if(check==0)
			putting(act->loc[0]-1,act->loc[1]-1,arr,act->type,act->size);
		else
			putting(oldPoints[0]-1,oldPoints[1]-1,arr,act->type,act->size);
	}
	
	//print result
	if(check == 3)
	{
		cout<<"BORDER ERROR: "<<act->type<<" can not be moved from ("<<oldPoints[0]<<","<<oldPoints[1] <<") to (" << wantedPoints[0]<<","<<wantedPoints[1]<<")."<<endl;
		cout<<"CONFLICT ERROR: type can not be moved from ("<<oldPoints[0]<<","<<act->loc[1] <<") to ("<<wantedPoints[0]<<","<<wantedPoints[1]<<")."<<endl;
	}
	else if(check==2)
	{
		cout<<"BORDER ERROR: "<<act->type<<" can not be moved from ("<<oldPoints[0]<<","<<oldPoints[1]<<") to ("<<wantedPoints[0]<<","<<wantedPoints[1]<<")."<<endl;
	}else if(check==1)
	{
		cout<<"CONFLICT ERROR: "<<act->type<<" can not be moved from ("<<oldPoints[0]<<","<<oldPoints[1] <<") to ("<<wantedPoints[0]<<","<<wantedPoints[1]<<")."<<endl;	
	}else
	{
		cout<<"SUCCESS: "<<act->type<<" moved from ("<<oldPoints[0]<<","<<oldPoints[1] <<") to ("<<wantedPoints[0]<<","<<wantedPoints[1]<<")."<<endl;
	}
	
}

int main(int argc, char * argv[])
{
	string s;
	int sTotal=0;
	int row,column;
	int i=0;
	int errorType = 0;
	
	ifstream in;
	in.open(argv[1]);

	while(!in.eof()) {
		getline(in, s);
		sTotal ++;	
	}
	in.close();	
	
	in.open(argv[1]);
	Action action[sTotal-2];
	
	in>>row>>column;
	char** arr = new char*[row];
	for (int i = 0; i < row; i++)
    { arr[i] = new char[column]; }
    
	cout<<"A grid is created:"<<row<<" "<<column<<endl;
		
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
			{
				arr[i][j]='*';
			}
	}
	
	while(i<sTotal-2)
	{
		in>>action[i].type>>action[i].loc[0]>>action[i].loc[1]>>action[i].size;
		i++;
	}
	
	//put action on array.
	for(int i=0;i<sTotal-2;i++)
	{
		errorType = checking(&action[i],row,column,arr,true);
		if(errorType == 3)
		{
			cout<<"BORDER ERROR: Operator "<<action[i].type<<" with "<<action[i].size<<" size can not be placed on ("
				<<action[i].loc[0]<<","<<action[i].loc[1]<<")."<<endl;
			cout<<"/CONFLICT ERROR: Operator "<<action[i].type<<" with "<<action[i].size<<" size can not be placed on ("
				<<action[i].loc[0]<<","<<action[i].loc[1]<<")."<<endl;
		}
		else if(errorType==2)
		{
			cout<<"BORDER ERROR: Operator "<<action[i].type<<" with "<<action[i].size<<" size can not be placed on ("
				<<action[i].loc[0]<<","<<action[i].loc[1]<<")."<<endl;
		}else if(errorType==1)
		{
			cout<<"/CONFLICT ERROR: Operator "<<action[i].type<<"with "<<action[i].size<<" size can not be placed on ("
				<<action[i].loc[0]<<","<<action[i].loc[1]<<")."<<endl;	
		}else
		{
			cout<<"SUCCESS: Operator "<<action[i].type<<" with "<<action[i].size<<" size is placed on ("
				<<action[i].loc[0]<<","<<action[i].loc[1]<<")."<<endl;
			action[i].Error = false;
		}
		if(!action[i].Error)
			putting(action[i].loc[0]-1,action[i].loc[1]-1,arr,action[i].type,action[i].size);
	}
	
	in.close();

	in.open(argv[2]);
	int insTotal =0 ;
	while(!in.eof()) {
		getline(in, s);
		insTotal ++;	
	}
	in.close();	
	
	Move a[insTotal-1];
	in.open(argv[2]);
	i=0;
	while(i<insTotal-1)
	{
		in>>a[i].name>>a[i].loc[0]>>a[i].loc[1]>>a[i].dist;
		i++;
	}
	in.close();	
	
	//find center of given
	char** tempArr = new char*[row];
	for (int i = 0; i < row; i++)
    {tempArr[i] = new char[column]; }
		
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
			{
				tempArr[i][j]='*';
			}
	}
	
	//Todo finding center points in instructions file.
	//loop in intructions
	for(int i=0;i<insTotal-1;i++)
	{
		//search in grids
		for(int j=0;j<sTotal-2;j++)
		{
			if(action[j].Error == false)
			{
				putting(action[j].loc[0]-1,action[j].loc[1]-1,tempArr,action[j].type,action[j].size);
				//check temp array		
				if(tempArr[a[i].loc[0]-1][a[i].loc[1]-1] != '*')
				{
					a[i].center[0] = action[j].loc[0];
					a[i].center[1] = action[j].loc[1];
					move(&action[j],&a[i],row,column,arr);
					break; 
				}
				del(action[j].loc[0]-1,action[j].loc[1]-1,tempArr,action[j].type,action[j].size);
			}
		}
	}
	
	return 0;
}
