# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>

TEST_CASE ("describe_factorial","[aufgabe3]")
{
// ihre Loesung :
// ...
REQUIRE ( std :: all_of ( v . begin () , v . end () , is_even ));
}

int main (int argc, char* argv[])
{
return Catch :: Session (). run ( argc , argv );
}