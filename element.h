#ifndef _element_h_
#define _element_h_

#include <string>
#include <iostream>

using namespace std;

class Element {
protected:
	string natpis;
public:

	virtual ~Element() {}
	virtual char dohvVrsta()const = 0;
	string dohvNatpis() const { return natpis; }

	virtual Element* kopiraj()const = 0;

	virtual void write(ostream& os) const {
		os << natpis;
	}

	friend ostream& operator<< (ostream& os, const Element& e) {
		e.write(os);
		return os;
	}
	
};

#endif // !_element_h_
