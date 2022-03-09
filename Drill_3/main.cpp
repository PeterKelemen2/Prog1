#include "std_lib_facilities.h"

class B1{
	public:
		virtual void vf() const{cout << "B1::vf\n";};
		void f() const{cout << "B1::f\n";};
};
B1 b1;

class D1 : public B1{
	public:
		void vf() const override {cout << "D1::vf\n";};
 };
D1 d1;

class B2{
	public:
		virtual void pvf() = 0;
		virtual void vf2() const{cout << "B2::vf2\n";};
};

class D : public B2{
	public:
		void f() const{cout << "D::f\n";};
		void vf2() const override {cout << "D::vf\n";};
		void pvf() {cout << "D::pvf\n";};
};
D d;

class D2 : public D1{
	public:
		void f() const{cout << "D2::f\n";};
		void vf() {cout << "D2::vf\n";};
		void pvf() {cout << "D2::pvf\n";};
};
D2 d2;


void call(const B1& b1){
	d1.vf();
	d1.f();
}

int main(){

	d1.vf();
	d1.f();
	b1.vf();
	b1.f();

	B2 *pvff = new D();
	pvff -> pvf();

	d.vf2();

	d2.f();
	d2.vf();
	d2.pvf();


	return 0;
}