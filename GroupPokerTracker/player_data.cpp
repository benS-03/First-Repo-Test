#include "player_data.h"
#include <ostream>
#include <fstream>
#include <stdlib.h>
#include <istream>


using namespace std;


player_data::player_data()
{
	Data = 0;
	size = 0;
}

void player_data::print_data()
{
	if (Data == 0)
	{
		cout << "---------No data.---------";
		return;
	}
	cout << "|  Player  |  Total Buy-In  | Total End Holdings  |  Balance  |"
		<< "\n--------------------------------------------------------------";
	for (int i = 0; i < size; i++)
	{
		Data[i].print_Player_t();
		cout << "\n--------------------------------------------------------------";
	}
	cout << "\n\n";

}

void player_data::gen_size()
{
	
	ifstream inData;

	inData.open("GroupData.txt");

	int count = 0;
	string dont_care;

	while (!inData.eof())
	{
		count++;
		getline(inData, dont_care);

	}

	inData.close();

	size = count;

}

bool player_data::file_reader()
{

	ifstream inData;
	inData.open("GroupData.txt");

	if (inData.fail())
		return 0;

	if (inData.peek() == ifstream::traits_type::eof())
	{
		return 1;
	}

	this->gen_size();

	Data = new player[size];

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

bool player_data::file_writer()
{
	ofstream outData;

	outData.open("GroupData.txt");

	for (int i = 0; i < size; i++)
	{
		outData << Data[i].get_Name() << " " << Data[i].get_BuyIn() << " " << Data[i].get_EndHolding() << " " << Data[i].get_Balance()<<"\n";
	}

	outData.close();

	return 1;
}

void player_data::decrease_size(int index_to_delete)
{
	player* tempData = new player[size - 1];
	bool flag = 0;

	for (int i = 0; i < size - 1; i++)
	{
		if (i != index_to_delete || flag)
			tempData[i] = Data[i];
		else
		{
			i -= 1;
			flag = 1;
		}
	}


	Data = new player[size - 1];

	for (int i = 0; i < size-1; i++)
	{
		Data[i] = tempData[i];
	}


	size--;
}

void player_data::increase_size()
{
	player* tempData = new player[size + 1];

	for (int i = 0; i < size; i++)
	{
		tempData[i] = Data[i];
	}


	Data = new player[size + 1];

	for (int i = 0; i < size; i++)
	{
		Data[i] = tempData[i];
	}
	

	size++;

}

void player_data::add_player()
{

	this->increase_size();

	player temp;
	string temp_name = "";
	double temp_data;

	cout << "Enter Player's Name: ";

	cin >> temp_name;
	temp.set_Name(temp_name);

	cout << "\nEnter Player's Buy In: ";

	cin >> temp_data;
	temp.set_BuyIn(temp_data);

	cout << "\nEnter Player's End Holdings: ";

	cin >> temp_data;
	temp.set_EndHolding(temp_data);

	temp.set_Balance();

	Data[size - 1] = temp;
}

void player_data::delete_player()
{
	string temp;
	int index = -1;
	cout << "\nEnter name of player you wish to delete: ";
	cin >> temp;

	for (int i = 0; i < size; i++)
	{
		if (temp == Data[i].get_Name())
		{
			index = i;
			break;
		}
	}

	this->decrease_size(index);
}


bool player_data::edit_player()
{
	string temp_name;
	int index = -1;
	int temp_select;
	double temp_data;


	cout << "\nEnter name of player you wish to edit: ";
	cin >> temp_name;

	for (int i = 0; i < size; i++)
	{
		if (temp_name == Data[i].get_Name())
		{
			index = i;
			break;
		}
	}

	cout << "1 for Add, 2 for edit: ";
	cin >> temp_select;
	cout << "\n";
	Data[index].print_Player();

	if (temp_select == 1)
	{
		cout << "\n\nHow Much to add to buy in: ";
		cin >> temp_data;

		Data[index].inc_BuyIn(temp_data);

		cout << "\nHow much to add to end holdings: ";
		cin >> temp_data;

		Data[index].inc_EndHolding(temp_data);

	}
	else
	{
		cout << "\n\nNew Buy In: ";
		cin >> temp_data;

		Data[index].set_BuyIn(temp_data);

		cout << "\nNew end holdings: ";
		cin >> temp_data;
		Data[index].set_EndHolding(temp_data);


	}

	Data[index].set_Balance();

	cout << "\n\nEdited player data:\n\n";
	Data[index].print_Player();
	cout << "\n\n";
	return 1;

}

void player_data::verify_totals()
{
	double total_buyin=0;
	double total_holdings = 0;

	for (int i = 0; i < size; i++)
	{
		total_buyin += Data[i].get_BuyIn();
		total_holdings += Data[i].get_EndHolding();
	}

	cout << "Toal End Buy In: " << total_buyin;
	cout << "\n\nTotal End Holdings: " << total_holdings;

	if (total_buyin == total_holdings)
	{
		cout << "\n\nValues Match. No lost balance\n\n";
	}
	else if (total_buyin > total_holdings)
	{
		cout << "\n\nValues do not match: Buy In Greater Than Holdings\n\n";
	}
	else
	{
		cout << "\b\bValues do not match: Holdings Greater Than Buy In\n\n";
	}

}