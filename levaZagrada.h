#ifndef _levaZagrada_h_
#define _levaZagrada_h_

#include "element.h";

class LevaZagrada : public Element {
	char vrsta;
public:
	LevaZagrada(){
		natpis = "(";
		vrsta = '(';
	}
	char dohvVrsta()const override { return vrsta; }
	LevaZagrada* kopiraj()const override { return new LevaZagrada(*this); }
};

#endif // !_levaZagrada_h_
