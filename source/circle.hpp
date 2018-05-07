#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class Circle{

public:
	Circle();
	Circle(float rad);
    Circle(float rad, Color const& farbe);
	Circle(float rad, Color const& farbe, Vec2 const& center);

	//getter
	float getRadius() const;
	Vec2 getCenter() const;
    Color getColor() const;

	//setter
    void setRadius(float rad);
    void setCenter(Vec2 const& cen);
    void setColor(Color const& col);

    //methods
    float circumference() const;

private:
	float radius_;
	Vec2 center_;
    Color color_;
};

#endif