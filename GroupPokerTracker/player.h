#pragma once
#include <string>
#include <iostream>

using namespace std;


class player
{
private:
	double total_buy_in = 0.0;
	double total_end_holding = 0.0;
	double balance;
	string Name;
	
public:
	
	//Constructors

	player();
	player(string n, double buy, double endhold);

	// setters
	void set_Name(string n);
	void set_BuyIn(double x);
	void set_EndHolding(double x);
	void set_Balance();

	// getters
	string get_Name();
	double get_BuyIn();
	double get_EndHolding();
	double get_Balance();

	// incrementers
	void inc_BuyIn(double x);
	void inc_EndHolding(double x);

	//display
	void print_Player();

};