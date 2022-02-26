#include<iostream>
#include<cmath>

#include "polar.h"

Polar :: Polar(float radius, float angle)
	: m_radius(radius), m_angle(angle)
{	
}

Polar Polar :: operator+(const Polar& rhs) 
{
	float x_lhs = m_radius * cos(m_angle);
	float y_lhs = m_radius * sin(m_angle);	

	float x_rhs = rhs.m_radius * cos(rhs.m_angle);
       	float y_rhs = rhs.m_radius * sin(rhs.m_angle);

	float tmp1 = x_lhs + x_rhs;
	float tmp2 = y_lhs + y_rhs;

	Polar tmp;
	tmp.m_radius = sqrt(tmp1*tmp1 + tmp2*tmp2);
	tmp.m_angle = atan(tmp2/tmp1);
	
	return tmp;
}

int main()
{
	
	return 0;
}
