#include "lista.h"
#include "element.h"
#include "greska.h"
#include "binOperator.h"
#include "desnaZagrada.h"
#include "izraz.h"
#include "levaZagrada.h"
#include "postfixGen.h"
#include "sabiranje.h"
#include "operand.h"
#include "mnozenje.h"
#include "Header.h"
#include<iostream>

int main() {
	try{
	Sabiranje s1;
	Mnozenje m1;
	Operand o1("s");
	Operand o2("k");
	LevaZagrada l1;
	DesnaZagrada l2;
	Izraz l;
	l += o1;
	l += m1;
	l += o2;
	l += s1;
	l += l1;
	l += o1;
	l += s1;
	l += o2;
	l += l2;
	
	cout << l << endl;

	GeneratorPostfiksa& generator = GeneratorPostfiksa::DohvatiGenerator();
	Izraz* p = generator(l);
	cout << *p << endl;


}
catch (exception e) {
	cout << e.what() << endl;
}
	return 0;


}

