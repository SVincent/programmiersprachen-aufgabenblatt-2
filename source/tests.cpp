#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


//Since our tests will check the validity of Vec2's, we need some Vec2's which we can compare things to
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
	REQUIRE(a1.x_ == Approx(12.88));
	REQUIRE(a1.y_ == Approx(24.44));
}
