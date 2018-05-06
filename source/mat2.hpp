#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"

struct Mat2 {
	Mat2();
	Mat2(float a, float b, float c, float d);

	double n[2][2];

	float det() const;

	Mat2& operator *=(Mat2 const& m);

};
Mat2 operator*(Mat2 const& m1, Mat2 const& m2);

#endif