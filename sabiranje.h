#ifndef _sabiranje_h_
#define _sabiranje_h_

#include "binOperator.h"

class Sabiranje : public BinOperator {
public:
	Sabiranje(){
		natpis = "+";
		prioritet = 1;
	}
	int dohvPrioritet()const override{ return prioritet; }
	Sabiranje* kopiraj()const override { return new Sabiranje(*this); }
};

#endif // !_sabiranje_h_
