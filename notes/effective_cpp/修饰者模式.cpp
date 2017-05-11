#include "stdafx.h"
#include <iostream>
using namespace std;
//abstract man
class Man {
public:
	virtual void prt_cloth() = 0;
	virtual void prt_name() = 0;
	virtual ~Man() {
		cout << "destructor of Man" << endl;
	}
};
//concrete man
class Picard :public Man {
public:
	void prt_cloth() {
		cout << "bare man";
	}
	void prt_name() {
		cout << "Picard";
	}
};
//abstract decorator
class Decorator :public Man {
public:
	Man* man;
	Decorator(Man* someone) :man(someone) {};
};
//concrete Decorator
class T_shirt :public Decorator {
public:
	T_shirt(Man* someone) :Decorator(someone) {}
	void prt_cloth() {
		cout << "T-shirt" << " ";
		man->prt_cloth();
	}
	void prt_name() {
		man->prt_name();
	}
};
class UnderWear :public Decorator {
public:
	UnderWear(Man* someone) :Decorator(someone) {}
	void prt_cloth() {
		cout << "Underwear" << " ";
		man->prt_cloth();
	}
	void prt_name() {
		man->prt_name();
	}
};
int main() {
	Man* p = new Picard();
	Man* wearpants = new UnderWear(p);
	Man* wearshirt = new T_shirt(wearpants);
	wearpants->prt_cloth();
	cout << endl;
	wearshirt->prt_cloth();
	cout << endl;
	delete p;
	delete wearpants;
	delete wearshirt;
	getchar();
}
