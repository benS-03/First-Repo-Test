#pragma once
#include "player.h"

class player_data
{

private:

	int size;
	player* Data;

public:


	player_data();

	void gen_size();

	bool file_reader();

	bool file_writer();

	void increase_size();

	void decrease_size(int index_to_delete);

	void add_player();

	void delete_player();

	bool edit_player();

	void print_data();
	
	void verify_totals();

	void generate_payment();

	void clear_data();

	void create_file();















};