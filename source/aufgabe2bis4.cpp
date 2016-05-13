# include <cstdlib>
# include <vector>
# include <list>
# include <iostream>
# include <iterator>
# include <algorithm>
# include <set>

int main ()
{
	std::list<unsigned int> hRandNum (100);//hundred random numbers

	for ( auto& i : hRandNum ) 
	{
		i = std::rand() % 101;
	}

	std::vector<unsigned int> vRandNum (100);//vector random numbers

	std::copy(std::begin(hRandNum), std::end(hRandNum), std::begin(vRandNum));

	std::copy(std::begin(hRandNum), std::end(hRandNum), std::ostream_iterator<int>( std::cout , " \n " ));	

    std::list <unsigned int> notInRand;
    std::set <unsigned int> howManyInRand;

	for ( auto & i : hRandNum ) 
	{
		howManyInRand.insert(i);
	}
	std::cout<<"In der Liste sind "<<howManyInRand.size()<<" verschiedene Zahlen."<<std::endl;

	for ( int i = 0; i <= 100 ;++i) 
	{
		notInRand.push_back(i);
	}

	for ( auto & i : hRandNum) 
	{
		//void remove(const& i);
		notInRand.remove(i);
	}

	std::cout << "Und zwar alle ausser:";
	while (!notInRand.empty()) 
	{
		std::cout << ' ' << *notInRand.begin();
		notInRand.erase(notInRand.begin());
  	}

return 0;
}