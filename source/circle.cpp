#include "circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle():
rad{1}
{}

Circle::Circle(float rad_):
rad{rad_}
{}

void Circle::setradius(double r)
{
	rad=r;
}      

double Circle::getradius()
{
	return rad;
}

bool Circle::operator< (Circle const& a)
{
	return rad < a.rad;
}
bool Circle::operator> (Circle const& a)
{
	return rad > a.rad;
}
bool Circle::operator==(Circle const& a)
{
	return rad== a.rad;
}

