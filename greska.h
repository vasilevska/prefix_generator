#ifndef _greska_h_
#define _greska_h_

#include <exception>
using namespace std;

class GPrazna : public exception {
public:
	GPrazna() :exception("Zadata je neispravna vrednost.") {}
};
class GPostfiks : public exception {
public:
	GPostfiks() :exception("Nije moguce generisati ispravan izraz") {}
};

#endif // !_greska_h_