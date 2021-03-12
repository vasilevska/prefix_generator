#ifndef _stepenovanje_h_
#define _stepenovanje_h_

#include "binOperator.h"

class Stepenovanje : public BinOperator {
public:
	Stepenovanje() {
		natpis = "^";
		prioritet = 3;
	}
	int dohvPrioritet()const override { return prioritet; }
	Stepenovanje* kopiraj()const override { return new Stepenovanje(*this); }
};

#endif // !_stepenovanje_h_