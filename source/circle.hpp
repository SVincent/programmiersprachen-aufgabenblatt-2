#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"

class Circle{

public:
	Circle();
	Circle(float rad);

	//getter
	float getRadius() const;
	Vec2 getCenter() const;

	//setter
    void setRadius(float rad);
    void setCenter(Vec2 cen);

    //methods
    float circumference() const;

private:
	float radius_;
	Vec2 center_;
};

#endif