#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"

class Rectangle {

public:
	Rectangle();
	Rectangle(Vec2 const& vec1, Vec2 const& vec2);

	// getter
	Vec2 getMax() const;
	Vec2 getMin() const;

	// setter
    void setMax(Vec2 const& vecmax);
    void setMin(Vec2 const& vecmin);

    // methods
    float circumference() const;

private:
	Vec2 max_;
	Vec2 min_;
};

#endif