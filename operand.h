#ifndef _operand_h_
#define _operand_h_

#include "element.h"
#include <string>

class Operand : public Element {

public:
	Operand(string s){
		natpis = s; 
	}
	Operand* kopiraj()const override{ return new Operand(*this); }
	char dohvVrsta()const override{ return 'D'; }
};

#endif // !_operand_h_
