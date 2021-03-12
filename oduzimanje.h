#ifndef _oduzimanje_h_
#define _oduzimanje_h_

#include "binOperator.h"

class Oduzimanje : public BinOperator {
public:
	Oduzimanje() {
		natpis = "-";
		prioritet = 1;
	}
	int dohvPrioritet()const override { return prioritet; }
	Oduzimanje* kopiraj()const override { return new Oduzimanje(*this); }
};

#endif // !_oduzimanje_h_
