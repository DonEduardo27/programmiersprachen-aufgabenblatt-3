# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <vector>
# include <algorithm>
# include <iostream>
# include "circle.hpp"


TEST_CASE ("describe_sort","[is_sorted]")
{
	std::vector <Circle> tenDifferentCircles(10);

	for(int i=0;i<10;i++) 
	{
		tenDifferentCircles[i].setradius(rand());
	}
	std::sort (tenDifferentCircles.begin(), tenDifferentCircles.end());

	REQUIRE (std::is_sorted(tenDifferentCircles.begin(), tenDifferentCircles.end ()));
}
TEST_CASE ("describe_sort2","[is_sorted]")
{
	std::vector <Circle> twentyDifferentCircles(20);

	for(int i=0;i<10;i++) 
	{
		twentyDifferentCircles[i].setradius(rand());
	}


	std::sort (twentyDifferentCircles.begin(), twentyDifferentCircles.end(),
		[] (Circle a, Circle b) { return a.getradius() < b.getradius(); } );

REQUIRE (std::is_sorted(twentyDifferentCircles.begin(), twentyDifferentCircles.end ()));
	
}

TEST_CASE ("describe_add","[transform]")
{
std :: vector < int > v1 {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
std :: vector < int > v2 {9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1};
std :: vector < int > v3 (10);

std :: transform( v1.begin(), v1.end(), v2.begin(), v3.begin(), 
                    [] (int a, int b) { return a + b; });
	
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
