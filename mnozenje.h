#ifndef _mnozenje_h_
#define _mnozenje_h_

#include "binOperator.h"

class Mnozenje : public BinOperator {
public:
	Mnozenje() {
		natpis = "*";
		prioritet = 2;
	}
	int dohvPrioritet()const override { return prioritet; }
	Mnozenje* kopiraj()const override { return new Mnozenje(*this); }
};

#endif // !_mnozenje_h_