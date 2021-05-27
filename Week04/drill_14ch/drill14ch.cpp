#include "std_lib_facilities.h"

//1. feladat
class B1{

public:
	virtual void vf() {cout << "b1::vf() ";}
	void f() {cout << "b1::f() ";}
	virtual void pvf()=0; //5. feladat

};
//2. feladat
class D1 : public B1 {
	
public:
	void vf() override {cout << "d1::vf() ";}
	void pvf() override {cout << "d1::pvf() ";}
};

//6. feladat
class D2 : public D1 {
public:
	void pvf() override {cout << "d2::pvf() ";}


};
//7. feladat
struct B2{
 	virtual void pvf()=0;
};

class D21: public B2{
	string s = "d21::pvf()";
public:
	void pvf() override {cout << s << " ";}
};

class D22 : public B2{
	int m = 42;
public:
	void pvf() override {cout << m << " ";}


};

void f(B2& btwo){
	btwo.pvf();
}

int main()
{


	//1.
//	B1 b;
//	b.vf();
//	b.f();
//	b.pvf();
	//2.
	D1 d;
	d.vf();
	d.f();
	d.pvf();
	cout << "D1-es vége" << endl;
	//3.

	D1& br = d;
	br.vf();
	br.f();
	br.pvf();
	cout << "D1 ref vége" << endl;

	//4.
	D2 ds;
	ds.vf();
	ds.f();
	ds.pvf();
	cout << "D2-es vége" << endl;

	D21 dtwoone;
	D22 dtwotwo;
	dtwoone.pvf();

	f(dtwoone);
	f(dtwotwo);
	cout << "D21-D22 pvf-f vége" << endl;

	return 0;
}

