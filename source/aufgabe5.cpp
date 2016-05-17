# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <vector>
# include <algorithm>

bool is_even(unsigned int a)
{
	return a%2==0;
}

template <typename container>

	void swap(int first ,int second, container& C )
	{
		auto temp = C[first];
		C[first]=C[second];
		C[second]=temp;
	}

template <typename container, typename function>

	container filter(container const& C, function const& F)
	{
		container newCont;
		for(auto i : C)
		{
			if(F(i))newCont.push_back(i);
		}
		return newCont;
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

TEST_CASE ("describe_swapped","[swap]")
{
	std::vector <unsigned int> onetosix{1,2,3,4,5,6};
	swap(1,4,onetosix);
	swap(0,5,onetosix);
	REQUIRE (onetosix[1]==5);
	REQUIRE (onetosix[4]==2);
	REQUIRE (onetosix[0]==6);
	REQUIRE (onetosix[5]==1);	
}
TEST_CASE ("describe_evenTemplate","[even]")
{
    std :: vector < int > v {1 ,2 ,3 ,4 ,5 ,6,7,8,9,10,11,12};
    v = filter(v,is_even);
	REQUIRE ( std :: all_of ( v.begin () , v.end () , is_even ));

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
