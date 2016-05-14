# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <vector>
# include <algorithm>
# include "circle.hpp"


TEST_CASE ("describe_factorial","[is_even]")
{
	std::vector <Circle> tenDifferentCircles(10);

	for(int i=0;i<10;i++) 
	{
		tenDifferentCircles[i].setradius(10-i);
	}
	std::sort (tenDifferentCircles.begin(), tenDifferentCircles.end());

	REQUIRE (std::is_sorted(tenDifferentCircles.begin(), tenDifferentCircles.end ()));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
