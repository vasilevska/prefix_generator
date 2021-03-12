#ifndef _desnaZagrada_h_
#define _desnaZagrada_h_

#include "element.h"

class DesnaZagrada : public Element {
	char vrsta;
public:
	DesnaZagrada() {
		natpis = ")";
		vrsta = ')';
	}
	char dohvVrsta()const override { return vrsta; }
	DesnaZagrada* kopiraj()const override { return new DesnaZagrada(*this); }
};

#endif // !_desnaZagrada_h_
