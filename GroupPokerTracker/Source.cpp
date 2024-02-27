#include <iostream>
#include <fstream>
#include <vector>
#include "player.h"
#include <string>

using namespace std;

template<class T>
T get(std::istream& is) {
	T result;
	is >> result;
	return result;
}


int getNumLines();

void print_Data(player* Data, int num);

bool file_reader(player* Data);

void print_menu();

bool add_player(player* Data, int num);

int main()
{
	
	int numOfPlayer = getNumLines();

	player* Data = new player[numOfPlayer];
	
	int select;
	bool e = 1;

	if(!file_reader(Data))
	{
		cout << "No Data File Detected\nBefore Exiting Program select save to new file";
	}

	while (e == 1)
	{
		cout << "Welcome To Poker Balance Tracker\n\n";
		print_menu();
		cout << "\n\n";
		print_Data(Data, numOfPlayer);
		cin >> select;
		switch (select)
		{
		case 1:
			
			add_player(Data, numOfPlayer);
			numOfPlayer++;
			break;

		case 2:

			break;

		case 3:

			break;

		case 4:

			break;

		case 0:
			e = 0;
			break;

		default:

			cout << "\nINVALID SELECTION\nTry again.";
			
		}
	}
	
	return 0;
}


bool file_reader(player* Data)
{
	ifstream inData;

	inData.open("GroupData.txt");

	if (inData.fail())
	{
		return 0;
	}

	string temp;
	int count = 0;
	double temp2;

	

	while (!inData.eof())
	{
		player temp_p;
		inData >> temp;
		temp_p.set_Name(temp);
		
		inData >> temp2;

		temp_p.set_BuyIn(temp2);

		inData >> temp2;

		temp_p.set_EndHolding(temp2);

		inData >> temp2;

		temp_p.set_Balance();

		Data[count] = temp_p;
		
		count++;
	}


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

void print_menu()
{
	cout << "Make a Selection"
		<< "\n1: Add a Player"
		<< "\n2: Edit a Player"
		<< "\n3: Delete a Player"
		<< "\n4: Clear Data"
		<< "\n0: Exit Program\n\n";
}

bool add_player(player* Data,int num)
{
	player temp;

	cout << "Enter Player's Name\n";

	temp.set_Name(get<string>(cin));

	cout << "\nEnter Player's Buy In\n";

	temp.set_BuyIn(get<double>(cin));

	cout << "\nEnter Player's End Holdings\n";

	temp.set_EndHolding(get<double>(cin));

	temp.set_Balance();

	player* newData = new player[num];

	for (int i = 0; i < num; i++)
	{
		newData[i] = Data[i];
	}
	
	Data = new player[num + 1];

	for (int i = 0; i <= num; i++)
	{
		Data[i] = newData[i];
	}

	Data[num] = temp;

	delete newData;


	

	return 1;
}

void print_Data(player* Data, int num)
{
	for (int i = 0; i < num; i++)
	{
		Data[i].print_Player();
		cout << "\n";
	}
}