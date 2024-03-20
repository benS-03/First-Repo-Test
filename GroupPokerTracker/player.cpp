
#include "player.h"
#include <sstream>
#include <iomanip>

using namespace std;

player::player()
{
	Name = "";
	total_buy_in = 0;
	total_end_holding = 0;
	balance = 0;
}

player::player(string n, double buy, double endhold)
{
	Name = n;
	total_buy_in = buy;
	total_end_holding = endhold;
	this->set_Balance();
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
	cout << Name << "\nTotal Buy-In:        " << total_buy_in
		<< "\nTotal End Holdings:  " << total_end_holding
		<< "\nBalance:             " << balance;
}

void player::print_Player_t()
{
	int buy_in_length;
	int holdings_length;
	int balance_length;

	stringstream s;
	
	s << fixed << setprecision(2) << total_buy_in;
	buy_in_length = s.str().length();
	s.str("");
	s << total_end_holding;
	holdings_length = s.str().length();
	s.str("");
	s << balance;
	balance_length = s.str().length();
	s.str(string());


	cout << fixed << setprecision(2) << "\n| " << Name << string(9 - Name.length(), ' ') << "| " << total_buy_in << string(15-buy_in_length,' ') <<'|'<<"  " << total_end_holding << string(19-holdings_length,' ')<<'|'<<"  " << balance << string(9-balance_length,' ') << '|';
}