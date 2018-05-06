#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


//Since our tests will check the validity of Vec2's, we need some Vec2's which we can compare things to
//these will be re-initialized in every test to ensure the tests work in sequence
Vec2 d; //d for default
Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
Vec2 a2(1.1, 0.5);
Vec2 a3(0.0, 0.0);

// Test for default constructor
TEST_CASE("constructor Vec2()", "[d]") {
	REQUIRE(d.x_ == 0);
	REQUIRE(d.y_ == 0);
}

// Test for constructor with assigned values 
TEST_CASE("constructor Vec2(x,y)", "[Vec2(x,y)]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);
	REQUIRE(a1.x_ == Approx(12.88).epsilon(0.01));
	REQUIRE(a1.y_ == Approx(24.44).epsilon(0.01));
}

// Test for += operator
TEST_CASE("Vec2 operator+=", "[operator+=]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

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
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

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
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a1.operator*=(1.6);
	REQUIRE(a1.x_ == Approx(20.608).epsilon(0.001));
	REQUIRE(w.y_ == Approx(165.664).epsilon(0.001));

	//Edge case
	a1.operator*=(0.0);
	REQUIRE(a1.x_ == Approx(0).epsilon(0.001));
	
}

// Test for /= operator
TEST_CASE("Vec2 operator /=", "[operator/=]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a1.operator/=(1.6);
	REQUIRE(a1.x_ == Approx(8.05).epsilon(0.01));
	REQUIRE(a1.y_ == Approx(15.275).epsilon(0.001));

	//Edge case
	a1.operator/=(0.0);
	REQUIRE(a1.x_ == Approx(99999.99).epsilon(0.001)); //the /= operator checks for division by zero, and returns 99999.99 as pseudo-infinity. Better would probably be an actual exception output

}

//Task 2.4

// Test for + operator
TEST_CASE("+ operator", "[operator+]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a3 = operator+(a1, a2);
	REQUIRE(a3.x_ == Approx(13.98).epsilon(0.01));
	REQUIRE(a3.y_ == Approx(24.94).epsilon(0.01));
}

// Test for - operator
TEST_CASE("- operator", "[operator-]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a3 = operator-(a1, a2);
	REQUIRE(a3.x_ == Approx(11.78).epsilon(0.01));
	REQUIRE(a3.y_ == Approx(23.94).epsilon(0.01));

}

// Test for * operator
TEST_CASE("* operator", "[operator*]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  //Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	// Operator *(Vec2, float)
	a3 = operator*(a1, 2.5);
	REQUIRE(a3.x_ == Approx(32.2).epsilon(0.01));
	REQUIRE(a3.y_ == Approx(61.1).epsilon(0.01));

	// Operator *(float, Vec2)
	a3 = operator*(2.5, a1);
	REQUIRE(a3.x_ == Approx(32.2).epsilon(0.01));
	REQUIRE(a3.y_ == Approx(61.1).epsilon(0.01));

	a3 = operator* (0.0, a1);
	REQUIRE(a3.x_ == Approx(0).epsilon(0.01));
	REQUIRE(a3.y_ == Approx(0).epsilon(0.01));
}

// Test for / operator
TEST_CASE("/ operator", "[operator/]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a3 = operator/(a1, 1.3);
	REQUIRE(a3.x_ == Approx(9.9076923).epsilon(0.0000001));
	REQUIRE(a3.y_ == Approx(18.8).epsilon(0.001));

	a3 = operator/(a2, -5.5);
	REQUIRE(a3.x_ == Approx(-0.2).epsilon(0.001));
	REQUIRE(a3.y_ == Approx(-0.090909).epsilon(0.000001));

	a3 = operator/(a1, 0); //exception, as division by zero is not defined
	REQUIRE(a3.x_ == Approx(99999.99).epsilon(0.001));
	REQUIRE(a3.y_ == Approx(99999.99).epsilon(0.001));
}