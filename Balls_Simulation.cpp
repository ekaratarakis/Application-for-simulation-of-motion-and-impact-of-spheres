#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <iostream>
#include <limits>
#include <cstdlib>
#define TRACK_LENGTH 60

using namespace std;

int main()
{
	int debugflag = 0;
	int NUM_BALLS=0;
	//int m;
	srand(time(NULL));
	char track[TRACK_LENGTH+1];
	// inserting empty slots into the stack
	for(int m = 1; m<TRACK_LENGTH+1; ++m)
	{
		track[m]='-';
	}
	cout<<"\nPlease enter the number of balls (1-40): ";
	cin>>NUM_BALLS;
	if(NUM_BALLS<1 || NUM_BALLS>60)
	{
		system("PAUSE");
	}
	
	int position[NUM_BALLS];
	int table[60];
	for(int m = 0; m < 60; ++m)
	{
		table[m] = m;
	}
	for(int m = 0; m < 60; ++m)
	{
		int j = m + rand() % (60 - m);
		int tab = table[m];
		table[m] = table[j];
		table[j] = tab;
	}
	for(int m = 0; m < NUM_BALLS; m++)
	{
		position[m] = table[m];
	}
	int i, go, get;
	for(go = 1; go <= (NUM_BALLS-1); ++go)
	{
		for(i = 0; i <= (NUM_BALLS-2); i++)
		{
			if(position[i] > position[i + 1])
			{
				get = position[i];
				position[i] = position[i + 1];
				position[i + 1] = get;
			}
		}
	}
	
	int direction[NUM_BALLS];
	direction[0]=1; // direction of the 1st ball
	direction[NUM_BALLS-1]=-1; // direction of the last ball
	
	int way;
	for(int m=1;m<NUM_BALLS-1;++m)
	{
		way=rand()%2;
		if(way <1) // the choices of the balls between the 1st and the last are random
		{
			direction[m] = -1;
		}
		else
		{
			direction[m] = 1;
		}
	}
	for(int m=0;m<NUM_BALLS;++m)
	{
		if(direction[m]==1 && position[m]<70)
		{
			track[position[m]+1]='>';
		}
		else
		{
			track[position[m]+1]='<';
		}
	}
	// printing the slots and the directions
	cout<<"\nThe positions of the balls together with their directions can be seen below\n";
	for(int m = 1; m<TRACK_LENGTH+1; m++)
	{
		cout<<track[m];
	}
	system("PAUSE");
	
	int timer = 0;
	int sum=0,m2;
	for(int ts = 0; ts<NUM_BALLS; ++ts)
	{
		sum += position[ts];
	}
	while(sum != NUM_BALLS*70) // strikes' durations
	{
		for(int m1 = 0; m1<NUM_BALLS; ++m1)
		{
			if(position[m1] !=70) // for balls that are not out of the limits
			{
				if(((position[m1]+direction[m1]) == position[m1+1])&&(direction[m1]==1 && direction[m1+1]==-1))
				{
					position[m1] = position[m1]-1;
					position[m1+1] = position[m1+1]+1;
					direction[m1]=-direction[m1];
					direction[m1+1] = -direction[m1+1];
					m1++;
				} // for balls that have distance of 1 before they strike
				else if(((position[m1]+direction[m1]) == (position[m1+1]+direction[m1+1])) && (direction[m1+1]==-direction[m1]))
				{
					direction[m1]=-direction[m1];
					direction[m1+1] = -direction[m1+1];
					m1=m1+1;
				} // balls that are just moving per direction
				else
				{
					if(position[m1]==0 && timer>1)
					{
						position[m1] = 70;
						m2 = m1+1;
						cout<<m1<<"< ["<<timer<<"]\n";
					}
					else if(position[m1]==59 && timer>1)
					{
						position[m1] = 70;
						m2 = m1+1;
						cout<<">"<<m1<<" ["<<timer<<"]\n";
					}
					else
					{
						position[m1] = position[m1]+direction[m1];
					}
				}
			}
		}
		for(int m = 0; m<TRACK_LENGTH; ++m) // inserting empty slots again into the stack since we are going to use it again 
		{
			track[m]='-';
		}
		for(int m2=0; m2<NUM_BALLS; ++m2)
		{
			if(direction[m2]==1 && position[m2]!=70)
			{
				track[position[m2]]='>';	
			}
			else
			{
				track[position[m2]]='<';
			}
		}
		for(int m = 0; m<TRACK_LENGTH; ++m)
		{
			cout<<track[m];
		}
		cout<<"\n";
		timer++;
		sum = 0;
		for(int ts=0;ts<NUM_BALLS;ts++) // summing the positions of the balls
		{
			sum = sum + position[ts];
		}
	}
	system("PAUSE");
	return 0;	
}
