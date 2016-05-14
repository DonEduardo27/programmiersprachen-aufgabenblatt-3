# include <cstdlib>
# include <vector>
# include <list>
# include <iostream>
# include <iterator>
# include <algorithm>

int main ()//Start
{
std :: vector < int > v0 (10); //Array v0 mit 10 stellen=default
for ( std :: vector < int >:: iterator it = v0 . begin ();//eine fot schleife, die
it != v0 . end (); ++ it ) {//uber das komklette array iteriert
* it = std :: rand ();//..und es mit zufallszahlen belegt
}

std :: copy ( std :: begin ( v0 ) , std :: end ( v0 ) ,//std copy kopiert v0
std :: ostream_iterator < int >( std :: cout , " \n " ));//in einen ostream und gibt ihn aus

std :: list < int > l0 ( v0 . size ());//dann erstellen wir eine liste l0 so gross wie v0

std :: copy ( std :: begin ( v0 ) , std :: end ( v0 ) , std :: begin ( l0 ));//...und kopieren v0 komplett rein.

std :: list < int > l1 ( std :: begin ( l0 ) , std :: end ( l0 ));//dann erstellen wir eine Liste l1 mit dem selbnen inhalt von l0

std :: reverse ( std :: begin ( l1 ) , std :: end ( l1 ));//drehen ihn komplett um

std :: copy ( std :: begin ( l1 ) , std :: end ( l1 ) ,
std :: ostream_iterator < int >( std :: cout , " \n " ));//geben ihn wie oben aus

l1 . sort ();//sortieren ihn

std :: copy ( l1 . begin () , l1 . end () ,
std :: ostream_iterator < int >( std :: cout , " \n " ));//geben den sortierten inhalt wie oban aus

std :: generate ( std :: begin ( v0 ) , std :: end ( v0 ) , std :: rand );//weist jedem feld in v0 einen von der funktion std::rand generierten wert zu

std :: copy ( v0 . rbegin () , v0 . rend () ,
std :: ostream_iterator < int >( std :: cout , " \n " ));//und gibt ihn wie oben, bloss von hinten nach vorne aus.

return 0;//YEAH!
}
