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

	Data.file_reader();



	
	cout << "Welcome To Poker Balance Tracker\n\n";
	while (e == 1)
	{
		
		print_menu();
		cout << "\n\n";
		Data.print_data();
		cin >> select;
		switch (select)
		{
		case 1:
			
			Data.add_player();
			system("pause");
			break;
			

		case 2:
			Data.edit_player();
			system("pause");
			break;

		case 3:

			Data.delete_player();
			system("pause");
			break;

		case 4:
			
			Data.clear_data();
			system("pause");
			break;

		case 5:

			Data.file_writer();
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
	
	return 0;
}

void print_menu()
{
	cout << "Make a Selection"
		<< "\n1: Add a Player"
		<< "\n2: Edit a Player"
		<< "\n3: Delete a Player"
		<< "\n4: Clear Data"
		<< "\n5: Write Data to File"
		<< "\n6: Vertify Totals"
		<< "\n7: Generate Payment"
		<< "\n0: Exit Program\n\n";
}






