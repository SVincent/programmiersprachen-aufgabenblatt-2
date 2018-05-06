#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


//Since our tests will check the validity of Vec2's, we need some Vec2's which we can compare things to
Vec2 d; //d for default
Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc. //w 23.54, 51.77
Vec2 a2(1.1, 0.5);        //z  1.3, 2.2
Vec2 a3(0.0, 0.0);        //r

// Test for default constructor
TEST_CASE("constructor Vec2()", "[d]") {
	REQUIRE(d.x_ == 0);
	REQUIRE(d.y_ == 0);
}

// Test for constructor with assigned values 
TEST_CASE("constructor Vec2(x,y)", "[Vec2(x,y)]") {
	REQUIRE(a1.x_ == Approx(12.88).epsilon(0.01));
	REQUIRE(a1.y_ == Approx(24.44).epsilon(0.01));
}

// Test for += operator
TEST_CASE("Vec2 operator+=", "[operator+=]") {

	a1.operator+=(a2);
	REQUIRE(a1.x_ == Approx(13.98).epsilon(0.01));
	REQUIRE(a1.y_ == Approx(24.94).epsilon(0.01));

	//Edge cases (a3 = (0,0))
	a1.operator+=(a3);
	REQUIRE(a1.x_ == Approx(12.88).epsilon(0.01));
	a3.operator+=(a1);
	REQUIRE(a3.y_ == Approx(24.44).epsilon(0.01));
	
}

// Test for -= operator
TEST_CASE("Vec2 operator -=", "[operator-=]") {

	a1.operator-=(a2);
	REQUIRE(a1.x_ == Approx(11.78).epsilon(0.01));
	REQUIRE(a1.y_ == Approx(23.94).epsilon(0.01));

	//Edge cases (a3 = (0,0))
	a1.operator-=(a3);
	REQUIRE(a1.x_ == Approx(12.88).epsilon(0.01));
	a3.operator-=(a1);
	REQUIRE(r.y_ == Approx(-24.44).epsilon(0.01));
}

// Test for *= operator
TEST_CASE("Vec2 operator *=", "[operator*=]") {

	a1.operator*=(1.6);
	REQUIRE(a1.x_ == Approx(20.608).epsilon(0.001));
	REQUIRE(w.y_ == Approx(165.664).epsilon(0.001));

	//Edge case
	a1.operator*=(0.0);
	REQUIRE(a1.x_ == Approx(0).epsilon(0.001));
	
}

// Test for /= operator
TEST_CASE("Vec2 operator /=", "[operator/=]") {

	a1.operator/=(1.6);
	REQUIRE(a1.x_ == Approx(8.05).epsilon(0.01));
	REQUIRE(a1.y_ == Approx(15.275).epsilon(0.001));

	//Edge case
	a1.operator/=(0.0);
	REQUIRE(a1.x_ == Approx(99999.99).epsilon(0.001)); //the /= operator checks for division by zero, and returns 99999.99 as pseudo-infinity. Better would probably be an actual exception output

}