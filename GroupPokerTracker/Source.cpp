
#include "player.h"

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