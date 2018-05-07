#define _USE_MATH_DEFINES
#include "rectangle.hpp"
#include <math.h>

Rectangle::Rectangle() {
	Vec2 vec; //empty Vec2
	max_ = vec;
	min_ = vec;
};

Rectangle::Rectangle(Vec2 const& vec1, Vec2 const& vec2) {
	max_ = vec1;
	min_ = vec2;
};

Vec2 Rectangle::getMax() const{
	return max_;
};

Vec2 Rectangle::getMin() const{
	return min_;
};

void Rectangle::setMax(Vec2 const& vec) {
    max_ = vec;
}

void Rectangle::setMin(Vec2 const& vec) {
    min_ = vec;
}

float Rectangle::circumference() const {
    float height = max_.y_ - min_.y_;
	float width = max_.x_ - min_.x_;
	return 2 * (height + width);
};

void Rectangle::setColor(Color const& col) {
	color_ = col;
};