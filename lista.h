#ifndef _lista_h_
#define _lista_h_

#include "greska.h"
#include"element.h"
#include <iostream>
using namespace std;

template <typename T>
class Lista {
	struct Cvor {
		T* info;
		Cvor* next;
		Cvor* prev;
		Cvor( T* i, Cvor* s = nullptr) {
			info = i->kopiraj();
			next = prev = s;
		}
	};
	Cvor* fr, * bc;
	int br;
	mutable Cvor* cur;
public: 
	Lista() {
		fr = nullptr;
		bc = nullptr;
		cur = nullptr;
		br = 0;
	}
	/**/
	//DODAJ KOP I PREM KONSTRUKTOR I OPERATOR = DVE VARIJANTE
	Lista(const Lista& l) {
		kopiraj(l);
	}
	Lista& operator= (const Lista& l) {
		if (this != &l) {
			isprazni();
			kopiraj(l);
		}
	}


	Lista(Lista&& l) {
		fr = l.fr;
		bc = l.bc;
		cur = l.cur;
		l.fr = l.bc = l.cur = nullptr;

	}
	Lista& operator= (const Lista&& l) {
		if (this != &l) {
			isprazni();
			fr = l.fr;
			bc = l.bc;
			cur = l.cur;
			l.fr = l.bc = l.cur = nullptr;
		}
	}

	void kopiraj(const Lista& l) {
		fr = bc = nullptr;
		l.cur = l.fr;
		br = l.br;
		while (l.cur) {
			Cvor* n = new Cvor(l.cur->info);
			if (!fr) fr = n;
			n->prev = bc;
			if (bc) bc->next = n;
			bc = n;
			l.cur = l.cur->next;
		}
	}
	//OVO NISTA NE VALJA!



	Lista& operator+=(T& inf) {
		//Cvor* n = new Cvor(inf->kopiraj());
		Cvor* n = new Cvor(&inf);
		if (bc) bc->next = n;
		else fr = n;
		n->prev = bc;
		bc = n;
		br++;
		return *this;
	}

	T* operator-() {
		cur = fr;
		if (!cur) throw GPrazna();
		br--;
		if (cur == bc) {
			T* val = cur->info;
			delete cur;
			cur = fr = bc = nullptr;
			return val;
		}
		T* val = bc->info;
		cur = bc->prev;
		delete bc;
		cur->next = nullptr;
		bc = cur;
		return val;
	}

	T* operator*() {
		if (!fr) throw GPrazna();
		T* val = fr->info;
		br--;
		if (fr == bc) {
			delete bc;
			cur = fr = bc = nullptr;
			return val;
		}
		cur = fr;
		fr = fr->next;
		fr->prev = nullptr;
		delete cur;
		return val;
	}

	void isprazni() {
		Cvor* stari;
		while (fr) {
			stari = fr;
			fr = fr->next;
			delete stari->info;
			delete stari;
		}
		bc = cur = nullptr;
	}

	int broj() const { return br; }


	friend ostream& operator<<(ostream& os, const Lista& l) {
		l.cur = l.fr;
		while (l.cur != nullptr) {
			os << *(l.cur->info) << " ";
			l.cur = l.cur->next;
		}
		return os;
	}


	virtual ~Lista() {
		isprazni();
	}	

};

#endif // !_lista_h_

