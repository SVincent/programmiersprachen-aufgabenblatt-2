#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <math.h>

Circle::Circle() {
    //circle with no parameters: dot at origin
	radius_ = 0;
	center_ = Vec2(0, 0);
};

Circle::Circle(float rad) {
	radius_ = rad;
	center_ = Vec2(0, 0);
};

float Circle::getRadius() const{
	return radius_;
};

Vec2 Circle::getCenter() const {
	return center_;
}

void Circle::setRadius(float rad) {
    radius_ = rad;
}

void Circle::setCenter(Vec2 cen) {
    center_ = cen;
}

float Circle::circumference() const{
	return (2 * M_PI *radius_);
};