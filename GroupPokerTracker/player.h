#pragma once

class player
{
private:
	double total_buy_in = 0.0;
	double total_end_holding = 0.0;
	double balance;
	
public:
	
	// setters
	void set_BuyIn(double x);
	void set_EndHolding(double x);
	void set_Balance();

	// getters
	double get_BuyIn();
	double get_EndHolding();
	double get_Balance();

	// incrementers
	void inc_BuyIn(double x);
	void inc_EndHolding(double x);

};