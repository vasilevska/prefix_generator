#ifndef _binOperator_h_
#define _binOperator_h_

#include "element.h"

class BinOperator: public Element{
protected:
protected:
	int prioritet;

public:
	BinOperator(){ } 
	virtual ~BinOperator(){}
	char dohvVrsta()const override { return 'O'; }
	virtual int dohvPrioritet()const = 0;
	friend bool operator> (const BinOperator& b1, const BinOperator& b2);
	BinOperator* kopiraj()const override = 0;
};

#endif // !_binOperator_h_
