# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <vector>
# include <algorithm>

bool is_even(unsigned int a)
{
	return a%2==0;
}

TEST_CASE ("describe_factorial","[is_even]")
{
	std::vector <unsigned int> hRandNum(100);

	for(auto& i : hRandNum) 
	{
		i = std::rand() % 101;
	}
	std::vector <unsigned int> evenRandNum; //weil ich fur .erase zu bjoern bin

	for(auto& i : hRandNum) 
	{
		if(is_even(i)) evenRandNum.push_back(i) ;
	}
	REQUIRE ( std :: all_of ( evenRandNum.begin () , evenRandNum.end () , is_even ));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
