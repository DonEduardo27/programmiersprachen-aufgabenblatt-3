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
TEST_CASE ("describe_copyif","[copy_if]")
{
	std::vector<Circle>circles {{5.0f } ,{3.0f } ,{8.0f } ,{1.0f } ,{5.0f }};
	std::vector<Circle>remcirc (3);//remainingcircles

	std::copy_if( circles.begin(), circles.end(),
                  remcirc.begin(),
                  [] (Circle a) { return a.getradius() > 4.0f; });


	REQUIRE ( std :: all_of ( remcirc.begin () , remcirc.end () ,  [] (Circle a) { return a.getradius() > 3.0f; }));

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}



/*Legen Sie einen std::vector mit Objekten der Klasse Circle an. Alle Kreise
sollen verschiedene Radien haben. Zum Beispiel:
// Vorrausgesetzt es gibt einen Konstruktor
// der einen Radius als Parameter bekommt
std :: vector < Circle > circles {{5.0 f } ,{3.0 f } ,{8.0 f } ,
{1.0 f } ,{5.0 f }};
Kopieren Sie anschliessend mit dem Algorithmus copy_if alle Kreise deren
Radius größer als 4.0f ist, in einen zweiten std::vector. Verwenden Sie für das
benötigte Prädikat wieder ein Lambda. Testen Sie danach mit std::all_of,
dass die Radien im Zielcontainer alle größer drei sind (unter Verwendung eines
Lambdas).*/