#include "mat2.hpp"
#include <math.h>

//Task 2.5
// Mat2 constructor: default values
Mat2::Mat2() {
	n[0][0] = 1;
	n[0][1] = 0;
	n[1][0] = 0;
	n[1][1] = 1;
}

// Mat2 constructor: user input
Mat2::Mat2(float a, float b, float c, float d) {
	n[0][0] = a;
	n[0][1] = b;
	n[1][0] = c;
	n[1][1] = d;
};

// Mat2 *= operator
Mat2& Mat2::operator *=(Mat2 const& m) {
	float zz = this->n[0][0]; //zz = zerozero, etc.
	float zo = this->n[0][1];
	float oz = this->n[1][0];
	float oo = this->n[1][1];

	this->n[0][0] = zz * m.n[0][0] + zo * m.n[1][0];
	this->n[0][1] = zz * m.n[0][1] + zo * m.n[1][1];
	this->n[1][0] = oz * m.n[0][0] + oo * m.n[1][0];
	this->n[1][1] = oz * m.n[0][1] + oo * m.n[1][1];
	return *this;
};

// Mat2 * operator
Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
	Mat2 temp;
	temp.n[0][0] = m1.n[0][0] * m2.n[0][0] + m1.n[0][1] * m2.n[1][0];
	temp.n[0][1] = m1.n[0][0] * m2.n[0][1] + m1.n[0][1] * m2.n[1][1];
	temp.n[1][0] = m1.n[1][0] * m2.n[0][0] + m1.n[1][1] * m2.n[1][0];
	temp.n[1][1] = m1.n[1][0] * m2.n[0][1] + m1.n[1][1] * m2.n[1][1];
	return temp;
};