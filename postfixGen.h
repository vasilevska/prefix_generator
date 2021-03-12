#ifndef _postfixGen_h_
#define _postfixGen_h_

using namespace std;

class GeneratorPostfiksa {
	static GeneratorPostfiksa* generatorP;
	GeneratorPostfiksa() {

	}
public:
	static GeneratorPostfiksa& DohvatiGenerator() {
		if (!generatorP) generatorP = new GeneratorPostfiksa;
		return *generatorP;
	}

	GeneratorPostfiksa(const GeneratorPostfiksa& l) = delete;
	GeneratorPostfiksa(const GeneratorPostfiksa&& l) = delete;
	GeneratorPostfiksa& operator=(const GeneratorPostfiksa&) = delete;
	GeneratorPostfiksa& operator=(const GeneratorPostfiksa&&) = delete;



	Izraz* operator()(Izraz& infix) {
		int rank = 0;
		Izraz izr = *(infix.kopiraj());
		Izraz*postfix = new Izraz();
		Izraz stack;
		cout << izr << endl;
		Element* next = *izr;
		
		//BinOperator* top = nullptr;
		while (next) {
			if (next->dohvVrsta() == 'D') {
				*postfix += *next;
				rank++;
			}
			else {
				if (next->dohvVrsta() == 'O') {
					bool flag = 0;
					while (stack.broj() != 0) {
						/*
						poslednji = (BOperator*)-(*operatori);
						trenutni = (BOperator*)temp;
						if (poslednji->DohvatiNatpis() != "(" && trenutni->DohvatiNatpis() != "(" && trenutni->DohvatiPrioritet() == poslednji->DohvatiPrioritet()) {
						*/
						
		
						Element* tmp = -stack;//ne ako ide provera
	
							if (tmp->dohvVrsta() == '(' || tmp->dohvVrsta() == ')') {
								stack += *tmp;
								stack += *next;
								flag = 1;
								break;
							}
						
							
							while (tmp != nullptr && ((BinOperator*)next)->dohvPrioritet() <= ((BinOperator*)tmp)->dohvPrioritet() ) {
									*postfix += *tmp;
									rank--;
									if (stack.broj()) tmp = -stack;
									else tmp = nullptr;
							}
							if(tmp) stack += *tmp;
							stack += *next;
							flag = 1;
							
							

						
						cout << *postfix<< endl;
						
						if (rank < 1) {
							throw GPostfiks();
						}
						break;
						
						
					}
					if(!flag)stack += *next;
					cout <<"s: "<< stack << endl;
				}
				else if (next->dohvVrsta() == '(') {
					stack += *next;
				}
				else if (next->dohvVrsta() == ')') {
					Element* tmp = -stack;
					cout << "s: " << stack << endl;
					while (tmp->dohvVrsta() != '(') {
						*postfix += *tmp;
						cout << *postfix << endl;
						if (tmp->dohvVrsta() == 'D') rank++;
						else if (tmp->dohvVrsta() == 'O') rank --;
						tmp = -stack;
					}
				}
				
			}
			if (izr.broj()) next = *izr;
			else next = nullptr;
			
		}
		while (stack.broj() != 0) {
			Element* x = -stack;
			*postfix += *x;
			if (x->dohvVrsta() == 'D') rank++;
			else if (x->dohvVrsta() == 'O') rank --;
		}
		if (rank != 1) throw GPostfiks();
		return postfix;
	}
};

GeneratorPostfiksa* GeneratorPostfiksa::generatorP = 0;

#endif // !_postfixGen_h_
