#ifndef _izraz_h_
#define _izraz_h_

#include "lista.h"
#include "element.h"

class Izraz: public Lista<Element> {
public:
	Izraz* kopiraj() {
		return new Izraz(*this);
	}

	//da li je ovo dobro?
};

#endif // !_izraz_h_
