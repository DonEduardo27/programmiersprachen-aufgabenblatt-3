# include <cstdlib>
# include <vector>
# include <list>
# include <iostream>
# include <iterator>
# include <algorithm>
# include <set>
# include <map>

int main ()
{
	std::list<unsigned int> hRandNum (100);//hundred random numbers

	for ( auto& i : hRandNum ) 
	{
		i = std::rand() % 101;
	}

	std::vector<unsigned int> vRandNum (100);//vector random numbers

	std::copy(std::begin(hRandNum), std::end(hRandNum), std::begin(vRandNum));
	std::cout<<"\nUnser Vektor enthalt folgende Zahlen:\n"<<std::endl;
	std::copy(std::begin(hRandNum), std::end(hRandNum), std::ostream_iterator<int>( std::cout , ", " ));	
	std::cout<<std::endl;
    std::list <unsigned int> notInRand;
    std::set <unsigned int> howManyInRand;

	for ( auto & i : hRandNum ) 
	{
		howManyInRand.insert(i);
	}
	std::cout<<"\nIn unserer Liste sind "<<howManyInRand.size()<<" verschiedene Zahlen. \n"<<std::endl;

	for ( int i = 0; i <= 100 ;++i) 
	{
		notInRand.push_back(i);
	}

	for ( auto & i : hRandNum) 
	{
		notInRand.remove(i);
	}

	std::cout << "Und zwar alle ausser:"<<std::endl;
	while (!notInRand.empty()) 
	{
		std::cout << ' ' << *notInRand.begin();
		notInRand.erase(notInRand.begin());
  	}
  	std::cout<<std::endl;

  	std::map <unsigned int,unsigned int> countsInRand;

  	for ( auto & i : hRandNum)
	{
		++countsInRand[i];
		//<5 = 1>
	}

	for (  int i = 0; i <= 100 ;++i)
	{
		std::cout<<i<<" existiert "<<countsInRand[i]<<"x"<<std::endl;
	}
return 0;
}