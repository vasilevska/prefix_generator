#ifndef _deljenje_h_
#define _deljenje_h_

#include "binOperator.h"

class Deljenje : public BinOperator {
public:
	Deljenje() {
		natpis = "/";
		prioritet = 2;
	}
	int dohvPrioritet()const override { return prioritet; }
	Deljenje* kopiraj()const override { return new Deljenje(*this); }
};

#endif // !_deljenje_h_