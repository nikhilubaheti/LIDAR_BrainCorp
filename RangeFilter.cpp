#include "RangeFilter.h"
#include <algorithm>

RangeFilter::RangeFilter(double high, double low)
{
	this->max_range = high;
	this->min_range = low;
}

void RangeFilter::setProperty(double high, double low)
{
	this->max_range = high;
	this->min_range = low;
}

array1D RangeFilter::update(array1D value)
{
	for (array1D::iterator it = value.begin(); it != value.end(); ++it)
	{
		*it = std::max(this->min_range, std::min(this->max_range, *it));
	}
	return value;
}

double RangeFilter::getMaxRange()
{
	return this->max_range;
}

double RangeFilter::getMinRange()
{
	return this->min_range;
}
