#include <iostream>
#include <fstream>
#include <vector>
#include "player.h"
#include <string>

using namespace std;


int getNumLines();

bool file_reader(player* Data);

int main()
{
	
	const int numOfPlayer = getNumLines();

	player* Data = new player[numOfPlayer];

	Data[0] = new player("ben", 20, 30, -10);
		
	return 0;
}


bool file_reader(player* Data)
{
	


	return 1;
}

int getNumLines()
{
	ifstream inData;

	inData.open("GroupData.txt");

	int count = 0;
	string dc;
	while (!inData.eof())
	{
	
		count++;
		getline(inData, dc);

	}

	inData.close();

	return count;
}