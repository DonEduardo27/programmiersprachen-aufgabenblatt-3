#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle 
{
public:
Circle();
Circle(float rad);

void setradius(double r);      
double getradius() const;


bool operator< (Circle const& a);
bool operator> (Circle const& a);
bool operator==(Circle const& a);

private:
float rad;
    
};


#endif
