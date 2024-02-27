
#include "player.h"

using namespace std;

player::player()
{
	Name = "";
	total_buy_in = 0;
	total_end_holding = 0;
	balance = 0;
}

player::player(string n, double buy, double endhold, double bal)
{
	Name = n;
	total_buy_in = buy;
	total_end_holding = endhold;
	balance = bal;
}


void player::set_Name(string n)
{
	Name = n;
}

void player::set_BuyIn(double x)
{
	total_buy_in = x;
	return;
}

void player::set_EndHolding(double x)
{
	total_end_holding = x;
}

void player::set_Balance()
{
	balance = total_end_holding - total_buy_in;
}

string player::get_Name()
{
	return Name;
}

double player::get_BuyIn()
{
	return total_buy_in;
}

double player::get_EndHolding()
{
	return total_end_holding;
}

double player::get_Balance()
{
	return balance;
}

void player::inc_BuyIn(double x)
{
	total_buy_in += x;
	return;
}

void player::inc_EndHolding(double x)
{
	total_end_holding += x;
	return;
}

void player::print_Player()
{
	cout << Name << "\nTotal Buy In: "<< total_buy_in << "\nEnd Holdings: "<< total_end_holding << "\nBalance: "<<balance;
}