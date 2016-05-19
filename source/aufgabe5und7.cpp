# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <vector>
# include <algorithm>
# include "circle.hpp"

bool is_even(unsigned int a)
{
	return a%2==0;
}
bool is_odd(unsigned int a)
{
	return !is_even(a);
}

template <typename container, typename number>

	void swap(number const& first ,number const& second, container& C )
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
	
class circless //unser Functor
{
public:
	bool operator()(Circle const& a,Circle const& b)
	{
		return a.getradius() < b.getradius();
	}
};

TEST_CASE ("describe_factorial","[is_even]")
{

	std::vector <unsigned int> hRandNum(100);
 
	for(auto& i : hRandNum) 
	{
		i = std::rand() % 101;
	}

	hRandNum.erase( std::remove_if(hRandNum.begin(), hRandNum.end(), is_odd), hRandNum.end() );

	REQUIRE ( std :: all_of ( hRandNum.begin () , hRandNum.end () , is_even ));

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
TEST_CASE ("describe_copyif","[copy_if]")
{
	std::vector<Circle>circles {{5.0f } ,{3.0f } ,{8.0f } ,{1.0f } ,{5.0f }};
	std::vector<Circle>remcirc (3);//remainingcircles

	std::copy_if( circles.begin(), circles.end(),
                  remcirc.begin(),
                  [] (Circle a) { return a.getradius() > 4.0f; });


	REQUIRE ( std :: all_of ( remcirc.begin () , remcirc.end () ,  [] (Circle a) { return a.getradius() > 3.0f; }));

}

TEST_CASE ("describe_sort","[is_sorted]")
{
	std::vector <Circle> tenDifferentCircles(10);

	for(int i=0;i<10;++i) 
	{
		tenDifferentCircles[i].setradius(rand());
	}

	std::sort(tenDifferentCircles.begin(), tenDifferentCircles.end());

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

TEST_CASE ("describe_sort3","[is_FUNCORT]")
{
	std::vector <Circle> twentyDifferentCircles(20);

	for(int i=0;i<20;i++) 
	{
		twentyDifferentCircles[i].setradius(rand()%1000);
	}


	std::sort(twentyDifferentCircles.begin(), twentyDifferentCircles.end(), circless());

REQUIRE (std::is_sorted(twentyDifferentCircles.begin(), twentyDifferentCircles.end ()));
	
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
