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
         //Gets Radius
double Circle::getradius()
{
	return rad;
}          
             //Calculate the are
double Circle::area()
{
	return 3.141592*rad*rad;
}      
             //Calculate the circumferenc
double Circle::circum()
{
	return 3.141592*rad*2;
}
             //returns the diameter
double Circle::diameter() 
{
	return rad*2;
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
/*
bool  operator< (Circle const& a, Circle const& b)
{
	return (a.getradius() < b.getradius());
}

bool  operator> (Circle const& a, Circle const& b)
{
	return (a.getradius() > b.getradius());
}

bool  operator==(Circle const& a, Circle const& b)
{
	return (a.getradius() == b.getradius());
}*/
