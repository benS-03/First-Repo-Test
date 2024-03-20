#include <iostream>
#include <fstream>
#include <vector>
#include "player.h"
#include <string>
#include <stdlib.h>
#include "player_data.h"

using namespace std;





void print_menu();


int main()
{
	int select;
	bool e = 1;

	player_data Data;

	bool func_flag;
	bool file_flag;
	bool change_flag = 0;
	file_flag = Data.file_reader();



	
	cout << "Welcome To Poker Balance Tracker\n\n";
	while (e == 1)
	{
		if (!file_flag)
		{
			cout << "\nNo file in directory exists: place file in directory ( should be tited GroupData.txt )\n"
				<< "\nEnter 0 if you have placed your file or 1 if you would like the file to be created for you: ";
			cin >> select;

	
			if (select == 1)
			{
				Data.create_file();
				file_flag = 1;
			}
			else if ( select != 0)
			{
				cout << "\nINVALID OPTION\n";
			}

			continue;
		}
		print_menu();
		cout << "\n\n";
		Data.print_data();
		cin >> select;
		switch (select)
		{
		case 1:
			
			Data.add_player();
			change_flag = 1;
			system("pause");
			break;
			

		case 2:
			func_flag = Data.edit_player();

			if (func_flag)
				change_flag = 1;

			system("pause");
			break;

		case 3:

			Data.delete_player();
			change_flag = 1;
			system("pause");
			break;

		case 4:
			
			Data.clear_data();
			change_flag = 1;
			system("pause");
			break;

		case 5:

			Data.file_writer();
			change_flag = 0;
			system("pause");
			break;

		case 6:
			Data.verify_totals();
			system("pause");
			break;

		case 7:
			Data.generate_payment();
			cout << "\n\n Would you like to clear data now? (1 for yes 2 for no):";
			cin >> select;
			if (select == 1) Data.clear_data();
			system("pause");
			break;

		case 0:
			e = 0;
			break;

		default:

			cout << "\nINVALID SELECTION\nTry again.";
			
		}
	}
	
	while (change_flag)
	{
		cout << "\n\n Would you like to save your changes? (1 for yes 2 for no): ";
		cin >> select;
		if (select == 1)
		{
			Data.file_writer();
			change_flag = 0;
		}
		else if (select == 2)
		{
			cout << "\nChanges will not be saved";
			change_flag = 0;
		}
		else
			cout << "\nInvalid Option";

	}
	
	return 0;
}

void print_menu()
{
	cout << "Make a Selection"
		<< "\n1: Add a Player"
		<< "\n2: Edit a Player"
		<< "\n3: Delete a Player"
		<< "\n4: Clear Data"
		<< "\n5: Write Data to File ( if file does not exist, one will be created )"
		<< "\n6: Vertify Totals"
		<< "\n7: Generate Payment"
		<< "\n0: Exit Program\n\n";
}






