#include <iostream>
#include <fstream>
#include <vector>
#include "player.h"
#include <string>
#include <stdlib.h>

using namespace std;




int getNumLines();

void print_Data(player* Data, int num);

bool file_reader(player* Data);

void print_menu();

bool add_player(player* Data, int num);

bool edit_player(player* Data, int num);

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
			edit_player(Data, numOfPlayer);
			break;

		case 3:

			break;

		case 4:
			
			Data = 0;
			numOfPlayer = 0;
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

bool add_player(player* Data, int num)
{



	player temp;
	string temp2 = "";
	double temp3;

	cout << "Enter Player's Name\n";

	cin >> temp2;
	temp.set_Name(temp2);

	cout << "\nEnter Player's Buy In\n";

	cin >> temp3;
	temp.set_BuyIn(temp3);

	cout << "\nEnter Player's End Holdings\n";

	cin >> temp3;
	temp.set_EndHolding(temp3);

	temp.set_Balance();

	if (Data == 0)
	{
		//todo

	}

	player* newData = new player[num];

	for (int i = 0; i < num; i++)
	{
		newData[i] = Data[i];
	}

	Data = new player[num + 1];

	for (int j = 0; j < num; j++)
	{
		Data[j] = newData[j];
	}

	Data[num] = temp;

	
	return 1;
}

void print_Data(player* Data, int num)
{
	if (Data == 0)
	{
		cout << "No data.";
		return;
	}

	for (int i = 0; i < num; i++)
	{
		Data[i].print_Player();
		cout << "\n";
	}
}



bool edit_player(player* Data, int num)
{
	string temp;
	string temp2;
	double temp3;
	int temp4;

	cout << "Enter name of player you wish to edit: ";
	cin >> temp;

	for (int i = 0; i < num; i++)
	{
		if (temp == Data[i].get_Name())
		{
			Data[i].print_Player();
			
			cout << "1 for Add, 2 for edit: ";
			cin >> temp4;

			if (temp4 == 1)
			{
				cout << "How Much to add to buy in: ";
				cin >> temp3;

				Data[i].inc_BuyIn(temp3);

				cout << "\nHow much to add to end holdings: ";
				cin >> temp3;

				Data[i].inc_EndHolding(temp3);

			}
			else
			{
				cout << "New Buy In: ";
				cin >> temp3;

				Data[i].set_BuyIn(temp3);

				cout << "New end holdings: ";
				cin >> temp3;
				Data[i].set_EndHolding(temp3);


			}

			Data[i].set_Balance();

			cout << "\nEdited player data";
			Data[i].print_Player();
			system("pause");
			return 1;
			
		}
	}
}